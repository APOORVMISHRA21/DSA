// to find if there exists a pair of given sum in a rotated sorted array

#include <bits/stdc++.h>
using namespace std;

bool pairsInSortedRotated(int arr[], int n, int sum)
{
    int index;

    for (index = 1; index < n; index++)
    {
        if (arr[index - 1] > arr[index])
            break;
    }

    //index-->smallest index-1 --> largest

    int minIndex = index % n;
    int maxIndex = (index - 1) % n;

    while (minIndex != maxIndex)
    {
        if (arr[minIndex] + arr[maxIndex] == sum)
            return true;

        if (arr[minIndex] + arr[maxIndex] < sum)
        {
            minIndex = (minIndex + 1) % n;
        }

        if (arr[minIndex] + arr[maxIndex] > sum)
        {
            maxIndex = (maxIndex - 1 + n) % n;
        }
    }

    return false;
}

int main()
{
    int arr[] = {11, 15, 6, 7, 9, 10};
    int sum = 55;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (pairsInSortedRotated(arr, n, sum))
        cout << "True";
    else
        cout << "False";

    return 0;
}