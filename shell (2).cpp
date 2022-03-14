#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <bits/stdc++.h>
#include <random>
using namespace std;
using namespace std::chrono;
ifstream f("shellsort.in");
///SHELL SORT

int v[100000000];

void verificare(int n) {
    int OK=1;
    for(int i=0;i<n-1;i++)
        if(v[i]>v[i+1])
           OK=0;
    if(OK==1)
      cout<<"vectorul a fost sortat corect";
    else
       cout<<"vectorul NU a fost sortat corect";
}

int shellSort(int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int aux = v[i];

            int j;
            for (j = i; j >= gap && v[j - gap] > aux; j -= gap)
                v[j] = v[j - gap];
            v[j] = aux;
        }
    }
    return 0;
}


int main()
{

    long long int n, maxim,nrteste,j;

    f>>nrteste;

    for(j=1;j<=nrteste;j++) {

        f>>n>>maxim;

        for(int i=0;i<n;i++)
            v[i]=rand()%maxim;

        auto start = high_resolution_clock::now();

        shellSort(n);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout<<"Testul"<<" "<<j<<"."<<" "<<"n="<<n<<" "<<"maxim="<<maxim<<" "<<duration.count()<<" "<<"microsecunde"<<endl;

        verificare(n);

        cout<<endl;

        auto inceput = high_resolution_clock::now();

        sort(v,v+n);

        auto sfarsit = high_resolution_clock::now();

        auto durata = duration_cast<microseconds>(sfarsit - inceput);

        cout<<"Algoritmul nativ de sortare dureaza "<<durata.count()<<" microsecunde"<<endl;

    }

    return 0;
}
