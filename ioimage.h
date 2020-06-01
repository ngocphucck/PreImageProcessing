#pragma once

using namespace cv;

// Convert the text file to matrix
Mat read(std::string path)
{
	std::ifstream file;
	Mat mat;
	int row = 0;
	int column = 0;

	file.open(path, std::ios::in);
	std::string string;

	//Get the number from text file and put to matrix
	while (std::getline(file, string))
	{
		int num = 0;
		row++;
		for (int i = 0; i < string.length(); ++i)
		{
			if (string[i] == ' ' || i == string.length() - 1)
			{
				mat.push_back((uchar)num);
				num = 0;
				if (row == 1) column++;
			}
			else num = num * 10 + (string[i] - 48);
		}
	}
	file.close();

	//Change the shape
	mat = mat.reshape(1, row);
	return mat;
}

//Convert the matrix to text file
void write(Mat& mat, std::string path)
{
	std::ofstream ofile;
	ofile.open(path, std::ios::out);
	for (int i = 0; i < mat.rows; ++i)
	{
		for (int j = 0; j < mat.cols; ++j)
		{
			ofile << (int)mat.at<uchar>(i, j);
			if (j == mat.cols - 1) ofile << '\n';
			else ofile << ' ';
		}
	}
	ofile.close();
}