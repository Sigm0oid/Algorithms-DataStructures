#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
vector<vii> AdjList;
vector<ll> dist;
ll m,nb_tasks,min_dis;
bool found;

void bellman(){
dist.assign(nb_tasks+1, 0);
for (ll i = 0; i < nb_tasks ; i++)

for (ll u = 1; u <=nb_tasks; u++)
for (ll j = 0; j < (ll)AdjList[u].size(); j++) {
ii v = AdjList[u][j];

dist[v.first] = min(dist[v.first], dist[u] + v.second);
//min_dis=min(min_dis,dist[v.first] );
}

for (ll u = 1; u <=nb_tasks; u++)
for (ll j = 0; j < (ll)AdjList[u].size(); j++) {
ii v = AdjList[u][j];
if (dist[v.first] > dist[u] + v.second)
found = true;

}

}

int main()
{
    freopen("in.in","r",stdin);
    while(cin>>nb_tasks&&nb_tasks!=0){
    min_dis=0;
    cin>>m;
    found=false;
    dist.clear();
    AdjList.clear();
    cin.ignore();
    AdjList.resize(nb_tasks+1);

        while(m--){
        string s;
        getline(cin,s);
        ///substrss

        stringstream ss;
        ss.str(s);
        string token;
        vector<string> v;
        while(getline(ss,token,' '))
        v.push_back(token);

        ll task1=(ll)(atoi)(v[1].c_str());
        ll task2=(ll)(atoi)(v[v.size()-1].c_str());
//        task1--;
//        task2--;

        bool within=(v[3]=="within");
        ll a;
        if(within)
        a=(atoi)(v[4].c_str());
        else
        a=(atoi)(v[5].c_str());

        if(within){
        AdjList[task2].push_back(ii(task1,0));

        }
        else{
        a*=-1;
        swap(task1,task2);
        }
        AdjList[task1].push_back(ii(task2,a));
        }
    bellman();
    if(found)
    cout<<"Impossible.";
    else
    for(ll i=1;i<=nb_tasks;i++)
    cout<<1-dist[i]<<" ";
    cout<<"\n";

    }
    return 0;
}
