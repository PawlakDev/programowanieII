#include <iostream>
#include <fstream> //file.open
#include <vector> //vectorint
#include <sstream> //stringstream
#include <cstring> //memcpy

using namespace std;

class Uczen{
public:
    int id;//identyfikator ucznia (unikalny numer na skale szkolna)
    int rating; //ocena z zachowania (zakres od 1-6)
    int numberofaward;//ilosc zdobytych nagród
    int* tab; // dynamicznie alokowana tablice bedaca lista uzyskanych ocen (zakres kazdej z ocen 1-6)
    int numberofmarks; // ilosc ocen

    //zwracajaca float, liczaca srednia ocen
    float AverageGrade(){
        int suma=0;
        for(int i=0;i<numberofmarks;i++){
            suma+=tab[i];
        }
        return (float)suma/numberofmarks;
    }

private:
    void readmarks(string a){

        //Wydzielenie ze stringa wszystkich liczb
        stringstream ss(a); // stringstream wykrywa nowy strumień na podstawie podanego separatora, który jest ustawiony domyślnie jako spacja
        string part; // tutaj je zapiszemy

        vector<int> vectorint; //tutaj zapisujemy wszystkie part'y

        while (ss >> part) // pobieramy kolejne podnapisy z stringstream
        {
            vectorint.push_back(stoi(part));
        }

        //Metoda ma utworzyæ tablice intow o rozmiarze takim, jaka jest ilosc przekazanych ocen
        tab = new int[vectorint[2]];

        //i wypelnic je poprawnymi wartosciami.

        for(int i=0;i<vectorint[2];i++){
            tab[i]=vectorint[i+3];
        }

        // Ponadto funkcja ma ustawic poprawnie pole reprezentujace ilosc ocen.
        numberofmarks = vectorint[2];

        //Zapisuje ocene z zachowania
        rating = vectorint[1];

    }

public :

    //bezargumentowy - tablica ustawiona na nullptr, pola typu int na -1
    Uczen(){
        id = -1;
        rating = -1;
        numberofaward=-1;
        tab = nullptr;
        numberofmarks=-1;
    }


    //przyjmujacy dwa argumenty
    Uczen(int id, string text){
        numberofaward=0;
        this->id = id;
        readmarks(text);
    }


    // konstruktor kopiujący
    Uczen(const Uczen& uczen){
        id=uczen.id;
        rating=uczen.rating;
        numberofaward=uczen.numberofaward;
        numberofmarks=uczen.numberofmarks;

        tab = new int[numberofmarks];
        memcpy(tab, uczen.tab, numberofmarks * sizeof(int)); //Funkcja kopiuje dane z obszaru źródłowego do obszaru docelowego
    }

    //zarzadzanie pamiecia
    ~Uczen(){
        delete[] tab;
    }
};

class Grupa{
    static int nextid; //na początku = 10

    static int generateid(){
        return nextid + 5;
    }

public:
    //30 elementowa tablica wskaźników na uczniów
    Uczen *tab[30];

    //pole reprezentujace ilosc uczniow w grupie
    int nositg; // nositg - number of students in the group

    int numberofgroup;//numer grupy


    void AddStudent(string text){
        numberofgroup = stoi(text);
        if(nositg==30){

            Uczen kandydat(-1,text);
            float lowerave = 9999;
            int studid = -1;

            //Szukanie osoby z najnizsza srednia
            for(int i=0;i<nositg;i++){
                if(tab[i]->AverageGrade()<lowerave){
                    lowerave = tab[i]->AverageGrade();
                    studid = i;
                }
            }

            if(kandydat.AverageGrade()>=lowerave){
                tab[studid] = new Uczen(nextid,text);
            }

        } else{
            tab[nositg] = new Uczen(nextid,text);
            nositg++;
        }
    }

    Grupa(){
        for(int i=0;i<30;i++){
            tab[i]=nullptr;
        }
        nositg = 0;
        numberofgroup=-1;
    }

    Grupa(int numbergroup){
        for(int i=0;i<30;i++){
            tab[i]=nullptr;
        }
        nositg = 0;
        numberofgroup= numbergroup;
    }

    ~Grupa(){
        for(int i = 0; i < nositg; i++)delete tab[i];
    }
};
int Grupa::nextid = 10;

