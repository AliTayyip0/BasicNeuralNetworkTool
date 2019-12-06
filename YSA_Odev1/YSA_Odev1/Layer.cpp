#include "Layer.h"
#include <memory.h>

using namespace std;




#define GIRDISAYISI 3



float ornekGirdi[GIRDISAYISI];







Layer::Layer(int NoronSayisi)
{
	noronSayisi = NoronSayisi;


	
#pragma region NORONLARIN OLU�TURULMASI


	beklenenDegerlerMatrisi = new float[NoronSayisi];
	for (int i = 0; i < NoronSayisi; i++)
	{
		Noronlar->Add(gcnew Neuron((0.1f)*(i+1),0.4f,0.5f)); //TODO: bura randomla�a bilir
	}

#pragma endregion


#pragma region A�IRLIK MATR�S�N�N D�NAM�K ATAMASI VE DE�ERLER�N�N ALINMASI

	agirlikMatrisleri = new float*[NoronSayisi];   // A�IRLIK MATR�S�N�N D�NAM�K ATAMASI

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




bool Layer::Ayr�kEgitimPerseptron(float* girdiler, float* lbeklenendeger)
{
	bool DegisenAgirlikVarMi = false;

	for (int i = 0; i < noronSayisi; i++)
	{
		stepsayisi++;
		if (Noronlar[i]->Perseptronegitim(girdiler,lbeklenendeger[i]))
		{
			//A��rl�klar de�i�tirilmemi�tir
		}
		else
		{
			DegisenAgirlikVarMi = true;
			
			//A��rl�klar de�i�mi�tir
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
			//A��rl�klar de�i�tirilmemi�tir
		}
		else
		{
			DegisenAgirlikVarMi = true;
			//A��rl�klar de�i�mi�tir
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