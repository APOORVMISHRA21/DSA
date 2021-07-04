/*

	A sorted array is rotated at some unknown point, find the minimum element in it. 
	The following solution assumes that all elements are distinct.

	Efficient approach O(Log n).

*/

/*
Examples: 

Input: {5, 6, 1, 2, 3, 4}
Output: 1

Input: {1, 2, 3, 4}
Output: 1

Input: {2, 1}
Output: 1

*/

#include <bits/stdc++.h>
using namespace std;

int findMin(int arr[], int low, int high)
{
	//	edge case
	if(low > high)
		return arr[0];

	//	only one element
	if(low == high)
		return arr[low];

	int mid = low + (high-low)/2;

	if(mid < high && arr[mid] > arr[mid+1])
		return arr[mid+1];

	if(mid > low && arr[mid-1] > arr[mid])
		return arr[mid];

	if(arr[mid] > arr[high])
		return findMin(arr, mid+1, high);

	return findMin(arr, 0, mid-1);
}

int main()
{
	int arr[] = {5, 6, 1, 2, 3, 4};

	int n = sizeof(arr)/sizeof(arr[0]);

	cout << findMin(arr, 0, n-1) << endl;
}
