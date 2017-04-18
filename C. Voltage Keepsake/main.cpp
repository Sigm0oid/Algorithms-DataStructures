#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<double,ll> ii;
ll n,p;
vector<ll> ai,bi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>p;
    ai.resize(n);
    bi.resize(n);
    ll fastest=0;

    bool found=0;
    priority_queue<ii,vector<ii>,greater<ii> > pq;
    for(ll i=0;i<n;i++){
    cin>>ai[i]>>bi[i];
    double to_finish=(bi[i]/(1.0*ai[i]));

            pq.push(ii(to_finish,i));
        }
    double cmp=0.000;
    bool ok=true;
    while(ok){
    ii u=pq.top();
    pq.pop();
    if(u.first<=cmp)
    break;


    u.first+=(0.0001*p);
     pq.push(u);
    cmp+=0.0001;
    }
    cout<<cmp<<endl;

    return 0;
}
