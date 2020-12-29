#include <iostream>
#include <fstream>

using namespace std;

const char R[]="U1rez.txt";
const char D[]="U1.txt";

// Struktura duomenims apie pirstines saugoti
struct Pirstine{
int lytis, ranka, dydis;
bool pora;
};

// Funkcija duomenims skaityti
void Duomenys (int &nD, Pirstine *PD){
    ifstream fd(D);
    fd >> nD;
    for(int x=0; x<nD; x++){
        fd >> PD[x].lytis >> PD[x].ranka >> PD[x].dydis;
        PD[x].pora = false;
    }
    fd.close();
}

// Funkcija skaiciuojanti kiek poru galima sudaryti
int KiekPoru(int nKP, Pirstine *PKP, int VarM){
    int kiek=0;
    for(int x=0; x<nKP; x++){
        for(int y=x+1; y<nKP; y++){
            if((PKP[x].lytis==VarM) && (PKP[y].lytis==VarM) &&
               (PKP[x].ranka!=PKP[y].ranka) && (PKP[x].dydis==PKP[y].dydis) &&
               (PKP[x].pora==false) && (PKP[y].pora==false)){
                PKP[x].pora=true;
                PKP[y].pora=true;
                kiek++;
            }
        }
    }
    return kiek;
}

// Funkcija skaiciuojanti kiek pirstiniu lieka nepanaudotu
int KiekAtliekamu(int nKA, Pirstine *PKA, int VarM){
    int kiek=0;
    for(int x=0; x<nKA; x++){
        if(PKA[x].lytis==VarM&&PKA[x].pora==false) kiek++;
    }
    return kiek;
}

// Pagrindine funkcija
int main(){
    int n, Vp, Mp, Va, Ma;
    Pirstine P[101];

    // Nuskaitomi duomenys
    Duomenys(n, P);

    // Skaiciuojama kiek poru vyrisku pirstiniu galima sudaryti ir kiek pirstiniu lieka
    Vp=KiekPoru(n, P, 3);
    Mp=KiekPoru(n, P, 4);

    // Skaiciuojama kiek poru moterisku pirstiniu galima sudaryti ir kiek pirstiniu lieka
    Va=KiekAtliekamu(n, P, 3);
    Ma=KiekAtliekamu(n, P, 4);

    // Duomenys issaugomi rezultatu byloje
    ofstream fr(R);
    fr << Mp << endl << Vp << endl << Ma << endl << Va;
    fr.close();

    return 0;
}
