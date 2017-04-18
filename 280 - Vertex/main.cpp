#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int n;
vector<vii> Adjlist;
vector<int> vis;
void dfs(int u){


for(int i=0;i<Adjlist[u].size();i++){
    if(vis[Adjlist[u][i].first]==0){
    vis[Adjlist[u][i].first]=1;
    dfs(Adjlist[u][i].first);

    }
}


}
int main()
{
    freopen("out.txt","w",stdout);
    while(cin>>n&&n!=0){
    Adjlist.clear();
    Adjlist.resize(n);


    int src;
    while(cin>>src&&src!=0){
        int dist;
        while (cin>>dist&&dist!=0){

            Adjlist[src-1].push_back(ii(dist-1,1));
        }
    }
    int vertix_nb;
    cin>>vertix_nb;
        for(int i=0;i<vertix_nb;i++){
            int vertix;
            cin>>vertix;

             vis.assign(n,0);
             dfs(vertix-1);
             set<int> res;
             int cmp=0;
             for(int j=0;j<n;j++){
                if(vis[j]==0)
                {
                    res.insert(j+1);
                    cmp++;
                }
             }
             cout<<cmp;
             for(auto j=res.begin();j!=res.end();j++){
             cout<<" "<<*j;

             }
             cout<<endl;
        }


    }
    return 0;
}
