#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

const int N=201000;
vector<vii> Adjlist(N);
ll vertix[N],res[N];
ll dis[N];
ll depth[N];
ll n;

void dfs(ll s,ll cmp,ll d){

    depth[cmp]=s;
    dis[cmp]=d;

    ll l=lower_bound(dis,dis+cmp,(dis[cmp]-vertix[s]))-dis;
    //cout<<depth[l]<<" for "<<s<<endl;
if(l!=cmp) {
if((l)>0)
res[depth[l-1]]--;
res[depth[cmp-1]]++;
}

    for(auto i:Adjlist[s]){
        ll v=i.first;
        dfs(v,cmp+1,d+i.second);
        res[s]+=res[v];

    }



}

int main()
{
    scanf("%d",&n);


    for(ll i=0;i<n;i++)
    scanf("%d",&vertix[i]);
    for(ll i=0;i<n-1;i++)
    {
        ll p,w;
        scanf("%lld %lld",&p,&w);
        Adjlist[p-1].push_back(ii(i+1,w));
    }
    dis[0]=0;
    dfs(0,0,0);
    for(ll i=0;i<n;i++)
    printf("%lld ",res[i]);
    //printf("\n");

    return 0;
}

