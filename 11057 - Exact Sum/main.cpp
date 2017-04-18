#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
ll n,sum;
ii res;
vector<ll> prices;
void find_best(){
ll minn =LLONG_MAX;
    for(ll i=0;i<n-1;i++){
        for(ll j=i+1;j<n;j++){
            if(abs(prices[i]-prices[j])<minn&&(prices[i]+prices[j]==sum)){
                minn=abs(prices[i]-prices[j]);
                res.first=prices[i];
                res.second=prices[j];
            }
        }
    }

}

int main()
{

    while(cin>>n){


    prices.clear();
    for(int i=0;i<n;i++){
    ll x;
    cin>>x;
    prices.push_back(x);
    }
    cin>>sum;
    find_best();
    if(res.first>res.second)
    swap(res.first,res.second);
    cout<<"Peter should buy books whose prices are "<<res.first<<" and "<<res.second<<"."<<endl<<endl;
    }
    return 0;
}
