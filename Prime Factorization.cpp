#include "stdafx.h"
#include <iostream>

using namespace std;

int PrimeFactorization(int destination) {
	
	int itr = 1;
	long n = 1;
	long holder = n;

	while (itr != destination) {

		holder++;
		n = holder;

		while (n % 2 == 0) {
			// 2 is a factor
			n = n / 2;
		}

		while (n % 3 == 0) {
			// 3 is a factor
			n = n / 3;
		}

		while (n % 5 == 0) {
			// 5 is a factor
			n = n / 5; 
		}

		if (n == 1) {
			itr++;
		}
	}
	return holder;
}

int main()
{
	cout << PrimeFactorization(1500) << endl;
	system("pause");
}