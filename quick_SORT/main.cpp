/*
 * main.cpp
 *
 *  Created on: 01-04-2012
 *      Author: User
 */


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "quick_sort.hpp"

using namespace std;

int main()
{
	srand((unsigned)time(0));

	ifstream file;
	file.open("Samples\\QuickSort.txt");
	if(!file.is_open())
	{
		cerr << "Could not open file" << endl;
		return -1;
	}
	int n = 1000000;
	int *A;
	int i = 0;
	A = new int[n];

	/*for(int j = 0; j < n; j++)
	{
		A[j] = rand();
		cout << A[j] << endl;
	}
cout << endl;*/

	while(!file.eof() && i < n)
	{
		file >> A[i];
		i++;
	}
	file.close();

	cout<< "Comparisons: " << quick_sort(A, 0, i-2) << endl;

	cout << "Final array: " << endl;
	int err = 0;
	for(int j = 0; j < i-2; j++)
	{
		if(A[j] > A[j+1]) err++;
		//cout << A[j] << endl;
	}
cout << i<<endl;
cout << err << endl;
	delete[] A;

	return 0;
}





