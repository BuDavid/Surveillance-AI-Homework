#include <opencv2/opencv.hpp>

int main() {
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
            cv::rectangle(frame, face, cv::Scalar(255, 0, 0), 2);
        }

		cv::imshow("Webcam", frame);
	}

	cv::destroyAllWindows();
}

