#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
vector<vii> Adjlist;
vector<ll> colors;
vector<ll> parents;
ll global_max=0;
void bfs(ll u){
colors[0]=1;
queue<ii> q;
q.push(ii(0,1));
    while(!q.empty()){
   // cout<<" cc"<<endl;
    ii u=q.front();
    q.pop();
    set<ll> used;
    used.insert(u.second);
    if(u.first!=0)
    used.insert(colors[parents[u.first]]);
    ll k=1;
        for(ll i=0;i<Adjlist[u.first].size();i++){
            ll v=Adjlist[u.first][i].first;
                if(colors[v]==0){

                    while(used.find(k)!=used.end())
                    k++;
                    used.insert(k);
                    colors[v]=k;
                    global_max=max(global_max,k);
                    q.push(ii(v,colors[v]));
                    parents[v]=u.first;
                }

            }

    }
}
int main()
{
    ll n;
    cin>>n;
    Adjlist.resize(n);
    colors.resize(n);
    parents.resize(n);
    for(int i=0;i<(n-1);i++) {
    ll a,b;
    cin>>a>>b;
    a--;
    b--;
    Adjlist[a].push_back(ii(b,1));
    Adjlist[b].push_back(ii(a,1));
    }
    bfs(0);
    cout<<global_max<<endl;
    for(ll i=0;i<n;i++)
        cout<<colors[i]<<" ";
        cout<<endl;



    return 0;
}
