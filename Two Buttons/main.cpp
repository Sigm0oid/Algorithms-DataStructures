#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
int dis[21000];
vector<vii> Adjlist;
int n,m;
void bfs(int s){
dis[s]=0;
queue<int> q;
q.push(s);
while(!q.empty()){

int v=q.front();
//cout<<" visited "<<v<<endl;
q.pop();
if(v==m)
break;
for(int i=0;i<(int)Adjlist[v].size();i++){
    ii p=Adjlist[v][i];
    //cout<<"Adjacent are "<<p.first<<" distance are "<<dis[p.first]<<endl;
    if(dis[p.first]>dis[v]+1){
    dis[p.first]=dis[v]+1;
    q.push(p.first);
    }
}
}
}

int main()
{
    Adjlist.resize(20010);
    memset(dis,10000,sizeof dis);
    for(int i=1;i<10010;i++){
        for(int j=1;j<10010;j++){
                if(j==(i-1)||j==(2*i)){
                Adjlist[i].push_back(ii(j,1));
            }
        }
    }
    cin>>n>>m;
    bfs(n);
    cout<<dis[m]<<endl;
    return 0;
}
