// Array rotation using REVERSAL ALGORITHM

#include <bits/stdc++.h>

using namespace std;

void rev(int arr[], int start, int end)
{
    while (start < end)
    {
        arr[end] = arr[start] + arr[end];
        arr[start] = arr[end] - arr[start];
        arr[end] = arr[end] - arr[start];

        start++;
        end--;
    }
}
void rotate(int arr[], int d, int n)
{
    //rotate = rev(rev(arr, 0, d-1) + rev(arr, d, n-1))

    rev(arr, 0, d - 1);
    rev(arr, d, n - 1);
    rev(arr, 0, n - 1);
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
    int d = 2;

    rotate(arr, d, n);

    printArray(arr, n);

    return 0;
}
