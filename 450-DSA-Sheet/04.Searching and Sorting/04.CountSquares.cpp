#include <bits/stdc++.h>
using namespace std;

int countSquares(int N)
{

    int count = 0;
    long long i = 1;
    while (i * i < N) {
        count++;
        i++;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    cout << countSquares(n);

    return 0;
}