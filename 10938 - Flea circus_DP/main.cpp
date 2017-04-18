#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
vector<vii> Adjlist;
const int MAX = 5001;
const int LOGMAX = 13;

int P[MAX][LOGMAX], parent[MAX], depth[MAX];
int n;
void dfs(int u,int dep ){

for(int i=0;i<Adjlist[u].size();i++)
if(parent[Adjlist[u][i].first]==-1&&parent[u]!=Adjlist[u][i].first)
    parent[Adjlist[u][i].first]=u,depth[Adjlist[u][i].first]=depth[u]+1,dfs(Adjlist[u][i].first,dep+1);
}
void preprocessing() // O(nlog(n)) // P[i][j] is 2^j ancestor of i
{
    for(int i=0;i<n;i++){
        for(int j=0;(1<<j)<n;j++)
            P[i][j]=-1;
            P[i][0]=parent[i];

    }
        //bottom up dynamic programing
      for (int j = 1; 1 << j < n; j++)
         for (int i = 0; i < n; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];


}

int LCA (int q,int p){
    if(depth[p]<depth[q])
    swap(p,q);
    int lg;
    for ( lg = 1; 1 << lg <= depth[p]; lg++)
    ;
    lg--;


    for(int i=lg;i>=0;i--)
    {
    if (depth[p] - (1 << i) >= depth[q])
			p = P[p][i];
    }
    if (p == q)
		return p; //one of them parent of another

		for (int i = lg; i >= 0; i--) //we compute LCA(p, q) using the values in P
		if (P[p][i] != -1 && P[p][i] != P[q][i])
			p = P[p][i], q = P[q][i];

	return parent[p];


}
int shortestPath( int p, int q) {
	return depth[p]+depth[q]-2*depth[LCA(p, q)]+1;
}
int getparent(int a,int dis){
if(dis==0)
return a+1;
return getparent(parent[a],dis-1);

}

int main()
{
    while(cin>>n&&n>0){
    Adjlist.clear();
    Adjlist.resize(n);
    for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    Adjlist[a].push_back(ii(b,1));
    Adjlist[b].push_back(ii(a,1));
    }
    memset(parent,-1,sizeof parent);
    for(int i=0;i<n;i++)
    if(parent[i]==-1){
    dfs(i,0);
    }
    preprocessing();
//   for(int i=0;i<n;i++)
//   cout<<" depth of "<<i<<" is "<<depth[i]<<endl;
    int q;
    cin>>q;
    while(q--){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    int dis=shortestPath(a,b)-1;
    if(depth[a]<depth[b])
    swap(a,b);
    if(dis%2==0)
    cout<<"The fleas meet at "<<getparent(a,dis/2)<<"."<<endl;
    else
    cout<<"The fleas jump forever between "<<getparent(a,dis/2+1)<<" and "<<getparent(a,dis/2)<<"."<<endl;
    }
    }
    return 0;
}
