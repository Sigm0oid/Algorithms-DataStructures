#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef vector<iii> EdgeList;
vector<ii> positions;
ll  p;
ll  res=INT_MAX;
ll vis[410];
int dis(int i,int j){
//cout<< "distance from "<<i<<" to "<<j<<" = "<<abs(positions[i].first-positions[j].first)+abs(positions[i].second-positions[j].second)<<endl;
return (abs(positions[i].first-positions[j].first)+abs(positions[i].second-positions[j].second));
}
void isibizi(ll current_res,int used,int current_node){

if(used==positions.size())
{
    res=min(res,current_res+dis(current_node,0));
    return ;
}
    for(int i=0;i<positions.size();i++){
        if(vis[i]==0){
            vis[i]=1;
            isibizi(current_res+dis(current_node,i),used+1,i);
            vis[i]=0;
        }

    }

}
int main()
{
    int t;
    cin>>t;
    while(t--){
    memset(vis,0,sizeof vis);
    positions.clear();
    res=INT_MAX;
    ll x1,y1;
    ///read size of grid
    cin>>x1>>y1;
    cin>>x1>>y1;
    positions.push_back(ii(x1,y1));
    cin>>p;
    for(int i=0;i<p;i++){
    cin>>x1>>y1;
    positions.push_back(ii(x1,y1));
    }
    vis[0]=1;
    isibizi(0,1,0);
    cout<<"The shortest path has length "<<res<<endl;
    }
    return 0;
}

