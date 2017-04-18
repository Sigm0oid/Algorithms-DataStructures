#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int>ii;
typedef vector<ii>vii;
typedef  vector<int> vi;
int vis[10010];
int lvl[10010];

vector<vii> Adjlist;
int bfs(int s){
vis[s]=1;
queue<int> q;
q.push(s);
 int x;
while(!q.empty()){
     x=q.front();
    q.pop();
    for(int i=0;i<(int)Adjlist[x].size();i++){
        ii u=Adjlist[x][i];
        if(vis[u.first]==0){
                vis[u.first]=1;
            q.push(u.first);
        }
    }
}
return x;
}
int bfs2(int s){
vis[s]=1;
lvl[s]=1;
queue<int> q;
q.push(s);
 int x;
while(!q.empty()){
     x=q.front();
    q.pop();
    for(int i=0;i<(int)Adjlist[x].size();i++){
        ii u=Adjlist[x][i];
        if(vis[u.first]==0){
                vis[u.first]=1;
            q.push(u.first);
            lvl[u.first]=lvl[x]+1;

        }
//        if(vis[u.first]){
//            lvl[u.first]=max(lvl[u.first],lvl[x]+1);
//
//        }
    }
}
return lvl[x];
}


int main()
{
int t;
cin>>t;
while(t--){
        Adjlist.clear();
      memset(vis,0,sizeof vis);
      memset(lvl,0,sizeof lvl);
    int n;
    cin>>n;
    Adjlist.resize(n);


    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        Adjlist[a-1].push_back(ii(b-1,1));
        Adjlist[b-1].push_back(ii(a-1,1));
    }
    int a=bfs(0);
      memset(vis,0,sizeof vis);

    cout<<n-bfs2(a)<< endl;

}
    return 0;
}
