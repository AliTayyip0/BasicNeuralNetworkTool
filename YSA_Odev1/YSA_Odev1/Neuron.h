#pragma once


#define GIRDISAYISI 3


ref class Neuron
{


public:
	Neuron();
	Neuron(float agirlik1, float agirlik2, float agirlik3);

	bool Perseptronegitim(float* girdiler, float lbeklenendeger); // perseptron
	
	bool DeltaEgitim(float girdiler[], float lbeklenendeger); // perseptron
	
	float* GetAgirlikDondur(); // global

	float* agirlik;
	void Neuron::SetHataDegeri(float deger);

	
	float Epsilon = 0.1f; // Delta


private:
	void PerseptronAgirliklariyenidenata(float gelen); //Perseptron
	void DeltaAgirliklariyenidenata(float gelen); // Delta
	float HATADEGERI; // Delta


	float Toplam(float girdiler[], float agirliklar[]); // Global












	// Aktivasyon fonksiyonlarý

	int SignFonk(int deger);
	float TanjanthFonksiyonu(float deger);
	float TanjanthFonksiyonuTersi(float deger);
};

