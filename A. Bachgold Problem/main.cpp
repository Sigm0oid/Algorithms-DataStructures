#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n ;
    cin >> n;
    if (n%2==0)
    {
        cout << n/2 << endl ;
        for (int i=0;i<n/2;i++)
        {
            cout << 2 << " " ;
        }
        cout << endl ;
    }
    else
    {
        int a = n-3 ;
        cout << (a/2)+1 << endl ;
        cout << 3 << " " ;
        for (int i=0;i<a/2;i++)
            cout << 2 << " " ;
    }
    cout << endl ;
}

