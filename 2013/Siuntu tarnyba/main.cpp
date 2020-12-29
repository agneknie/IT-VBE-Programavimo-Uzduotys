#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

const char D[]="U1.txt";
const char R[]="U1rez.txt";

//Struktura duomenims saugoti
struct siuntiniai{
    int x;
    int y;
    string pav;
};

// Funkciju antrastes
int atstumas (int x0, int y0);
void duomenys (int& nd, int& md, siuntiniai *Q);
void rezultatai (int kiekimon, int kiekkm, string paskpav);

// Pagrindine funkcija
int main()
{
    int n=50, m=500, kmviso=0;
    siuntiniai S[n];

    duomenys(n, m, S);

    for (int a=1; a<=n; a++){
        kmviso=kmviso+atstumas(S[a].x, S[a].y);
        if (kmviso==m){
        rezultatai(a, kmviso, S[a].pav);
        a=a+n;          //a=a+n yra skirta ciklui uzdaryti, nes salyga buvo patenkinta
    }
        if (kmviso>m){
            rezultatai(a-1, kmviso-atstumas(S[a].x, S[a].y), S[a-1].pav);
            a=a+n;      //a=a+n yra skirta ciklui uzdaryti, nes salyga buvo patenkinta
        }
    }
    return 0;}

//Funkcija atstumui iki imones ir atgal skaiciuoti
int atstumas (int x0, int y0){
    int xmod, ymod, km;
    xmod=abs(x0);
    ymod=abs(y0);
    km = (xmod+ymod)*2;
    return km;}

//Funkcija duomenims skaityti
void duomenys (int& nd, int& md, siuntiniai *Q){
    ifstream fd (D);
    fd >> nd >> md;
    for(int a=1; a<=nd; a++){
    fd >> Q[a].pav >>Q[a].x >> Q[a].y;
    }
    fd.close();}

//Funkcija rezultatams isvesti
void rezultatai (int kiekimon, int kiekkm, string paskpav){
    ofstream fr(R);
    fr << kiekimon << " " << kiekkm << " " << paskpav;
    fr.close();}
