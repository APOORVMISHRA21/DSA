//array reversal

#include <bits/stdc++.h>

using namespace std;

void reverse(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
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