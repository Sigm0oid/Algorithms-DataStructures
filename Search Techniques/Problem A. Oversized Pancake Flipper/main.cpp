#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
ll k;
string s;
ll ans=INT_MAX;
bool check(string s){
for( ll i=0;i<s.length();i++)
if(s[i]=='-')
return false;
return true;
}
string clean(string s){

   ll j=s.length()-1;
    ll i=0;
    while((s[i]=='+'||s[j]=='+')&& i<=j){
    if(s[i]=='+')
    i++;
    if(s[j]=='+')
    j--;
    }
    string tmp="";
    for(ll k=i;k<=j;k++)
    tmp+=s[k];
    return tmp;
}
string  flip(string s){
for(int i=0;i<k;i++)
    if(s[i]=='+')
    s[i]='-';
    else
    s[i]='+';
return s;
}
ll  solve(string s, ll flips){


    s=clean(s);

    if(s.length()<k){
    if(s.length()==0)
    return flips;
    return -1;
    }
    s=flip(s);
    return (solve(s,flips+1));
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.out","w",stdout);
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++){
    cin>>s>>k;
   // ll res=solve(s,0);
   ll res=0;
    for(ll j=0;j<s.length()-k+1;j++){

        if(s[j]=='-'){
        res++;
            for(ll o=j;o<j+k;o++){
                if(s[o]=='+')
                s[o]='-';
                else
                s[o]='+';
            }
        }
    }

    if(!check(s))
    cout<<"Case #"<<i+1<<": "<<"IMPOSSIBLE"<<endl;
    else
    cout<<"Case #"<<i+1<<": "<<res<<endl;


    }
    return 0;
}
