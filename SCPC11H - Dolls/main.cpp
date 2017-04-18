#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vi;
ll INF=INT_MAX,n;
ll res[1010][1010];
ll f,mf,s,t;
vi parent;
viii dolls;


void augment(ll v,ll minEdge){
if(v==s){f=minEdge; return;}
else if(parent[v]!=-1){
augment(parent[v],min(minEdge,res[parent[v]][v]));

res[parent[v]][v]-=f;res[v][parent[v]]+=f;
}
}

void Edmon_karp(){

            mf=0; //max flow to 0
            while(1){
                f=0; //initialize flow t 0
                //run bfs and stop when u found a path to t
                vi dis(2*n+2,INF); dis[s]=0;queue<ll> q;q.push(s);
                parent.assign(2*n+2,-1);
                while(!q.empty()){
                ll u=q.front();q.pop();
                 //cout<<" u "<<u<<endl;
                if(u==t) break; //stop bfs directly
                for(int i=0;i<=(2*n+2);i++){
                if(res[u][i]>0&&dis[i]==INF){
                dis[i]=dis[u]+1;q.push(i);parent[i]=u;}
                }

            }

            augment(t,INF);
            if(f==0)break;
            mf+=f;



        }

}

int main()
{
    while(cin>>n&&n>0){
    dolls.clear();
    s=0;
    t=(2*n+1);
    memset(res,0,sizeof res);
    for(ll i=0;i<n;i++){
    res[s][i+1]=1;
    res[n+i+1][t]=1;
    ll a,b,c;
    cin>>a>>b>>c;
    dolls.push_back(iii(a,ii(b,c)));
    for(ll j=i-1;j>=0;j--){
        if(dolls[i].first<dolls[j].first&&dolls[i].second.first<dolls[j].second.first&&dolls[i].second.second<dolls[j].second.second)
        res[i+1][n+j+1]=1;
        if(dolls[j].first<dolls[i].first&&dolls[j].second.first<dolls[i].second.first&&dolls[j].second.second<dolls[i].second.second)
        res[j+1][n+i+1]=1;
    }
    }
    Edmon_karp();
    //cout<< " mf "<<mf<<endl;
    cout<<n-mf<<endl;


    }
    return 0;
}

