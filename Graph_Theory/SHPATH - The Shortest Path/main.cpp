#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vii>Adjlist;
ll dist[10001];


string tab[10001];
int getindex(string name,int n){
    int i=0;
while(i<n){
    if(name==(tab[i])){
        return i;
    }
    i++;
}
}

void dijkstra(int src,int n){
dist[src]=0;
priority_queue<ii,vector<ii>,greater<ii> >pq;
pq.push(ii(0,src));
while(!pq.empty()){
    ii s=pq.top();
    pq.pop();
    int d=s.first;
    int u=s.second;
    if((ll)d>dist[u])
        continue;


for(int i=0;i<(int)Adjlist[u].size();i++){
        ii v=Adjlist[u][i];
    if(dist[u]+v.second<dist[v.first]){
        dist[v.first]=dist[u]+v.second;
        //cout<<"new changes distance of "<<v.first<<" become "<<dist[u]+v.second<<endl;
        pq.push(ii((dist[v.first]),(v.first)));
    }
}
}


}


int main()
{
    ios_base::sync_with_stdio(false);
int t;
cin>>t;
for(int i=0;i<t;i++){
    Adjlist.clear();

   // memset(tab," ",sizeof tab);

    int n;
    cin>>n;
    Adjlist.resize(n);

    for(int j=0;j<n;j++){
    string name;
    cin>>name;
    tab[j]=name;
    int p;
    cin>>p;
    for(int k=0;k<p;k++){
        int nr,cost;
        cin>>nr>>cost;
        Adjlist[j].push_back(make_pair(nr-1,cost));
        //cout<<nr-1<<" "<<cost<<endl;
        //Adjlist[nr-1].push_back(make_pair(cost,j));

    }
 }
 int r;
 cin>>r;
 for(int j=0;j<r;j++){
    string s,dis;
    cin>>s>>dis;
    memset(dist,10000,sizeof dist);
    dijkstra(getindex(s,n),n);
//    for(int k=0;k<n;k++){
//    cout<<dist[k]<<" ";
//}
//cout<<endl;

    cout<<dist[getindex(dis,n)]<<endl;
 }
   string s;
 getline(cin,s);
}

    return 0;
}
