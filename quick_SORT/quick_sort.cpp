/*
 * quick_sort.cpp
 *
 *  Created on: 01-04-2012
 *      Author: User
 */


#include <iostream>
#include <cmath>
#include "quick_sort.hpp"

using namespace std;

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int quick_sort(int *A, int l, int r)
{
	int p = 0;
	int i_max, i_min, i_median;
	int i_midd = floor((r-l)/2.) + l;
	//cout << l << "\t" << i_midd << "\t" << r << endl;
	i_max = r;
	if(A[l] > A[i_max])
		i_max = l;
	if(A[i_midd] > A[i_max])
		i_max = floor((r-l)/2.);

	i_min = r;
	if(A[l] < A[i_min])
		i_min = l;
	if(A[i_midd] < A[i_min])
		i_min = i_midd;

	i_median = r;
	if(A[i_median] == A[i_max] || A[i_median] == A[i_min])
		i_median = l;
	if(A[i_median] == A[i_max] || A[i_median] == A[i_min])
		i_median = i_midd;

	/*cout<< "min:    " << A[i_min] << endl;
	cout<< "Median: " << A[i_median] << endl;
	cout<< "max:    " << A[i_max] << endl;*/

	int i;
	int comp_number = 0;


	if(r - l > 1)
	{
		comp_number += r - l;
		//std::cout << std::endl;
		i = partition(A, l, r, i_median);

		//std::cout<<"Call 1: "<<l<< " "<<i<<std::endl;
		//comp_number += MAX(0, (i - l - 1));
		comp_number += quick_sort(A, l, MAX(l, i-1));
		//for(int j = 0; j <= r; j++)
			//std::cout<<A[j]<<std::endl;
		//std::cout<<"Call 2: "<<i+1<< " " << r<<std::endl;
		comp_number += quick_sort(A, i + 1, r);
		//comp_number += MAX(0, (r - (i + 1)));
		//for(int j = 0; j <= r; j++)
					//std::cout<<A[j]<<std::endl;
	}
	else if((r - l) == 1)
	{
		comp_number += 1;
		//std::cout<<"BASE CASE" << std::endl;
		if(A[r] < A[l])
		{
			//std::cout << "SWAP!" << std::endl;
			int tmp = A[r];
			A[r] = A[l];
			A[l] = tmp;
		}
	}else
	{
		//std::cout<<"NOTHING"<<std::endl;
	}

	return comp_number;
}


int partition(int *A, int l, int r, int p)
{
	if(p != l)
	{
		// put pivot in the first place of the array
		int tmp = A[l];
		A[l] = A[p];
		A[p] = tmp;
	}
	//std::cout << "l: " << l << "  r: " << r << std::endl;
	//std::cout << "pivot: " << A[l] << std::endl;
	int i = l + 1;
	for(int j = l+1; j <= r; j++)
	{
		//std::cout << A[j] << std::endl;
		if(A[j] < A[l])
		{
			int tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
			i++;
		}
	}
	// put pivot in the rightful place and return its position

	int tmp = A[l];
	A[l] = A[i-1];
	A[i - 1] = tmp;

	//std::cout << "After partitioning: "<<std::endl;
	for(int j = l; j <=r; j++)
	{
		//std::cout << A[j] << std::endl;
	}

	return i-1;
}
