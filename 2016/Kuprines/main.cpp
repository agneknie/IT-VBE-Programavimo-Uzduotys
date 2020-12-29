#include <iostream>
#include <fstream>
using namespace std;

const char D[] = "U1.txt";
const char R[] = "U1rez.txt";

// Funkciju antrastes
int sunkiausiakuprine(int kuprsk, int didz);
int kieklengvesniu(int didz);

// Pagrindine funkcija
int main(){

    int kuprsk, didz, kiek;

    // Nuskaitomi duomenys, atliekami skaiciavimai
    ifstream fd (D);
    fd >> kuprsk >> didz;

    didz=sunkiausiakuprine(kuprsk, didz);

    fd.close();
    fd.open("U1.txt");

    kiek=kieklengvesniu(didz);
    fd.close();

    // Irasomi rezultatai i faila
    ofstream fr (R);
    fr << didz << " " << kiek;
    fr.close();
}

// Funkcija atrandanti sunkiausia kuprine
int sunkiausiakuprine(int kuprsk, int didz){
    ifstream fd (D);
    int x=0;
    int nuskait;
     while (x<kuprsk){
        fd >> nuskait;
        if(nuskait>didz){
            didz=nuskait;
        }
    x++;
    }
    return didz;
}

// Funkcija atrandanti kiek kupriniu yra lengvesniu pagal duota salyga
int kieklengvesniu(int didz){
    ifstream fd (D);
    int x=0;
    int nuskait, kiek, kuprsk;
    fd >> kuprsk;
    while (x<kuprsk){
        fd >> nuskait;
        nuskait=nuskait*2;
        if(didz>=nuskait){
            kiek++;
        }
        x++;
    }
    return kiek;
}
