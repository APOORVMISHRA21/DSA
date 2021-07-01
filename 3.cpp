// find min and max elements of an array

#include <bits/stdc++.h>
using namespace std;

struct Pair
{
    int min;
    int max;
};

Pair getMinMax(int arr[], int low, int high)
{
    Pair minmax;

    if (low == high)
    {
        minmax.max = arr[0];
        minmax.min = arr[0];
        return minmax;
    }

    if (high == low + 1)
    {
        if (arr[low] <= arr[high])
        {
            minmax.min = arr[low];
            minmax.max = arr[high];
            return minmax;
        }
        else
        {
            minmax.max = arr[low];
            minmax.min = arr[high];
            return minmax;
        }
    }

    int mid = (low + high) / 2;

    Pair pair1 = getMinMax(arr, low, mid);
    Pair pair2 = getMinMax(arr, mid + 1, high);

    if (pair1.min < pair2.min)
    {
        minmax.min = pair1.min;
    }
    else
    {
        minmax.min = pair2.min;
    }

    if (pair1.max > pair2.max)
    {
        minmax.max = pair1.max;
    }
    else
    {
        minmax.max = pair2.max;
    }

    return minmax;
}

int main()
{
    int arr[] = {1000, 11, 445,
                 1, 330, 3000};
    int arr_size = 6;

    Pair minmax = getMinMax(arr, 0, arr_size - 1);

    cout << "nMinimum element is "
         << minmax.min << endl;
    cout << "nMaximum element is "
         << minmax.max;

    return 0;
}