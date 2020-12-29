#include <iostream>
#include <fstream>

using namespace std;

const char D[]="U1.txt";
const char Rez[]="U1rez.txt";

//Funkcija, skaiciuojanti veliaveliu skaiciu
int KiekVeliaveliu(int spG, int spZ, int spR){
    int maz=spG, kiek;
    if(maz>spZ) maz=spZ;
    if(maz>spR) maz=spR;
    kiek=maz/2;
    return kiek;}

// Pagrindine funkcija
int main()
{
    int n, G=0, Z=0, R=0, kiek, velsk;
    char SpKod;

    //Nuskaitomi duomenys
    ifstream fd(D);
    fd>>n;
    for(int x=0; x<n; x++){
    fd>>SpKod>>kiek;
    if(SpKod=='G') G=G+kiek;
    if(SpKod=='Z') Z=Z+kiek;
    if(SpKod=='R') R=R+kiek;}
    fd.close();

    velsk=KiekVeliaveliu(G, Z, R);

    //Skaiciujama, kiek kiekvienos spalvos veliaveliu liko
    G=G-2*velsk;
    Z=Z-2*velsk;
    R=R-2*velsk;

    //Rezultatai irasomi i faila
    ofstream fr(Rez);
    fr << velsk << endl;
    fr << "G = " << G << endl << "Z = " << Z << endl << "R = " << R;
    fr.close();

    return 0;
}
