#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n ;
    cin >> n ;
    long tab[n] ;
    for (int i=0;i<n;i++)
    {
        cin >> tab[i] ;
    }
    sort(tab,tab+n);
    bool check=false ;
    for (int i=2;i<n;i++)
    {
        if (tab[i-2]+tab[i-1]>tab[i] && tab[i]+tab[i-1]>tab[i-2] && tab[i-2]+tab[i]>tab[i-1])
        {
            check = true ;
            break ;
        }
    }
    if (check== true)
        cout << "YES" << endl ;
    else
        cout << "NO" << endl ;

    return 0 ;
}
