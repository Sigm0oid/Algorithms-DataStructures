#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
vector<vii> Adjlist;
vector<ll> vis;
map<string,ll> ordre;
map<ll,string> rev;
set<ll> res;
ll cmp=1;

void dfs(ll x){
vis[x]=1;
res.insert(x);
for(int i=0;i<Adjlist[x].size();i++){
    ll a=Adjlist[x][i].first;
    if(!vis[a])
    dfs(a);
}

}
int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
    ordre.clear();
    rev.clear();
    Adjlist.clear();
    vis.clear();
    cmp=0;
        ll n,k;
        cin>>n>>k;
        res.clear();
        Adjlist.resize(n);
        vis.resize(n);
        for(ll i=0;i<n;i++){
            string s;
            ll a;
            cin>>s>>a;
            ordre[s]=cmp;
            rev[cmp]=s;
                for(ll j=0;j<a;j++){
                    string str;
                    cin>>str;
                    Adjlist[cmp].push_back(ii(ordre[str],1));
                }
            cmp++;
        }

        for(ll i=0;i<k;i++){
            string a;
            cin>>a;
            if(!vis[ordre[a]])
            dfs(ordre[a]);
        }
        for(auto i:res){
        cout<<rev[i]<<endl;
        }

    }
    return 0;
}

