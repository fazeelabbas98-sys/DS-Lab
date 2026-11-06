#include <iostream>
#include <string>
using namespace std;

// Linear Search using template
template <typename T>
int linearSearch(T arr[], T value, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }

    return -1;
}

// Function to print search result
template <typename T>
void printSearchResult(int index, T key)
{
    if (index != -1)
    {
        cout << key << " found at index " << index << endl;
    }
    else
    {
        cout << key << " not found in the array" << endl;
    }
}

int main()
{
    // Test with an integer array of size 5
    int intArray[5] = { 64, 25, 12, 22, 11 };
    int intKey = 12;

    int intIndex = linearSearch(intArray, intKey, 5);
    printSearchResult(intIndex, intKey);

    // Test with a float array of size 4
    float floatArray[4] = { 3.14, 2.71, 1.62, 0.57 };
    float floatKey = 1.62;

    int floatIndex = linearSearch(floatArray, floatKey, 4);
    printSearchResult(floatIndex, floatKey);

    // Test with a string array of size 4
    string stringArray[4] = { "apple", "orange", "banana", "grape" };
    string stringKey = "banana";

    int stringIndex = linearSearch(stringArray, stringKey, 4);
    printSearchResult(stringIndex, stringKey);

    return 0;
}