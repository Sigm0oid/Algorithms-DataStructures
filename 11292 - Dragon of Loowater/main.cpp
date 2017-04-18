#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n,m;
vector<ll> heads;
vector<ll> lengths;
int main()
{
    while(cin>>n>>m&&n>0&&m>0){
    heads.clear();
    lengths.clear();
    ll tmp=n;
    while(tmp--){
    ll x;
    cin>>x;
    heads.push_back(x);
    }
    while(m--){
    ll x;
    cin>>x;
    lengths.push_back(x);
    }
    sort(heads.begin(),heads.end());
    sort(lengths.begin(),lengths.end());
    ll i=0;
    ll j=0;
    ll cmp=0;
    ll cost=0;
    while(i<heads.size()&&j<lengths.size()&&cmp<n){
    //cout<<heads[i]<<" "<<lengths[j]<<" "<<cmp<<endl;
    if(heads[i]<=lengths[j]){
    cost+=lengths[j];
    j++;
    i++;
    cmp++;
    }
    else if(heads[i]>lengths[j]){
    j++;
    }
    }
    if(cmp<n)
    cout<<"Loowater is doomed!"<<endl;
    else
    cout<<cost<<endl;

    }
    return 0;
}
