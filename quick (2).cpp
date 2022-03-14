#include <iostream>
#include <chrono>
#include <fstream>
#include <bits/stdc++.h>
#include <random>
using namespace std;
using namespace std::chrono;
ifstream f("quicksort.in");
///QUICK SORT

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
int divizare(int start, int sfarsit)
{

    int pivot = v[start];

    int nr = 0;
    for (int i = start + 1; i <= sfarsit; i++) {
        if (v[i] <= pivot)
            nr++;
    }
    int pivotPoz = start + nr;
    swap(v[pivotPoz], v[start]);

    int i = start, j = sfarsit;

    while (i < pivotPoz && j > pivotPoz) {

        while (v[i] <= pivot) {
            i++;
        }

        while (v[j] > pivot) {
            j--;
        }

        if (i < pivotPoz && j > pivotPoz) {
            swap(v[i++], v[j--]);
        }
    }

    return pivotPoz;
}

void quickSort(int start, int sfarsit)
{

    if (start >= sfarsit)
        return;

    int p = divizare(start, sfarsit);

    // Sortam partea din stanga
    quickSort(start, p - 1);

    // Sortam partea din dreapta
    quickSort(p + 1, sfarsit);
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

        quickSort(0, n - 1);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout<<"Testul"<<" "<<j<<"."<<" "<<"n="<<n<<" "<<"maxim="<<maxim<<" "<<duration.count()<<" microsecunde"<<endl;

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
