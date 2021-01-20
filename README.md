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
