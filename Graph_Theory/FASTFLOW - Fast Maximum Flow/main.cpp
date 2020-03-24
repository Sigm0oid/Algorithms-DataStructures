#include <bits/stdc++.h>
#define MAX_V 5010
#define INF LLONG_MAX
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
ll res[MAX_V][MAX_V];
ll n,m;
ll mf,f,s,t;
vector<ll> p;
vector<vii> Adjlist;
void augment(ll v, ll minEdge) {

//cout<<v<<endl;
if (v == s) {  f = minEdge; return; }
else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v]));
res[p[v]][v] -= f; res[v][p[v]] += f; } }


void Edmon_karp(){

mf = 0;

while (1) {

f = 0;

vi dist(MAX_V, INF); dist[s] = 0; queue<ll> q; q.push(s);
p.assign(MAX_V, -1);

while (!q.empty()) {
ll u = q.front(); q.pop();

if (u == t) break;
for (ll i = 0; i < (ll)Adjlist[u].size(); i++){
ll v=Adjlist[u][i].first;
if (res[u][v] > 0 && dist[v] == INF)
dist[v] = dist[u] + 1, q.push(v), p[v] = u;
}

}
augment(t, INF);
//cout<<" f "<<f<<endl;
if (f == 0) break;
mf += f;

}
}
int main()
{
    cin>>n>>m;
    memset(res,0,sizeof res);
    while(m--){
    s=0;
    t=n-1;
    Adjlist.resize(n);
    ll a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);
    res[a-1][b-1]+=c;
    res[b-1][a-1]+=c;
    Adjlist[a-1].push_back(ii(b-1,1));
    Adjlist[b-1].push_back(ii(a-1,1));
    }
    Edmon_karp();
    printf("%lld\n",mf);
    return 0;
}

