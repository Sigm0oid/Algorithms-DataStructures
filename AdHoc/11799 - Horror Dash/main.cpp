#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T ;
    for (int t=1;t<=T;t++)
    {
        int n ;
        cin >> n ;
        int MAX = 0 ;
        for (int i=0;i<n;i++)
        {
            int x ;
            cin >> x ;
            MAX = max(MAX,x) ;
        }
        cout <<"Case "<<t <<": "<< MAX << endl ;
    }
    return 0;
}
