#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
vector<ll> items;

int main()
{
    cin>>n;
//    ll miin=LLONG_MAX;
//    ll indx_min=-1;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        items.push_back(x);
        //if(items[i]<miin)
       //miin=items[i],indx_min=i;

    }
    ll cmp=-1 ;
    bool ok=false;
    while(!ok){
    cmp++;
    ok=true;
        ll miin=LLONG_MAX;
        ll indx_min=-1;
        for(ll i=0;i<n;i++){
       // cout<<items[i]<<" ";
        if(items[i]>0)
        ok=false;
         if(items[i]<miin)
        miin=items[i],indx_min=i;
        items[i]--;

        }
        //cout<< "le min est "<<miin<<endl;
        items[indx_min]++;
    }




    cout<<cmp<<endl;
    return 0;
}



