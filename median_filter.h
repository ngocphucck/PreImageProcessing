#pragma once

using namespace cv;

//find the medium of the array
int find_medium(int* array)
{
	//sort the array
	for (int i = 0; i < 9; ++i)
	{
		for (int j = i + 1; j < 9; ++j)
		{
			if (array[i] < array[j])
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	return array[4];
}

//get the 2D array contain cell (x + 1, y + 1) and its neiborhoods for each cell in mat
void get_array(Mat mat, int x, int y, int* array)
{
	int position = 0;
	for (int i = x; i < x + 3; ++i)
	{
		for (int j = y; j < y + 3; ++j)
		{
			array[position] = mat.at<uchar>(i, j);
			position++;
		}
	}
}

//median filter
Mat median_filter(Mat& mat)
{
	int array[9];

	//make new matrix to store new image
	Mat nmat(mat.rows, mat.cols, CV_8UC1);

	//traversal all the cells in matrix and change the gray value
	for (int i = 0; i < mat.rows - 2; ++i)
	{
		for (int j = 0; j < mat.cols - 2; ++j)
		{
			get_array(mat, i, j, array);
			nmat.at<uchar>(i + 1, j + 1) = (uchar)find_medium(array);
		}
	}
	return nmat;
}