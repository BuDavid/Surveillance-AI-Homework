#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
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

		cv::imshow("Webcam", frame);

		if (cv::waitKey(1) == 'q') {
			break;
		}
	}

	webcam.release();
	cv::destroyAllWindows;
}




