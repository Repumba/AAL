### Instrukcja do pojedyńczego uruchomienia

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


# Uruchomienie na wielu instancjach problemu
Do generacji wielu instancji problemu należy użyć pliku *generator.py*. Przykład uruchomienia
```
	python generator.py
```

Po wykonaniu się skryptu (może to zająć kilka minut) wygenerowane zostaną instancje problemu dla różnych kombinacji parametrów wejściowych: 
* liczby pracowników
* pojemności mikrofalówki
* czasu podgrzania się pojedyńczego kawałka pizzy
* typu rozkładu momentów przyjścia pracownik oraz rozkładu prawdopodobieństwa przyjścia pracowników do kuchni
* samych momentów czasowych przyjścia pracowników do kuchni

Uruchomienie algorytmu do przetestowania wszystkich instancji problemu odbywa się w następujący sposób:
```
	python tester.py
```

Rezultat testu wydajności znajduje się w pliku *results.csv*.

 - Anton Masiukevich
