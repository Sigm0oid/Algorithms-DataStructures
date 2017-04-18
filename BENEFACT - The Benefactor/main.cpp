#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef  vector<ii> vii;
typedef vector<ll> vi;
vector<vii>Adjlist;
ll vis[50010];
ll dis [50010];
ll n;



ll bfs(ll x){

int cur=x;
dis[cur]=0;
vis[cur]=1;
queue<ll> q;
q.push(cur);
while(!q.empty()){
cur=q.front();
q.pop();

for(ll i=0;i<(ll)Adjlist[cur].size();i++){
    if(vis[Adjlist[cur][i].first]==0){
       vis[Adjlist[cur][i].first]=1;
        dis[Adjlist[cur][i].first]=dis[cur]+Adjlist[cur][i].second;
        q.push(Adjlist[cur][i].first);

        }

    }
}
return ll(max_element(dis+1,dis+n+1)-dis);

}


ll dfs(int cur){
    vis[cur]=1;
ll mx=0;
for(ll i=0;i<(ll)Adjlist[cur].size();i++){
    if(vis[Adjlist[cur][i].first]==0){
        vis[Adjlist[cur][i].first]=1;
       mx=max(mx,dfs(Adjlist[cur][i].first)+Adjlist[cur][i].second);

    }
}

return mx;
}



int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){

        cin>>n;
        Adjlist.clear();
        Adjlist.resize(n);
        memset(vis,0,sizeof vis);
        memset(dis,0,sizeof dis);
        for(ll i=0;i<n-1;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            Adjlist[a-1].push_back(ii(b-1,c));
            Adjlist[b-1].push_back(ii(a-1,c));
        }


   ll start=bfs(0);
//for(int i=0;i<n;i++){
//    cout<<dis[i]<<" ";
//   }
//
//   cout<<endl;
   memset(vis,0,sizeof vis);
   ll ans=bfs(start);
//   for(int i=0;i<n;i++){
//    cout<<dis[i]<<" ";
//   }
//
//   cout<<endl;
   cout<<dis[ans]<<endl;





    }
    return 0;
}
