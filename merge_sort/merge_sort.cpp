/*
 * merge_sort.cpp
 *
 *  Created on: 18-03-2012
 *      Author: User
 */

#include <iostream>
using namespace std;

void merge_sort(int C[], int n)
{

	int *A, *B;
	int i, j, k;

	if(n > 2)
	{
		int a_s, b_s;
		if((n % 2) == 1)
		{
			a_s = n/2 + 1;
		}
		else
		{
			a_s = n/2;
		}
		b_s = n/2;
		A = new int[a_s];
		B = new int[b_s];

		for(i = 0; i < a_s; i++)
		{
			A[i] = C[i];
		}
		for(i = 0; i < b_s; i++)
		{
			B[i] = C[a_s + i];
		}

		// sort first part of the array
		merge_sort(A, a_s);

		// sort second part of the array
		merge_sort(B, b_s);

		// merge both sorted arrays
		i = 0;
		j = 0;

		for(k = 0; k < n; k++)
		{
			if(i >= a_s)
			{
				C[k] = B[j];
				j++;
			}
			else if(j >= b_s)
			{
				C[k] = A[i];
				i++;
			}
			else
			{
				if(A[i] < B[j])
				{
					C[k] = A[i];
					i++;
				}
				else
				{
					C[k] = B[j];
					j++;
				}
			}
		}
		delete[] A;
		delete[] B;
	}
	else
	{
		int tmp;
		if(n == 2)
		{
			if(C[0] > C[1])
			{
				tmp = C[1];
				C[1] = C[0];
				C[0] = tmp;
			}
		}
	}

}


