#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <stdexcept>
#include <opencv2/opencv.hpp>

namespace fs = std::filesystem;

const cv::Size img_size(100, 100);
void get_data(std::vector<cv::Mat>& images, const std::string& data_path);
void make_eigenfaces(std::vector<cv::Mat>& images, cv::Mat& mean, cv::Mat& eigenfaces, cv::Mat& projected); 

int main() {
    std::string data_path = "../data";
    std::vector<cv::Mat> images;

    get_data(images, data_path);

    cv::Mat mean;
    cv::Mat eigenfaces;
    cv::Mat projected;

    make_eigenfaces(images, mean, eigenfaces, projected); 

    cv::CascadeClassifier face_cascade;

    if (!face_cascade.load("../cascade.xml")) {
            std::cerr << "Error loading face cascade classifier!" << std::endl;
            return -1;
    }

	cv::VideoCapture webcam(0);

	if (!webcam.isOpened()) {
		std::cerr << "Couldn't take input from webcam." << std::endl;
		return 1;
	}

	cv::namedWindow("Webcam", cv::WINDOW_NORMAL);

	while(true) {
		cv::Mat frame;
		webcam >> frame;

		if (frame.empty()) {
			std::cerr << "Couldn't read a frame." << std::endl;
			break;
		}

		if (cv::waitKey(1) == 'q') {
			break;
		}

        cv::Mat gray_frame;
        cv::cvtColor(frame, gray_frame, cv::COLOR_BGR2GRAY);

        std::vector<cv::Rect> faces;
        face_cascade.detectMultiScale(gray_frame, faces, 1.1, 3, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

        for (const auto& face : faces) {
            cv::Mat cropped_face = gray_frame(face);
            cv::resize(cropped_face, cropped_face, img_size);

            cropped_face = cropped_face.reshape(1, 1);
            cropped_face.convertTo(cropped_face, CV_32F);
            cropped_face = (cropped_face - mean) * eigenfaces.t();

            double min_dis = DBL_MAX;
            for (int i = 0; i < projected.rows; ++i) {
                double dist = cv::norm(cropped_face, projected.row(i), cv::NORM_L2);
                if (dist < min_dis) {
                    min_dis = dist;
                }
            }
        
            std::cout << min_dis;
            cv::rectangle(frame, face, cv::Scalar(255, 0, 0), 2);
            if (min_dis < 6000) {
                cv::putText(frame, "Ana", cv::Point(face.x, face.y + face.height + 20), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0), 2);
            } else {
                cv::putText(frame, "???", cv::Point(face.x, face.y + face.height + 20), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0), 2);
            }
        }

		cv::imshow("Webcam", frame);
	}

	cv::destroyAllWindows();
}

void make_eigenfaces(std::vector<cv::Mat>& images, cv::Mat& mean, cv::Mat& eigenfaces, cv::Mat& projected) {
    cv::Mat data;
    for (int i = 0; i < images.size(); i++) {
        cv::Mat image = images[i].reshape(1, 1);
        data.push_back(image);
    }

    data.convertTo(data, CV_32F);
    cv::PCA pca(data, cv::Mat(), cv::PCA::DATA_AS_ROW);

    mean = pca.mean.reshape(1, 1);
    eigenfaces = pca.eigenvectors;
    projected = data * eigenfaces.t();
}

void get_data(std::vector<cv::Mat>& images, const std::string& data_path) {
    for (const auto& image : fs::directory_iterator(data_path)) {
        if (image.path().extension() == ".jpg") {
            cv::Mat tmp = cv::imread(image.path().string());
            if (tmp.empty()) {
                throw std::runtime_error("Failed to read image.");
            }
            cv::cvtColor(tmp, tmp, cv::COLOR_BGR2GRAY);
            cv::resize(tmp, tmp, img_size);
            images.push_back(tmp);
        }
    }
}
