#include <iostream>

using namespace std;

struct M{
    int rows; //Wiersze
    int cols; //Kolumny
    int **data; // pamiec
};

//tworzy matrix o wskazanych wymiarach, alokuje pamiec, ustawia jej wartoœci na 0 i zwraca ja
M create(int cols, int rows){
    M matrix;
    matrix.cols = cols;
    matrix.rows = rows;

    //Alokuję pamięć
    matrix.data = new int *[matrix.cols];

    for(int i=0;i<matrix.cols; i++){
        matrix.data[i] = new int [matrix.rows];
    }

    //Ustawiam wartości na 0
    for(int i=0;i<matrix.cols;i++){
        for(int j=0; j<matrix.rows;j++){
            matrix.data[i][j] = 0 ;
        }
    }

     return matrix ;
}

// dodaje do wszystkich elementów matrixy wartość value
M add(M a, int value){
    if(a.cols !=0 && a.rows !=0){ //zabezpieczenie gdy wymiar jest 0,0
        for(int i=0;i<a.cols;i++){
            for(int j=0;j<a.rows;j++){
                a.data[i][j] += value;
            }
        }
    }
    return a;
}


//mnożenie macierzy (jeśli to możliwe, w przeciwnym wypadku wypisz na ekranie stosowny komunikat i zwróć macierz o wymiarach 0 ze wskaźnikiem ustawionym na nullptr)
M mul(M a, M b){
    int sum=0;

    M matrix;

    if(a.cols == b.rows && a.cols!=0){ //Zabezpieczenie
    matrix = create(b.cols,a.rows);

        int z=0;
        for(int i=0;i<a.rows;i++){
            for(int j=0;j<b.cols;j++){ //a.cols == b.rows
                for(int k=0;k<a.cols;k++){
                    sum += a.data[k][i] * b.data[j][k];
                    //cout << a.data[k][i] << " * " << b.data[j][k] << " " ;
                }
                //cout << sum << endl ;
                //cout << "kol : " << z << " wiersz: " << i << endl ;
                matrix.data[z][i] = sum;
                z++;
                sum = 0;
            }
            z=0;
        }
    }else{
        cout << "You can't do this a.cols != b.rows" << endl ;
        //zwróć macierz o wymiarach 0
        matrix = create(0,0);
        //ze wskaźnikiem ustawionym na nullptr
        matrix.data = nullptr;
    }


    return matrix;

}

void set(M a, int col, int row, int value) //ustawia wartość w pozycji [col, row] na value;
{
    if(a.cols >= col && a.rows >= row){ //Zabezpieczenie
    a.data[col][row] = value;
    }
}


void fill(M a, int value){ //ustawia wszystkie pola macierzy na wartość value;

    if(a.rows != 0 && a.cols != 0) { //Zabezpiecznie
        for(int i=0;i<a.cols;i++){
            for(int j=0;j<a.rows;j++){
                a.data[i][j] = value;
            }
        }
    }
}

bool compare(M a, M b){ //zwraca true, jeśli macierze mają ten sam rozmiar i wszystkie pola o tej samej wartości, false w przeciwnym wypadku.
        int pom=0;
    if(a.cols != 0 && a.rows !=0 && b.rows != 0 && b.cols !=0){
        if(a.cols == b.cols && a.rows == b.rows){
            for(int i=0;i<a.cols;i++){
                for(int j=0;j<a.rows;j++){
                    if(a.data[i][j]!=b.data[i][j]) pom=1;
                }
            }
        } else pom=1;

        if(pom==1){
            return false;
        }
        else{
            return true;
        }
    } else return false;
}

void release(M a) //zwalnia pamięć struktury i ustawia jej wymiary na 0, 0 i wskaźnik na nullptr
{

    // zwalnianie pamieci
    for(int i=0;i<a.cols;i++){
        delete [] a.data[i];
    }

    delete [] a.data;

    //ustawia jej wymiary na 0
    if(a.cols !=0 && a.rows != 0){
        a.cols = 0; a.rows=0;
    }


    // wskaźnik na nullptr
    a.data = nullptr;


}

void print(M a){ //wyświetla macierz (dobrze jak będą zachowane wymiary)

    if(a.rows != 0 && a.cols != 0){ // Zabezpieczenie dla macierzy o wymiarach 0,0
        for(int i=0;i<a.rows;i++){
            for(int j=0;j<a.cols;j++){
                cout << a.data[j][i] << " ";
            }
            cout << endl ;
        }
    }
}

int main(){
    //Tworzę przykladowe 4 macierze
    M matrix = create(3,3);
    M matrix2 = create(2,3);
    M matrix3 ; M matrix4;

    //Ustawiam wartosci macierzy
    matrix.data[0][0]=1;matrix.data[1][0]=4;matrix.data[2][0]=7;
    matrix.data[0][1]=2;matrix.data[1][1]=5;matrix.data[2][1]=8;
    matrix.data[0][2]=3;matrix.data[1][2]=6;matrix.data[2][2]=9;

    matrix2.data[0][0]=9;matrix2.data[1][0]=6;
    matrix2.data[0][1]=8;matrix2.data[1][1]=5;
    matrix2.data[0][2]=7;matrix2.data[1][2]=4;


    //Mnoze macierze (gdy jest spelniony warunek)
    matrix3 = mul(matrix,matrix2);
    //Mnoze macierze (gdy nie jest spelniony warunek)
    matrix4 = mul(matrix2,matrix);

    //Zwalniam pamięć matrix4
    release(matrix4);

    //Sprawdzam wynik mnozenia macierzy (dla spelnionego warunku)
    print(matrix3);

    cout << endl;

    //Uzupelniam macierze dana wartoscia
    fill(matrix, 2);
    fill(matrix2,3);


    //Sprawdzam macierz numer 1
    print(matrix);

    //
    cout << endl ;
    //

    //Sprawdzam macierz numer 2
    print(matrix2);

    //
    cout << endl ;
    //

    //Ustawiam element kolumna 1 wiersz 0 (licze od 0) - wartosc -1
    set(matrix3,1,0,-1);

    //Sprawdzam czy sie zmienilo
    print(matrix3);

    //Dodaje do kazdej wartosci 2
    add(matrix3,2);

    //
    cout << endl;
    //

    //Sprawdzam
    print(matrix3);
    //
    cout << endl ;
    //

    //Sprawdzam porownanie dla falszu
    cout << compare(matrix,matrix3) << endl;

    //Sprawdzam porownanie dla prawdy
    fill(matrix3,1);
    fill(matrix2,1);
    cout << compare(matrix2,matrix3);


    //zwolnienie pamieci
    release(matrix);
    release(matrix2);
    release(matrix3);

    return 0;
}
