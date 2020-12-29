#include <iostream>
#include <fstream>
using namespace std;

const char D[]="U1.txt";
const char R[]="U1rez.txt";
const int MAX_SK=100;

// Pagrindine funkcija
int main(){

    int kieksuv[MAX_SK];
    int kiekliko[MAX_SK];
    int n;
    int a=1;
    int b;

    // Nuskaitomi duomenys
    ifstream fd (D);
    for(int x=1; x<=10; x++){
        fd >> kieksuv[x];
    }
    fd.close();

    // Pagrindines operacijos, formuojancios rezultatus
    for(int x=11; x<=20; x++){
        kieksuv[x]=0;
    }

    for(int y=1; y<=10; y++){
        kiekliko[y]=10-kieksuv[y];
    }


    while(a<=10){
        b=1;
        n=kiekliko[a];
    while(b<=n){
        kieksuv[a+b]=kieksuv[a+b]+1;
        b++;
   }
        a++;
   }

    // Irasomi rezultatai i faila
    ofstream fr(R);
    for(int h=1; h<=20; h++){
        fr << kieksuv[h] << " ";
    }
    fr.close();

    return 0;
}
