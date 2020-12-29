#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const char D[] = "U1.txt";
const char R[] = "U1rez.txt";

// Funkcijos antraste
string paversti (int skaicius);

// Pagrindine funkcija
int main(){
    int a, b, spalva;

    ifstream fd (D);
    fd >> a >> b;
    ofstream fr (R);

    for (int x=0; x<a; x++){
        for(int y=1; y<=b; y++){
            for (int z=0; z<3; z++){
                fd >> spalva;
                fr << paversti(spalva);
            }
            if(b!=y) fr << ";";
        }
    }
    fr << endl;

    fr.close();
    fd.close();

    return 0;
}

// Funkcija pavercianti skaiciu i sesioliktaini
string paversti (int skaicius){
    int sveik, liek;
    string s, l;
        sveik=skaicius/16;
        liek=skaicius%16;

        switch(sveik){
            case 0:
                s = "0";
                break;
            case 1:
                s = "1";
                break;
            case 2:
                s = "2";
                break;
            case 3:
                s = "3";
                break;
            case 4:
                s = "4";
                break;
            case 5:
                s = "5";
                break;
            case 6:
                s = "6";
                break;
            case 7:
                s = "7";
                break;
            case 8:
                s = "8";
                break;
            case 9:
                s = "9";
                break;
            case 10:
                s = "A";
                break;
            case 11:
                s = "B";
                break;
            case 12:
                s = "C";
                break;
            case 13:
                s = "D";
                break;
            case 14:
                s = "E";
                break;
            case 15:
                s = "F";
                break;
        }

                switch(liek){
            case 0:
                l = "0";
                break;
            case 1:
                l = "1";
                break;
            case 2:
                l = "2";
                break;
            case 3:
                l = "3";
                break;
            case 4:
                l = "4";
                break;
            case 5:
                l = "5";
                break;
            case 6:
                l = "6";
                break;
            case 7:
                l = "7";
                break;
            case 8:
                l = "8";
                break;
            case 9:
                l = "9";
                break;
            case 10:
                l = "A";
                break;
            case 11:
                l = "B";
                break;
            case 12:
                l = "C";
                break;
            case 13:
                l = "D";
                break;
            case 14:
                l = "E";
                break;
            case 15:
                l = "F";
                break;
        }
    return s+l;
}
