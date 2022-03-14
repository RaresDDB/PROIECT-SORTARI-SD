#include <iostream>
#include <math.h>
#include <chrono>
#include <fstream>
#include <bits/stdc++.h>
#include <random>
using namespace std;
using namespace std::chrono;
ifstream f("countsort.in");

///COUNTING SORT

int v[100000000],output[100000000],numarare[100000000];

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


void countSort(int n) {



  int maxim = v[0];

  for (int i = 1; i < n; i++) {
    if (v[i] > maxim)
      maxim = v[i];
  }

  for (int i = 0; i <= maxim; ++i) {
    numarare[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    numarare[v[i]]++;
  }

  for (int i = 1; i <= maxim; i++) {
    numarare[i] += numarare[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    output[numarare[v[i]] - 1] = v[i];
    numarare[v[i]]--;
  }

  for (int i = 0; i < n; i++) {
    v[i] = output[i];
  }
}

int main() {


    long long int n, maxim,nrteste,j;

    f>>nrteste;

    for(j=1;j<=nrteste;j++) {

        f>>n>>maxim;

        for(int i=0;i<n;i++)
            v[i]=rand()%maxim;

        auto start = high_resolution_clock::now();

        countSort(n);

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
