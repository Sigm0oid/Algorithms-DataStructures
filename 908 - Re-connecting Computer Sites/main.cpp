#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef vector<ii>vii;
typedef vector<iii> viii;
typedef vector<int> vi;
vi p,rnk;
viii Edgelist,t;
ll n;
ll findSet(ll a){
if(p[a]!=a)
return p[a]=findSet(p[a]);
else
    return a;
}
bool isSameSet(ll a,ll b){
return findSet(a)==findSet(b);}

void UnionSet(ll a,ll b){
ll x=findSet(a);
ll y=findSet(b);
if(rnk[x]>rnk[y])
   p[y]=p[x];
   else{
    p[x]=p[y];
    if(rank[x]==rank[y]){rank[y]++;}
   }

}
int main()
{
    //freopen("out.out","w",stdout);
    int g=0;
    while(cin>>n){
            if(g==0){g++;}
            else{cout<<endl;}
    rank.clear();
    rank.resize(n);
    p.resize(n);
    Edgelist.clear();
    t.clear();
     for(ll i=0;i<n;i++){
        p[i]=i;
    }

    for(ll i=0;i<n-1;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        t.push_back(make_pair(c,ii(b-1,a-1)));

    }
    int k;
    cin>>k;
    for(ll i=0;i<k;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        t.push_back(make_pair(c,ii(b-1,a-1)));

    }

    ll cost=0,cost1=0;
    sort(t.begin(),t.end());
    for(ll i=0;i<n+k-1;i++){
        if(!isSameSet(t[i].second.first,t[i].second.second)){
            cost+=t[i].first;
            UnionSet(t[i].second.first,t[i].second.second);
        }
    }
    //cout<<cost<<endl;



    ll m;
    cin>>m;
     for(ll i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        Edgelist.push_back(make_pair(c,ii(b-1,a-1)));

    }
    rank.clear();
     rank.resize(n);
      for(ll i=0;i<n;i++){
        p[i]=i;
    }
     sort(Edgelist.begin(),Edgelist.end());
    for(ll i=0;i<m;i++){
        if(!isSameSet(Edgelist[i].second.first,Edgelist[i].second.second)){
            cost1+=Edgelist[i].first;
            UnionSet(Edgelist[i].second.first,Edgelist[i].second.second);
        }
    }
    cout<<cost1<<endl<<cost<<endl;


}

    return 0;
}
