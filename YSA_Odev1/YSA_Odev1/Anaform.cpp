#include "Anaform.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace YSAOdev1;

[STAThread]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	YSAOdev1::Anaform form;
	Application::Run(% form);
}





void Anaform::pictureBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	if (asd == nullptr)
		asd = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);

	int NoktaX = e->Location.X;
	int NoktaY = e->Location.Y;


	Color renk;
	if (islem_number == 1)
	{
		renk = Color::Black;
	}
	else if (islem_number == 2)
	{
		renk = Color::Red;
	}
	else if (islem_number == 3)
	{
		renk = Color::Green;
	}
	else
	{
		renk = Color::Blue;
	}



	ArtiCiz(NoktaX,NoktaY,renk);

	/*for (int i = 0; i < asd->Height; i++)
	{
		for (int j = 0; j < asd->Width; j++)
		{
			asd->SetPixel(j,i , System::Drawing::Color::Black);
		}
	}*/

	pictureBox1->Image = asd;

	/*CizgiCiz(1 ,100);*/

	ArrayList^ ar = gcnew ArrayList();
	
}


void Anaform::Anaform_Load(System::Object^  sender, System::EventArgs^  e)
{
	if (asd == nullptr)
		asd = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
	if(grfx==nullptr)
		grfx = pictureBox1->CreateGraphics()->FromImage(asd);


	Color renk = Color::Gray;
	for (int i = 0; i < pictureBox1->Height; i++)
	{
		asd->SetPixel(pictureBox1->Width/2,i,renk);
	}
	for (int i = 0; i < pictureBox1->Width; i++)
	{
		asd->SetPixel(i, pictureBox1->Height/2, renk);
	}

	pictureBox1->Image = asd;
}

void Anaform::pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	Point gecici = NormalKordinattanÝstenilenKordinataCevirme(e->Location.X,e->Location.Y);
	lblKonum->Text = gecici.ToString();
}




#pragma region Kordinat Sistemi Ayarlarý






Point Anaform::NormalKordinattanÝstenilenKordinataCevirme(int x, int y)
{
	Point donecek = MousePosition;

	donecek.X = x;
	donecek.Y = y;
	donecek.X = donecek.X - pictureBox1->Width / 2;
	donecek.Y = pictureBox1->Height / 2 - donecek.Y;
	return donecek;
}

Point Anaform::IstenilenKordinattanNormaleCevirme(int x,int y)
{
	Point donecek = MousePosition;
	donecek.X = x;
	donecek.Y = y;


	donecek.X = donecek.X + pictureBox1->Width / 2;
	donecek.Y = pictureBox1->Height / 2 + donecek.Y;



	return donecek;
}





#pragma endregion


#pragma region Çizim Ýþlemleri





void Anaform::ArtiCiz(int NoktaX, int NoktaY, Color renk)
{



	//if (renk == nullptr) return;

	//TODO: en sondaki piksellere basýnca patlýo kod


	asd->SetPixel(NoktaX, NoktaY, renk);

	for (int i = 1; i < arti_boyutu + 1; i++)
	{
		asd->SetPixel(NoktaX - i, NoktaY, renk);
		asd->SetPixel(NoktaX + i, NoktaY, renk);
		asd->SetPixel(NoktaX, NoktaY - i, renk);
		asd->SetPixel(NoktaX, NoktaY + i, renk);
	}



}

void Anaform::CizgiCiz(int a, int b)
{
	if (a == 0)return;

	Pen^ myPen = gcnew Pen(Color::Black, 2);

	grfx->DrawLine(myPen, IstenilenKordinattanNormaleCevirme(XiBul(280, a, b), 280), IstenilenKordinattanNormaleCevirme(XiBul(-280, a, b), -280));

}
int Anaform::XiBul(int y, int a, int b)
{
	//if (a == 0)return 1;
	return ((y - b) / a);
}




#pragma endregion

