#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ii,ii> iiii;
typedef  vector<iiii> vii;
vii ap;
vector<ll> bi;
ll n,r,l;
vector<ll> ai;
vector<ll> pi;
int main()
{
 //   freopen("in.in","r",stdin);
    cin>>n>>l>>r;
    ap.resize(n);
    pi.resize(n);
    ai.resize(n);
    bi.resize(n);
    for(ll i=0;i<n;i++)
    {
    cin>>ai[i];
    ap[i].first.second=ai[i];
    }
    for(ll i=0;i<n;i++)
    {
    cin>>pi[i];
    ap[i].first.first=pi[i];
    ap[i].second.second=i;
    }
    sort(ap.begin(),ap.end());
    ll cmp=l;
    bool ok=true;
    for(ll i=0;i<n;i++){
    ap[i].second.first=cmp;
    if(i==0)
    {
    continue;
    }
    ll old_ci=((ap[i-1].second.first)-(ap[i-1].first.second));
    //cout<<" old "<<old_ci<<endl;
    cmp=old_ci+ap[i].first.second+1;
    if(cmp<l)
    cmp+=(l-cmp);

    if(cmp>r)
    ok=false;
    ap[i].second.first=cmp;
    }


    if(!ok)
    cout<<"-1"<<endl;
    else{
        for(ll i=0;i<n;i++){
            bi[ap[i].second.second]=ap[i].second.first;
        }
        for(ll i=0;i<n;i++){
            cout<<bi[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
