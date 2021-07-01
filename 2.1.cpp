// array reversal using recursive approach

#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int start, int end)
{
    if (start >= end)
        return;

    //swap start end

    arr[end] = arr[start] + arr[end];
    arr[start] = arr[end] - arr[start];
    arr[end] = arr[end] - arr[start];

    reverse(arr, start + 1, end - 1);
}

void printArray(int arr[], int n)
{
    int t = 0;
    while (t < n)
    {
        cout << arr[t] << " ";
        t++;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    reverse(arr, 0, n - 1);

    printArray(arr, n);

    return 0;
}