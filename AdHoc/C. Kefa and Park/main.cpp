#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vii> Adjlist;
vi dis,vis,cat,catint,maxcat,parent;
int m,n,res=0,maxdis=0;

void dfs(int src,int maxdis){
vis[src]=1;
dis[src]=0;


    for(int i=0;i<Adjlist[src].size();i++){
        int v=Adjlist[src][i].first;
        if(vis[v]==0){
            vis[v]=1;
            dis[v]=dis[src]+1;
            if(catint[v]==0){
                    maxdis=max(maxdis,cat[src]);

            }
            else{
                cat[v]+=cat[src];

            }
            maxcat[v]=max(maxdis,cat[v]);
            dfs(v,maxdis);
            }
}

}

int main()
{
    cin>>n>>m;
    Adjlist.resize(n);
    dis.resize(n);
    vis.resize(n);
    cat.resize(n);
    catint.resize(n);
    parent.resize(n);
    maxcat.resize(n);
    for(int i=0;i<n;i++){
        cin>>cat[i];
        catint[i]=cat[i];
    }
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
    Adjlist[a-1].push_back(ii(b-1,1));
    Adjlist[b-1].push_back(ii(a-1,1));
    parent[b-1]=a-1;

    }
    dfs(0,cat[0]);
    for(int i=1;i<n;i++){
        if(Adjlist[i].size()==1){
            if(maxcat[i]<m+1){
                res++;
            //cout<<"chousen "<<i+1<<endl;
            }
        }
    }
    cout<<res<<endl;


    return 0;
}
