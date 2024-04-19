#include "webcam.hpp"

Webcam::Webcam() {
	is_blured = 0;
	is_gray = 0;
	is_horizontal = 0;
	is_LAB = 0;
	is_median = 0;
	quit = 0;
	is_rotated = 0;
	is_vertical = 0;
	is_HSV = 0;
    font = cv::FONT_HERSHEY_COMPLEX_SMALL;
    font_size = 1.0;
    color = (0, 0, 0);
    thickness = 1;
}

void Webcam::run() {
	cv::VideoCapture webcam(0);

	if (!webcam.isOpened()) {
		std::cerr << "Couldn't take input from webcam." << std::endl;
		return;
	}

	cv::namedWindow("Webcam", cv::WINDOW_NORMAL);

	cv::Mat frame_tmp;
	webcam >> frame_tmp;
	cv::Point2f center(frame_tmp.cols / 2, frame_tmp.rows / 2);
	rotate_matrix_45 = cv::getRotationMatrix2D(center, 45.0, 1.0);

	while(true) {
		cv::Mat frame;
		webcam >> frame;

		if (frame.empty()) {
			std::cerr << "Couldn't read a frame." << std::endl;
			break;
		}

		process_input();
		
		if (quit) {
			break;
		}

		activate_effect(frame);
		print_active_effects(frame);

		cv::imshow("Webcam", frame);
	}

	webcam.release();
	cv::destroyAllWindows;
}

void Webcam::process_input() {
	switch(cv::waitKey(1)) {
		case 'b':
			switch_bool(is_blured);
			break;
		case 'g':
			switch_bool(is_gray);
			break;
		case 'h':
			switch_bool(is_horizontal);
			break;
		case 'l':
			switch_bool(is_LAB);
			break;
		case 'm':
			switch_bool(is_median);
			break;
		case 'q':
			switch_bool(quit);
			break;
		case 'r':
			switch_bool(is_rotated);
			break;
		case 'v':
			switch_bool(is_vertical);
			break;
		case 'x':
			switch_bool(is_HSV);
			break;
	}
}

void Webcam::activate_effect(cv::Mat& frame) {
	if (is_horizontal) {
		cv::flip(frame, frame, 1);
	}
	if (is_vertical) {
		cv::flip(frame, frame, 0);
	}
	if (is_blured) {
		cv::GaussianBlur(frame, frame, cv::Size(7, 7), 0);
	}
	if (is_gray) {
		if (is_LAB || is_HSV) {
			is_gray = 0;
		} else {
			cv::cvtColor(frame, frame, cv::COLOR_RGB2GRAY);
		}
	}
	if (is_LAB) {
		cv::cvtColor(frame, frame, cv::COLOR_RGB2Lab);
	}
	if (is_median) {
		cv::medianBlur(frame, frame, 3);
	}
	if (is_rotated) {
		cv::warpAffine(frame, frame, rotate_matrix_45, frame.size());
	}
	if (is_HSV) {
		cv::cvtColor(frame, frame, cv::COLOR_RGB2HSV);
	}
}

void Webcam::print_active_effects(const cv::Mat& frame) {
	if (is_horizontal) {
		cv::Point point(10, 50);
		cv::putText(frame, "horiz", point, font, font_size, color, thickness);
	}
	if (is_vertical) {
		cv::Point point(10, 90);
		cv::putText(frame, "vertical", point, font, font_size, color, thickness);
	}
	if (is_blured) {
		cv::Point point(10, 30);
		cv::putText(frame, "blured", point, font, font_size, color, thickness);
	}
	if (is_gray) {
			cv::Point point(10, 40);
			cv::putText(frame, "gray", point, font, font_size, color, thickness);
	}
	if (is_LAB) {
		cv::Point point(10, 60);
		cv::putText(frame, "LAB", point, font, font_size, color, thickness);
	}
	if (is_median) {
		cv::Point point(10, 70);
		cv::putText(frame, "median", point, font, font_size, color, thickness);
	}
	if (is_rotated) {
		cv::Point point(10, 80);
		cv::putText(frame, "rotated", point, font, font_size, color, thickness);
	}
	if (is_HSV) {
		cv::Point point(10, 90);
		cv::putText(frame, "HSV", point, font, font_size, color, thickness);
	}
}

void Webcam::switch_bool(bool& val) {
	val = val ? 0 : 1;
}

