#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main()
{
    int n ;
    cin >> n ;
    int tab[100003]={0} ;
    int ans =0 ;
    int res = 0 ;
    for (int i=0;i<2*n;i++)
    {
        int x ;
        cin >> x ;
        tab[x]++ ;
        if (tab[x]==1) ans++ ;
        else if (tab[x]==2) ans-- ;
        res=max(ans,res) ;
    }
    cout << res << endl ;
}
