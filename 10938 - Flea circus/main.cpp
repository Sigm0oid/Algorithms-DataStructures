#include <bits/stdc++.h>
#define N_MAX 5100


using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
vector<vii> Adjlist;
ll n,l;
vi parent,dis,lvl;
void bfs (ll src,ll dist){
dis[src]=0;
queue<ll> q;q.push(src);
while(!q.empty()){
ll u=q.front();q.pop();
if(u==dist)
break;
for(int i=0;i<(int)Adjlist[u].size();i++){
ll v=Adjlist[u][i].first;
if(dis[v]>dis[u]+1){
dis[v]=dis[u]+1;q.push(v);
}
}
}
}

//ll getlvl(ll a){
//    if(parent[a]==-1)
//    return 0;
//    else
//    return 1+getlvl(parent[a]);
//}
ll getparent(ll i,ll d){
if(d>0){
    return getparent(parent[i],d-1);
}
else{
    return i;}
}
    void build_tree(ll r,ll depth){
    lvl[r]=depth;
    for(int i=0;i<Adjlist[r].size();i++ ){
    if(lvl[Adjlist[r][i].first]==-1){
    build_tree(Adjlist[r][i].first,depth+1);
    parent[Adjlist[r][i].first]=r;
    }
    }

    }
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    while(cin>>n&&n>0){
    Adjlist.clear();
    Adjlist.resize(n);
    parent.clear();
    parent.assign(n,-1);
    lvl.clear();
    lvl.assign(n,-1);
    ll n1=(n-1);
    while(n1--){
    ll a,b;
    cin>>a>>b;
    a--;b--;
    Adjlist[a].push_back(ii(b,1));
    Adjlist[b].push_back(ii(a,1));
    //parent[b]=a;

    }
    build_tree(0,0);
    cin>>l;
    while(l--){
        ll a,b,minlvl,maxlvl;
        cin>>a>>b;
        a--;b--;
        dis.clear();
        dis.assign(n,INT_MAX);
        bfs(a,b);

        if(lvl[a]>lvl[b]){
         maxlvl=a;
         minlvl=b;}
        else{
        maxlvl=b;
        minlvl=a;}
         ll d=dis[b];
        if(d%2==0){
        cout<<"The fleas meet at "<<getparent(maxlvl,d/2)+1<<"."<<endl;
        }
        else{
        ll x=getparent(maxlvl,(d/2)+1);
        ll y=getparent(maxlvl,(d/2));

        cout<<"The fleas jump forever between "<<min(x,y)+1<<" and "<<max(x,y)+1<<"."<<endl;
        }


            }

        }

    return 0;
}
