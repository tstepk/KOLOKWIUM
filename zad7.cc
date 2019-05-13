#include <omp.h>
#include <iostream>
#include <string>
using namespace std;

int main () {

string buf;
char c = 'a';
omp_lock_t zmienna;
omp_init_lock(&zmienna);
// Stworz i zainicjalizuj obiekt typu 
// omp_lock_t
// Nastepnie zabezpiecz za jego pomoca
// operacje w sekcjach, na koniec 
// zwolnij zasoby obiektu omp_lock_t

#pragma omp parallel num_threads(2)
{
    #pragma omp sections nowait
    {
       #pragma omp section
       {
        omp_set_lock(&zmienna);
          buf += c++;
        omp_unset_lock(&zmienna);
        omp_set_lock(&zmienna);
          buf += c++;
        omp_unset_lock(&zmienna);
       }

       #pragma omp section
       {
        omp_set_lock(&zmienna);
          buf += c++;
        omp_unset_lock(&zmienna);
        omp_set_lock(&zmienna);
          buf += c++;
        omp_unset_lock(&zmienna);
       }
    }  
}  
omp_destroy_lock(&zmienna);
cout << buf << endl;
// abcd
}
