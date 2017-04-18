#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<vector<ll> > res;
void  findway(ll a,ll b,vector<ll> l){
if(res.size()>0){
return ;}
if(a==b){
res.push_back(l);
return ;}
else if(a>b){
return ;}
else{
l.push_back(a*10+1);
findway(a*10+1,b,l);
l[l.size()-1]=a*2;
findway(a*2,b,l);
return ;
}

}


int main()
{
    ll a,b;
    cin>>a>>b;
    vector<ll> x;
    x.push_back(a);
    findway(a,b,x);
    if(res.size()==0){
    cout<<"NO"<<endl;}
    else{
    cout<<"YES"<<endl<<res[0].size()<<endl;
    for(int i=0;i<res[0].size();i++){
    cout<<res[0][i]<<" ";
    }
    cout<<endl;
    }

    return 0;
}

