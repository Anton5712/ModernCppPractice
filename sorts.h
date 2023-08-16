#include <iostream>

void BubbleSort(int arr[], size_t length)
{
    while (length != 0)
    {
        size_t maxIndex = 0;
        for(size_t i = 1; i < length; ++i)
        {
            if(arr[i-1] > arr[i]) {
                std::swap(arr[i-1], arr[i]);
                maxIndex = i;
            }            
        }
        length = maxIndex;
    }   
}

void SelectionSort(int arr[], size_t length)
{
    for(size_t i = 0; i < length-1; i++)
    {
        auto minElement = i;
        for(size_t j = i+1; j < length; j++)
        {
            if (arr[minElement] > arr[j])
                minElement = j;
        }

        if (minElement != i)
            std::swap(arr[minElement], arr[i]);
    }
}

void InsertionSort(int arr[], size_t length)
{
    for (size_t i = 1; i < length; i++)
    {
        int sorted = i-1;

        while (sorted > -1 && arr[sorted] > arr[sorted+1]) 
        {
            std::swap(arr[sorted], arr[sorted+1]);
            sorted--;
        }
    }
}

int PartOfSortHoara(int arr[], int left, int right)
{
    int pivot = arr[(left+right)/2];
    while (left <= right) 
    {
        while (arr[left] < pivot) left++;
        while (arr[right] > pivot) right--;
        if (left <= right)
        {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    return left;
}

void QuickSortHoara(int arr[], int start, int end)
{
    if (start >= end )
        return;

    auto rightStart = PartOfSortHoara(arr, start, end);
    QuickSortHoara(arr, start, rightStart-1);
    QuickSortHoara(arr,rightStart, end);
}

void QuickSortHoara(int arr[], size_t length)
{
    QuickSortHoara(arr, 0, length-1);
}

int PartOfSortLomuto(int arr[], int start, int end)
{
    int left = start;
    for (int current = start; current < end; current++)
    {
        if (arr[current] < arr[end]) 
        {
            std::swap(arr[left], arr[current]);
            left++;
        }
    }

    std::swap(arr[left], arr[end]);

    return left;
}

void QuickSortLomuto(int arr[], int start, int end)
{
    if (start >= end)
        return;

    auto rightStart = PartOfSortLomuto(arr, start, end);
    QuickSortLomuto(arr, start, rightStart-1);
    QuickSortLomuto(arr,rightStart+1, end);
}

void QuickSortLomuto(int arr[], size_t length)
{
    QuickSortLomuto(arr, 0, length-1);
}