#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef  vector <ii> vii;
typedef  vector <int> vi;
vi vis;
vector<vii> Adjlist;
vi dis(6,10000);
int  dijkstra (int src,int dist){
dis[src]=0;
priority_queue < ii,vector<ii>,greater<ii> > pq;
pq.push(ii(0,src));
while(!pq.empty()){
        ii v;
        v=pq.top();
        int d=v.first;
        int u=v.second;

    pq.pop();
    if(d>dis[u])
        continue;
for(int i=0;i<Adjlist[u].size();i++){
    if(dis[Adjlist[u][i].first]>dis[u]+Adjlist[u][i].second){
        dis[Adjlist[u][i].first]=dis[u]+Adjlist[u][i].second;
        pq.push(ii(dis[Adjlist[u][i].first],Adjlist[u][i].first));
       // cout<<"OK";
    }
}
}

return dis[dist];
}

int main()
{

    Adjlist.resize(6);

    Adjlist[0].push_back(ii(1,3));
    Adjlist[1].push_back(ii(2,3));
    Adjlist[0].push_back(ii(3,3));
    Adjlist[0].push_back(ii(4,3));
    Adjlist[0].push_back(ii(5,3));



    for(int i=0;i<6;i++){
        cout<<dijkstra(0,i)<<endl;
    }
    cout<<dijkstra(0,5);
    return 0;
}
