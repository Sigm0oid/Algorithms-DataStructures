#include <bits/stdc++.h>
//j problem
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vi p;
int res[100][100];


int INF=INT_MAX;
vector<vii> Adjlist;
int n,m,s,t,mf,f,monkey_needs;

void augment(int v,int minEdge){

if(v==s){f=minEdge;return;}
else if (p[v]!=-1 ){augment(p[v],min(minEdge,res[p[v]][v]));
                    res[p[v]][v]-=f;res[v][p[v]]+=f;
}
}

bool Edmon_karps(){
 mf=0;
    while(1){
    f=0;
    vi dis(n+9,INF);
    p.clear();
    p.assign(n+9,-1);
    dis[s]=0;queue<int> q;q.push(s);
    while(!q.empty()){
    int u=q.front();
    q.pop();
    if(u==t) break;
    for(int i=0;i<Adjlist[u].size();i++){
    int v=Adjlist[u][i].first;
    if(res[u][v]>0&&dis[v]==INF){
    dis[v]=dis[u]+1;q.push(v);p[v]=u;
    }
    }
    }
    augment(t,INF);
    if(f==0)break;
    mf+=f;
    }
    return (mf>=monkey_needs);
}

int main()
{
if(6&1)
cout<<"not pair";
    return 0;
}
