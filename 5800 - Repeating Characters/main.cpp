#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
        int t;
        cin>>t;
        while(t--){
        ll nb_test,rep;
        string s,res="";
        cin>>nb_test>>rep>>s;

        for(ll i=0;i<s.length();i++){
            for(ll j=0;j<rep;j++)
            res+=(s[i]);
        }
        cout<<nb_test<<" "<<res<<endl;
        }
    return 0;
}
