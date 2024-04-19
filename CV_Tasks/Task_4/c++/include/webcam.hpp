#ifndef  WEBCAM_H_
#define WEBCAM_H_

#include <iostream>
#include <opencv2/opencv.hpp>

class Webcam {
public:
	Webcam();
	void run();
private:
	void process_input();
	void switch_bool(bool& val);
	void print_active_effects(const cv::Mat& frame);
	void activate_effect(cv::Mat& frame);
private:
	bool is_blured;
	bool is_gray;
	bool is_horizontal;
	bool is_LAB;
	bool is_median;
	bool quit;
	bool is_rotated;
	bool is_vertical;
	bool is_HSV;
    int font;
    double font_size;
    cv::Scalar color;
    int thickness;
	cv::Mat rotate_matrix_45;
};

#endif  // WEBCAM_H_

