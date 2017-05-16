# ZadanieSemestralneKulki
Zadanie Semestralne Na Programowanie Obiektowe.
Zadanie polegało na stworzeniu implementacji gry w kulki.
W Zadaniu celowo ograniczono użycie strumieni, szablonów oraz kontenerów STL.




Manual
Zadanie, które program ma realizować
Klasyczna gra w kulki według przykładu podanego w serwisie kurnik.pl
Lista opcji do wyboru z krótkim opisem każdej z nich
W głównym menu należy wpisać jedną z możliwości (np. Nowa Gra – ważne są duże litery i odstępy)
w przypadku błędu, program poinformuje użytkownika i powróci do menu wyboru
Nowa Gra –  otwiera kreator tworzenia nowej gry
Wczytaj Gre – otwiera menu wczytywania gry z pliku
Lista – wyświetla listę wyników (o ile istnieje, jeśli nie – podaje komunikat o braku jej istnienia lub że 	jest pusta, jeżeli jest rzeczywiście pusta)
Zasady – wyświetla zasady gry w kulki
Koniec – zamyka program.
Nietypowe zachowania programu
Nie stwierdzono.
Niezgodności z założeniami przekazanymi w treści zadania 
Nie stwierdzono.
Składnia danych wejściowych i wyjściowych 
Struktura plików, typy danych przechowywane w poszczególnych polach pliku
Plik „listawynikow.txt”
Zawiera listę wyników dotychczas rozegranych gier w formacie 
„imięgracza liczbapunktow”. Tworzony (w przypadku braku istnienia) pod koniec pierwszej ukończonej gry.
Domyślnie umieszczany w katalogu D:\.
plik z zapisem gry
Tworzony w przypadku stworzenia nowej gry (lub dostarczany z zewnątrz)
Począwszy od pierwszego wiersza do wiersza numer 11 włącznie zawiera mapę będącą odwzorowaniem pola Mapa klasy Gracz. Składa się ze znaków 'H' na każdej z krawędzi Mapy, oraz znaków ' ' - jeśli dane jest puste, lub numerowi od 1 do 7 będącym odniesieniem do koloru kulki.
Poniżej znajduję się liczba punktów a jeszcze poniżej nazwa gracza (cała linijka)
Struktura katalogów niezbędna dla poprawnego działania programu
Plik „kulki2.exe” będącym programem. Pozostałe pliki („listawynikow.txt” oraz ewentualne zapisy gry) nie są konieczne do poprawnego działania programu. (Uwaga. Ze względu na specyfikę projektu wymagane jest posiadanie pewnych zainstalowanych bibliotek uruchomieniowych oraz woluminu D:\)
Opis kodu
Lista plików z kodem źródłowym wchodzących w skład programu
„grcz.h” oraz „grcz.cpp”;
„klk.h” oraz „klk.cpp”;
„Lbrnt.h” oraz „Lbrnt.cpp”;
„plnsz.h” oraz „plnsz.cpp”;
Source.cpp;
