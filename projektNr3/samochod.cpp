#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

class Car{
private:
    string name; // Nazwa auta
    float aveSpeed; //Srednia predkosc
    float aveFuelConsumption; //Srednie spalanie (L/100KM)
    float fuel;//aktualna ilosc paliwa (L)
    float remainingDistance; //Pozostaly dystans do przejechania (KM)
    int trunkSize; // Wielkosc bagaznika
    int * tab; // Tablica jednowymiarowa dynamiczna zawierajaca ciezar rzeczy w bagazniku

public:

    Car(string name, float aveSpeed, float aveFuelConsumption, float fuel, float remainingDistance, int trunkSize){
        this->name = name;
        this->aveSpeed = aveSpeed;
        this->aveFuelConsumption = aveFuelConsumption;
        this->fuel = fuel;
        this->remainingDistance = remainingDistance;
        if(trunkSize<5) trunkSize = 5;
        else if(trunkSize>20) trunkSize=20;
        else this->trunkSize = trunkSize;

        tab = new int[trunkSize];

        //Gdyby bylo potrzebne sprawdzenie wylosowanych liczb

        //cout << "----------------------------" << endl ;
        for(int i=0;i<trunkSize;i++){
            tab[i] = rand()%11;
        //    cout << tab[i] << endl;
        }
        //cout << "----------------------------" << endl;
    }


    Car(string name){
        this->name = name;
        aveSpeed = rand()%140+1;
        aveFuelConsumption = rand()%25+1;
        fuel = rand()%60+1;
        remainingDistance = rand()%300+1;
        trunkSize = rand()%16+5;

        tab = new int[trunkSize];

        //Gdyby bylo potrzebne sprawdzenie wylosowanych liczb

        //cout << "----------------------------" << endl ;
        for(int i=0;i<trunkSize;i++){
            tab[i] = rand()%11;
        //    cout << tab[i] << endl;
        }
        //cout << "----------------------------" << endl;
    }

    Car(){
        name = "Auto";
        aveSpeed = rand()%140+1;
        aveFuelConsumption = rand()%25+1;
        fuel = rand()%60+1;
        remainingDistance = rand()%300+1;
        trunkSize = rand()%16+5;

        tab = new int[trunkSize];

        //Gdyby bylo potrzebne sprawdzenie wylosowanych liczb

        //cout << "----------------------------" << endl ;
        for(int i=0;i<trunkSize;i++){
            tab[i] = rand()%11;
        //    cout << tab[i] << endl;
        }
        //cout << "----------------------------" << endl;
    }


    string getName(){
        return name;
    }
    float getAveSpeed(){
        return aveSpeed;
    }
    float getAveFuelConsumption(){
        return aveFuelConsumption;
    }
    float getFuel(){
        return fuel;
    }
    float getRemainingDistance(){
        return remainingDistance;
    }
    int getTrunkSize(){
        return trunkSize;
    }
    int getTab(int i){
        return tab[i];
    }

    //Zasięg auta
    float Range(){
        float range = -1;
        range = (fuel/aveFuelConsumption)*100;
        return range;
    }

    //Sprawdzanie czy wystarczy paliwa aby dojechać
    bool CheckIsEnoughtFuel(float range){
        if(range>=remainingDistance) return true;
        else return false;
    }

    //Szacowany czas podróży
    float EstimatedTime(bool enoughtFuel){
        if(enoughtFuel==1){
            float result = -1;
            result = remainingDistance / aveSpeed ;
            return result;
        } else return -1;
    }

    //Czy jest m wolnych miejsc w bagazniku
    bool NumberOfEmpty(int m){
        int licznik=0;
        for(int i = 0 ; i < trunkSize ; i++){
            if(tab[i]==0) licznik++;
        }
        if(licznik>=m) return true;
        else return false;
    }

    //Średnia waga przedmiotów
    int AveWeight(){
        int licznik=0;
        for(int i = 0 ; i < trunkSize ; i++){
            if(tab[i]>0) licznik = licznik + tab[i];
        }
        return licznik;
    }

    //destruktor
    ~Car(){
            //cout << "destruktor ;(" << endl ;
            delete []tab;
    }
};

//Sprawdzanie ktore z 2 aut dojedzie piersze
string WhichIsFirst(Car &car1, Car &car2){
    float numberOfHours[2];
    numberOfHours[0] = car1.EstimatedTime(1);
    numberOfHours[1] = car2.EstimatedTime(1);
    //cout << "godziny pierwszego: " << numberOfHours[0] << endl ;
    //cout << "godziny drugiego: " << numberOfHours[1] << endl ;
    if(numberOfHours[0]<numberOfHours[1]) return car1.getName();
    else if (numberOfHours[0]>numberOfHours[1]) return car2.getName();
    else return car1.getName(); //W przypadku remisu zwróć dowolną nazwę samochodu
}

