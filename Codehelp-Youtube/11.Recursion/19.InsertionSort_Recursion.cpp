/*
    @author: princebansal_
    Types of Sorting algo [GFG]: https://www.geeksforgeeks.org/classification-of-sorting-algorithms/
*/

#include <iostream>
using namespace std;
#define nl "\n"
#define ll long long

int arr[100];

void insertionSort(int arr[], int n)
{
    // base case
    if (n <= 1)
        return;

    // Recursive call for remaining part
    insertionSort(arr, n - 1);

    // solve 1 case: inserting last element to it's correct position

    int key = arr[n - 1];
    int j = n - 2;
    while (j >= 0 and arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    insertionSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << nl;

    return 0;
}