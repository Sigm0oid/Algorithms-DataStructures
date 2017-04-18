#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin>>t;
    while(t--){
    ll n,h;
    cin>>n>>h;
    ll g1=n/2;
    ll g2=n-(n/2);
    cout<<"0 "<<(g1*g2*2)*h<<endl;
    }
    return 0;
}
