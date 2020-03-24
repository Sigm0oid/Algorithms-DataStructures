#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int>ii;
typedef vector<ii> vii;
typedef  vector<int> vi;
int INF=INT_MAX;
vector<vii> Adjlist;
vi p;
int s,t,n,m,f,mf;
int res[110][110];
void augment(int v,int minEdge){
if(v==s) {f=minEdge;return;}
else if(p[v]!=-1){
augment(p[v],min(minEdge,res[p[v]][v]));
res[p[v]][v]-=f;res[v][p[v]]+=f;

}
}

int main()
{
freopen("out.out","w",stdout);
int cmp=0;
    while(cin>>n&&n>0){
    cmp++;
    cin>>s>>t>>m;
    s--;t--;
    Adjlist.resize(n);
   // p.resize(n);
    memset(res,0,sizeof res);
    for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    res[a][b]+=c;
    res[b][a]+=c;
    Adjlist[a].push_back(ii(b,c));
    Adjlist[b].push_back(ii(a,c));
    }

    //Edmons Karps
    mf=0;
    while(1){
    f=0;
    bitset<110> vis ;vis[s]=1;queue<int> q;q.push(s);
    p.assign(n,-1);
    while(!q.empty()){
        int u=q.front();q.pop();
        if(u==t)break;
        for(int i =0;i<Adjlist[u].size();i++){
        int v=Adjlist[u][i].first;
        if(!vis[v]&&res[u][v]>0){
        q.push(v);vis[v]=1;p[v]=u;
        }
        }
      }
    augment(t,INF);

    if(f==0)break;
    mf+=f;

    }
    cout<<"Network "<<cmp<<endl<<"The bandwidth is "<<mf<<"."<<endl;



    cout<<endl;}
    return 0;
}
