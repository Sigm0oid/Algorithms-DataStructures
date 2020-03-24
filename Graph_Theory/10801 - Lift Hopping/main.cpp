#include <bits/stdc++.h>
#define INF 100000000
using namespace std;
typedef long long ll;
typedef  pair<int,int> ii;
typedef pair<int,ii > iii;
typedef vector<iii> viii;
typedef vector<int> vi;
vector<viii> Adjlist;
vi dis,elevatorsrc;
int n,k;

void Dijkstra(int src,int elev)
{
dis[src]=0;
priority_queue<iii,vector<iii>,greater<iii> > pq;
pq.push(make_pair(0,ii(src,elev)));

while(!pq.empty()){
iii v=pq.top(); pq.pop();
int u=v.second.first;
int d=v.first;
int elevator=v.second.second;
if(dis[u]<d)
continue;

for(int i=0;i<Adjlist[u].size();i++){
    iii v=Adjlist[u][i];
    int elevator2=v.first;
    int uu=v.second.first;
    int dd=v.second.second;
    if(elevator2!=elevator)
    dd+=60;
    if(dis[uu]>dis[u]+dd){
    dis[uu]=dis[u]+dd;
    pq.push(make_pair(dis[uu],ii(uu,elevator2)));
    }
}

}
}

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
   while(cin>>n>>k){
   elevatorsrc.clear();
   Adjlist.clear();
   Adjlist.resize(100);
   dis.clear();
   dis.assign(100,INF);
   int cout_elevator[n];
   for(int i=0;i<n;i++){
    cin>>cout_elevator[i];
   }
    string ss;
    getline(cin,ss);
   for(int i=0;i<n;i++){
   vector<int> stations;
  // cout<<"Elevator No "<<i+1 <<endl<<endl;
   string s;
   getline(cin,s);
   stringstream ss;
   ss.str(s);
   string token;
   while(getline(ss,token,' ')){
   stations.push_back((atoi)(token.c_str()));
   }
   if(stations[0]==0)
   elevatorsrc.push_back(i);
    for(int j=1;j<stations.size();j++){
    for(int k=0;k<j;k++){
    Adjlist[stations[j]].push_back(make_pair(i,ii(stations[k],abs(stations[j]-stations[k])*cout_elevator[i])));
    Adjlist[stations[k]].push_back(make_pair(i,ii(stations[j],abs(stations[k]-stations[j])*cout_elevator[i])));
    //cout<<"Edge from "<<stations[k]<<" to "<<stations[j]<<endl;
    }

    }
   }
   int res=INF;
   for(int i=0;i<elevatorsrc.size();i++){
   Dijkstra(0,elevatorsrc[i]);
   res=min(res,dis[k]);
   }

   if(res==INF){
   cout<<"IMPOSSIBLE"<<endl;
   }
   else{
   cout<<res<<endl;
   }
    }

    return 0;
}
