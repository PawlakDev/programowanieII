#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

char *fun(int &n, string s) {

    n=s.size(); // sprawdzam wielkość stringa s i zapisuję w zmiennej n

    char *tab = new char[n];

    for(int i=n-1;i>=0;i--){
        if( islower(s[i]) ) // sprawdza czy litera jest mala
            {
                s[i]-=32; // odejmuje 32 w kodzie ascii aby zamienić ją na dużą
            }
        tab[n-i-1]=s[i]; //do tablicy charów wpisuje konkretną literę z wyrazu
    }

    return tab;
}


int main() {

    int n=0;
    vector<int> g1; //tablica dynamiczna
    string s;
    ifstream file;

    char **wsk = new char*[25];

    file.open("slowa.txt");

    int i=0;
    while(file>>s){ //dopóki wczytuje wyraz to zapisuje go w stringu s
        wsk[i] = fun(n,s);
        g1.push_back(n); //wrzuca na koniec do tablicy dynamicznej
        i+=1;
    }

    file.close();

    //Zamiana słowo zaczynającego się na najbliższą literze A z pierwszym
    int ascii = 65;
    int ischanged = 0; //Sprawdzenie czy została wykonana zmiana 0-Nie 1-Tak
    char pom[99]; //Da radę tutaj zamiast na sztywno wpisywać liczbę zrobić coś lepszego ?
    int pomsize; //Zmienna pomocnicza na int'y

    while(ischanged == 0){
        for(unsigned long int k2=0;k2<g1.size();k2++){ // unsigned long int bo g1.size() przyjmuje wartości >=0 a "long" bo przyjmuje albo short albo long, więc aby to kontrolować wpisałem long

            if((int)wsk[k2][0] == ascii){
            //Zamiana z pierwszym slowem

                //Przypisuje zmiennej pomocniczej wartosci wsk[0][0-i2]
                for(int i2=0;i2<g1[0];i2++)
                {
                    pom[i2] = wsk[0][i2];
                }

                //Nadpisuje wartosci wsk[0] przez wsk[k2]
                for(int i3=0;i3<g1[k2];i3++){
                    wsk[0][i3] = wsk[k2][i3];
                }

                //Nadpisuje wartosci wsk[k2] przez wsk[0]
                for(int i4=0;i4<g1[0];i4++){
                    wsk[k2][i4] = pom[i4];
                }

                //Zamieniam dlugosc wsk[0][x] z wsk[k2][x] , x to kolejne liczby 0,1,2,3,4,...
                pomsize = g1[k2];
                g1[k2]=g1[0];
                g1[0]=pomsize;
            //Wydaje mi się, że w przypadku różnic w długości słów pozostaną śmieci w tablicy ale lepiej je zignorować niż usuować bo usuwanie też zabiera trochę mocy (tak mi się wydaje)

            ischanged = 1;
            }

        }
        ascii++;
    }

    //wyswietlanie wszystkich wyrazów tablicy
    for(unsigned long int j=0;j<=g1.size();j++){ //g1.size bo jak bedzie wiecej/mniej niz 25 to i tak zadziała
        for(int k=0;k<g1[j];k++){
            cout << wsk[j][k];
        }
        cout << endl;
        if(j!=g1.size()){
            delete[] wsk[j]; //Zwolnienie pamięci
        }
    }
    //

    delete[] wsk; //Zwolnienie pamięci

    return 0;
}


