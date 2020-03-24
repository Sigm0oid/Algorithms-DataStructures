#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii>iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<int> vi;
vi p;
long long dis[1010][110];
int n,m,c,src,dist;
vector<vii> Adjlist;
void dijkstra(int s){
dis[s][0]=0;
priority_queue<iii,vector<iii>,greater<iii> > pq;
pq.push(iii(0,ii(s,0)));
while(!pq.empty()){

    iii v=pq.top();
    pq.pop();
    ll price=v.first;
    ll cur=v.second.first;
    ll gaz=v.second.second;





    if(price>dis[cur][gaz])
          continue;

    //I can buy another gallon and stay where I am
    if(gaz<c && price+p[cur]<dis[cur][gaz+1])
        {
            dis[cur][gaz+1]=price+p[cur];
            pq.push(make_pair(price+p[cur],ii(cur,gaz+1)));
        }

//cout<<cur;
    for(int i=0;i<(int)Adjlist[cur].size();i++){
           ii a=Adjlist[cur][i];
               // cout<<"ici";

                if(gaz>=a.second){

                if((dis[a.first][gaz-a.second])>price){
                dis[a.first][gaz-a.second]=price;
                pq.push(make_pair(price,ii(a.first,gaz-a.second)));

                }
            }


    }
}


}




 int  main(){
     ios_base::sync_with_stdio(false);
     //freopen("out.out","w",stdout);
     cin>>n>>m;
     Adjlist.resize(n);
     memset(dis,10000,sizeof dis);
       // cout<<dis[0][0];
     p.resize(n);
     for(int i=0;i<n;i++){
        cin>>p[i];
     }
     for(int i=0;i<m;i++){
        int u,v,d;
        cin>>u>>v>>d;
        Adjlist[u].push_back(ii(v,d));
        Adjlist[v].push_back(ii(u,d));
     }
     int q;
     cin>>q;
     for(int i=0;i<q;i++){
         int src,dist;
         cin>>c>>src>>dist;
         dijkstra(src);
         ll res=10000;
         for(int i=0;i<=c;i++){
            res=min(res,dis[dist][i]);
            //cout<<dis[dist][i]<<" ";
         }
         //cout<<endl;
         if(res>=10000){
            cout<<"impossible"<<endl;
         }
         else{cout<<res<<endl;}
//         for(int i=0;i<n;i++){
//            for(int j=0;j<c+1;j++){
//                cout<<dis[i][j]<<" ";
//            }
//            cout<<endl;
//         }

       memset(dis,10000,sizeof dis);

      }










 return 0;}
