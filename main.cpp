#include <iostream>
using namespace std;

void insertionSort(int arr[], int low, int high)
{
    for(int i = low + 1; i <= high; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= low && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

int medianOfThree(int arr[], int low, int high)
{
    int mid = (low + high) / 2;

    if(arr[low] > arr[mid])
        swap(arr[low], arr[mid]);

    if(arr[low] > arr[high])
        swap(arr[low], arr[high]);

    if(arr[mid] > arr[high])
        swap(arr[mid], arr[high]);

    swap(arr[mid], arr[high-1]);

    return arr[high-1];
}

void quickSort(int arr[], int low, int high)
{
    if(high - low <= 10)
    {
        insertionSort(arr, low, high);
        return;
    }

    int pivot = medianOfThree(arr, low, high);

    int i = low;
    int j = high - 1;

    while(true)
    {
        while(arr[++i] < pivot);
        while(arr[--j] > pivot);

        if(i < j)
            swap(arr[i], arr[j]);
        else
            break;
    }

    swap(arr[i], arr[high-1]);

    quickSort(arr, low, i-1);
    quickSort(arr, i+1, high);
}

int main()
{
    int arr[] = {8,4,7,3,9,2,6,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n-1);

    for(int i=0;i<n;i++)
        cout << arr[i] << " ";

    return 0;
}