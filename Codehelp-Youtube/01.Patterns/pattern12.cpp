#include <iostream>
using namespace std;

int main()
{
    /*
        A A A A A
        B B B B B
        C C C C C
        D D D D D
        E E E E E
    */

    int n;
    cin >> n;

    /* ----WAY-1---------------------
        int i = 1;
        int c = 65;
        while (i <= n) {
            int j = 1;
            while (j <= n) {
                cout << (char)c << " ";
                j++;
            }
            c++;
            cout << endl;
            i++;
        }
    ---------------------------------*/

    //-------------WAY-2-------------
    int i = 1;
    while (i <= n) {
        int j = 1;
        while (j <= n) {
            cout << (char)('A' + i - 1) << " ";
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}