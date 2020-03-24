#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector< int > vi;
typedef vector<ii> vii;
vi vis,lvl,tab;
vector<vii> Adjlist;
int n;
int res=0;
void bfs(int x){

vis[x]=1;
lvl[x]=1;
res=max(lvl[x],res);
queue<int> q;
q.push(x);
while(!q.empty()){
        int s=q.front();
        q.pop();

for(int i=0;i<(int)Adjlist[s].size();i++){
    if(vis[Adjlist[s][i].first]==0){
            vis[Adjlist[s][i].first]=1;
            q.push(Adjlist[s][i].first);
            lvl[Adjlist[s][i].first]=lvl[s]+1;
            res=max(res,lvl[s]+1);
    }
}
}


}
int main()
{
    cin>>n;
    Adjlist.resize(n);
    vis.resize(n);
    lvl.resize(n);
    tab.resize(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        tab[i]=x;
         if(x!=-1){
            Adjlist[x-1].push_back(ii(i,1));

         }

    }

    for(int i=0;i<n;i++){
        if(tab[i]==-1){

            bfs(i);

        }
    }

    cout<<res<<endl;

    return 0;
}
