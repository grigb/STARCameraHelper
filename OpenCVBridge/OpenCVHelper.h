﻿#pragma once
#include <opencv2\core\core.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\video.hpp>
#include <opencv2\calib3d\calib3d.hpp>

namespace OpenCVBridge 
{
	public ref class OpenCVHelper sealed
	{
	public:
		OpenCVHelper();

		// Image processing operators
		void Blur(
			Windows::Graphics::Imaging::SoftwareBitmap^ input,
			Windows::Graphics::Imaging::SoftwareBitmap^ output);
		void HoughLines(
			Windows::Graphics::Imaging::SoftwareBitmap^ input,
			Windows::Graphics::Imaging::SoftwareBitmap^ output);
		void Contours(
			Windows::Graphics::Imaging::SoftwareBitmap^ input,
			Windows::Graphics::Imaging::SoftwareBitmap^ output);
		void Histogram(
			Windows::Graphics::Imaging::SoftwareBitmap^ input,
			Windows::Graphics::Imaging::SoftwareBitmap^ output);
		void MotionDetector(
			Windows::Graphics::Imaging::SoftwareBitmap^ input,
			Windows::Graphics::Imaging::SoftwareBitmap^ output);

		void DrawChessboard(
			Windows::Graphics::Imaging::SoftwareBitmap^ input,
			Windows::Graphics::Imaging::SoftwareBitmap^ output,
			int chessX,
			int chessY,
			float chessSquareSizeMeters,
			bool saveDetectedCorners);

		void ClearDetectedCorners();

		int GetNumDetectedCorners();
	private:
		std::vector<std::vector<cv::Point2f>> detectedCorners;
		int chessX;
		int chessY;
		float chessSquareSizeMeters;

		// used only for the background subtraction operation
		cv::Mat fgMaskMOG2;
		cv::Ptr<cv::BackgroundSubtractor> pMOG2;

		// helper functions for getting a cv::Mat from SoftwareBitmap
		bool GetPointerToPixelData(Windows::Graphics::Imaging::SoftwareBitmap^ bitmap,
			unsigned char** pPixelData, unsigned int* capacity);

		bool TryConvert(Windows::Graphics::Imaging::SoftwareBitmap^ from, cv::Mat& convertedMat);

		void UpdateChessParameters(int newChessX, int newChessY, float newChessSquareSizeMeters);
	};
}