#include <opencv2/opencv.hpp>

int main() {
	cv::Mat image = cv::imread("../../resources/test.png");

	if (image.empty()) {
		std::cerr << "Couldn't open the image" << std::endl;
		return 1;
	}

	cv::resize(image, image, cv::Size(1000, 1000));

	cv::flip(image, image, -1);

	cv::Rect crop(0, 0, 900, 900);
	image = image(crop);

	cv::Point2f center(image.cols / 2, image.rows / 2);
	cv::Mat rotate_matrix_45 = cv::getRotationMatrix2D(center, 45.0, 1.0);
	cv::warpAffine(image, image, rotate_matrix_45, image.size());

	cv::imshow("changed photo", image);
	cv::imwrite("new.png", image);

	cv::waitKey(0);
	cv::destroyAllWindows();
}
