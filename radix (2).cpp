#include <iostream>
#include <math.h>
#include <chrono>
#include <fstream>
#include <bits/stdc++.h>
#include <random>
using namespace std;
using namespace std::chrono;
ifstream f("radixsort.in");
///RADIX SORT

int v[100000000],output[100000000];

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

int getMax(int n)
{
    int max = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] > max)
            max = v[i];
    return max;
}


void countSort(int n, int exp)
{
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(v[i] / exp) % 10]++;


    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(v[i] / exp) % 10] - 1] = v[i];
        count[(v[i] / exp) % 10]--;
    }


    for (i = 0; i < n; i++)
        v[i] = output[i];
}


void radixsort(int n)
{

    int m = getMax(n);

    for (int i = 1; m / i > 0; i *= 10)
        countSort(n, i);
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

        radixsort(n);

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
