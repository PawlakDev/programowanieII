Utwórz klasę reprezentującą samochód (w trakcie podróży) zawierającą pola:

nazwa - string
średnia prędkość w km/h - float
średnie spalanie / 100km - float
aktualna ilość paliwa - float
pozostały do przejechania dystans w km - float
rozmiar bagażnika - int o losowej wartości z zakresu [5; 20], mówi o tym ile rzeczy zmieści się w bagażniku
bagażnik reprezentowany przez dynamicznie zaalokowaną tablicę intów. Rozmiar tablicy jest równy rozmiarowi bagażnika z poprzedniego punktu zadania. Każde pole tej tablicy ustaw na losową wartość z zakresu [0; 10]. Każde pole oznacza wagę jednego przedmiotu w bagażniku. 0 oznacza brak przedmiotu w danym miejscu.
Oraz metody, które mają zrealizować następujące zadania:

Sprawdzić, czy na aktualnej ilości paliwa auto może dojechać do celu oraz zwrócić true jeśli tak, i false jeśli nie
Zwrócić dystans (w kilometrach) jaki może pokonać auto na aktualnej ilości paliwa
Zwrócić w jakim czasie auto dojedzie do celu. Jeśli nie jest to możliwe ze względu na brak paliwa zwróć -1
Sprawdzić, czy w bagażniku jest przynajmniej n wolnych miejsc; n ma zostać przekazane jako parametr metody. Metoda zwraca true jeśli są wolne miejsca i false, jeśli nie.
Obliczyć średnią wagę rzeczy z bagażnika (uwaga, pamiętaj, że wartość 0 oznacza brak przedmiotu w bagażniku!)
Ponadto utwórz konstruktory:

Przyjmujący parametr nazwa - pozostałe zmienne przydziel losowo (zadbaj o poprawność losowych danych, na przykład, żeby wartości nie były ujemne, albo prędkość była > 0).
Bezargumentowy, działający tak jak powyższy, z tą różnicą, że nazwa samochodu ma być ustawiona na "Auto".
Przyjmujący parametry nazwa, średnia prędkość, średnie spalanie, aktualna ilość paliwa, pozostały do przejechania dystans i rozmiar bagażnika.
(jeśli bagażnik będzie miał rozmiar spoza zakresu [5; 20] ustaw go na najbliższą poprawną wartość [np. rozmiar = 3 zostanie ustawiony na 5, rozmiar = 1034 zostanie ustawiony na 20])
Pamiętaj, żeby konstruktory utworzyły bagażnik!

Zwalnianiem pamięci przeznaczonej na bagażnik ma zająć się destruktor.

Nazwy pól i metod są dowolne. Proszę zadbać o to, żeby ich nazwy reprezentowały zadanie, które mają realizować oraz żeby dobrać poprawne typy zmiennych do realizacji zadań.

---

Zaktualizowana treść:

Utwórz funkcję (ale nie metodę klasy!) która przyjmie za argumenty dwa wskaźniki na obiekty klasy samochód i zwróci nazwę samochodu, który jako pierwszy dojedzie do celu. W przypadku remisu zwróć dowolną nazwę samochodu.

---

Zaktualizowana treść:

W funkcji main:

Utwórz tablicę 20-tu wskaźników na samochód.
15 z nich utwórz pierwszym konstruktorem, pozostałe drugim (operator new zwraca wskaźnik)
Dla każdego z samochodów wypisz informacje czy dojedzie do celu
Wybierz parę samochodów, które dojadą do celu i sprawdź, który dojedzie szybciej
Znajdź samochód o 3 pustych miejscach w bagażniku, jeśli nie ma takiego, wypisz stosowną informację, Jeśli jest, wypisz jego średnią wagę bagażu.
Znajdź najszybszy samochód
Znajdź samochód o najmniejszym zasięgu (taki, który może przejechać najkrótszy dystans)
Wypisz samochody, które dojadą do celu w czasie dłuższym niż 1 godzina.
Pamiętaj aby zwolnić pamięć (każdy samochód osobno!)
