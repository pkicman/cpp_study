/*
 * main.cpp
 *
 *  Created on: 18-03-2012
 *      Author: User
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "merge_sort.hpp"


using namespace std;

int main(void)
{
	srand((unsigned)time(0));

	int n = 100000;
	int *C;

	C = new int[n];

	for(int i = 0; i < n; i++)
	{
		C[i] = rand();
		cout << C[i] << endl;
	}

	merge_sort(C, n);
cout << endl;
	for(int i = 0; i < n; i++)
	{
		cout << C[i] << endl;
	}
	delete [] C;
	return 0;
}

