#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
vector<ll> tab;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
    ll x;
    cin>>x;
    tab.push_back(x);
    }
    for(int i=0;i<n/2;i++){

    if(i%2==0){
    //cout<<" swapped "<<tab[i]<<" "<<tab[n-i-1]<<endl;
    swap(tab[i],tab[n-i-1]);
    }

    }
    for(int i=0;i<n;i++)
    cout<<tab[i]<<" ";
    cout<<endl;
    return 0;
}
