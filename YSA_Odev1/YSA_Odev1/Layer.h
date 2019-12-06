#pragma once
#include "Neuron.h"

#define GIRDISAYISI 3


using namespace System::Collections::Generic; 
using namespace std; 



ref class Layer
{


public:

	Layer(int NoronSayisi);

	bool Ayr�kEgitimPerseptron(float* girdiler, float* lbeklenendeger); // Bunun i�inde girdiler s�rayla t�m noronlara g�nderilecek  
																		// Noronlar a�er beklenen de�erle uyu�muyorsa a��rl�klar�n� kendi i�inde de�i�ecekler
																		// E�er Noronlardan herhangi birinde de�i�im olursa TRUE d�nd�recek ve main class da sistemin yeniden ba�lat�lmas� gerekti�i anla��lacak



	bool SurekliEgitimDelta(float* girdiler, float* lbeklenendeger/*, bool HATADEGERLER�SIFIRLANSINMI*/);
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

