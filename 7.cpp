/*
Consider an array of distinct numbers sorted in increasing order. 
The array has been rotated (clockwise) k number of times. 
Given such an array, find the value of k.
*/


/*


Input : arr[] = {15, 18, 2, 3, 6, 12}
Output: 2
Explanation : Initial array must be {2, 3,
6, 12, 15, 18}. We get the given array after 
rotating the initial array twice.

Input : arr[] = {7, 9, 11, 12, 5}
Output: 4

Input: arr[] = {7, 9, 11, 12, 15};
Output: 0


*/



#include <bits/stdc++.h>
using namespace std;


/*
	Edge case:
		entire array is sorted and not rotated.
*/

int countRotation(int arr[], int n)
{
	int count = 1;

	for (int i = 0; i < n-1; ++i)
	{
		if(arr[i]>arr[i+1])
			return count;
		else
			count++;
	}

	if(count >= n)
		count = 0;

	return count;
}


int main()
{
	int arr[] = {15, 18, 2, 3, 6, 12};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << countRotation(arr, n) << endl;
}