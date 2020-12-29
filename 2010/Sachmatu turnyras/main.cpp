#include <iostream>
#include <fstream>

using namespace std;

const char D[]="U1.txt";
const char R[]="U1rez.txt";

// Funkcija skaiciuojanti komplektu kieki
KiekKomplektu(int fig[]){
    int kiek=0;
    bool viskas=false;

    while(viskas == false){
        if(fig[0]>=8&&fig[1]>=2&&fig[2]>=2&&fig[3]>=2&&fig[4]>=1&&fig[5]>=1){
            kiek++;
            fig[0]=fig[0]-8;
            fig[1]=fig[1]-2;
            fig[2]=fig[2]-2;
            fig[3]=fig[3]-2;
            fig[4]=fig[4]-1;
            fig[5]=fig[5]-1;
        }
        else viskas = true;
    }
    return kiek;
}

// Pagrindine funkcija
int main(){

    // Masyvas pripildomas 0
    int N, nusk, fig[6]={0,0,0,0,0,0};

    // Nuskaitomi duomenys
    ifstream fd(D);
    fd >> N;
    for(int x=0; x<N; x++){
        for(int y=0; y<6; y++){
            fd >> nusk;
            fig[y]=fig[y]+nusk;
        }
    }
    fd.close();

    // Duomenys irasomi i faila
    ofstream fr(R);
    fr << KiekKomplektu(fig);
    fr.close();

    return 0;
}
