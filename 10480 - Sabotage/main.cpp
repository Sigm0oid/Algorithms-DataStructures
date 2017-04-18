#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vii> Adjlist;
vi p,test,s_comp,t_comp;
int n,m,s=0,t=1,mf,f;
int res[55][55];

bool in_tcomp(int v){
for(int i=0;i<t_comp.size();i++)
if(t_comp[i]==v)
return true;
return false;
}

void augment(int v,int MinEdge){
if(v==s){ f=MinEdge;return;}
else if(p[v]!=-1){
augment(p[v],min(MinEdge,res[p[v]][v]));
res[p[v]][v]-=f;
res[v][p[v]]+=f;

}
}

void edmon_karps(){
mf=0;
while(1){
f=0;
vi dis(n,INT_MAX);queue<int> q;dis[s]=0;q.push(s);
p.assign(n,-1);
while(!q.empty()){

int u=q.front();
q.pop();
if(u==t) break;
for(int i=0;i<Adjlist[u].size();i++){
int v=Adjlist[u][i].first;
if(dis[v]==INT_MAX&&res[u][v]>0){
dis[v]=dis[u]+1;
p[v]=u;
q.push(v);
}
}

}

augment(t,INT_MAX);
if(f==0)break;
mf+=f;

}
}

void dfs(int u){
test[u]=1;

for(int i=0;i<Adjlist[u].size();i++){
if(test[Adjlist[u][i].first]==0&&res[u][Adjlist[u][i].first]>0){
//cout<<Adjlist[u][i].first+1<<"reachble with "<<res[u][Adjlist[u][i].first]<<endl;
dfs(Adjlist[u][i].first);
}
}
}
int main()
{
    freopen("in.in","r",stdin);
    while(cin>>n>>m&&n>0){
    memset(res,0,sizeof res);
    Adjlist.clear();
    Adjlist.resize(n);
    s_comp.clear();
    t_comp.clear();
    for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    res[a-1][b-1]=c;
     res[b-1][a-1]=c;
    Adjlist[a-1].push_back(ii(b-1,c));
     Adjlist[b-1].push_back(ii(a-1,c));
    }
    edmon_karps();
    test.clear();
    test.resize(n);
    dfs(0);
    //cout<<"s comp"<<endl;
    for(int i=0;i<n;i++){
    if(test[i]!=0)
    {
    s_comp.push_back(i);
    //cout<<i<<endl;
    }
    else
    t_comp.push_back(i);

    }
//    cout<<"t comp"<<endl;
//    for(int i=0;i<t_comp.size();i++){
//     cout<<t_comp[i]<<endl;
//    }

    for(int i=0;i<t_comp.size();i++){
    for(int j=0;j<Adjlist[t_comp[i]].size();j++){
    int v=Adjlist[t_comp[i]][j].first;
    if(!in_tcomp(v)){
    cout<<t_comp[i]+1<<" "<<v+1<<endl;}
    }

    }
    cout<<endl;

    }

    return 0;
}
