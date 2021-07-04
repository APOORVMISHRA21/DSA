/*
	For a given sorted and rotated array, find a pair with given sum.
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool findSum(int arr[], int n, int sum)
{
	// pointers to locate elements.
	int low=0, high=0;

	for(int i=0; i<n-1; i++)
	{
		if(arr[i] > arr[i+1])
		{
			low = i+1;
			high = i;
			break;
		}
	}

	// low-> smallest element, high-> largest element

	while(high!=low)
	{
		if(arr[high] + arr[low] == sum)
		{
			return true;
		}

		else if(arr[high] + arr[low] < sum)
		{
			low = (low+1)%n;
		}

		else //arr[high] + arr[low]  > sum
		{
			high = (n+high-1)%n;
		}

	}

	return false;
}

int main()
{
	//sorted and rotated array
	int arr[] = {11, 15, 6, 8, 9, 10};

	//size of array
	int n = sizeof(arr)/sizeof(arr[0]);

	int sum = 36;

	if(findSum(arr, n, sum))
	{
		cout << "TRUE" << endl;
	}
	else
	{
		cout << "FALSE" << endl;
	}

	return 0;
}