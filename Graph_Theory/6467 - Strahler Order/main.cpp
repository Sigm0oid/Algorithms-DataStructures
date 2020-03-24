#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
vector<vii> Adjlist;
vi order;
vi res;
ll n,m,glob;
vector<set<ll> > parents;

int main()
{
    ll k;
    cin>>k;
    while(k--){

    glob=0;
    ll nb_test;
    cin>>nb_test;
    cin>>n>>m;
    Adjlist.clear();
    Adjlist.resize(n);
    order.assign(n,1);
    parents.clear();
    parents.resize(n);
    res.assign(n,0);

        while(m--){
            ll a,b;
            cin>>a>>b;
            a--;b--;
            Adjlist[a].push_back(ii(b,1));
            order[b]++;
            parents[b].insert(a);
        }
    bool finished=false;
    while(!finished){
    finished=true;
    for(ll i=0;i<n;i++){
        if(order[i]==1){
       // cout<<" node i ="<<i+1<<" has order 1"<<endl;
        finished=false;
            ll maax=1;
            ll max_occ=0;
            //    cout<<" im "<<i<<endl<<" my parents level are "<<endl;
                for(auto it=parents[i].begin();it!=parents[i].end();it++){
              //      cout<<res[*it]<<endl;
                    if(res[*it]>maax)
                    maax=res[*it],max_occ=1;
                    else{
                    if(res[*it]==maax)
                    max_occ++;
                    }
                }

                res[i]=maax;
                if(max_occ>1)
                res[i]++;
                glob=max(glob,res[i]);


               order[i]=INT_MAX;
               for(ll j=0;j<Adjlist[i].size();j++)
               order[Adjlist[i][j].first]--;
        }
    }

    }

    cout<<nb_test<<" "<<glob<<endl;
    }
    return 0;
}
