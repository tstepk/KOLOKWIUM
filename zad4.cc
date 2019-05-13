#include <omp.h>
#include <iostream>
using namespace std;

int main () {

    const int N = 10;
    int i;
    float a[N], b[N], c[N];

    for (i=0; i < N; ++i)
          a[i] = b[i] = i * 1.0;

    // Zrownoleglij wykonanie ponizszej petli
     #pragma omp parallel for num_threads(4)
     for (i=0; i<N; ++i)
     {
           c[i] = a[i] + b[i];
     }


     // Kontrolny wynik
     for (i=0; i<N; ++i)
         cout << "c[" << i << "] = " << c[i] << endl;

}
