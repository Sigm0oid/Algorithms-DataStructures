#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    map<char,ll> fi;
    string s;
    cin>>s;

    for(ll i=0;i<s.length();i++){
    fi[s[i]]++;
    }
    ll res=LLONG_MAX;
    ll mod_res=0;
    for(ll tmp=2;tmp<=1e5;tmp++){
    ll tmp_res=0;
    for(auto it=fi.begin();it!=fi.end();it++){
         if(it->second>1)
          {
            tmp_res+=(it->second%tmp)*it->second;
          }
     }
     //cout<<" tmp res "<<tmp_res<<endl;
     (tmp_res<res)?res=tmp_res,mod_res=tmp:mod_res=mod_res;
    }


    cout<<mod_res<<endl;
    return 0;
}
