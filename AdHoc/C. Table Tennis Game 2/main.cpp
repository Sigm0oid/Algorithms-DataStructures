#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ll a,b,k;
    cin>>k>>a>>b;
    ll winner=max(a,b);
    ll looser=min(a,b);
    ll res=(winner/k)+(looser/k);
    if(res==0)
    cout<<"-1"<<endl;
    else{
        if(winner%k!=0&&looser<k)
        cout<<"-1"<<endl;
        else

    cout<<res<<endl;
    }


    return 0;
}