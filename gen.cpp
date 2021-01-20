#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 2){
        cout << "Zla liczba arguemntow" << endl;
        return 0;
    }
    srand(time(0));
    int choice = atoi(argv[1]);
    if(choice == 1){ //procownicy przychodza do kuchni w odstepach wiekszych niz t, a dokladnie co t+1
        int n, m, t, p;
        n = rand()% 1000000 +1;
        m = rand()%n +1;
        t = rand()%999 +1;
        int k = t+1;
        p=k;
        cout << n << " " << m << " " << t << endl;
        for(int i=0; i<n; ++i){
            cout << p << " ";
            p+=k;
        }
        cout << endl;
        return 0;
    }
    if(choice == 2){ //w czasie t przychodzi do kuchni maksymalnie m pracownikow
        int n, m, t, p;
        do{
            n = rand()% 1000000 +1;
            m = rand()%n +1;
            t = rand()%999 +1;
        }while(t<m); //potencjalnie bardzo dluga petla, ale male ryzyko wiecznego zapetlenia
        p = 1;
        cout << n << " " << m << " " << t << endl;
        for(int i=0; i<n; ++i){
            int z = rand()%m + 1;
            for(int j=0; j<z && i<n; ++j, ++i){
                cout << p << " ";
                p += 1;
            }
            p += t+1;
        }
        cout << endl;
        return 0;
    }
    if(choice == 3){ //w czasie t do kuchni przychodzi m+10 pracownikow
        int n, m, t, p;
        do{
            n = rand()%1000000 +1;
            m = rand()%n +1;
            t = rand()%999 +1;
        }while(t < m+10); //potencjalnie bardzo dluga petla, ale male ryzyko wiecznego zapetlenia
        //test skonstruowany tak, zeby bylo 10 pracownikow nadwyzkowych
        p = 1;
        cout << n << " " << m << " " << t << endl;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m+10 && i<n; ++j, ++i){
                cout << p << " ";
                p += 1;
            }
            p += t+1;
        }
        cout << endl;
        return 0;
    }
    if(choice == 4){ //test maksymalny
        int n=1000000, m=1, t=1000000;
        cout << n << " " << m << " " << t << endl;
        int p = 1;
        for(int i=0; i<n-1; ++i){
            cout << p << " ";
            p += rand()%10+1;
        }
        p = 1000000;
        cout << p << endl;
        return 0;
    }
    if(choice == 5 || choice == 6){
        int n;
        if(choice == 5){ //test calkowicie losowy o zadanej liczbie pracownikow
            if(argc < 3 ){
                cout << "Zla liczba arguemntow" << endl;
                return 0;
            }
            n=atoi(argv[2]);
        }
        else //choice==6, test calkowicie losowy
            n = rand()%1000000+1;

        int m = rand()%n + 1;
        int t = rand()%1000000 +1;
        cout << n << " " << m << " " << t << endl;
        int* tab = new int[1000000];
        for(int i=0; i<1000000; ++i)
            tab[i] = i+1;
        int w = 1000000;
        int* o = new int[n];
        for(int i=0; i<n; ++i){
            int p = rand()%w;
            o[i] = tab[p];
            tab[p] = tab[w--];
        }
        sort(o, o+n);
        for(int i=0; i<n; ++i)
            cout << o[i] << " ";
        cout << endl;
    }
    return 0;
}
