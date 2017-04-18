#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll>ii;
 typedef vector<ii> vii;
 typedef  vector<int> vi;
 vi vis,lvl,tab;
 vector<vii> Adjlist;
int n,nbnoed,ttl,cmp;

int getindex(ll src){
ll i=0;
    while(tab[i]!=src){
        i++;
    }
return i;
}

bool exist(ll src){
ll i=0;
bool a=false;
    while((i<tab.size())){
        if(tab[i]==src){return true;}
        i++;
    }

   return false;


}





int bfs(int src){
vis[src]=1;
lvl[src]=0;
queue<int> q;
q.push(src);
while(!q.empty()){
        ll u=q.front();
        q.pop();
for(int i=0;i<(int)Adjlist[u].size();i++){
    ii v=Adjlist[u][i];
    if((vis[v.first]==0)&&(lvl[u]<ttl)){
            vis[v.first]=1;
        //nbnoed++;
        cmp++;
       //cout<<v.first<<" reachble"<<endl;
        lvl[v.first]=lvl[u]+1;
        q.push(v.first);
    }

}


}
//cout<<nbnoed<<" noed et cmp = "<<cmp<<endl;
return tab.size()-cmp;

}

int main()
{
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int testCase=1;
    while((cin>>n)&&(n>0)){
           // cout<<n<<endl;
            Adjlist.clear();
            tab.clear();
            Adjlist.resize(40);
            vis.clear();
            vis.resize(40);
            lvl.clear();
            lvl.resize(40);
        for(int i=0;i<n;i++){
                ll a,b;
                cin>>a>>b;
                if(!exist(a)){tab.push_back(a);}
                if(!exist(b)){tab.push_back(b);}
                Adjlist[getindex(a)].push_back(ii(getindex(b),1));
                Adjlist[getindex(b)].push_back(ii(getindex(a),1));
        }
        ll src;
        while((cin>>src>>ttl)&&((src>0)||(ttl>0))){
                cmp=1;
                vis.clear();
                vis.resize(40);
                lvl.clear();
                lvl.resize(40);
                //nbnoed=1;
            cout<<"Case "<<testCase<<": "<<bfs(getindex(src))<<" nodes not reachable from node "<<src<<" with TTL = "<<ttl<<"."<<endl;
            testCase++;
        }
        string s;
    getline(cin,s);



    }

    return 0;
}
