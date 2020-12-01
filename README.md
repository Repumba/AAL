Aby wygenerowac testy nalezy wykonac skrypt gen.sh poleceniem:

	sh gen.sh

gen.sh przyjmuje 2 lub 3 argumenty

argument 1: liczba testow - liczba calkowita

argument 2: rodzaj testu - liczba calkowita
1 - pracownicy przychodza w odstepach wiekszych niz t, a dokladnie co t+1 czasu
2 - w czasie t do kuchni przychodzi maksymalnie m pracownikow
3 - w czasie t do kuchni przychodzi m+10 pracownikow
4 - test maksymalny
5 - test losowy z zadana liczba pracownikow (wymaga podania 3 argumentow)
6 - calkowicie losowy test

argument 3: liczba pracownikow, tylko gdy rodzaj testu 5

Przyklad:
	sh gen.sh 5 1
Wykona 5 testow rodzaju 1
	sh gen.sh 6 5 4
Wykona 6 testow rodzaju 5, w kazdym tescie bedzie po 4 pracownikow

Aby uruchomic program na testach nalezy uruchomic skrypt run.sh poleceniem:
	sh run.sh
run.sh przyjmuje 1 argument -> liczbe testow, liczba calkowita

Przyklad:
	sh run.sh 10
Program wykona testy dla i od 1 do 10

Wszystkie testy mozna obejrzec i zweryfikowac poprawnosc rozwiazania.
	test*.in	dane wejsciowe i-tego testu
	test*.out	dane wyjsciowe z programu dla i-tego testu

Do pomiaru czasu polecam uzyc takiej skladni:
	time sh run.sh X
Pomiar czasu dla X testow

Aby skompilowac programy uzyj:
	make
Aby usunac pliki testowe uzyj:
	make clean

-Tomek

