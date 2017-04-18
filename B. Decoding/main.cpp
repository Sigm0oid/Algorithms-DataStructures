#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n ;
    int l =n ;
    string s ;
    cin >> s ;
    string ans="" ;
    while (ans.length() != l)
    {
        char a = s[n-1] ;
        n-- ;
        int mid = ans.length()/2 ;
        ans = ans.insert(mid,1,a) ;
    }
    cout << ans << endl ;
}
