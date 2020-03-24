#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector <int> vi;
vector<vii> Adjlist;
int dfsNumCmp,n,m;
vi vis,dfs_num,dfs_low,tab;
vector<vi> res;

void TarjanSCC(int s){
vis[s]=1;
tab.push_back(s);
dfs_num[s]=dfs_low[s]=dfsNumCmp++;
for(int i=0;i<(int)Adjlist[s].size();i++){
    int v=Adjlist[s][i].first;
    if(dfs_num[v]==-1)
    {
        TarjanSCC(v);
    }
    if(vis[v]==1){
        dfs_low[s]=min(dfs_low[s],dfs_low[v]);
    }
}
if(dfs_low[s]==dfs_num[s]){
    vi tmp;
   // cout<<"SCC ";
    while(1){

        int x=tab.back();
        tab.pop_back();
        tmp.push_back(x);
      //  cout<<x<<" ";
        if(s==x){
            break;
        }

    }
    res.push_back(tmp);
}
}

int main()
{
    freopen("out.out","w",stdout);
    while(cin>>n>>m&&(n>0||m>0)){
            dfsNumCmp=0;
        res.clear();
        Adjlist.clear();
        Adjlist.resize(n);
        dfs_low.clear();
        dfs_low.resize(n);
        dfs_num.clear();
        dfs_num.assign(n,-1);
        vis.clear();
        vis.resize(n);
        tab.clear();
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            Adjlist[a-1].push_back(ii(b-1,1));
            if(c>1)
                Adjlist[b-1].push_back(ii(a-1,1));
        }
        for(int i=0;i<n;i++){
            if(dfs_num[i]<0){
                    //cout<<"call on "<<endl;
                    TarjanSCC(i);
            }
        }

        if(res.size()==1&&res[0].size()==n){cout<<1<<endl;}
        else{cout<<0<<endl;}
    }

    return 0;
}
