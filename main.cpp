#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int n, m, t;
    vector<int> v;
    cout << "Podaj liczbe pracownikow" << endl;
    cin >> n;
    cout << "Podaj pojemnosc mikrofalowki" << endl;
    cin >> m;
    cout << "Podaj czas podgrzewania kawalka pizzy" << endl;
    cin >> t;
    cout << "Podaj czasy przyjscia pracownikow do kuchni" << endl;
    int* tab = new int[n];
    for(int i=0; i<n; ++i) //w tej tablicy przechowujemy czas przyjscia pracownikow
        cin >> tab[i];
    for(int i=0; i<m; ++i) //w tym wektorze przechowujemy kiedy najwczesniej moze pojawic sie nowy, gotowy kawalek
        v.push_back(t);
    int w=0, i=0, pizza=0; //w,i - indeksy; pizza - ile jest dostepnych kawalkow
    bool block = false; //czy jakis pracownik czeka w kuchni
    vector <int> odp; //czasy, w ktorych pracownicy wyjeli kawalek pizzy z mikorfalowki
    while(i<n){
        /*
        Bedziemy sprawdzac co bedzie szybciej: potencjalnie gotowy kawalek, czy kolejny pracownik przychodzacy
        do kuchni.
        */
        int p;
        if(w >= v.size()){ //sprawdzamy czy istnieje wgl mozemy rozwazac nowe kawalki
            p = INT_MAX; //jest to rownowazne z potencjalnie pelna mikrofalowka
        }
        else
            p = v[w]; //czas, kiedy zyskamy kolejny potencjalnie gotowy kawalek
        /*
        Jesli potencjalnie gotowy kawalek bedzie szybciej niz kolejny pracownik lub
        pracownik siedzi juz w kuchni i czeka na pizze. W momencie p jestesmy w stanie dostraczyc
        nowy kawalek pizzy. Jesli ktos jest w kuchi (block=true), wymuszamy rozwazenie nastepnego
        potencjalnego kawalka.
        */
        if(p <= tab[i] || block) {
            if(block){ //jesli ktos czeka w kuchni to od razu dajemy mu kawalek
                v.push_back(p+t); //po czasie t jestesmy w stanie zaoferowac kolejny kawalek
                odp.push_back(p); //ten pracownik dostal pizze w chwili p
                ++i; //przechodzimy do nastepnego pracownika
                block = false; //zaspokoilismy czekajacego pracownika
            }
            else
                ++pizza; //jesli w kuchni nikt nie czekal, to od tego momentu mozemy zaoferowac 1 kawalek pizzy wiecej
            ++w; //przechodzimy do nastepnego potencjalnego kawalka
        }
        else{ //nikt nie czeka w kuchni, przychodzi pracownika
            if(pizza > 0){ //jesli mozemy dac mu potencjalny kawalek pizzy, to to robimy
                --pizza; //zmniejszamy liczbe potencjalnie gotowych kawalkow
                v.push_back(tab[i]+t); //po czasie t, jestesmy w stanie zaoferowac kolejny kawalek
                odp.push_back(tab[i]); //pracownik dostaje pizze w tej samej chwili, w ktorej przyszedl do kuchni
                ++i; //przechodzimy do nastepnego pracownika
            }
            else
                block = true; //pracownik zostaje w kuchni i czeka na swoja kolej
        }
    }

    if(odp.size() != n){ //kazdy pracownik musi miec czas, kiedy odebral pizze
        cout << "Blad algorytmu" << endl;
        return 0;
    }
    int suma = 0; //zliczanie sumarycznego czasu oczekiwania
    for(int i=0; i<n; ++i)
        suma += odp[i] - tab[i]; //czas_dostania_pizzy - czas_przyjscia_do_kuchni
    cout << suma << endl;
    for(int i=0; i<n; ++i)
        cout << odp[i]-t << " "; //czas_dostania_pizzy - czas podgrzewania kawalka
    cout << endl;

    return 0;
}
