#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int > ii;
typedef vector<ii> vii;
typedef vector <int> vi;
vector<vii>Adjlist;
vi dis,vis;
void Dijkstra(int src){
vis[src]=1;
dis[src]=0;
priority_queue <ii,vector<ii>,greater<ii> > pq;
pq.push(ii(0,src));
while(!pq.empty()){
    ii v=pq.top();
    pq.pop();
    int x=v.second;
    double d=v.first;
    if(d>dis[x])
        continue;
    for(int j=0;j<(int)Adjlist[x].size();j++){
        ii v=Adjlist[x][j];
        if((dis[x]+v.second)<dis[v.first]){
                dis[v.first]=dis[x]+1;
            pq.push(ii(dis[v.first],v.first));

        }
    }

}
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int d,n;
        cin>>d>>n;
        int x[n+2];
        int y[n+2];
        x[0]=25;
        y[0]=0;
        x[n+1]=25;
        y[n+1]=50;
        Adjlist.clear();
        Adjlist.resize(n+2);
        dis.clear();
        dis.assign(n+2,100000);
        vis.clear();
        vis.resize(n+2);
        for(int i=1;i<n+1;i++){
            cin>>x[i]>>y[i];
        }
        for(int i=0;i<n+1;i++){
           for(int j=i+1;j<n+2;j++){
            if(sqrt(((x[j]-x[i])*(x[j]-x[i]))+((y[j]-y[i])*(y[j]-y[i])))<=d){
                    Adjlist[i].push_back(ii(j,1));
                    Adjlist[j].push_back(ii(i,1));
                   // cout<<"paath from "<<x[i]<<" "<<y[i]<<" to "<<x[j]<<" "<<y[j]<<endl;
                    }
           }
        }
        Dijkstra(0);
        if(dis[n+1]>=100000){cout<<"Impossible"<<endl;}
        else{cout<<dis[n+1]<<endl;}
//        for(int i=0;i<n+2;i++){
//            cout<<dis[i]<<" ";
//        }
//        cout<<endl;


    }
    return 0;
}
