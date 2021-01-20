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


## Instrukcja obsługi generatora danych wejściowych `generator.py`

Aby wyświetlić opcje z jakimi można generować rozwiązania należy wpisać 
```
python generator.py --help
```
