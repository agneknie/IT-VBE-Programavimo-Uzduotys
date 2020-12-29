#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const char D[]="D.txt";
const char R[]="R.txt";

//Struktura aviu duomenims saugoti
struct Avis{
    string vardas;
    char kodas[21];
    int koef=0;
};

//Funkcija skaitanti duomenis   (Struktura su * - Kai masyvas; Struktura su & - Kai vienas elementas.)
void Duomenys (int& nD, int& mD, int& nrD, Avis *XD){
    ifstream fd(D);
    fd >> nD >> mD >> nrD;
    for(int x=0; x<nD; x++){
        fd >> XD[x].vardas;
        for(int y=0; y<mD; y++){
            fd >> XD[x].kodas[y];
        }
    }
    fd.close();}

//Funkcija rezultatams irasyti
void Rezultatai (int nR, Avis* XR, Avis& TR){
    ofstream fr(R);
    fr << setw(10) << left << TR.vardas << endl;
    for(int x=0; x<nR; x++){
        if(XR[x].vardas!=TR.vardas){
            fr << setw(10) << left << XR[x].vardas << " " << XR[x].koef << endl;
        }
    }
    fr.close();
}

//Funkcija, rikiuojanti avis pagal koeficienta
void Rikiavimas (int nRi, Avis* XRi){
    for(int x=0; x<nRi; x++){
        for(int y=0; y<nRi-1; y++){
            if(XRi[y].koef<XRi[y+1].koef) swap(XRi[y], XRi[y+1]);
        }
    }
}

//Funkcija, randanti vienos avies sutapimo koeficienta su tiriamaja avimi
int SutapimoKoeficientas (int xSK, int nSK, int mSK, int nrSK, Avis* XSK){
    int SK=0;
    for(int y=0; y<mSK; y++){
        if(XSK[nrSK].kodas[y]==XSK[xSK].kodas[y]) SK++;
    }
    return SK;
}

// Pagrindine funkcija
int main(){

    int n=20, m=20, nr;         //Aviu skaicus, DNR fragmento ilgis, tiriamosios avies numeris
    Avis X[n];                  //Aviu duomenys
    Avis T;                     //Tiriamosios avies duomenys

    // Duomenu nuskaitymas
    Duomenys (n, m, nr, X);
    nr=nr-1;                    //Atimti viena, nes masyvas nuo 0
    T=X[nr];                    //Tiriamosios avies duomenys issaugomi atskirai, kad veliau liktu su kuo lyginti

    // Surandamas kiekvienos avies sutapimo koeficientas
    for(int x=0; x<n; x++){
        X[x].koef=SutapimoKoeficientas(x, n, m, nr, X);
    }

    //Ciklas, rikiuojantis avis pagal varda, jei koeficientas sutampa
    for(int x=0; x<n; x++){
        for(int y=0; y<n; y++){
        if(X[y].koef==X[y+1].koef&&X[y].vardas>X[y+1].vardas) swap(X[y], X[y+1]);}}

    // Irasomi rezultatai i faila
    Rezultatai(n, X, T);

    return 0;
}
