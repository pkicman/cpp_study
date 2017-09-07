/*
 * main.cpp
 *
 *  Created on: 22-04-2012
 *      Author: User
 */
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main()
{
	std::map<int, int> H;
	ifstream t("..\\HashInt.txt");

	int sums[9] = {231552, 234756, 596873, 648219, 726312, 981237, 988331, 1277361, 1283379};
	int score[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int aa;

	while(!t.eof())
	{
		t >> aa;
		H[aa] = aa;
	}

	t.close();

	cout << H.size() << endl;

	map<int, int>::const_iterator itr;
	for(int i = 0; i < 9; i++)
	{
		for(itr = H.begin(); itr != H.end(); itr++)
		{
	//		cout << "Key: " << (*itr).first << " Value: " << (*itr).second << endl;

			if(H.count(sums[i] - (*itr).first)) score[i]++;
		}
	}

	for(int i = 0; i < 9; i++)
	{
		if(score[i] > 0) cout << "1";
		else cout << "0";
	}


	return 0;
}


