# AAL

Aby skompilować programy należy użyć:
```
make
```
Aby usunąć pliki testowe należy użyć:
```
make clean
```
## Instrukcja uruchomienia algorytmu
Do uruchomienia programu w trybie manualnym:
```
./main.e
```
Przykład uruchomienia w trybie automatycznym
```
./main.e -m auto -n 10 -c 2 -t 5 -w 1 2 3 4 5 6 7 8 9 10
```

Aby zmierzyć czas wykonania algorytmu należy uruchomić go z następującymi flagami (dane wejściowe pobiera z pliku `filename.txt` oraz zapisuje wynik do pliku `results.csv`)
```
./main.e -m time_test -f filename.txt
```
Ze względu na strukturę programu kolejność parametrów wejściowych jest istotna

## Instrukcja do pojedyńczego uruchomienia

Aby wygenerować testy należy wykonać skrypt gen.sh poleceniem:

	sh gen.sh

gen.sh przyjmuje 2 lub 3 argumenty

argument 1: liczba testów - liczba całkowita

argument 2: rodzaj testu - liczba całkowita

1 - pracownicy przychodza w odstępach większych niż t, a dokładnie co t+1 czasu

2 - w czasie t do kuchni przychodzi maksymalnie m pracowników

3 - w czasie t do kuchni przychodzi m+10 pracowników

4 - test maksymalny

5 - test losowy z zadaną liczba pracowników (wymaga podania 3 argumentów)

6 - całkowicie losowy test

argument 3: liczba pracowników, tylko gdy rodzaj testu 5

Przykład:

	sh gen.sh 5 1
	
Wykona 5 testów rodzaju 1

	sh gen.sh 6 5 4
	
Wykona 6 testów rodzaju 5, w każdym teście będzie po 4 pracowników

Aby uruchomić program na testach należy uruchomić skrypt run.sh poleceniem:

	sh run.sh

run.sh przyjmuje 1 argument -> liczbę testów, liczba całkowita

Przykład:

	sh run.sh 10

Program wykona testy dla i od 1 do 10

Wszystkie testy można obejrzeć i zweryfikować poprawność rozwiązania.

test*.in	dane wejściowe i-tego testu

test*.out	dane wyjściowe z programu dla i-tego testu

Do pomiaru czasu polecam użyć funkcji time:

	time sh run.sh X

Pomiar czasu dla X testów

Aby skompilować programy należy użyć:

	make

Aby usunąć pliki testowe należy użyć:

	make clean

-Tomek Trzeciak

## Instrukcja obsługi generatora danych wejściowych `generator.py`

Przykład generowania kombinacji testów dla parametrów
* liczby pracowników ze zbioru [1000, 20000, 500000]
* pojemności mikrofalówki ze zbioru [2, 10, 100]
* czasów podgrzewania ze zbioru [10, 20, 50]
* liczby testów dla jednej kombinacji parametrów: 3
* typu rozkładu momentów przyjścia pracowników: poisson
* parametrów rozkłądu Poissona ze zbioru [3, 4]

jest podany poniżej

```
python generator.py -n 1000 20000 500000 -m 2 10 100 -t 10 20 50 -k 3 -d poisson -l 3 4
```


Szczegóły dotyczące parametrów CLI generatora można wyświetlić za pomocą komendy
```
python generator.py --help
```
