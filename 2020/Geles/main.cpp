#include <iostream>
#include <fstream>

using namespace std;

const char D[] = "U1.txt";
const char R[] = "U1rez.txt";

// Funkcija randanti diena, kuria pradeda zydeti daugiausia geliu
int pradedaZydetiDaugiausiaGeliu(int *dienuSarasas){
    int maxGeles = 0, dienosNr;
    for(int i=1; i<93; i++){
        if(dienuSarasas[i]>maxGeles){
            maxGeles = dienuSarasas[i];
            dienosNr = i;
        }
    }
    return dienosNr;
}

// Pagrindine funkcija
int main(){
    int n; // geliu skaicius

    // Masyvas dienu duomenims saugoti. Birzelis 30 dienu + Liepa 31 diena + Rugpjutis 31 diena = 92. Pradedu skaiciuot nuo 1, ne nuo 0, tai 93.
    // Uzpildau masyva nuliais, kad galeciau prideti, jeigu gele zydi ta diena
    int dienos[93];
    for (int i=1; i<93; i++) dienos[i] = 0;

    // Atidaroma duomenu byla, nuskaitomi duomenys
    ifstream fd(D);
    fd >> n;
    for (int i=0; i<n; i++){
        // Nuskaitau geles numeri, zydejimo pradzios menesi ir diena bei zydejimo pabaigos menesi ir diena
        int nr, pradzM, pradzD, pabM, pabD;
        fd >> nr >> pradzM >> pradzD >> pabM >> pabD;

        // Apskaiciuoju nuo kada iki kada zydi gele dienomis kad galeciau lengvai eiti per dienu masyva.
        // Pvz 06 23 yra 23 vasaros diena, 07 21 yra 51 vasaros diena, 08 01 yra 62 vasaros diena.
        int nuo, iki;
        if(pradzM==6) nuo = pradzD;
        if(pradzM==7) nuo = pradzD+30;
        if(pradzM==8) nuo = pradzD+61;

        if(pabM==6) iki = pabD;
        if(pabM==7) iki = pabD+30;
        if(pabM==8) iki = pabD+61;

        // Jei gele zydi kazkuria vasaros diena, pridedu ja prie ta diena zydinciu geliu skaiciaus
        for (int i=nuo; i<=iki; i++) dienos[i]++;
    }
    fd.close();

    // Suranda vasaros diena kai pradeda zydeti daugiausia geliu
    int pradzMaxGeliu = pradedaZydetiDaugiausiaGeliu(dienos);

    // Suranda kiek daugiausia geliu zydi vienu metu
    int geliuSk = dienos[pradzMaxGeliu];

    // Suranda vasaros diena kai baigia zydeti daugiausia geliu
    int pabMaxGeliu;
    for(int i=pradzMaxGeliu; i<93; i++){
        // Jei maximumas geliu dar zydi, periodas kai geles zydi pailgeja
        if(dienos[i]==geliuSk) pabMaxGeliu = i;
        // Jei max geliu nebezydi, tai radom ilgiausia perioda ir baigiam cikla
        else break;
    }

    // Rezultatai irasomi i tekstine byla
    ofstream fr(R);
    fr << geliuSk << endl;

    // Isvedu zydejimo pradzios data
    if (pradzMaxGeliu<=30) fr << "6 " << pradzMaxGeliu << endl;
    if (pradzMaxGeliu>30&&pradzMaxGeliu<=61)  fr << "7 " << pradzMaxGeliu-30 << endl;
    if (pradzMaxGeliu>61) fr << "8 " << pradzMaxGeliu-61 << endl;

    // Isvedu zydejimo pabaigos data
    if (pabMaxGeliu<=30) fr << "6 " << pabMaxGeliu << endl;
    if (pabMaxGeliu>30&&pabMaxGeliu<=61)  fr << "7 " << pabMaxGeliu-30 << endl;
    if (pabMaxGeliu>61) fr << "8 " << pabMaxGeliu-61 << endl;

    fr.close();

    return 0;
}
