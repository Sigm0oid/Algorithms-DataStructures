#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef vector<ll> vi;
 vi p,rnk;
int n,k;
ll findSet(ll i){
if(p[i]==i){
return i;}
else{
return p[i]=findSet(p[i]);
}
}
bool isSameset(ll i ,ll j){
return(findSet(i)==findSet(j));
}
void unionSet(ll i,ll j){

if(!isSameset(i,j)){
ll x=findSet(i);
ll y=findSet(j);
if(rnk[x]>rnk[y]) p[y]=x;
else{p[x]=y;
    if(rnk[x]==rnk[y])rnk[y]++;
}
}
}

//vector <ii>dogs;
vector<iii> Edgelist;
vector<ll> dogs;


int main()
{
ios_base::sync_with_stdio(false);
int t;
cin>>t;
while(t--){
    Edgelist.clear();
    p.clear();
    rnk.clear();
    dogs.clear();
    cin>>k>>n;
    p.resize(k);
    rnk.resize(k);
    dogs.resize(k);
    for(int i=0;i<k;i++){
    cin>>dogs[i];
    p[i]=i;

    }
    sort(dogs.begin(),dogs.end());
    for(int i=0;i<k-1;i++){
    Edgelist.push_back(make_pair(dogs[i+1]-dogs[i],ii(i,i+1)));
    }
    ll res=0;
     sort(Edgelist.begin(),Edgelist.end());
     for(int i=0;i<k-n;i++){
     unionSet(Edgelist[i].second.first,Edgelist[i].second.second);
     res+=Edgelist[i].first;

     }
     cout<<res<<endl;
    }
    return 0;
}
