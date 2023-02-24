Napisz dwie klasy - reprezentującą ucznia oraz klasę w szkole (żeby nie mylić słów klasa i class, klasa szkolna dalej będzie nazwana grupą).

klasa uczeń ma zawierać:
pola:
typu int reprezentujące identyfikator ucznia (unikalny numer na skalę szkolną) - sposób przydzielania identyfikatora będzie podany dalej
typu int reprezentującą ocenę z zachowania (zakres od 1-6)
typu int reprezentującą ilość zdobytych nagród
typu int* - dynamicznie alokowaną tablicę będącą listą uzyskanych ocen (zakres każdej z ocen 1-6)
typu int reprezentującą ilość ocen
metody:
zwracająca float, licząca średnią ocen
prywatną, przyjmującą za argument napis, który będzie zawierał ilość ocen i ich wartości. Metoda ma utworzyć tablicę intów o rozmiarze takim, jaka jest ilość przekazanych ocen i wypełnić ją poprawnymi wartościami. Ponadto funkcja ma ustawić poprawnie pole reprezentujące ilość ocen. 
konstruktory:
bezargumentowy - tablica ustawiona na nullptr, pola typu int na -1
przyjmujący dwa argumenty - int id i napis reprezentujący oceny ucznia [format napisu i jego pochodzenie w dalszej części zadania]. Konstruktor ma wywołać metodę konwertującą napis i jej wynik zapisać jako tablicę ocen.
kopiujący, który skopiuje wszystkie dane, łącznie z zaalokowaną tablicą i przeniesie wszystkie oceny. Kopia ma mieć ten sam identyfikator co oryginał
destruktor
zarządzanie pamięcią

klasa grupa ma zawierać:
prywatne pole statyczne:
reprezentujące następny wolny identyfikator ucznia. Początkowa wartość to 10.
prywatne metody statyczne:
zwracającą int, generującą nowy identyfikator użytkownika. Nowy identyfikator jest pobierany z pola statycznego, które następnie jest zwiększane o 5. (co oznacza, że identyfikatory wygenerowane dla kolejnych uczniów to 10, 15, 20, 25, ...
pola:
30 elementową tablicę wskaźników na uczniów (to są uczniowie w danej grupie, 30 elementów oznacza limit uczniów w grupie).
pole reprezentujące ilość uczniów w grupie
numer grupy
metody
zwracającą void, dodającą nowego ucznia do wskazanej grupy, przyjmującą napis reprezentujący listę ocen.
Metoda ma wywołać utworzyć obiekt ucznia i dodać go do tablicy. Zmodyfikować pole reprezentujące ilość uczniów w grupie. Ma wywołać dwuargumentowy konstruktor ucznia: identyfikator pochodzi z wywołania metody statycznej, a napis z przekazanego argumentu.
(Jeśli grupa jest pełna (ma 30. uczniów) nowy uczeń ma zastąpić tego, który ma najniższą średnią ocen. Jeśli nowy uczeń ma niższą średnią niż wszyscy w grupie nie dostaje się do niej).
konstruktory:
bezargumentowy - uczniowie w tablicy ustawieni na nullptr, ilość uczniów na 0, a pozostałe pola liczbowe ustawione na -1
przyjmujący argument typu int, będący numerem grupy. Uczniowie w tablicy ustawieni na nullptr, a ilość uczniów na 0.
destruktor
zarządzanie pamięcią

W funkcji main:
utwórz tablicę ośmiu grup [będzie reprezentowała dziennik].
każdej grupie nadaj kolejne numery od 1 do 8 wywołując odpowiedni konstruktor.
wczytaj plik uczniowie.txt dostępny na moodle. Każdy wiersz tego pliku zawiera informacje o jednym uczniu w następującej formie:
numer_grupy ocena_z_zachowania ilość_ocen ocena_1 ocena_2 ... ocena_n     ---     gdzie n jest ilością ocen
funkcja std::stoi zamienia tekst złożony z cyfr na liczbę
dla każdego wiersza z pliku:
utwórz ucznia w odpowiedniej grupie (odczytaj ją ze wczytanego tekstu)
ilość uczniów przypisanych do niektórych grup może być większa niż 30!
Przyznaj nagrody uczniom (przyznanie nagrody oznacza zwiększenie licznika zdobytych nagród danemu uczniowi)
O najwyższej średniej ocen w danej grupie (jeśli jest więcej niż jeden uczeń w danej grupie o najwyższej średniej, przydziel nagrodę im wszystkim)
O najwyższej średniej ze wszystkich uczniów (ponownie, w przypadku remisu przydziel nagrodę wszystkim uczniom)
Wszystkim uczniom, którzy mają przynajmniej pięć ocen >=5
Wszystkim uczniom o ocenie z zachowania == 6
Wypisz ilu uczniów dostało nie dostało żadnej nagrody, ilu jedną, ilu dwie itd
Utwórz tablicę 8 uczniów i skopiuj do niej po jednym wybranym uczniu z każdej grupy

Wskazówki:

(pamiętaj, że uczniowie w klasie grupa są przechowywani jako wskaźnik, a do wywołania konstruktora kopiującego potrzebujemy referencji, można zatem wywołać go następująco (przykład dla klasy ABC):
ABC *obj = new ABC();  //utworzenie obiektu
ABC kopia1 = ABC(*obj); //konstruktor kopiujący
ABC kopia2 = *obj;  //konstruktor kopiujący z niejawną konwersją
ABC *kopia3 = new ABC(*obj); //konstruktor kopiując
Podziel zadanie na mniejsze kroki:
przygotuj klasy (kolejność ma znaczenie, w grupie odnosimy się do osoby, zatem osoba musi być napisana pierwsza)
przygotuj pola i funkcje (nawet puste, żeby o żadnej nie zapomnieć)
przejdź do implementacji szczegółów
przetestuj na pojedynczych obiektach czy wszystko dobrze działa (konstruktory, destruktory)
wczytaj plik
przetestuj tworzenie ucznia dla jednego wiersza
wczytaj wszystkich uczniów
dopiero dokończ resztę poleceń
może warto przygotować funkcje pomocnicze
wypisującą informacje o uczniu, grupie, co przyjdzie Ci do głowy (za nadmiarowe funkcje nie będą odejmowane punkty, jeśli będą działać poprawnie, nie będą powodowały wycieków pamięci itp. wręcz zachęcam do ich tworzenia).
do testów być może warto tymczasowo ustalić mniejszy rozmiar grup (na przykład z 30 na 5 osób) żeby sprawdzić czy dobrze działa podmiana uczniów o wyższej średniej.
Pamiętaj o zwalnianiu pamięci. Wszystko co było utworzone za pomocą new musi być usunięte poleceniem delete. Szczególnie zwróć uwagę na przypadki, w których podmieniasz wskaźnik, żeby nie stracić jedynego odnośnika do obiektu.
