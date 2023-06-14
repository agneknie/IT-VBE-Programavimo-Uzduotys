#include <iostream>
#include <fstream>
using namespace std;

const char D[] = "U2.txt";
const char R[] = "U2rez.txt";

// Mokinių duomenis sauganti struktūra
struct Mokinys{
    string vardas;
    string dalykas;
};

// Dalykų duomenis sauganti struktūra
struct Dalykas{
    string pavadinimas;
    int populiarumas;
};

/**
 *   Funkcija, nuskaitanti mokinių duomenis.
 *   Išssaugo tik tuos mokinius, kurių vidurkis ne mažesnis nei 9.
 *
 *   mokiniai - nuoroda į struktūrą, saugančią mokinių duomenis;
 *   m - nuoroda į kintamąjį, saugantį mokinių skaičių.
 */
void nuskaitytiDuomenis(Mokinys *mokiniai, int &m)
{
    int tinkamuMokiniuSkaicius = 0;

    // Deklaruojamas ir atidaromas duomenų failas
    ifstream fd(D);

    // Nuskaitomas mokinių skaičius
    fd >> m;

    // Nuskaitomi kiekvieno mokinio duomenys
    for(int i=0; i<m; i++){
        string vardas;
        string dalykas;
        int pazymiuSkaicius;

        fd >> vardas >> dalykas >> pazymiuSkaicius;

        // Nuskaitomi mokinio pažymiai ir apskaičiuojamas vidurkis
        int pazymiuSuma = 0;
        for(int j=0; j<pazymiuSkaicius; j++){
            int pazymys;
            fd >> pazymys;
            pazymiuSuma += pazymys;
        }

        // Jei mokinio vidurkis ne mažesnis nei 9, mokinys išsaugomas struktūroje
        if(pazymiuSuma/pazymiuSkaicius >= 9){
            mokiniai[tinkamuMokiniuSkaicius].vardas = vardas;
            mokiniai[tinkamuMokiniuSkaicius].dalykas = dalykas;
            tinkamuMokiniuSkaicius++;
        }
    }

    // Uždaromas duomenų failas
    fd.close();

    // Atnaujinamas išsaugotų mokinių skaičius
    m = tinkamuMokiniuSkaicius;
}

/**
 *   Funkcija, išrikiuojanti/sugrupuojanti mokinius pagal dalykus.
 *   Rikiavimo algoritmas yra stabilus.
 *
 *   mokiniai - nuoroda į struktūrą, saugančią mokinių duomenis;
 *   m - mokinių skaičius.
 */
void rikiuotiMokinius(Mokinys *mokiniai, int m)
{
    for(int i=0; i<m; i++){
        for(int j=0; j<m-1; j++){
            if(mokiniai[j].dalykas > mokiniai[j+1].dalykas){
                swap(mokiniai[j], mokiniai[j+1]);
            }
        }
    }
}

/**
 *   Suformuoja dalykų masyvą ir suskaičiuoja jų populiarumą.
 *   Mokinių masyvas turi būti išrikiuotas abecėline tvarka, pagal dalykus.
 *
 *   mokiniai - nuoroda į struktūrą, saugančią mokinių duomenis;
 *   dalykai - nuorodą į struktūrą, saugančią dalykų duomenis;
 *   m - mokinių skaičius;
 *   n - nuoroda į kintamąjį, saugantį dalykų skaičių.
 */
void skaiciuotiPopuliaruma(Mokinys *mokiniai, Dalykas *dalykai, int m, int &n)
{
    n = -1;     // -1, kad teisingai priskirtų pirmąjį (nulinį) elementą

    // Suformuojamas dalykų masyvas
    for(int i=0; i<m; i++){
        // Jei dabartinio mokinio mėgstamiausias dalykas sutampa su dabartiniu dalyku,
        // populiarumas padidėja 1.
        if(mokiniai[i].dalykas == dalykai[n].pavadinimas){
            dalykai[n].populiarumas++;
        }

        // Jei dabartinio mokinio mėgstamiausias dalykas nesutampa su dabartiniu dalyku,
        // suformuojamas naujas dalykas.
        else{
            n++;
            dalykai[n].pavadinimas = mokiniai[i].dalykas;
            dalykai[n].populiarumas = 1;
        }
    }

    // Dalykų skaičius buvo skaičiuojamas nuo 0
    n++;
}

/**
 *   Funkcija, išrikiuojanti dalykus pagal populiarumą.
 *   Dalykai abecėliškai jau yra surikiuoti, nes mokiniai buvo išrikiuoti
 *   pagal dalyką, o naudojamas rikiavimo algoritmas yra stabilus.
 *
 *   dalykai - nuorodą į struktūrą, saugančią dalykų duomenis;
 *   n - dalykų skaičius.
 */
void rikiuotiDalykus(Dalykas *dalykai, int n)
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(dalykai[j].populiarumas<dalykai[j+1].populiarumas){
                swap(dalykai[j], dalykai[j+1]);
            }
        }
    }
}

/**
 *   Rezultatai įrašomi į textinę bylą.
 *
 *   mokiniai - nuoroda į struktūrą, saugančią mokinių duomenis;
 *   dalykai - nuorodą į struktūrą, saugančią dalykų duomenis;
 *   m - mokinių skaičius;
 *   n - dalykų skaičius.
 */
void irasytiRezultatus(Mokinys *mokiniai, Dalykas *dalykai, int m, int n)
{
    // Deklaruojamas ir atidaromas rezultatu failas
    ofstream fr(R);

    // Jei visi vidurkiai buvo mažesni nei 9
    if(n <= 0){
        fr << "Neatitinka vidurkis";
    }

    // Jei buvo mokinių, su ne mažesniu nei 9 vidurkiu
    else{
        for(int i=0; i<n; i++){
            // Įrašomas kiekvieno dalyko pavadinimas ir populiarumas
            fr << dalykai[i].pavadinimas << " " << dalykai[i].populiarumas << endl;

            // Įrašomi visi mokiniai, kurių šis dalykas yra mėgstamiausias
            for(int j=0; j<m; j++){
                if(mokiniai[j].dalykas == dalykai[i].pavadinimas){
                    fr << mokiniai[j].vardas << endl;
                }
            }
        }
    }

    // Uždaromas rezultatų failas
    fr.close();
}

int main()
{
    // Deklaruojami kintamieji
    int m;                      // Mokinių skaičius
    Mokinys mokiniai[50];       // Maximalus m=50 (žiūrėti uždavinio sąlygą)

    int n;                      // Dalykų skaičius
    Dalykas dalykai[50];

    // Nuskaitomi duomenys, išsaugomi tik mokiniai, kurių vidurkis ne mažesnis nei 9
    nuskaitytiDuomenis(mokiniai, m);

    // Mokiniai išrikiuojami pagal dalyka, nekeičiant tvarkos tarp mokinių
    rikiuotiMokinius(mokiniai, m);

    // Suskaičiuojamas dalyko populiarumas
    skaiciuotiPopuliaruma(mokiniai, dalykai, m, n);

    // Dalykai išrikiuojami pagal populiarumą ir abecėliškai
    rikiuotiDalykus(dalykai, n);

    // Resultatai surašomi į rezultatų failą
    irasytiRezultatus(mokiniai, dalykai, m, n);

    return 0;
}
