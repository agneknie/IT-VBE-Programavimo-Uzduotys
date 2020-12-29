#include <iostream>
#include <fstream>
using namespace std;

const char D[] = "U2.txt";
const char R[] = "U2rez.txt";

// Struktura duomenims apie staciakampius saugoti
struct Staciakampiai{
    int x;
    int y;
    int dx;
    int dy;
    string spalva;
};

// Pagrindine funkcija
int main(){

    Staciakampiai S[100];
    int n, a=0, b=0;
    string pirm, antr, trec, lang[100][100];

    //Nuskaitomi duomenys is failo
    ifstream fd(D);
    fd >> n;

    for (int z=0; z<n; z++){
    fd >> S[z].x >> S[z].y >> S[z].dx >> S[z].dy >> pirm >> antr >> trec;
    S[z].spalva=pirm+" "+antr+" "+trec;}

    fd.close();

    //Langeliai uzpildomi balta spalva
    for (int z=0; z<100; z++){
        for (int q=0; q<100; q++){
        lang[z][q]="255 255 255";}}

    // Atliekami skaiciavimai
    for(int h=0; h<n; h++){
            if(S[h].dx==1&&S[h].dy==1){
                for(int z=S[h].x; z<=S[h].dx; z++){
                    for(int q=S[h].y; q<=S[h].dy; q++){
                    lang[z][q]=S[h].spalva;
                    if(a<q){
                    a=q;}}
                if(b<z){
                b=z;}}}
            else if(S[h].dy==1){
                for(int z=S[h].x; z<S[h].dx; z++){
                    for(int q=S[h].y; q<=S[h].dy; q++){
                    lang[z][q]=S[h].spalva;
                    if(a<q){
                    a=q;}}
                if(b<z){
                b=z;}}}
            else if(S[h].dx==1){
                for(int z=S[h].x; z<=S[h].dx; z++){
                    for(int q=S[h].y; q<S[h].dy; q++){
                    lang[z][q]=S[h].spalva;
                    if(a<q){
                    a=q;}}
                if(b<z){
                b=z;}}}
            else{
                for(int z=S[h].x; z<S[h].dx; z++){
                    for(int q=S[h].y; q<S[h].dy; q++){
                    lang[z][q]=S[h].spalva;
                    if(a<q){
                    a=q;}}
                if(b<z){
                b=z;}}}}

    b++;
    a++;

    // Rezultatai irasomi i tekstine byla
    ofstream fr(R);
    fr << a << " " << b << endl;
    for(int z=0; z<a; z++){
        for(int q=0; q<b; q++){
            fr << lang[q][z] << endl;
        }
    }
    fr.close();

    return 0;
}
