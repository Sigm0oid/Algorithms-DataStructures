#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll ,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
ll n,a;
vector<ll> tab;
#define INF 10000001
// ll fuck(ll pos,ll taken,ll cmp){
//ll res=INF;
// if(cmp==n-1){
//    return taken;
// }
// else{
//        cout<<"ici"<<endl;
//    for(ll i=0;i<n;i++){
//        res=min(fuck(tab[i],taken+abs(pos-tab[i]),cmp+1),res);
//    }
// }
// return res;
// }


int main()
{
    ios_base::sync_with_stdio(false);

    cin>>n>>a;
    tab.resize(n);
    for(ll i=0;i<n;i++){
        cin>>tab[i];
    }
    if(n==1){
        cout<<"0"<<endl;
    }
    else if(n==2){
        cout<<min(abs(a-tab[0]),abs(a-tab[1]))<<endl;
    }
    else{
  sort(tab.begin(),tab.end());
  ll max1,max2,min1,min2;
  max1=tab[tab.size()-2];
  max2=tab[tab.size()-1];
  min1=tab[0];
  min2=tab[1];
 // cout<<min1<<" "<<max1<<" "<<min2<<" "<<max2<<endl;
ll    res=min((min((abs(max1-a)+abs(max1-min1)),abs(min1-a)+abs(max1-min1))),(min((abs(max2-a)+abs(max2-min2)),abs(min2-a)+abs(max2-min2))));

    cout<<res<<endl;
    }
    return 0;
}
