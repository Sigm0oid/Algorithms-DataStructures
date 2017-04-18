#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int res[210][210];
int s=0,t,f,mf;
vi p;

void augment(int v,int MIN_EDGE){
if(v==s){f=MIN_EDGE;return;}
else if(p[v]!=-1){
augment(p[v],min(MIN_EDGE,res[p[v]][v]));
res[p[v]][v]-=f;
res[v][p[v]]+=f;
}
}

int edmon_karps(){
mf=0;
while(1){
f=0;
vi dis(210,INT_MAX); dis[s]=0;queue<int> q;q.push(s);
p.assign(210,-1);
while(!q.empty()){
int u=q.front();
q.pop();
if(u==t)
break;
for(int v=0;v<210;v++){
if(res[u][v]>0&&dis[v]==INT_MAX){
q.push(v);dis[v]=dis[u]+1;p[v]=u;}
}
}
augment(t,INT_MAX);

if(f==0)
break;
mf+=f;
}
return mf;

}

int main()
{
    freopen("in.in","r",stdin);
    memset(res,0,sizeof res);
   int n1,n2;
    cin>>n1;
    vector<int> boys;
    vector<int> girls;
    for(int i=0;i<n1;i++){
    res[0][i+1]=1;
    int x;
    cin>>x;
    boys.push_back(x);
    }
    cin>>n2;
    t=n1+n2+1;
    for(int i=0;i<n2;i++){
    res[n1+i+1][n1+n2+1]=1;
    int x;
    cin>>x;
    girls.push_back(x);
    }
    for(int i=1;i<n1+1;i++){
    for(int j=n1+1;j<n1+n2+1;j++){
    if (abs(boys[i-1]-girls[j-n1-1])<=1)
    res[i][j]=INT_MAX;


    }
    }
    cout<<edmon_karps()<<endl;

    return 0;
}
