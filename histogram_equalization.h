#pragma once

using namespace cv;

// Calculate the histogram
int* get_hist(Mat& mat)
{
	int* hist = new int[256]{};
	for (int i = 0; i < mat.rows; ++i)
	{
		for (int j = 0; j < mat.cols; ++j)
		{
			hist[(int)mat.at<uchar>(i, j)]++;
		}
	}
	return hist;
}

Mat histogram_equalization(Mat mat)
{
	//calculate pdf function 
	int* hist = get_hist(mat);
	double* pdf = new double[256]{};
	for (int i = 0; i < 256; ++i) pdf[i] = (double)hist[i] / (mat.rows * mat.cols);

	//calculate cdf function
	double* cdf = new double[256]{};
	for (int i = 0; i < 256; ++i)
	{
		if (i == 0) cdf[i] = pdf[i];
		else cdf[i] = cdf[i - 1] + pdf[i];
	}

	//calculate map function
	int* map = new int[256]{};
	for (int i = 0; i < 256; ++i) map[i] = (uchar)(cdf[i] * 255);

	//change the gray level in each pixel
	for (int i = 0; i < mat.rows; ++i)
	{
		for (int j = 0; j < mat.cols; ++j)
		{
			mat.at<uchar>(i, j) = map[(int)mat.at<uchar>(i, j)];
		}
	}
	return mat;
}