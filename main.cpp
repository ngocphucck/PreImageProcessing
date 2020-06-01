#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "ioimage.h"
#include "median_filter.h"
#include "histogram_equalization.h"

using namespace cv;

int main()
{
	//Write the source image to text file
	Mat mat = imread("D:/Pictures/pgm_processing/7.pgm", IMREAD_GRAYSCALE);
	write(mat, "D:/Documents/image_text1.txt");
	mat = imread("D:/Pictures/pgm_processing/noise.jpg", IMREAD_GRAYSCALE);
	write(mat, "D:/Documents/image_text2.txt");
	
	//Read the source text file
	Mat nmat1 = read("D:/Documents/image_text1.txt");
	namedWindow("Source image", WINDOW_NORMAL);
	imshow("Source image", nmat1);

	//Apply the histogram equalization to the source matrix and display, write the histogram image
	// to text file
	Mat hmat = histogram_equalization(nmat1);
	namedWindow("Hist_image", WINDOW_NORMAL);
	imshow("Hist_image", hmat);
	write(hmat, "D:/Documents/hist_image_text.txt");
	imwrite("D:/Pictures/pgm_processing/hist.pgm", hmat);
	waitKey(0);
	destroyWindow("Hist_image");

	//Read the second source text file
	Mat nmat2 = read("D:/Documents/image_text2.txt");
	imshow("Source image", nmat2);

	//Apply the median filter to the source matrix and display, write the median image
	// to text file
	Mat mmat = median_filter(nmat2);
	namedWindow("Median_image", WINDOW_NORMAL);
	imshow("Median_image", mmat);
	write(mmat, "D:/Documents/median_image.txt");
	imwrite("D:/Pictures/pgm_processing/median.jpg", mmat);
	waitKey(0);
}
