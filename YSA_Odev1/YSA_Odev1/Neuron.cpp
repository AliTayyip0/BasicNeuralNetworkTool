#include "Neuron.h"
#include <math.h>







Neuron::Neuron()
{
	agirlik = new float[GIRDISAYISI];
	agirlik[0] = 0.5f;
	agirlik[1] = 0.5f;
	agirlik[2] = 0.5f;
	HATADEGERI = 0;
	//agirlik[GIRDISAYISI] = new float();
	/*agirlik[0] = 1.0f;
	agirlik[1] = 0.0f;
	agirlik[2] = -1.0f;*/
	// oto aðýrlýk atamasý yapýlacak
}


Neuron::Neuron(float agirlik1, float agirlik2, float agirlik3)
{
	agirlik = new float[GIRDISAYISI];
	agirlik[0] = agirlik1;
	agirlik[1] = agirlik2;
	agirlik[2] = agirlik3;
	HATADEGERI = 0;
}



float girdi[GIRDISAYISI]; // Girdi matrisinin oluþturulmasý

//float agirlik[GIRDISAYISI] = {0.5f,0.4f,0.9f};  // Aðýrlýk matrisinin oluþturulmasý ve ilk aðýrlýk atamasý

float beklenendeger = 0; // iþlem yapýlan örnek için beklenen deger

float ogrenmekatsayisi = 1.0f; // Nöronun öðrenme katsayýsý




void Neuron::SetHataDegeri(float deger)
{
	HATADEGERI = deger;
}



#pragma region Perseptron






bool Neuron::Perseptronegitim(float* girdiler,float lbeklenendeger)
{
	for (int i = 0; i < GIRDISAYISI; i++)
	{
		girdi[i] = girdiler[i];
	}
	beklenendeger = lbeklenendeger;

	float cikandeger = Toplam(girdi, this->agirlik);
	

	if (beklenendeger == SignFonk(cikandeger)) 
	{
		return true;
	}
	else
	{
		float gonderilecek = ogrenmekatsayisi*(beklenendeger - SignFonk(cikandeger));
		PerseptronAgirliklariyenidenata(gonderilecek);
		return false;// aðýrlýklar deðiþtiyse yani sistem hatalýysa false döndürüo
	}
}


void Neuron::PerseptronAgirliklariyenidenata(float gelen)
{

	for (int i = 0; i < GIRDISAYISI; i++)
	{
		this->agirlik[i] = this->agirlik[i] + (gelen*girdi[i]);
	}
}




#pragma endregion










#pragma region Delta








void Neuron::DeltaAgirliklariyenidenata(float gelen)
{
	/*float dene1 = agirlik[0];
	float dene2 = agirlik[1];
	float dene3 = agirlik[2];*/
	for (int i = 0; i < GIRDISAYISI; i++)
	{
	
		agirlik[i] = agirlik[i] + (gelen*girdi[i]);
		
	}
	/*float dene4 = agirlik[0];
	float dene5 = agirlik[1];
	float dene6 = agirlik[2];*/
}






bool Neuron::DeltaEgitim(float girdiler[], float lbeklenendeger)
{
	ogrenmekatsayisi = 0.6f;
	bool donecek = false;
	beklenendeger = lbeklenendeger;
	for (int i = 0; i < GIRDISAYISI; i++)
	{
		girdi[i] = girdiler[i];
	}

	float cikandeger = Toplam(girdi, agirlik);


	float fnet = TanjanthFonksiyonu(cikandeger);
	float fnetturevi = TanjanthFonksiyonuTersi(cikandeger);
	
	float gonderilecek = ogrenmekatsayisi * ((beklenendeger - fnet) * fnetturevi);
	DeltaAgirliklariyenidenata(gonderilecek);
	

	HATADEGERI += pow((lbeklenendeger - fnet), 2)/2;
	float test = TanjanthFonksiyonu(cikandeger);
	if (HATADEGERI > Epsilon)
		donecek = false;
	else
		donecek = true;

	//oncedencikan = TanjanthFonksiyonu(cikandeger);
	return donecek;

}







#pragma endregion









#pragma region ORTAK





float Neuron::Toplam(float girdiler[], float agirliklar[])
{
	float toplam = 0;
	for (int i = 0; i < GIRDISAYISI; i++)
	{
		toplam += girdiler[i] * agirliklar[i];
	}
	return toplam;
}



float* Neuron::GetAgirlikDondur()
{
	return this->agirlik;
}







#pragma endregion







#pragma region Akitivasyon Fonksiyonlarý

int Neuron::SignFonk(int deger)
{
	if (deger < 0) return -1;
	else return 1;
}

int Relu(int deger)
{
	if (deger < 0) return 0;
	else return deger;
}

float Neuron::TanjanthFonksiyonu(float deger)
{
	float girecek = deger * -1;

	float sayi = expf(girecek);
	sayi = sayi + 1;
	sayi = 2 / sayi;
	sayi = sayi - 1;
	return sayi;
}

float Neuron::TanjanthFonksiyonuTersi(float deger)
{
	/*deger = deger ;*/
	deger = (1 - powf(TanjanthFonksiyonu(deger), 2));
	deger = deger / 2;
	return deger;
}

#pragma endregion


