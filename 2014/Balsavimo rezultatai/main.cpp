#include <iostream>
#include <fstream>
using namespace std;

const char D[] = "U1.txt";
const char R[] = "U1rez.txt";

// Funkciju antrastes
void taskai (int balsai1, int balsai2, int balsai3, int& pirmas, int& antras, int& trecias);
int laimejo (int taskai1, int taskai2, int taskai3, int d1, int d2, int d3);

// Pagrindine funkcija
int main(){

    int k=10, pirmasBviso=0, antrasBviso=0, treciasBviso=0, pirmasTviso=0, antrasTviso=0, treciasTviso=0;
    int pirmasB[k], antrasB[k], treciasB[k], pirmasT[k], antrasT[k], treciasT[k];
    int dir1, dir2, dir3, laim;

    // Duomenu nuskaitymas ir skaiciavimai
    ifstream fd(D);
    fd >> k;
    for(int x=1; x<=k; x++){
        fd >> pirmasB[x] >> antrasB[x] >> treciasB[x];
        pirmasBviso=pirmasBviso+pirmasB[x];
        antrasBviso=antrasBviso+antrasB[x];
        treciasBviso=treciasBviso+treciasB[x];
        taskai(pirmasB[x], antrasB[x], treciasB[x], pirmasT[x], antrasT[x], treciasT[x]);
        pirmasTviso=pirmasTviso+pirmasT[x];
        antrasTviso=antrasTviso+antrasT[x];
        treciasTviso=treciasTviso+treciasT[x];
    }
    fd >> dir1 >> dir2 >> dir3;
    fd.close();

    // Laimetojo isrinkimas ir ezultatu irasymas i tekstine byla
    ofstream fr (R);
    laim=laimejo(pirmasTviso, antrasTviso, treciasTviso, dir1, dir2, dir3);
    fr << pirmasBviso << " " << antrasBviso << " " << treciasBviso << endl;
    fr << pirmasTviso << " " << antrasTviso << " " << treciasTviso << endl;
    fr << laim;
    fr.close();

    return 0;
}

// Funkcija priskirianti taskus pagal balsu skaiciu
void taskai (int balsai1, int balsai2, int balsai3, int& pirmas, int& antras, int& trecias){
    if((balsai1==balsai2)&&(balsai1==balsai3)&&(balsai2==balsai3)){
        pirmas = 0;
        antras = 0;
        trecias = 0;
    }
    else if ((balsai1>balsai2)&&(balsai1>balsai3)){
        pirmas = 4;
        antras = 0;
        trecias =0;
    }
    else if ((balsai2>balsai1)&&(balsai2>balsai3)){
        pirmas = 0;
        antras = 4;
        trecias =0;
    }
    else if ((balsai3>balsai2)&&(balsai3>balsai1)){
        pirmas = 0;
        antras = 0;
        trecias =4;
    }
    else if (balsai1==balsai2){
        pirmas = 2;
        antras = 2;
        trecias = 0;
    }
    else if (balsai1==balsai3){
        pirmas = 2;
        antras = 0;
        trecias = 2;
    }
    else if (balsai3==balsai2){
        pirmas = 0;
        antras = 2;
        trecias = 2;
    }
}

// Funkcija isrenkanti laimetoja
int laimejo (int taskai1, int taskai2, int taskai3, int d1, int d2, int d3){
    if((taskai1>taskai2)&&(taskai1>taskai3)) return 1;
    if((taskai2>taskai1)&&(taskai2>taskai3)) return 2;
    if((taskai3>taskai1)&&(taskai3>taskai2)) return 3;
    if((taskai1==taskai2)||(taskai2==taskai3)||(taskai1==taskai3)){
        taskai1=taskai1+d1;
        taskai2=taskai2+d2;
        taskai3=taskai3+d3;
    }
    if((taskai1>taskai2)&&(taskai1>taskai3)) return 1;
    if((taskai2>taskai1)&&(taskai2>taskai3)) return 2;
    if((taskai3>taskai1)&&(taskai3>taskai2)) return 3;
}
