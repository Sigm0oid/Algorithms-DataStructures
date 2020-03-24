#include <bits/stdc++.h>
#define MAXV 75
using namespace std;
typedef long long ll;
int n,m,s=0,t=74,mf,f;
vector<int> p;
 map<string,int> tshirts;
int res[75][75];

void augment(int v,int min_flow){

    if(v==s){f=min_flow;return ;}
else if(p[v]!=-1){ augment(p[v],min(min_flow,res[p[v]][v])); res[p[v]][v]-=f;
                            res[v][p[v]]+=f;}
}
void Edmon_karp(){
mf=0;
while(1){
f=0;
vector<int>  dis(MAXV,INT_MAX); dis[s]=0;
p.assign(MAXV,-1);
queue<int> q;q.push(s);
while(!q.empty()){
    int u=q.front();
    q.pop();
   // cout<<" u "<<u<<endl;
    if(u==t)
    break;
    for(int i=0;i<MAXV;i++){
        if(res[u][i]>0&&dis[i]==INT_MAX)
        dis[i]=dis[u]+1,q.push(i),p[i]=u;

    }
}
augment(t,INT_MAX);
if(f==0)
break;
mf+=f;



}

}

int main()
{
    tshirts["XS"]=1;
    tshirts["S"]=2;
    tshirts["M"]=3;
    tshirts["L"]=4;
    tshirts["XL"]=5;
    tshirts["XXL"]=6;

    int T;
    cin>>T;
    while(T--){

    cin>>m>>n;
    memset(res,0,sizeof res);
     for(int i=1;i<7;i++){
    res[n+i][t]=(m/6);

    }
    for(int i=1;i<=n;i++){
        string a,b;
        cin>>a>>b;
        res[i][n+tshirts[a]]=1;
        res[i][n+tshirts[b]]=1;
        res[s][i]=1;
    }

    Edmon_karp();
   // cout<<" max flow "<<mf<<endl;
    if(mf>=n)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    }


    return 0;
}
