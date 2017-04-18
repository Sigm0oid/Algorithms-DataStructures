#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll ,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;

ll vis[2001];
ll sexe[2001];
//ll cmp=0;
bool found;

void bfs(ll s ,vector<vii> Adjlist){
vis[s] = 1;
//cmp++;
sexe[s]=0;
queue<ll>q;
q.push(s);
while(!q.empty()){
    ll u;
    u=q.front();
    q.pop();
    vis[u]=1;
       // cout<<u<<"visited"<<endl;
        for(ll i=0;i<(ll)Adjlist[u].size();i++){
            if(vis[Adjlist[u][i].first]==0){
                q.push(Adjlist[u][i].first);
                sexe[Adjlist[u][i].first]=((sexe[u]+1)%2);

            }
            else{

                    if(sexe[u]==sexe[Adjlist[u][i].first]){
                    found=true;
                    return;}

            }
        }


}

}

int main()
{
//
//freopen("in.in","r",stdin);
//
//freopen("out.out","w",stdout);

ll t;
scanf("%lld",&t);

for(ll i=0;i<t;i++){
        //initialisations
        memset(vis,0,sizeof vis);
        memset(sexe,-1,sizeof sexe);
        found=false;
        //

    ll bugs;
    ll interractions;
     scanf ("%lld",&bugs);
     scanf ("%lld ",&interractions);
    vector<vii> Adjlist(bugs+1);
    for(ll  j=0;j<interractions;j++){
            ll a,b;
     scanf ("%lld",&a);
     scanf ("%lld",&b);

        Adjlist[a].push_back(make_pair(b,1));
        Adjlist[b].push_back(make_pair(a,1));
    }
ll j=1;
while((!found) &&(j<bugs+1)){
              //  cout<<j<<endl;
    if(vis[j]==0){
        bfs(j,Adjlist);
        //cout<<"call"<<endl;

    }
    j++;


}
printf ("Scenario #%lld: \n",i+1);
if(found){
   printf("Suspicious bugs found! \n");
}else{
    printf("No suspicious bugs found! \n");
}
//cout<<cmp<<endl;
}

    return 0;
}
