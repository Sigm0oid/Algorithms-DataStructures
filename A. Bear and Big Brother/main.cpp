#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll a,b;
    cin>>a>>b;
    ll res=0;
    while(a<=b){
    a*=3;
    b*=2;
    res++;
    }
    cout<<res<<endl;
    return 0;
}
