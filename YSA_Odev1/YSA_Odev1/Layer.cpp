#include "Layer.h"
#include <memory.h>

using namespace std;




#define GIRDISAYISI 3



float ornekGirdi[GIRDISAYISI];







Layer::Layer(int NoronSayisi)
{
	noronSayisi = NoronSayisi;


	
#pragma region NORONLARIN OLUÞTURULMASI


	beklenenDegerlerMatrisi = new float[NoronSayisi];
	for (int i = 0; i < NoronSayisi; i++)
	{
		Noronlar->Add(gcnew Neuron((0.1f)*(i+1),0.4f,0.5f)); //TODO: bura randomlaþa bilir
	}

#pragma endregion


#pragma region AÐIRLIK MATRÝSÝNÝN DÝNAMÝK ATAMASI VE DEÐERLERÝNÝN ALINMASI

	agirlikMatrisleri = new float*[NoronSayisi];   // AÐIRLIK MATRÝSÝNÝN DÝNAMÝK ATAMASI

	for (int i = 0; i < NoronSayisi; i++)
	{
		agirlikMatrisleri[i] = new float[3];
		memset(agirlikMatrisleri[i], false, GIRDISAYISI * sizeof(float));


		agirlikMatrisleri[i] = Noronlar[i]->GetAgirlikDondur();

		//for (int j = 0; j < GIRDISAYISI; j++)
		//{
		//	agirlikMatrisleri[i][j] = Noronlar[i]->GetAgirlikDondur()[j];
		//}
	}


#pragma endregion


	
}




bool Layer::AyrýkEgitimPerseptron(float* girdiler, float* lbeklenendeger)
{
	bool DegisenAgirlikVarMi = false;

	for (int i = 0; i < noronSayisi; i++)
	{
		stepsayisi++;
		if (Noronlar[i]->Perseptronegitim(girdiler,lbeklenendeger[i]))
		{
			//Aðýrlýklar deðiþtirilmemiþtir
		}
		else
		{
			DegisenAgirlikVarMi = true;
			
			//Aðýrlýklar deðiþmiþtir
			agirlikdegisimsayisi++;
		}
	}

	return DegisenAgirlikVarMi;

}




bool Layer::SurekliEgitimDelta(float* girdiler, float* lbeklenendeger)
{


	bool DegisenAgirlikVarMi = false;

	for (int i = 0; i < noronSayisi; i++)
	{
		stepsayisi++;
		if (Noronlar[i]->DeltaEgitim(girdiler, lbeklenendeger[i]))
		{
			//Aðýrlýklar deðiþtirilmemiþtir
		}
		else
		{
			DegisenAgirlikVarMi = true;
			//Aðýrlýklar deðiþmiþtir
			agirlikdegisimsayisi++;
		}
	}

	return DegisenAgirlikVarMi;
}







void Layer::HataDegerleriniSifirla()
{
	for (int i = 0; i < noronSayisi; i++)
	{
		Noronlar[i]->SetHataDegeri(0.0f);
	}
}



float** Layer::GetAgirlikDondur()
{
	return agirlikMatrisleri;
}