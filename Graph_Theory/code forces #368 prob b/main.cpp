#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
#define INF 1000000001


int main()
{
    std::ios::sync_with_stdio(false);

    ll n,m,k;
    cin>>n>>m>>k;
    if(k>0){
            int presented[n+1];
            int isstore[n+1];
            ll store[k];

            memset(presented,0,sizeof presented);
            memset(isstore,0,sizeof isstore);
            //ll store[k];
            vector<vii> Adjlist(n+1);
            for(int i=0;i<m;i++){
                    ll u,v,l;
                    cin>>u>>v>>l;
                    Adjlist[u].push_back(make_pair(v,l));
                    Adjlist[v].push_back(make_pair(u,l));
                    presented[u+1]=1;
                    presented[v+1]=1;


            }
            ll res=INF;
            for(ll j=0;j<k;j++){
                    //ll ki;
                cin>>store[j];
                isstore[store[j]]=1;
                    }

                    for(ll j=0;j<k;j++){
                for(ll i=0;i<(ll)Adjlist[store[j]].size();i++){
                            if(isstore[Adjlist[store[j]][i].first]!=1){
                            res=min(res,Adjlist[store[j]][i].second);
                            }

                       }

                }

           if(res==INF){
            cout<<"-1"<<endl;
           } else {
               cout<<res<<endl;
               }

            }







    else{
    cout<<"-1"<<endl;

    }
    return 0;
}
