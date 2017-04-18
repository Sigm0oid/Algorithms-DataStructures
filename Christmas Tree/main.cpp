#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vi dis;
vector<vii> Adjlist;
ll n,q,idx;
vi vis;
int l[200000],e[200000],h[100000];
void dfs(ll cur,ll depth){

    cout<<"call"<<endl;
    h[cur]=idx;
e[idx]=cur;
l[idx++]=depth;
for(ll i=0;i<(ll)Adjlist[cur].size();i++){
    if(vis[Adjlist[cur][i].first]==0){
            vis[cur]=1;
    dfs(Adjlist[cur][i].first,depth+1);
    e[idx]=cur;
    l[idx++]=depth;
    }
}
}


int main()
{
    int t;
    cin>>t;
    while(t--){
            cin>>n;
        Adjlist.clear();
        Adjlist.resize(n);
        vis.clear();
        vis.resize(n);
        for(ll i=0;i<n-1;i++){

        ll a,b;
        cin>>a>>b;
        Adjlist[min(a,b)].push_back(ii(max(a,b),1))    ;
        Adjlist[b].push_back(ii(a,1))    ;
        }
        idx=0;
        memset(h,-1,sizeof h);
        vis[0]=1;
        dfs(0,0);
        for(int i=0;i<2*n;i++){
            cout<<h[i]<<" "<<endl;
        }
            //cin>>q;
//            int a=h[1];
//            int b=h[5];




    }
    return 0;
}
