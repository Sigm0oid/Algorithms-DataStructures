#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
vector<ll> type2_mana;
ll n,m,k,x,s;
vii type1;
vii type2;

ll calcule(ll i,ll j){

if(i==-1)
{
    if(type2[j].second>s){
    return LLONG_MAX;

    }else return ((n-type2[j].first)*x);
}
else if(j==-1)
{
    if(type1[i].second>s){
    return LLONG_MAX;

    }else return (n*(type1[i].first));
}
else{
if((type1[i].second+type2[j].second)>s)
return LLONG_MAX;
else
{
//if(i==1&&j==1)
//cout<< ((n-type2[j])*(type1[i]))<<endl;
  return ((n-type2[j].first)*(type1[i].first));


}
}
}


ll findbest(ll mana){
ll  tmp = distance(type2_mana.begin(), upper_bound(type2_mana.begin(),type2_mana.end(),mana));
if(tmp==k)
tmp--;
while(type2_mana[tmp]>mana&&tmp>-1)
tmp--;

//cout<<"best of mana "<<mana<<" is "<<type2[tmp].first<<" "<<tmp<<endl;
return(tmp);

}

int main()
{
    cin>>n>>m>>k>>x>>s;

    type1.resize(m);
    type2.resize(k);
    type2_mana.resize(k);
    for( ll i=0;i<m;i++)
    cin>>type1[i].first;

    for( ll i=0;i<m;i++)
    cin>>type1[i].second;

    for( ll i=0;i<k;i++)
    cin>>type2[i].first;
    for( ll i=0;i<k;i++)
    {cin>>type2[i].second;type2_mana[i]=type2[i].second;}
ll res=(x*n);
 for(ll j=0;j<k;j++){
    { res=min(calcule(-1,j),res);}}

    for(ll i=0;i<m;i++){
    res=min(calcule(i,-1),res);
    ll tmp=findbest(s-type1[i].second);
    //if(type2[tmp].second>=(s-type1[i].second))
    res=min(calcule(i,tmp),res);


    }

    cout<<res<<endl;


    return 0;
}
