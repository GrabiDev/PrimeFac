/**
    PrimeFac
    version: 1.0.2
    author: Matt Grabara
    date: 23/02/2012

    This program implements, verifies correctness and proves invalidity of Goldbach Conjecture
    proof proposed by James Constant. For each provided number, algorithm determines factors
    and verifies whether they are prime numbers and they are indeed factors of the provided
    integer.

    Can be used to verify method using mathematical induction.

    Original article by James Constant:  http://coolissues.com/mathematics/Goldbach/goldbach.htm
**/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <limits>

using namespace std;

// easily check if provided number is a prime number
bool isPrime(int a) {
	for (int i=2; i<a; ++i) if (a%i==0) return false;
	return true;
}

// generate condition value for later while loop
bool compare(double a, int b) {
	if (a==b) return true;
	else return false;
}

// iterate 
void iterate(int &s2) {
	++s2;
	while (!compare(sqrt(s2), sqrt(s2))) ++s2;
}

int main()
{
    cout << "PrimeFac v. 1.0.2\n";
    beginning:
    cout << "\nType number to be presented as a product of two primes: ";
	int s2, p, c2, c;

    // no exception handling
    // for the purpose of the paper it is assumed input will be always an integer
    cin >> p;

    // use algorithm to generate s^2 and c
    cin.ignore();
	bool condition=false;
	s2=4*p;
	if (!compare(sqrt(s2), sqrt(s2))) iterate(s2);
	while (!condition) {
		again:
        	while(s2%2!=0) iterate(s2);
        	c2=s2-(4*p);
        	c=sqrt(c2);
        	if (c%2!=0) {iterate(s2); goto again;}
        	else condition=true;
    }

    // compute a and b
    int a, b;
    a=0.5*(sqrt(s2)-c);
    b=0.5*(sqrt(s2)+c);
    cout << "a= " << a << "\nb= " << b << '\n';

    // check if factors are prime
    if (!isPrime(a) || !isPrime(b)) cout << "\na or b are not primes (ERROR! - ALGORITHM FAILED)\n";
    if (a*b!=p) cout << "\nproduct of the generated numbers does not equal provided number (ERROR! - ALGORITHM FAILED)\n";
    
    // ask if user wants to quit or try again
    cout << "\n\nDo you want to quit? Y - yes, N - no: ";
    char z;
    while (z!='Y' && z!='N' && z!='y' && z!='n') {
        string decision;
        cin >> decision;
        cin.ignore();
        z=decision[0];
        if (z=='Y' || z=='y') return 0;
        else if (z=='N' || z=='n') goto beginning;
        else cout << "Input incorrect, try again: ";
    }
    
    return 0;
}
