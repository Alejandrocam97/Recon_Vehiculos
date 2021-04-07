#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/photo/cuda.hpp>
#include <iostream>

using namespace cv;
using namespace std;
using namespace cuda;

void poligon(vector<vector<Point>> forma);


int main()
{
	Mat im, gray, gauss, bin, erosion, dilatacion, noise;
	
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
	GaussianBlur(gray, gauss, Size(9, 9), 0, 0);
	//fastNlMeansDenoisingColored(im, noise, float(20), float(10));

	//imshow("gaus", noise);
	//waitKey(0);
	//erode(gauss, erosion, getStructuringElement(MORPH_RECT, Size(5, 5)), Point(-1, -1), 3);

	//dilate(erosion, dilatacion, Mat(), Point(-1, -1), 1);

	//imshow("gauss", gauss);
	//imshow("erosion", erosion);
	//waitKey(0);
	for (int i = 0; i < 22; i++)
	{
		int val = 20 + i * 10;
		threshold(erosion, prueba[i], val , 255, THRESH_BINARY);
		//imshow("prueba", prueba[i]);
  		//waitKey(0);
		findContours(prueba[i], Contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

		Mat drawing = Mat::zeros(im.size(), CV_8UC3);
		drawContours(drawing, Contours, -1, Scalar(255, 0, 0), 2);


		imshow("Contornos", drawing);
		waitKey(0);

	}
	//threshold(gauss, bin, 120, 255, THRESH_BINARY);
	//threshold(erosion, bin, 115, 255, THRESH_BINARY);


	findContours(bin, Contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	Mat drawing = Mat::zeros(im.size(), CV_8UC3);
	drawContours(drawing, Contours, -1, Scalar(255, 0, 0), 2);


	imshow("Contornos", drawing);
	waitKey(0);

}