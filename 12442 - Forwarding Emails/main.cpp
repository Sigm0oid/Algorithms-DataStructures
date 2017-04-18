#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
vector<vii> Adjlist;
vi vis;
vi reach;
ll n;
ll dfs(ll x){
    ll res=1;
    vis[x]=1;
for(ll i=0;i<(ll)Adjlist[x].size();i++){
    ll u=Adjlist[x][i].first;
    if(vis[u]==0){
         res+=dfs(u);

    }
     vis[x]=0;
}

 return reach[x]=res;

}
int main()
{

    freopen("out.out","w",stdout);
    freopen("in.in","r",stdin);

    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int cmp=1;
    while(t--){

        cin>>n;
        Adjlist.clear();
        Adjlist.resize(n);
        vis.clear();
        vis.resize(n);
        reach.clear();

        reach.assign(n,-1);
        for(ll i=0;i<n;i++){
            ll a,b;
            cin>>a>>b;
            Adjlist[a-1].push_back(ii(b-1,1));

        }
      ll ans=0;
      ll indx=0;
      dfs(0);
      for(ll i=0;i<n;i++){
            if(reach[i]==-1){
            dfs(i);

            //cout<<reach[i]<<" ";
            }
             if(ans<reach[i]){
                    ans=reach[i];
                    indx=i+1;

             }
      }






            cout<<"Case "<<cmp<<": "<<indx<<endl;
    cmp++;
    }

    return 0;
}
