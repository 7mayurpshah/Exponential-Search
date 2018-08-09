//algorithm to search the element in sorted array
//#include "stdafx.h"  for microsoft visual studio users
#include <iostream>
#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>


using namespace std;
void search(int[], int, int);
void main()
{
	int arr[16] = { 1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31 };
	int key;
	int pos = 0;
	clock_t begin, end;
	double time_taken;
	cout << "array are as goven below" << endl;
	for (int j = 0; j <= 15; j++)
	{
		cout << "a[ " << j << " ] = " << arr[j] << endl;
	}
	cout << "enter number to search  ";
	cin >> key;
	begin = clock();

	search(arr, key, pos);
	end = clock();
	time_taken = ((double)end - begin) / CLOCKS_PER_SEC;
	cout << "This algorithm took " << time_taken << " seconds" << endl;
	system("pause");
}

void search(int arr[], int key, int pos)
{
	int i = 0, c = 0;
	while (arr[pos] <= key && pos <= 15)
	{
		if (arr[pos] == key)
		{
			cout << "position is " << pos << endl;
			pos++;
			c++;
			break;
		}
		else
		{
			//cout << "position before call is " << pos << endl;
			pos = pos + pow(2, i);
			//cout << "position after call is " << pos << endl;
			//getchar();
			i++;
		}
	}

	i--;

	if (i == 0 && c == 0)
	{
		printf("Element is not present in array");
		getchar();
		exit(0);
	}

	else if (c == 0)
	{
		pos = pos - pow(2, i);
		search(arr, key, pos);
	}
}