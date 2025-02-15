#include "Utils.h"



Utils::Utils()
{
}

void Utils::Mat2PictureBox(cv::Mat frame, System::Windows::Forms::PictureBox^ pictureBox)
{
	System::Drawing::Bitmap^ bitmapImg = gcnew System::Drawing::Bitmap
	(frame.cols, frame.rows, frame.step,
		System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) frame.data);

	System::Drawing::Bitmap^ resultImg = gcnew System::Drawing::Bitmap
	(pictureBox->Width, pictureBox->Height);

	System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(resultImg);
	g->DrawImage(bitmapImg, 0, 0, pictureBox->Width, pictureBox->Height);

	pictureBox->Image = resultImg;

	pictureBox->Refresh();
}

String^ Utils::PictureBoxToBase64(System::Windows::Forms::PictureBox^ pictureBox)
{
	String^ base64String;
	MemoryStream^ memStream = gcnew MemoryStream();
	try
	{
		pictureBox->Image->Save(memStream, Drawing::Imaging::ImageFormat::Jpeg);
		array<Byte> ^imageBytes = memStream->ToArray();
		
		base64String = Convert::ToBase64String(imageBytes);
	}
	finally
	{
		memStream->Close();
	}

	return base64String;
}
