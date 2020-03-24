#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int T;
    cin>>T;
    while(T--){
    ll a;
    cin>>a;
    if(a&1)
    cout<<"First Box"<<endl;
    else{
        ll cmp=0;
        while(!(a&1))
        {
            a/=2;
            cmp++;
        }
        if(cmp&1)
        cout<<"Second Box"<<endl;
        else
        cout<<"First Box"<<endl;
    }

    }
    return 0;
}
