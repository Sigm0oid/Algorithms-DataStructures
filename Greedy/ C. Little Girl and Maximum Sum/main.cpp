#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main()
{
    //ios_base::sync_with_stdio(false);
    ll n,p;
    cin>>n>>p;
    ll tab[n];
    ll lvl[n];
    for(ll i=0;i<n;i++){
      cin>>tab[i];
      lvl[i]=0;

    }
    for(ll i=0;i<p;i++){
        ll a,b;
        cin>>a>>b;
            lvl[a-1]++;
            lvl[b]--;

    }
    for(int i=1;i<n;i++)
        lvl[i]+=lvl[i-1];

    sort(lvl,lvl+n);
    sort(tab,tab+n);
    ll somme=0;
    for(ll i=0;i<n;i++){
        somme+=(tab[i]*lvl[i]);
    }
    cout<<somme<<endl;


    return 0;
}
