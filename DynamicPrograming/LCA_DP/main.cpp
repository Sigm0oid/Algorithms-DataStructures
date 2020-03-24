#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
vector<vii > Adjlist;
const int MAX = 5001;
const int LOGMAX = 13;

int P[MAX][LOGMAX], parent[MAX], depth[MAX];
int n;
void dfs(int u,int dep ){

for(int i=0;i<Adjlist[u].size();i++)
if(parent[Adjlist[u][i].first]==-1)
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

//    cout<<"p "<<p<<" q "<<q<<" depth p "<<depth[p]<<" depth q "<<depth[q]<<endl;
//    cout<<"log "<<lg<<endl;

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
int main()
{
    n=8;
    Adjlist.resize(8);
    Adjlist[0].push_back(ii(1,0));
    Adjlist[0].push_back(ii(2,0));
    Adjlist[1].push_back(ii(3,0));
    Adjlist[2].push_back(ii(4,0));
    Adjlist[4].push_back(ii(5,0));
    Adjlist[4].push_back(ii(6,0));
    Adjlist[6].push_back(ii(7,0));
    memset(parent,-1,sizeof parent);
    for(int i=0;i<n;i++)
    if(parent[i]==-1)
    dfs(i,0);
    preprocessing();
    //cout<<LCA(3,2)<<endl;
    for(int i=0;i<n;i++)
    for(int j=0;j<3;j++)
    cout<<" parent i "<<i <<"  at level  "<<(j<<1)<<" is "<<P[i][j<<1]<<endl;

    return 0;
}
