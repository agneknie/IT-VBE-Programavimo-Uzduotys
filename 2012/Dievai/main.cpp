#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const char D[]="U2.txt";
const char R[]="U2rez.txt";

// Struktura duomenims apie dievus saugoti
struct Dievai {
    string vardas;
    int task[11], viso, kieklyg;
};

// Funkcija duomenims nuskaityti
void Duomenys(int &nD, int &kD, Dievai *OD){
    ifstream fd(D);
    fd >> nD >> kD;
    for(int x=0; x<nD; x++){
        fd >> OD[x].vardas;
        for(int y=0; y<kD; y++){
            fd >> OD[x].task[y];
        }
    }
    fd.close();
}

// Funkcija isrenkanti valdova
void Valdovas(Dievai *OV, Dievai *LV, int &kurisV, Dievai &VV, int &nV){
    bool arisrinko=false;
    int didzt=-51;
    for(int x=0; x<nV; x++){
        if(OV[x].viso>didzt) didzt=OV[x].viso;
    }

    int laimsk=0;
    for(int x=0; x<nV; x++){
        if(OV[x].viso==didzt){
            LV[laimsk]=OV[x];
            laimsk++;
            kurisV=x;
        }
    }

    int didzl=-51;
    if(laimsk==1) VV=OV[kurisV];
    else{
        for(int x=0; x<laimsk; x++){
            if(LV[x].kieklyg>didzl)didzl=LV[x].kieklyg;
        }
        for(int x=0; x<laimsk; x++){
            if(LV[x].kieklyg==didzl&&arisrinko==false){
                VV=LV[x];
                arisrinko=true;
            }
        }
    }
}

// Pagrindine funkcija
int main(){
    int n, k, kuris;
    Dievai O[51];
    Dievai L[51];
    Dievai V;

    // Nuskaitomi duomenys
    Duomenys(n, k, O);

    // Isrenkamas valdovas
    for(int x=0; x<n; x++){
        O[x].viso=0;
        O[x].kieklyg=0;
        for(int y=0; y<k; y++){
            if(O[x].task[y]%2==0){
                O[x].viso=O[x].viso+O[x].task[y];
                O[x].kieklyg++;
            }
            if(O[x].task[y]%2==1)O[x].viso=O[x].viso-O[x].task[y];
        }
    }

    Valdovas(O, L, kuris, V, n);

    // Irasomi rezultatai i byla
    ofstream fr(R);
    fr << setw(10) << left << V.vardas << " " << V.viso;
    fr.close();

    return 0;
}
