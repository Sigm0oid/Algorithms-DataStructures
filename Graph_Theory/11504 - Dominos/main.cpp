#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
vector<vii> Adjlist ;
vi vis,dfs_num,dfs_low,lvl,tab,sccnum;
ll n,m,t,DfsNumCmp;
vector<vi> res,income;


void TarjanSCC(ll s){
dfs_low[s]=dfs_num[s]=DfsNumCmp++;
vis[s]=1;
tab.push_back(s);
for(ll i=0;i<(ll)Adjlist[s].size();i++){
    ll v=Adjlist[s][i].first;
    if(dfs_num[v]==-1){
        TarjanSCC(v);
    }
    if(vis[v]==1){
        dfs_low[s]=min(dfs_low[s],dfs_low[v]);
    }
}
if(dfs_num[s]==dfs_low[s]){
    vi tmp;
    while(1){

            ll v=tab.back();
           // cout<<"SCC "<<v<<endl;
            tmp.push_back(v);
            vis[v]=0;
            tab.pop_back();
        sccnum[v]=res.size();
        if(s==v) break;
    }
    res.push_back(tmp);
}


}

int main()
{
    //freopen("out.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m;
        Adjlist.clear();
        Adjlist.resize(n);
        dfs_low.clear();
        dfs_low.resize(n);
        dfs_num.clear();
        dfs_num.assign(n,-1);
        vis.clear();
        vis.resize(n);
        lvl.clear();
        lvl.resize(n);
        res.clear();
        income.clear();
        income.resize(n);
        sccnum.clear();
        sccnum.resize(n);
        DfsNumCmp=0;
        for(ll i=0;i<m;i++){
            ll a,b;
            cin>>a>>b;
            Adjlist[a-1].push_back(ii(b-1,1));
            lvl[b-1]++;
            income[b-1].push_back(a-1);
        }
       for(ll i=0;i<n;i++){
        if(dfs_num[i]==-1){
               // cout<<"call "<< i<<endl;
            TarjanSCC(i);
        }
       }
        ll ans=0;
        for(ll i=0;i<res.size();i++){
                bool found =true;
            for(ll j=0;j<res[i].size();j++){
                    for(ll k=0;k<income[res[i][j]].size();k++)
                    {
                        if(sccnum[income[res[i][j]][k]]!=i){

                        found=false;
                    }
                    }



                }

                if(found) ans++;
            }


      cout<<ans<<endl;



    }

    return 0;
}
