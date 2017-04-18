#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
int  n;
ll s,t,mf,f;
vi p;

int res[210][210];
void augment(int v, int minEdge){
if(v==s){f= minEdge;return;}
else if(p[v]!=-1){
        augment(p[v],min(minEdge,res[p[v]][v]));
        res[p[v]][v]-=f;res[v][p[v]]+=f;
}
}
void Edmon_karp(){
mf=0;
while(1){
f=0;
vi dis(n+1,INT_MAX);
p.assign(n+1,-1);
dis [s]=0;
queue<ll> q;
q.push(s);
while(!q.empty()){

    ll u=q.front(); q.pop();
    if(u==t){
    //cout<<" im at "<<t<<endl;
    break;
    }


    for(int i=1;i<=n;i++){
        if(res[u][i]>0&&dis[i]==INT_MAX)
        {
        dis[i]=dis[u]+1;q.push(i);p[i]=u;
        }
    }

}
augment(t,INT_MAX);
//cout<< " f "<<f<<endl;
if(f==0)
break;
mf+=f;
}

}

int main()
{
    int T;
    cin>>T;
    while(T--){
    mf=0;
    f=0;
    cin>>n;
    memset(res,0,sizeof res);
    s=1;
    t=n;

    for(int i=1;i<n;i++){
            int k;
            cin>>k;
            while(k--){
                int a;
                cin>>a;
                res[i][a]=INT_MAX;
                if(a==t||i==s)
                res[i][a]=1;
               // cout<<" the nod "<<i<<" is connected to "<<a<<endl;

            }


    }
    Edmon_karp();
    cout<<mf<<endl;

    }
    return 0;
}
