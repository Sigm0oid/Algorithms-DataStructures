#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n,s;
list<ii> cycl;
vector<vii> Adjlist;
vi lvl;
vi vis;
void dfs(int u){
vis[u]=1;
for(int i=0;i<Adjlist[u].size();i++){
if(vis[Adjlist[u][i].first]==0){
dfs(Adjlist[u][i].first);
}
}
}

bool isEuler(){
for(int i=0;i<50;i++){
if(lvl[i]%2==1)

return false;

}
return true;
}

void Eulertour(list<ii>::iterator i, int u){
//cout<<u<<endl;
for(int j=0;j<(int)Adjlist[u].size();j++){
ii v=Adjlist[u][j];
if(v.second){
Adjlist[u][j].second=0;
for(int k=0;k<(int)Adjlist[v.first].size();k++){
ii uu=Adjlist[v.first][k];
if(u==uu.first&&uu.second){
Adjlist[v.first][k].second=0;
break;
}
}
Eulertour(cycl.insert(i,ii(v.first+1,u+1)),v.first);
}
}
}
int main()
{

    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    cin>>n;
    cycl.clear();
    Adjlist.clear();
    Adjlist.resize(50);
    lvl.clear();
    lvl.resize(50);
    vis.clear();
    vis.resize(50);
    for(int j=0;j<n;j++){
    int a,b;
    s=a-1;
    cin>>a>>b;
    Adjlist[a-1].push_back(ii(b-1,1));
    Adjlist[b-1].push_back(ii(a-1,1));
    lvl[a-1]++;
    lvl[b-1]++;
    }
    dfs(s);
    bool connected=true;
    for(int o=0;o<50;o++){
    if(vis[o]==0&&lvl[o]>0){
    connected=false;
    break;}
    }

    cout<<"Case #"<<i+1<<endl;
    if(isEuler()==false||connected==false){
    cout<<"some beads may be lost"<<endl;
    }else{
    Eulertour(cycl.begin(),s);
    for(list<ii>::iterator it=cycl.begin();it!=cycl.end();it++){
        printf("%d %d\n",it->first,it->second);
        }
    }
if(i!=t-1)
cout<<endl;
    }
    return 0;
}