int main(){

    int counter; //licznik
    const int numberOfCarObject = 20; //Stala int ktora zawiera ilosc obiektow (wpisane na sztywno)
    //Liczby pseudo losowe
    srand(time(NULL));

    //Utwórz tablicę 20 samochodów
    Car tab[20] =
    //15 z nich utwórz pierwszym konstruktorem, pozostałe drugim
    { {"Auto numer 1"},{"Auto numer 2"},{"Auto numer 3"},{"Auto numer 4"},{"Auto numer 5"},
    {"Auto numer 6"},{"Auto numer 7"},{"Auto numer 8"},{"Auto numer 9"},{"Auto numer 10"},{"Auto numer 11"},{"Auto numer 12"},
    {"Auto numer 13"},{"Auto numer 14"},{"Auto numer 15"} };

    //Dla każdego z samochodów wypisz informacje czy dojedzie do celu
    for(int z=0; z<20; z++){
        if(tab[z].CheckIsEnoughtFuel(tab[z].Range())==1) cout << "Auto nr " << z << " Dojedzie do celu" << endl ;
        else cout << "Auto nr " << z << " nie dojedzie do celu " << endl;
    }

    //Wybierz parę samochodów, które dojadą do celu i sprawdź, który dojedzie szybciej
    bool firstCarIsFinded = false;
    bool secondCarIsFinded = false;
    string whichIsFirst;
    int number[2];
    counter=0; // licznik
    while(! ( (firstCarIsFinded==1) && (secondCarIsFinded==1) ) ){
            if( ( tab[counter].CheckIsEnoughtFuel(tab[counter].Range() ) ==1 ) && firstCarIsFinded == 0 ){
                firstCarIsFinded=1;
                number[0] = counter;
            }
            else if( ( tab[counter].CheckIsEnoughtFuel(tab[counter].Range() ) ==1 ) && firstCarIsFinded == 1 ){
                    secondCarIsFinded=1;
                    number[1] = counter;
            }
            counter++;
    }

    whichIsFirst = WhichIsFirst(tab[number[0]],tab[number[1]]);

    cout << whichIsFirst << " dojedzie szybciej " << endl ;

    //Znajdź samochód o 3 pustych miejscach w bagażniku, jeśli nie ma takiego, wypisz stosowną informację, Jeśli jest, wypisz jego średnią wagę bagażu.
    bool carIsFinded = false;
    int sum = 0;
    float aveWeight = 0; //Srednia waga
    counter = 0; // licznik

    while(carIsFinded == 0){
        if( tab[counter].NumberOfEmpty(3) == 1 ){
            carIsFinded=1;
        }
        counter++;
    }

    if(carIsFinded == 1){
        for(int i2=0; i2<tab[counter].getTrunkSize();i2++){
            sum+=tab[counter].getTab(i2);
            //cout << "Waga : " <<  tab[counter].getTab(i2) << endl ;
            //cout << sum << endl ;
        }
        aveWeight = (float) sum/tab[counter].getTrunkSize();
        cout << "Auto numer " << counter << ", srednia waga bagazu: " << aveWeight << endl ;
    } else{
        cout << "brak auta o 3 pustych miejscach w bagazniku" << endl ;
    }

    //Znajdź najszybszy samochód
    float max = 0;
    int number2 = 0 ;
    for(int i3=0; i3<numberOfCarObject;i3++){
        if( (tab[i3].getAveSpeed()) > max){
            max = tab[i3].getAveSpeed();
            number2 = i3;
        }
    }
    cout << "Najszybszym autem jest auto numer: " << number2 << " osiaga predkosc " << tab[number2].getAveSpeed() << endl ;

    //Znajdź samochód o najmniejszym zasięgu (taki, który może przejechać najkrótszy dystans)
    float min = 999999;
    number2 = 0;
    for(int i4=0; i4<numberOfCarObject;i4++){
        if( tab[i4].Range() < min ) {
            min = tab[i4].Range();
            number2 = i4;
        }
    }

    cout << "Autem o najmniejszym zasiegu jest auto numer " << number2 << " ma on zasieg rowny " << tab[number2].Range() << endl ;

    //Wypisz samochody, które dojadą do celu w czasie dłuższym niż 1 godzina.

    vector<int> counterVector;
    counter = 0; // licznik

    //Wyszukiwanie i zapisywanie takich aut
    for(int i5=0;i5<numberOfCarObject;i5++){
        if(tab[i5].EstimatedTime(1) > 1){
            counter+=1;
            counterVector.push_back(i5);
        }
    }

    cout << "Samochody numer: ";

    //Wyswietlanie
    for(unsigned long i6=0;i6<counterVector.size();i6++){
        if(i6!=counterVector.size()-1) cout << counterVector[i6] << ", ";
        else cout << counterVector[i6];
    }
    cout << " dojada do celu w czasie dluzszym niz 1 godzina." << endl;


    return 0;
}

