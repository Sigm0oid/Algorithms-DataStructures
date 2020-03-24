#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<pair<ll,ii> > viii;
viii Edgelist;
int n,m;
vi parent,rnk;
ll ans;

ll  FindSet(ll i){
if(parent[i]==i){
    return i;
}
else{
    return parent[i]=FindSet(parent[i]);
}
}
bool SameSet(ll i,ll j){
return (FindSet(i)==FindSet(j));
}
void UnionSet(ll i,ll j,ll k){
if(!SameSet(i,j)){
        ans+=k;
    ll x=FindSet(i);
    ll y=FindSet(j);
    if(rnk[x]>rnk[y]){
        parent[y]=x;
    }
    else{
        parent[x]=y;
        if(rnk[x]==rnk[y]){
            rnk[y]++;
        }
    }
}

}

int main()
{
    while(cin>>n>>m&&(n>0||m>0)){
        Edgelist.clear();
        rnk.clear();
        rnk.resize(n);
        parent.clear();
        parent.resize(n);
        for(ll i=0;i<n;i++){
            parent[i]=i;
        }
        ll somme=0;
        for(ll i=0;i<m;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            Edgelist.push_back(make_pair(c,ii(a,b)));
            somme+=c;
        }
        sort(Edgelist.begin(),Edgelist.end());
        ans=0;
        for(ll j=0;j<Edgelist.size();j++){
            ll x=Edgelist[j].second.first;
            ll y=Edgelist[j].second.second;
           UnionSet(x,y,Edgelist[j].first);
        }
        cout<<somme-ans<<endl;

    }
    return 0;
}
