#include <iostream>
#include <chrono>
#include <fstream>
#include <bits/stdc++.h>
#include <random>
using namespace std;
using namespace std::chrono;
ifstream f("mergesort1.in");
///MERGE SORT

int v[100000000],temp[100000000];

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

void Merge(int a, int b, int c)
{
	int i, j, k;
	i = a;
	k = 0;
	j = c + 1;

	while (i <= c && j <= b)
	{
		if (v[i] < v[j])
		{
			temp[k] = v[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = v[j];
			k++;
			j++;
		}
	}

	while (i <= c)
	{
		temp[k] = v[i];
		k++;
		i++;
	}

	while (j <= b)
	{
		temp[k] = v[j];
		k++;
		j++;
	}

	for (i = a; i <= b; i++)
	{
		v[i] = temp[i-a];
	}
}

void MergeSort(int a, int b)
{
	int c;
	if (a < b)
	{
		c=(a+b)/2;

		MergeSort(a,c);
		MergeSort(c+1,b);

		Merge(a,b,c);
	}
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

        MergeSort(0, n - 1);

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

    return
