#include <bits/stdc++.h>
#define N_MAX 100000
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vii> Adjlist;
int idx,destination;
vi dis,lvl,parent;
int H[N_MAX];
int sz[N_MAX];
int E[2*N_MAX];
int L[2*N_MAX];
int distination,n,m;

int RMQ(int i,int j){
    int x=H[i];
    int y=H[j];
    int minn=min(x,y);
    int maxx=max(x,y);
    int minlvl=minn;
    for(int k=minn;k<=maxx;k++){
    if(L[k]<L[minlvl]){
    minlvl=k;
    }
    }
  return E[minlvl];

}
int getparent(int i,int d){
if(d>0){
    return getparent(parent[i],d-1);
}
else{
    return i;}
}

void dfs(int cur,int depth){
    sz[cur]=1;
    H[cur]=idx;
    E[idx]=cur;
    L[idx++]=depth;
        for(int i=0;i<Adjlist[cur].size();i++){
            int v=Adjlist[cur][i].first;
            if(v==parent[cur])
            continue;
            dfs(v,depth+1);
            sz[cur]+=sz[v];
            E[idx]=cur;
            L[idx++]=depth;
        }
}
void buildRMQ(){
    idx=0;
    memset(H,-1,sizeof H);
    dfs(0,0);
}


void bfs(int s){
dis[s]=0;
queue<int> q;q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
//        if(u==destination)
//        break;
        for(int i=0;i<(int)Adjlist[u].size();i++){
            int v=Adjlist[u][i].first;
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;q.push(v);
                }
            }
        }


}
 void build_tree(int r,int depth){
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
   scanf("%d",&n);
    Adjlist.resize(n);
    dis.assign(n,INT_MAX);
    lvl.assign(n,-1);
    parent.assign(n,-1);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        a--;b--;
        Adjlist[a].push_back(ii(b,1));
        Adjlist[b].push_back(ii(a,1));
    }
    build_tree(0,0);
    memset(sz,0,sizeof sz);
    buildRMQ();

    scanf("%d",&m);
    for(int i=0;i<m;i++){
        dis.clear();
        int a,b,minlvl,maxlvl;
        scanf("%d %d",&a,&b);
        a--;b--;
        dis.clear();
        dis.assign(n,INT_MAX);
        bfs(a);
        destination=b;
        if(lvl[a]>lvl[b]){
         maxlvl=a;
         minlvl=b;}
        else{
        maxlvl=b;
        minlvl=a;}
        int d=dis[b];
        if(d&1){
        printf("0\n");}
        else if (a==b){
        printf("%d \n",n);
        }
        else{
            if(lvl[a]==lvl[b])
            {
                int l=RMQ(a,b);
                int A=getparent(a,lvl[a]-lvl[l]-1);
                int B=getparent(b,lvl[b]-lvl[l]-1);
//                cout<<A<<" and "<<B<<" lca "<<l<<endl;
               printf("%d \n",(n-sz[A]-sz[B]));
}
            else{
            int x=getparent(maxlvl,(d/2));
            int y=getparent(maxlvl,(d/2)-1);
           printf("%d \n",(sz[x]-sz[y]));
            //<<" "<<sz[x]<<" "<<sz[y]<<
            }
        }

    }
    return 0;
}
