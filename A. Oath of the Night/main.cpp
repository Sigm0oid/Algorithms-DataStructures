#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
vi num;
int main()
{
    ll n;
    cin>>n;
    map<ll,ll> mp;
    ll tmp=n;
    while(n--){
    ll x;
    cin>>x;
    mp[x]++;
    }
    cout<<max((1LL)*0,tmp-(mp.rbegin()->second+mp.begin()->second))<<endl;


    return 0;
}