int main(){
    fstream file;
    string a; // zmienna pomocnicza
    string groupstring;
    int groupint;

    Grupa grupa[8];
    for(int i=0;i<8;i++){
        grupa[i]=Grupa(i);
    }

    file.open("uczniowie.txt");
    if(!file.good()) return false;

    while(file.good()){
    getline(file,a); //numer_grupy ocena_z_zachowania ilość_ocen ocena_1 ocena_2 ... ocena_n

    groupint = stoi(a);

    grupa[groupint-1].AddStudent(a);

    }

    float higave=0; // Najwyzsza srednia
    vector<int> nrofstud; //numer studenta
    vector<int> nrgr; //numer grupy
    vector<int> nrofstud2; //numer studenta

    for(int i=0;i<8;i++){

        int licznikxz=0;

        for(int j=0;j<grupa[i].nositg;j++){


            //jezeli przynajmniej 5 ocen 5 / 6
            for(int xz=0;xz<grupa[i].tab[j]->numberofmarks;xz++){
                if(grupa[i].tab[j]->tab[xz]>=5)licznikxz+=1;
            }
            if(licznikxz>=5){
                grupa[i].tab[j]->numberofaward+=1;
            }
            licznikxz=0;

            //Wszystkim uczniom o ocenie z zachowania == 6
            if(grupa[i].tab[j]->rating==6){
                grupa[i].tab[j]->numberofaward+=1;
            }

            //Szukanie ucznia z najwyzsza srednia w grupie
            if(grupa[i].tab[j]->AverageGrade()>higave){
                nrofstud.clear();
                higave = grupa[i].tab[j]->AverageGrade();
                nrofstud.push_back(j);
            } else if (grupa[i].tab[j]->AverageGrade()==higave) nrofstud.push_back(j);
        }

        higave=0;


        for(int k=0;k<nrofstud.size();k++){
            //Dodawanie nagrody dla ucznia/uczniow z najlepsza srednia w grupie
            grupa[i].tab[nrofstud[k]]->numberofaward+=1;
            nrgr.push_back(i); nrofstud2.push_back(nrofstud[k]);
        }
    }

            //Szukanie ucznia/uczniow z najlepsza srednia ze wszystkich uczniów
            int higave2=0;
            vector<int> grupanajlepszego;
            vector<int> nrnalpeszego;
            int x,y;
            for(int i=0;i<nrgr.size();i++){
                x = nrgr[i];
                y = nrofstud2[i];
                if(grupa[x].tab[y]->AverageGrade() > higave2){
                    grupanajlepszego.clear();
                    nrnalpeszego.clear();
                    higave2=grupa[nrgr[i]].tab[nrofstud2[i]]->AverageGrade();
                    grupanajlepszego.push_back(nrgr[i]);
                    nrnalpeszego.push_back(nrofstud2[i]);
                } else if (grupa[x].tab[y]->AverageGrade() == higave2){

                }
            }

            for(int i=0;i<nrnalpeszego.size();i++){
                grupa[grupanajlepszego[i]].tab[nrnalpeszego[i]]->numberofaward+=1;
            }




    //Wypisz ilu uczniów dostało nie dostało żadnej nagrody, ilu jedną, ilu dwie itd
        int count0=0;
        int count1=0;
        int count2=0;
        int count3=0;
        int count4=0;


        for(int i=0;i<8;i++){
            for(int j=0;j<grupa[i].nositg;j++){
                if (grupa[i].tab[j]->numberofaward==1) count1++;
                else if (grupa[i].tab[j]->numberofaward==2) count2++;
                else if (grupa[i].tab[j]->numberofaward==3) count3++;
                else if (grupa[i].tab[j]->numberofaward==4) count4++;
                else count0++;
            }
        }

        cout << "Osob z 0 nagrodami jest: " << count0 << endl ;
        cout << "Osob z 1 nagroda jest: " << count1 << endl ;
        cout << "Osob z 2 nagrodami jest: " << count2 << endl ;
        cout << "Osob z 3 nagrodami jest: " << count3 << endl ;
        cout << "Osob z 4 nagrodami jest: " << count4 << endl ;

    //Utwórz tablicę 8 uczniów i skopiuj do niej po jednym wybranym uczniu z każdej grupy

    Uczen *kopie = new Uczen[8];
    for(int i=0;i<8;i++){
        kopie[0]= * grupa[i].tab[2] ;
    }

    file.close();
    return 0;
}
