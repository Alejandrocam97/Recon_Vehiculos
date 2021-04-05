#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void poligon(vector<vector<Point>> forma);


int main()
{
	Mat im, gray, gauss, bin, erosion, dilatacion;
	Mat prueba[22];
	vector<vector<Point>> Contours;

	//im = imread("D:/Alejandro/TFG Vulkan/OpenCV_formas/shapes.jpg");
	im = imread("D:/Alejandro/TFG Vulkan/coche2.jpeg");
	if (im.empty())
	{
		cout << "Cannot load image!" << endl;
		return -1;
	}


	imshow("original", im);
	cvtColor(im, gray, COLOR_BGR2GRAY);
	GaussianBlur(gray, gauss, Size(5, 5), 0, 0);
	//erode(gauss, erosion, Mat(), Point(-1, -1), 3);
	//dilate(erosion, dilatacion, Mat(), Point(-1, -1), 1);

	//imshow("gauss", gauss);
	//imshow("erosion", dilatacion);
	//waitKey(0);
	/*for (int i = 0; i < 22; i++)
	{
		threshold(gauss, prueba[i], (20+i*10), 255, THRESH_BINARY);
		imshow("prueba", prueba[i]);
		waitKey(0);

	}*/
	//threshold(gauss, bin, 120, 255, THRESH_BINARY);
	threshold(gauss, bin, 115, 255, THRESH_BINARY);


	findContours(bin, Contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	Mat drawing = Mat::zeros(im.size(), CV_8UC3);
	drawContours(drawing, Contours, -1, Scalar(255, 0, 0), 2);


	imshow("Contornos", drawing);
	waitKey(0);

}