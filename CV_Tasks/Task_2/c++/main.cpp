#include <opencv2/opencv.hpp>

int main() {
	cv::Mat image = cv::imread("../../resources/test.png");

	if (image.empty()) {
		std::cerr << "Couldn't open the image" << std::endl;
		return 1;
	}

// OG
	cv::imshow("original photo", image);
	cv::waitKey(0);

// RGB
	cv::Mat rgb_img;
	cv::cvtColor(image, rgb_img, cv::COLOR_BGR2RGB);

	cv::imshow("RGB photo", rgb_img);
	cv::imwrite("rgb.png", rgb_img);
	cv::waitKey(0);

// HSV
	cv::Mat hsv_img;
	cv::cvtColor(image, hsv_img, cv::COLOR_RGB2HSV);

	cv::imshow("HSV photo", hsv_img);
	cv::imwrite("hsv.png", hsv_img);
	cv::waitKey(0);

// LAB
	cv::Mat lab_img;
	cv::cvtColor(image, lab_img, cv::COLOR_RGB2Lab);

	cv::imshow("LAB photo", lab_img);
	cv::imwrite("lab.png", lab_img);
	cv::waitKey(0);

// grayscale
	cv::Mat gray_img;
	cv::cvtColor(image, gray_img, cv::COLOR_RGB2GRAY);

	cv::imshow("GRAY photo", gray_img);
	cv::imwrite("gray.png", gray_img);
	cv::waitKey(0);

// blur
	cv::Mat blur_img;
	cv::GaussianBlur(image, blur_img, cv::Size(7, 7), 0);
	
	cv::imshow("Blured photo", blur_img);
	cv::imwrite("blur.png", blur_img);
	cv::waitKey(0);

// sharp
	cv::Mat sharp_img;

	cv::Laplacian(blur_img, sharp_img, CV_16S);
	cv::convertScaleAbs(sharp_img, sharp_img);
	sharp_img = sharp_img + blur_img;

	cv::imshow("Sharp photo", sharp_img);
	cv::imwrite("sharp.png", sharp_img);
	cv::waitKey(0);

// median
	image = cv::imread("../../resources/noisy.png");
	cv::imshow("Noisy image", image);
	cv::waitKey(0);

	cv::Mat median_img;
	cv::medianBlur(image, median_img, 3);

	cv::imshow("Median photo", median_img);
	cv::imwrite("median.png", median_img);
	cv::waitKey(0);

	cv::destroyAllWindows();
}
