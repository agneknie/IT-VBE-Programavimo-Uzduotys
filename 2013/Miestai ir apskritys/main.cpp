#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char D[] = "U2.txt";
const char R[] = "U2rez.txt";

//Struktura pradiniams duomenims apie miestus laikyti
struct miestai{
    string pav;
    string apskr;
    int gyv;
};

//Struktura rezultatams apie apskritis laikyti
struct apskritys{
    string apskr;
    int mazmiest;
    int isviso;
};

void skaityti (int& skmst, miestai *Q);

// Pagrindine funkcija
int main()
{
    int miestsk=103;        //Maksimalus miestu skaicius =103
    miestai X[miestsk];     //Apibreziama struktura duomenims apie miestus laikyti
    miestai laikina;        //Struktura rikiavimo ciklui (apkeitimams)
    apskritys Y[10];        //Maksimalus apskriciu skaicius =10
    apskritys laik;          //Struktura rikiavimo ciklui (apkeitimams)

    skaityti(miestsk, X);   //Nuskaitomi duomenys is failo

    //Isrikiuojami nuskaityti miestai pagal apskriti
    for(int q=1; q<=miestsk; q++){
        for(int z=1; z<=(miestsk-q); z++){
            if (X[z].apskr>X[z+1].apskr){
                laikina=X[z];
                X[z]=X[z+1];
                X[z+1]=laikina;
            }
        }
    }


    int sk=0;      // Kintamasis apskritims skaiciuoti

    //Apskriciu skaiciavimas, maziausio miesto issrinkimas, gyventoju apskrityje skaiciavimas
    for(int a=1; a<=miestsk; a++){
        if(Y[sk].apskr==X[a].apskr){
            Y[sk].isviso=Y[sk].isviso+X[a].gyv;
            if(Y[sk].mazmiest>X[a].gyv){
                Y[sk].mazmiest=X[a].gyv;
            }
        }
        if(Y[sk].apskr!=X[a].apskr){
            sk++;
            Y[sk].apskr=X[a].apskr;
            Y[sk].mazmiest=X[a].gyv;
            Y[sk].isviso=X[a].gyv;
        }
    }

    //Rikiavimas pagal maziausia miesta
    for(int d=1; d<=sk; d++){
        for(int e=1; e<=(sk-d); e++){
            if(Y[e].mazmiest>Y[e+1].mazmiest){
                laik=Y[e];
                Y[e]=Y[e+1];
                Y[e+1]=laik;
            }
        }
    }

    //Rikiavimas pagal apskrities pavadinima, jeigu maziausias miestas sutampa
    for(int f=1; f<=sk; f++){
        for(int g=1; g<=(sk-f); g++){
            if(Y[g].apskr>Y[g+1].apskr){
                if(Y[g].mazmiest==Y[g+1].mazmiest){
                    laik=Y[g];
                    Y[g]=Y[g+1];
                    Y[g+1]=laik;
                }
            }
        }
    }

    //Rezultatu  irasymas i faila
    ofstream fr(R);
    fr << sk << endl;
    for(int h=1; h<=sk; h++){
        fr << Y[h].apskr << " " << Y[h].mazmiest << " " << Y[h].isviso << endl;
    }
    fr.close();

    return 0;
}

// Funkcija nuskaitanti duomenis is bylos
void skaityti (int& skmst, miestai *Q){
    ifstream fd (D);
    fd >> skmst;
    for (int m=1; m<=skmst; m++){
        fd >> Q[m].pav >> Q[m].apskr >> Q[m].gyv;
    }
    fd.close();}
