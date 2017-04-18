#include <bits/stdc++.h>

using namespace std;
#define N_MAX 100010
typedef long long ll;

int main()
{

    ll n;
    scanf("%lld",&n);
    ll tab[n];
    ll sum[n];
    ll parent[n];


    for(ll i=0;i<n;i++){
        scanf("%lld",&tab[i]);
        parent[i]=-1;
        sum[i]=0;

    }
    vector<ll> deleted(n);
    for(ll i=0;i<n;i++){
     scanf("%lld",&deleted[i]);
        deleted[i]--;
    }
    ll maxx=0;
    stack<ll> res;
    res.push(0);
    for(ll i=n-1;i>=1;i--)
    {

    ll tmp=0;
    sum[deleted[i]]=tab[deleted[i]];
    parent[deleted[i]]=deleted[i];
    ll l=deleted[i]-1,r=deleted[i]+1;

    if(r<n&&parent[r]!=-1){
    while(r!=parent[r])
    r=parent[r];
    parent[deleted[i]]=parent[r];
    sum[parent[r]]+=sum[deleted[i]];
    }


    if(l>=0&&parent[l]!=-1){
    while(l!=parent[l])
    l=parent[l];
    parent[l]=parent[deleted[i]];
    sum[parent[deleted[i]]]+=sum[l];
    }

    tmp=sum[parent[deleted[i]]];

    maxx=max(tmp,maxx);
    res.push(maxx);

    }
    while(!res.empty()){
    printf("%lld\n",res.top());
    res.pop();
    }




    return 0;
}

