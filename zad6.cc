#include <omp.h>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void fun( int t ) {
  this_thread::sleep_for(chrono::seconds(t));
}

// Ponizszy program wykonuje sie w czasie nieco ponad 21 sekundy.
// Przepisz go tak, zeby za pomoca konstrukcji typu zadanie (task)
// wykonywal sie niewiele dluzej niz 6 sekund, zakladajac ze mamy
// do wykorzystania szesc lub wiecej watkow

int main () {
	#pragma omp parallel num_threads(6)
{	
	#pragma omp single
{
	#pragma omp task
           fun(1); 
	#pragma omp task
           fun(2);
	#pragma omp task 
           fun(3);
    #pragma omp task 
           fun(4);
    #pragma omp task  
           fun(5);
    #pragma omp task  
           fun(6); 
}}
}


