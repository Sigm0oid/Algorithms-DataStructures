#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n ;
    cin >> n ;
    int tab[n] ;
    ll cpt=0 ;
    ll deb=1,fin=n ,res=1 ;
    ll sz =n ;
    ll cpt2= 0 ;
    bool check = false ;
    for (ll i=0;i<n;i++)
    {
        cin >> tab[i] ;
        cpt+=tab[i] ;
    }
    if (cpt)
    {
        check = true ;
        cout << "YES" << endl ;
        cout << 1 << endl ;
        cout << deb << " "<< fin << endl ;
    }
    else
    {
        res=2;
        while (n)
        {
            cpt-=tab[n-1] ;
            cpt2+=tab[n-1] ;
            n-- ;
            fin-- ;
            if (cpt && cpt2)
            {
                check = true ;
                cout << "YES" << endl ;
                cout << 2 << endl ;
                cout << deb << " " << fin << endl ;
                cout << fin+1 << " " << sz << endl ;
                break ;
            }
        }
    }
    if (check== false)
    {
        cout << "NO" << endl ;
    }
    return 0;
}
