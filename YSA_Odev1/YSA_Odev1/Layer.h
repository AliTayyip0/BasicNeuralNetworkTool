#pragma once
#include "Neuron.h"

#define GIRDISAYISI 3


using namespace System::Collections::Generic; 
using namespace std; 



ref class Layer
{


public:

	Layer(int NoronSayisi);

	bool AyrýkEgitimPerseptron(float* girdiler, float* lbeklenendeger); // Bunun içinde girdiler sýrayla tüm noronlara gönderilecek  
																		// Noronlar aðer beklenen deðerle uyuþmuyorsa aðýrlýklarýný kendi içinde deðiþecekler
																		// Eðer Noronlardan herhangi birinde deðiþim olursa TRUE döndürecek ve main class da sistemin yeniden baþlatýlmasý gerektiði anlaþýlacak



	bool SurekliEgitimDelta(float* girdiler, float* lbeklenendeger/*, bool HATADEGERLERÝSIFIRLANSINMI*/);
	void HataDegerleriniSifirla();
	



	float** GetAgirlikDondur();


	int stepsayisi = 0;
	int agirlikdegisimsayisi = 0;

	//bool Egitim2(float* girdiler, float* lbeklenendeger);


private:
	int noronSayisi = 0;
	int girdiSayisi = 3;



	List<Neuron^>^ Noronlar = gcnew List<Neuron^>();
	
	float* beklenenDegerlerMatrisi;
	float** agirlikMatrisleri;

};

