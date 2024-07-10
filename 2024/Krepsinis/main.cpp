#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

const char D[] = "U1.txt";
const char R[] = "U1rez.txt";

struct Zaidejas {       // Struktura apibudinanti zaideja ir jo duomenis
    int zaidNr;
    int baudPat;
    int baudViso;
    int dvitPat;
    int dvitViso;
    int tritPat;
    int tritViso;

    int rungtSk = 1;
};

// Funkcija skaiciuojanti zaidejo tasku vidurki ir pataikyma procentais
void zaidejoRezultatai(Zaidejas zaidejas, double& taskVid, double& pataikymas){
    double pataikytaTask = zaidejas.baudPat + zaidejas.dvitPat*2 + zaidejas.tritPat*3;
    taskVid = round(pataikytaTask/zaidejas.rungtSk *10)/10.0;

    double pataikytaMet = zaidejas.baudPat + zaidejas.dvitPat + zaidejas.tritPat;
    int mestaMet = zaidejas.baudViso + zaidejas.dvitViso + zaidejas.tritViso;
    pataikymas = round(pataikytaMet*100/mestaMet);
};

int main()
{
    int n;                               // Zaideju rezultatu skaicius
    Zaidejas zaidejai[100];              // Struktura sauganti zaideju rezultatus

    int zaidSk = 0;                      // Unikaliu zaideju skaicius

    // Atidaroma duomenu byla, nuskaitomi duomenys
    ifstream fd(D);
    fd >> n;


    // Nuskaitomi zaideju duomenys
    for(int i=0; i<n; i++){
        int zaidNr, baudPat, baudViso, dvitPat, dvitViso, tritPat, tritViso;
        bool naujasZaidejas = true;

        // Nuskaitoma viena duomenu eilute
        fd >> zaidNr >> baudPat >> baudViso >> dvitPat >> dvitViso >> tritPat >> tritViso;

        // Nuskaityta zaidejo rezultatu eilute tikriname su visais jau issaugotais zaidejais
        for(int j=0; j<zaidSk; j++){
            // Jeigu dabar nuskaityto zaidejo numeris sutampa su pries tai
            // issaugotu zaidejo numeriu reiskia, kad tai nera naujo zaidejo duomenys.
            // Taigi, nuskaityti zaidejo rezultatai yra pridedami prie jau issaugotu rezultatu
            if(zaidNr == zaidejai[j].zaidNr){
                naujasZaidejas = false;

                zaidejai[j].baudPat += baudPat;
                zaidejai[j].baudViso += baudViso;
                zaidejai[j].dvitPat += dvitPat;
                zaidejai[j].dvitViso += dvitViso;
                zaidejai[j].tritPat += tritPat;
                zaidejai[j].tritViso += tritViso;

                zaidejai[j].rungtSk++;
            }
        }
        // Jeigu tai yra naujas zaidejas, issaugome jo duomenis
        if(naujasZaidejas){
            zaidejai[zaidSk].zaidNr = zaidNr;
            zaidejai[zaidSk].baudPat = baudPat;
            zaidejai[zaidSk].baudViso = baudViso;
            zaidejai[zaidSk].dvitPat = dvitPat;
            zaidejai[zaidSk].dvitViso = dvitViso;
            zaidejai[zaidSk].tritPat = tritPat;
            zaidejai[zaidSk].tritViso = tritViso;
            zaidSk++;
        }
    }
    // Uzdaromas duomenu failas
    fd.close();

    // Surandame didziausia rungtyniu skaiciu suzaista vieno zaidejo
    int rungtSk = 0;
    for(int i=0; i<zaidSk; i++){
        if(zaidejai[i].rungtSk>rungtSk){
            rungtSk = zaidejai[i].rungtSk;
        }
    }

    // Atidarome rezultatu faila
    ofstream fr(R);
    // Irasome didziausia zaidejo suzaista rungtyniu skaiciu
    fr << rungtSk << endl;
    // Irasome daugiausiai rungtyniu suzaidusiu zaideju duomenis
    for(int i=0; i<zaidSk; i++){
        // Jeigu zaidejas suzaide didziausia rungtyniu skaiciu, jo/jos rezultatus irasome i rezultatu faila
        if(zaidejai[i].rungtSk == rungtSk){
            fr << zaidejai[i].zaidNr << " ";

            // Surandame zaidejo rezultatyvumo duomenis
            double taskVid, pataikymas;
            zaidejoRezultatai(zaidejai[i], taskVid, pataikymas);
            // Irasome zaidejo rezultatyvumo duomenis
            fr << fixed << setprecision(1) << taskVid << " " << (int)pataikymas << " %" << endl;
        }
    }
    // Uzdarome rezultatu faila
    fr.close();

    return 0;
}
