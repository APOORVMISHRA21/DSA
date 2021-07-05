/*

An array contains both positive and negative numbers in random order. 
Rearrange the array elements so that positive and negative numbers are placed alternatively. 
Number of positive and negative numbers need not be equal. 
If there are more positive numbers they appear at the end of the array. 
If there are more negative numbers, they too appear in the end of the array.

*/

/*

	Example: input  : 	[-1, 2, -3, 4, 5, 6, -7, 8, 9], 
			 output : 	[9, -7, 8, -3, 5, -1, 2, 4, 6]

*/

#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void rearrange(int arr[], int n)
{
	//polarise all negative elements to left of array
	//& all positive elements to the right of array

	int i=-1;

	for(int j=0; j<n; j++)
	{
		if(arr[j]<0)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	int pos = i+1;

	int neg = 0;

	//alternatively inserting positive elements amidst negative elements.

	while(pos<n && neg<pos && arr[neg] < 0)
	{
		swap(&arr[neg], &arr[pos]);

		pos++;
		neg+=2;
	}
}

void printArray(int arr[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout << arr[i] << " ";
	}
}
int main()
{
	int arr[] = {-1, 2, -3, 4, 5, 6, -7, -8, -9};
	int n = sizeof(arr)/sizeof(arr[0]);

	rearrange(arr, n);

	printArray(arr, n);

	return 0;
}