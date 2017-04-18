#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vii> Adjlist;
vector<ll> dis,inqueue,cmpinqueue;
int n,m;
bool possible;
void bellman(int s){
dis[s]=0;
queue<int> q;
q.push(s);
inqueue[s]=1;
cmpinqueue[s]++;
while(!q.empty()&&(!possible)){

    int j=q.front();
//cout<<"queue "<<j<<endl;
    q.pop();
    inqueue[j]=0;
    for(int k=0;k<(int)Adjlist[j].size();k++){
        int  v=Adjlist[j][k].first;
        int weight =Adjlist[j][k].second;
        if(dis[j]+weight<dis[v]){
           dis[v]=dis[j]+weight ;
           if(!inqueue[v]){
                inqueue[v]=1;
           q.push(v);
           cmpinqueue[v]++;
           if(cmpinqueue[v]>n-1){
            possible=true;
            return;
           }

           }
        }
        }
    }


// for(int j=0;j<n;j++){
//        for(int k=0;k<(int)Adjlist[j].size();k++){
//        ii u=Adjlist[j][k];
//        if(((dis[j]+u.second)<dis[u.first])){
//            possible=true;
//            break;
//            }
//        }
//
//}


}
int main()
{
    //freopen("out.out","w",stdout);
    ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--){
    possible=false;
    cin>>n>>m;
    Adjlist.clear();
    Adjlist.resize(n);
    dis.clear();
    dis.assign(n,100000000);
    inqueue.clear();
    inqueue.resize(n);
    cmpinqueue.clear();
    cmpinqueue.resize(n);

    for(int i=0;i<m;i++){
        int a,b,d ;
        cin>>a>>b>>d;
        Adjlist[a].push_back(ii(b,d));
    }
    bellman(0);
   if(possible){cout<<"possible"<<endl;}
   else{cout<<"not possible"<<endl;}


}
    return 0;
}
