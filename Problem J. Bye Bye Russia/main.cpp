#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int res=(c-a)*60;
        //if(d<b) res-=60;
        res+=(d-b);
    cout<<"Case "<<i<<": "<<res<<endl;
    }

    return 0;
}
