/*
Given an array, only rotation operation is allowed on array. 
We can rotate the array as many times as we want. 
Return the maximum possible summation of i*arr[i].

*/

/*

Input: arr[] = {1, 20, 2, 10}
Output: 72
We can get 72 by rotating array twice.
{2, 10, 1, 20}
20*3 + 1*2 + 10*1 + 2*0 = 72

Input: arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9}
Output: 330
We can get 330 by rotating array 9 times.
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
0*1 + 1*2 + 2*3 ... 9*10 = 330

*/


#include<bits/stdc++.h>
using namespace std;

int findMaxResult(int arr[], int n)
{
	int rotationSum = 0; //store rotated array sum.
	int result = 0; //store max of rotationSum.
	int arrSum = 0; //store array sum.



	//rotation sum initial, without rotating.
	for (int i = 0; i < n; ++i)
	{
		rotationSum += i*arr[i];
		arrSum += arr[i];
	}

	result = rotationSum;

	//rotationSum(j) - rotationSum(j-1) = arrSum - n*arr[n-j];

	//possible number of rotations = n-1;

	for (int j = 1; j < n; j++)
	{
		rotationSum = arrSum - n*arr[n-j] + rotationSum;

		if(result < rotationSum)
			result = rotationSum;
	}

	return result;
}

int main()
{
	int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << findMaxResult(arr, n) << endl;
}

