#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> Adjlist;
vi dis;


void bfs(int s){
dis[0]=0;
queue<int> q;
q.push(s);
while(!q.empty()){
int u=q.front();q.pop();
cout<<u<<" visited at level  "<<dis[u]<< endl;
for(int i=0;i<Adjlist[u].size();i++){
int v=Adjlist[u][i].first;
if(dis[v]>dis[u]+1){
dis[v]=dis[u]+1;
q.push(v);
}
}
}

}

int main()
{
    Adjlist.resize(6);
    dis.assign(6,INT_MAX);
    Adjlist[0].push_back(ii(1,1));
    Adjlist[0].push_back(ii(2,1));
    Adjlist[0].push_back(ii(3,1));
    Adjlist[1].push_back(ii(4,1));
    Adjlist[4].push_back(ii(5,1));
    bfs(0);

    return 0;
}
