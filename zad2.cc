#include <omp.h>
#include <iostream>
using namespace std;

int main () {

  int c = 0;
  int n_th=omp_get_num_threads();
  // Ponizszy kod to przyklad data race
  // Najpierw go uruchom i poobeserwuj nastepnie
  // tak zmodyfikuj, zeby na ekranie wypisaly sie
  // poprawnie wszystkie wartosci c (od 1 do 10)
  // lub mniej w zaleznosci od liczby watkow
  #pragma omp parallel private(n_th) num_threads(10)
  {
    if(n_th<=10)
    { 
    #pragma omp critical 
        {   
          while(c<=n_th )
                cout << ++c << " " << flush;
        }
    }
    else
    {
      #pragma omp critical 
                cout << ++c << " " << flush;
    }
  }  
  cout<<endl;
}

