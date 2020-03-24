#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
vector<vii> Adjlist,Adjlist1;
vi dfs_low,dfs_num,parent,vis,ArticulationVertex,cnt;
ll dfsNumberCounter,rootChildren,root,ans;
int sz;

ll countt(int u){
dfs_num[u]=1;
ll r=1;
for(ll i=0;i<(ll)Adjlist1[u].size();i++){
       // cout<<dfs_num[Adjlist1[u][i].first]<<endl;
    if(dfs_num[Adjlist1[u][i].first]==0){
        r+=countt(Adjlist1[u][i].first);
    }

}
return r;
}
void dfs_count(int u,int p ){
    cnt[u]=1;
    for(ll i=0;i<(ll)Adjlist1[u].size();i++){
        ll v=Adjlist1[u][i].first;
        if(v!=p){
            dfs_count(v,u);
            cnt[u]+=cnt[v];
            ans += 1* (sz-cnt[v]) * cnt[v];
            //cout<<"for node "<<v+1<<"size = "<<sz<<"- cnt[v]= "<<cnt[v]<<"* cnt [v] ="<<(sz-cnt[v])*cnt[v]<<endl;

        }
    }
}

void ArticulationBridge(ll src){
dfs_low[src]=dfs_num[src]=dfsNumberCounter++;
for(ll i=0;i<(ll)Adjlist[src].size();i++){
    ll v=Adjlist[src][i].first;
    if(dfs_num[v]==-1){
    parent[v]=src;
    //if(src==root){rootChildren++;}

    ArticulationBridge(v);

    if(dfs_low[v]>dfs_num[src]){
        Adjlist1[v].push_back(ii(src,1));
        Adjlist1[src].push_back(ii(v,1));
        //cout<<"articulation bridge "<<" "<<v<<" "<<src<<endl;
    }
    dfs_low[src]=min(dfs_low[src],dfs_low[v]);

    }
    else{
        if(v!=parent[src]){
            dfs_low[src]=min(dfs_low[src],dfs_num[v]);
        }
    }
}
}



int main(){
    ios_base::sync_with_stdio(false);
   freopen("in.in","r",stdin);
   freopen("out.out","w",stdout);
    int t;
    cin>>t;

    while(t--){
            dfsNumberCounter=rootChildren=root=0;
        ll n,m;
        cin>>n>>m;
        Adjlist1.clear();
        Adjlist.clear();

        Adjlist1.resize(n);
        Adjlist.resize(n);
        dfs_low.clear();
        dfs_low.resize(n);
        dfs_num.clear();
        dfs_num.assign(n,-1);
        parent.clear();
        parent.resize(n);
        ArticulationVertex.clear();
        ArticulationVertex.resize(n);

        vis.clear();
        vis.resize(n);
        ans=0;


        for(ll i=0;i<m;i++){
        ll a,b;

            cin>>a>>b;
          //  if(t==1)
                    //cout<<a<<" "<<b<<endl;

            Adjlist[a-1].push_back(ii(b-1,1));
            Adjlist[b-1].push_back(ii(a-1,1));

        }


        for(ll i=0;i<n;i++){
            if(dfs_num[i]==-1){
                ArticulationBridge(i);
            }


        }


        //ArticulationVertex[root]=(rootChildren>1);
        dfs_num.clear();
        dfs_num.resize(n);
        cnt.clear();
        cnt.resize(n);
            for(ll i=0;i<n;i++){

            if(dfs_num[i]==0){
                    sz=countt(i);
                dfs_count(i,-1);
            }
        }

           cout<<ans<<endl;

    }





    return 0;
}
