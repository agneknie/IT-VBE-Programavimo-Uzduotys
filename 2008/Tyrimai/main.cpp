#include <iostream>
#include <fstream>

using namespace std;

const char D[]="D.txt";
const char R[]="R.txt";

// Struktura marsrutu duomenims saugoti
struct Marsrutai{
    int il, isl;
};

void Duomenys (int& kiek, Marsrutai *Duo);          //Funkcija duomenims skaityti
void DaugiausiaKeleiviu(Marsrutai *R, int& Did);    //Funkcija marsrutui, vezusiam daugiausia keleiviu rasti

// Pagrindine funkcija
int main(){

    int n, daug;
    Marsrutai A[100];

    //Uzpildomas masyvas nuliais
    for(int x=0; x<100; x++){
        A[x].il=0;
        A[x].isl=0;}

    //Nuskaitomi duomenys ir patalpinami i struktura
    Duomenys(n, A);
    //Surandamas marsrutas, vezes daugiausiai keleiviu
    DaugiausiaKeleiviu(A, daug);

    //Rasomi duomenys i rezultatu faila
    ofstream fr(R);
    for(int x=0; x<100; x++){
        if(A[x].il!=0) fr << x << "   ";
    }
    fr << endl;

    for(int x=0; x<100; x++){
        if(A[x].il!=0) fr << A[x].il << "   ";
    }
    fr << endl;

    for(int x=0; x<100; x++){
        if(A[x].il!=0) fr << A[x].isl << "   ";
    }
    fr << endl;
    fr << daug;
    fr.close();

    return 0;
}

// Funkcija nuskaitanti duomenis is tekstines bylos
void Duomenys (int& kiek, Marsrutai *Duo){
    int nr, kel;

    ifstream fd(D);
    fd >> kiek;
    for(int x=0; x<kiek; x++){
        fd >> nr >> kel;
        if(kel>0) Duo[nr].il=Duo[nr].il+kel;
        else Duo[nr].isl=Duo[nr].isl+kel;}
    fd.close();
}

// Funkcija randanti marsruta su daugiausia keleiviu
void DaugiausiaKeleiviu(Marsrutai *R, int& Did){
    Marsrutai didz;
    didz.il=0;
    for(int x=0; x<100; x++){
        if(R[x].il!=0 &&R[x].il>didz.il){
            didz=R[x];
            Did=x;
        }
    }
}
