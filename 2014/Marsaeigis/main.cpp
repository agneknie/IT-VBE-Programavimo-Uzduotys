#include <iostream>
#include <fstream>

using namespace std;

const char D[]="U2.txt";
const char R[]="U2rez.txt";

// Struktura duomenims saugoti
struct Seka{
    int sekaviso[31];
    int sekaivyk[31];
    int k;
    int kiekiv;
    bool arpab;
};

// Pagrindine funkcija
int main(){
    Seka S[11];
    int n, x0, y0, x1, y1, x, y;

    // Duomenu nuskaitymas
    ifstream fd(D);
    fd >> x0 >> y0 >> x1 >> y1 >> n;

    for(int z=0; z<n; z++){
        fd >> S[z].k;
        for(int q=0; q<S[z].k; q++){
            fd >> S[z].sekaviso[q];
        }
    }
    fd.close();

    // Pagrindiniu operaciju atlikimas
    for(int z=0; z<n; z++){
        S[z].kiekiv=0;
        S[z].arpab=false;
        x=x0;
        y=y0;
        for(int q=0; q<S[z].k; q++){
            if(S[z].arpab==false){
                if(S[z].sekaviso[q]==1)y=y+1;
                if(S[z].sekaviso[q]==2)x=x+1;
                if(S[z].sekaviso[q]==3)y=y-1;
                if(S[z].sekaviso[q]==4)x=x-1;
                S[z].sekaivyk[S[z].kiekiv]=S[z].sekaviso[q];
                S[z].kiekiv++;
                if(x==x1&&y==y1) S[z].arpab=true;
            }
        }
    }

    // Rezultatu irasymas i faila
    ofstream fr(R);
    for(int z=0; z<n; z++){
        if(S[z].arpab==true) fr << "pasiektas tikslas   ";
        else fr << "sekos pabaiga       ";
        for(int q=0; q<S[z].kiekiv; q++) fr << S[z].sekaivyk[q] << " ";
        fr << S[z].kiekiv << endl;
    }
    fr.close();

    return 0;
}
