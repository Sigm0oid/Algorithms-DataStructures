#include <bits/stdc++.h>
#define MAX 1e9
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
map<ii,int> allowed;
map<ii,int> visited;
ll n;
ii start,finish;
int xi[8]={1,1,0,-1,-1,-1,0,1};
int yi[8]={0,1,1,1,0,-1,-1,-1};
bool inbound(ll x,ll y){
return (x>=0&&x<MAX&&y>=0&&y<MAX);
}

void bfs(ii v){
visited[v]=0;
queue<ii> q;
q.push(v);
while(!q.empty()){
    ii u=q.front();
    q.pop();
    for(int i=0;i<8;i++){
        ll x=u.first+xi[i];
        ll y=u.second+yi[i];
        if(inbound(x,y)){

            if(allowed.find(ii(x,y))!=allowed.end()&&visited.find(ii(x,y))==visited.end()){
            //cout<<" i can go to "<<x+1<<" "<<y+1<<endl;
                q.push(ii(x,y));
                visited[ii(x,y)]=visited[u]+1;
                if(ii(x,y)==finish)
                return;
            }
        }
    }

}

}

int main()
{
        cin>>start.first>>start.second>>finish.first>>finish.second;
        start.first--;
        start.second--;
        finish.first--;
        finish.second--;
        cin>>n;
        for(int i=0;i<n;i++){
        ll row,a,b;
        cin>>row>>a>>b;
        for(int j=a-1;j<=b-1;j++)
        allowed[ii(row-1,j)]++;
        }
        bfs(start);
        if(visited.find(finish)==visited.end())
        cout<<"-1"<<endl;
        else
        cout<<visited[finish]<<endl;


    return 0;
}
