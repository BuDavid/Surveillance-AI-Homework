#include <opencv2/opencv.hpp>

int main() {
	cv::Mat image = cv::imread("../../resources/test.png");

	if (image.empty()) {
		std::cerr << "Couldn't open the image" << std::endl;
		return 1;
	}

	std::string text = "Cam 1";
    cv::Point point(10, 30);
    int font = cv::FONT_HERSHEY_COMPLEX_SMALL;
    double font_size = 2.0;
    cv::Scalar color(33, 55, 183);
    int thickness = 2;
	cv::putText(image, text, point, font, font_size, color, thickness);

    cv::Point top_left_point(50, 100);
    cv::Point bottom_right_point(200, 300);
	cv::rectangle(image, top_left_point, bottom_right_point, color, thickness);

    cv::Point center(200, 200);
	int radius = 222;
	cv::circle(image, center, radius, color, thickness);

	cv::imshow("Image", image);
	cv::waitKey(0);
	cv::destroyAllWindows();
}

