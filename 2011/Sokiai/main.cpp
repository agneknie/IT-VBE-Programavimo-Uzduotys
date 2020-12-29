#include <iostream>
#include <fstream>

using namespace std;

const char D[]="U2.txt";
const char R[]="U2rez.txt";

// Struktura duomenims apie sokejus saugoti
struct Sokejai{
    string vard;
    int bal[11];
    int minB, maxB;
    int task;
};

// Funkcija skaiciuojanti taskus
int Taskai(int nT, int kT, Sokejai *ST, int xT){
    int viso=0;
    for(int y=0; y<kT; y++){
        if(y!=0&&ST[xT].minB>ST[xT].bal[y]) ST[xT].minB=ST[xT].bal[y];
        if(y!=0&&ST[xT].maxB<ST[xT].bal[y]) ST[xT].maxB=ST[xT].bal[y];
        if(y==0){
            ST[xT].minB=ST[xT].bal[y];
            ST[xT].maxB=ST[xT].bal[y];
        }
    }
    for(int y=0; y<kT; y++){
        viso=viso+ST[xT].bal[y];}
    viso=viso-ST[xT].minB-ST[xT].maxB;

    return viso;}

// Funkcija nuskaitanti duomenis is bylos
void Duomenys(int &nD, int &kD, Sokejai *SD){
    ifstream fd(D);
    fd >> nD >> kD;
    for(int x=0; x<nD; x++){
        char eil[21];
        fd.ignore();
        fd.get(eil, 20);
        SD[x].vard=eil;
        for(int y=0; y<kD; y++) fd >> SD[x].bal[y];
        SD[x].task=Taskai(nD, kD, SD, x);
        for(int y=0; y<kD; y++) fd >> SD[x].bal[y];
        SD[x].task=SD[x].task+Taskai(nD, kD, SD, x);
    }
    fd.close();}

// Funkcija rikiuojanti sokejus pagal surinktu tasku skaiciu
void Rikiuoti(int nR, Sokejai *SR){
    for(int x=0; x<nR; x++){
        for(int y=0; y<nR-1-x; y++){
            if(SR[y].task<SR[y+1].task) swap(SR[y], SR[y+1]);
        }
    }
}

// Pagrindine funkcija
int main(){
    int n, k;
    Sokejai S[101];

    Duomenys(n, k, S);
    Rikiuoti(n, S);

    ofstream fr(R);
    for(int x=0; x<n; x++) fr << S[x].vard << " " << S[x].task << endl;
    fr.close();

    return 0;
}
