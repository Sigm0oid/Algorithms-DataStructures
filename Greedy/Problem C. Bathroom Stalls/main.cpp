#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;
ll n,p;

int main()
{
    //   freopen("C-large.in","r",stdin);
    //freopen("out.out","w",stdout);
    ll T;
    cin>>T;
    for(ll t=0;t<T;t++){
    cin>>n>>p;
    priority_queue<ll,vector<ll>,greater<ll>  > pq;
    pq.push(-1*n);
    ll miin,maax;
    while(p--){
    ll tmp=pq.top();
    pq.pop();
    //cout<<tmp<<endl;
    tmp*=(-1);
    tmp--;
    miin=tmp/2;
    maax=tmp-(miin);
    pq.push(-1*miin);
    pq.push(-1*maax);
    }

    cout<<"Case #"<<t+1<<": "<<maax<<" "<<miin<<endl;


    }
    return 0;
}
