#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
ll n ,k;
vector<ll> before,after;
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    before.push_back(a);
    }

    ///queue
    priority_queue<iii,vector<iii> ,greater<iii> > pq;
    for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    after.push_back(a);
    pq.push(iii(-1*(after[i]-before[i]),ii(before[i],after[i])));
    }
    ll res=0;
    while(!pq.empty()){
    iii u=pq.top();
    pq.pop();
    if(k>0){
    res+=u.second.first;
    k--;
    }
    else
    res+=min(u.second.first,u.second.second);
    }
    cout<<res<<endl;
    return 0;
}
