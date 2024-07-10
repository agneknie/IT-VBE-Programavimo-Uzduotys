#include <iostream>
#include <fstream>

using namespace std;

const char D[] = "U2.txt";
const char R[] = "U2rez.txt";
const int MIN_DRAUGAI = 4;

struct LaisvasLaikas{           // Laisvas laikas galvosukiu kambaryje issaugomas poromis. Pvz.: (II 14) (IV 6)
    string diena;
    int laikas;

    int draugSk = 0;
    string draugai[20];
};

struct DraugoLaikas{            // Draugui tinkamas laikas issaugomas poromis su draugo vardu. Pvz.: (Tomas II 14) (Reda III 15)
    string draugas;
    string diena;
    int laikas;
};

// Funkcija rikiuojanti laisvus laikus pagal galinciu prisijungti draugu skaiciu
void rikiuotiLaikus(int laisvuLaikuSk, LaisvasLaikas *laisviLaikai){
    for(int i=0; i<laisvuLaikuSk; i++){
        for(int j=0; j<laisvuLaikuSk-1; j++){
            if(laisviLaikai[j].draugSk < laisviLaikai[j+1].draugSk){
                swap(laisviLaikai[j], laisviLaikai[j+1]);
            }
        }
    }
}

int main()
{
    int d, dr;                              // Dienu skaicius, Draugu skaicius

    int laisvuLaikuSk = 0;                  // Kiek laisvu laiku galvosukiu kambaryje yra is viso
    LaisvasLaikas laisviLaikai[7*24];

    int drauguLaisvuLaikSk = 0;             // Kiek tinkamu laiku yra draugams
    DraugoLaikas drauguLaikai[20*7*24];

    // Atidaromas duomenu failas
    ifstream fd(D);
    fd >> d >> dr;

    // Nuskaitomi tinkami/laisvi galvosukiu kambario laikai
    for(int i=0; i<d; i++){
        string diena;
        int laisvValSk;     // Kiek laisvu laiku/valandu yra dabar nuskaitomoje dienoje
        // Nuskaitoma diena ir kiek joje yra laisvu/tinkamu laiku
        fd >> diena >> laisvValSk;

        // Issaugoma dienos ir laisvo laiko pora
        for(int j=0; j<laisvValSk; j++){
            int laisvLaik;
            fd >> laisvLaik;

            laisviLaikai[laisvuLaikuSk].diena = diena;
            laisviLaikai[laisvuLaikuSk].laikas = laisvLaik;
            laisvuLaikuSk++;
        }
    }

    // Nuskaitomi draugams tinkami laikai
    for(int i=0; i<dr; i++){
        string draugas;
        int tinkLaikSk;
        fd >> draugas >> tinkLaikSk;

        // Nuskaitomos draugui tinkamu laiku poros
        for(int j=0; j<tinkLaikSk; j++){
            fd >> drauguLaikai[drauguLaisvuLaikSk].diena >> drauguLaikai[drauguLaisvuLaikSk].laikas;
            drauguLaikai[drauguLaisvuLaikSk].draugas = draugas;
            drauguLaisvuLaikSk++;
        }
    }
    // Uzdaromas duomenu failas
    fd.close();

    // Kiekviena galvosukiu laisva laika lyginame su draugu laisvais laikais
    for(int i=0; i<laisvuLaikuSk; i++){
        for(int j=0; j<drauguLaisvuLaikSk; j++){
            // Jeigu laisvo laiko diena ir valanda sutampa su draugo tinkamo laiko diena ir valanda
            // laisvam laikui padidiname galinciu prisijungti draugu skaiciu ir issaugome to draugo varda
            if(laisviLaikai[i].diena == drauguLaikai[j].diena &&
               laisviLaikai[i].laikas == drauguLaikai[j].laikas){
                laisviLaikai[i].draugai[laisviLaikai[i].draugSk] = drauguLaikai[j].draugas;
                laisviLaikai[i].draugSk++;
               }
        }
    }

    // Isrikiuojame laisvus laikus pagal galinciu prisijungti draugu skaiciu mazejanciai
    rikiuotiLaikus(laisvuLaikuSk, laisviLaikai);

    // Isrikiuojame draugus pagal abecele laisvu laiku strukturoje
    for(int i=0; i<laisvuLaikuSk; i++){
        for(int j=0; j<laisviLaikai[i].draugSk; j++){
            for(int k=0; k<laisviLaikai[i].draugSk-1; k++){
                if(laisviLaikai[i].draugai[k] > laisviLaikai[i].draugai[k+1]){
                    swap(laisviLaikai[i].draugai[k], laisviLaikai[i].draugai[k+1]);
                }
            }
        }
    }

    // Irasome rezultatus i faila
    ofstream fr(R);
    for(int i=0; i<laisvuLaikuSk; i++){
        if(laisviLaikai[i].draugSk >= MIN_DRAUGAI){
            fr << laisviLaikai[i].diena << " " << laisviLaikai[i].laikas << " " << laisviLaikai[i].draugSk << endl;
            for(int j=0; j<laisviLaikai[i].draugSk; j++){
                fr << laisviLaikai[i].draugai[j] << endl;
            }
        }
    }
    // Uzdarome rezultatu faila
    fr.close();

    return 0;
}
