/*
    @author: princebansal_
    Sheet: https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2/
*/

#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define nl '\n'

void printArr(vector<int>& arr, int n)
{
    cout << "Array is: " << nl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << nl;
}

//-------------------------------------------------------------------
/*
NOTE:
    in main():
        int array can be of max size 10^6
        bool array can be of max size 10^7
        (because in this case memory gets allocted in stack which have limited size of around 8 MB)
    Global: (outside main):
        int array can be of max size 10^7
        bool array can be max size 10^8
        (because in this case memory gets allocted in Data segments which doesn't have limited size,
        hence should declare large sized array globally, till 10^8)
*/

int freq[101]; // global arrays have default value 0
// size is 101 => can store frequencies of values from 0-100

void hashing(vector<int>& v, int n)
{
    for (int i = 0; i < n; i++) {
        freq[v[i]]++;
    }
}

void bruteForceApproach1(vector<int>& v, int n)
{
    vector<int> newArr;
    hashing(v, n);
    for (int i = 0; i < 101; i++) {
        if (freq[i] != 0) {
            newArr.push_back(i);
        }
    }
    int newSize = newArr.size();

    for (int i = 0; i < newSize; i++) {
        v[i] = newArr[i];
    }
    //     or
    // v = newArr;

    printArr(v, newSize);
}

//-----------------------------------------------------------------

void bruteForceApproach2(vector<int>& v, int n)
{
    set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(v[i]);
    }
    int newSize = st.size();

    int index = 0;
    for (int x : st) {
        v[index++] = x;
    }
    printArr(v, newSize);
}

//-----------------------------------------------------------------

void optimalApproach(vector<int> v, int n)
{
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (v[i] != v[j]) {
            i++;
            v[i] = v[j];
        }
    }
    int newSize = i + 1;
    printArr(v, newSize);
}

int main()
{
    vector<int> v { 1, 1, 1, 2, 3, 3, 3, 3, 4, 49 }; // given array will be sorted (non-decreasing)
    int n = v.size();

    // bruteForceApproach1(v, n);
    // bruteForceApproach2(v, n);
    optimalApproach(v, n);

    return 0;
}