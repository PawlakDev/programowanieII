Zaimplementuj macierz [M] zawierającą pola int rows, int cols i data - będącą dynamicznie alokowaną pamięcią (z wykorzystaniem operatora new) typu int (czyli data ma być wskaźnikiem). Zaimplementuj funkcje:

M create(int cols, int rows); //tworzy macierz o wskazanych wymiarach, alokuje pamięć, ustawia jej wartości na 0 i zwraca ją
M add(M a, int value); // dodaje do wszystkich elementów macierzy wartość value
M mul(M a, M b); //mnożenie macierzy (jeśli to możliwe, w przeciwnym wypadku wypisz na ekranie stosowny komunikat i zwróć macierz o wymiarach 0 ze wskaźnikiem ustawionym na nullptr);;
void set(M a, int col, int row, int value); //ustawia wartość w pozycji [col, row] na value; 
void fill(M a, int value); //ustawia wszystkie pola macierzy na wartość value;
bool compare(M a, M b); //zwraca true, jeśli macierze mają ten sam rozmiar i wszystkie pola o tej samej wartości, false w przeciwnym wypadku.
void release(M a); //zwalnia pamięć struktury i ustawia jej wymiary na 0, 0 i wskaźnik na nullptr
void print(M a); //wyświetla macierz (dobrze jak będą zachowane wymiary)
Rozwiązanie niech zawiera  w funkcji main kod sprawdzający działanie metod na macierzach o wymiarach max 3. Pamiętaj, że niektóre funkcje mogą wywoływać inne. Tych funkcji nie musisz ich dodatkowo testować. 

Niektóre operacje na macierzach mogą być niewykonalne (na przykład add, kiedy a ma wymiary 0, 0). Postaraj się zabezpieczyć przed jak największą ilością takich przypadków.
