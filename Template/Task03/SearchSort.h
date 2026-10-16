#pragma once
template <typename T, typename Compare>
void selectionSort(T arr[], int size, Compare compare)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (compare(arr[j], arr[minIndex]))
            {
                minIndex = j;
            }
        }

        T temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

template <typename T, typename Key, typename GetKey>
int linearSearch(T arr[], int size, const Key& key, GetKey getKey)
{
    for (int i = 0; i < size; i++)
    {
        if (getKey(arr[i]) == key)
        {
            return i;
        }
    }

    return -1;
}

template <typename T, typename Key, typename GetKey>
int binarySearch(T arr[], int size, const Key& key, GetKey getKey)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (getKey(arr[mid]) == key)
        {
            return mid;
        }
        else if (getKey(arr[mid]) < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}