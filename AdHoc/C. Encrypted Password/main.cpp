#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
vii s1_car;
bool test=false;
string s1="",s2="";
void match(ll pos,ll next,ll min_indx,ll max_indx){

if(test) return ;
if(abs(max_indx-min_indx)>=s2.length())
{return ;}
if(pos==s1.length()){
    test=(next==s2.length());
    return ;
}


if(s1_car[pos].first==s2[next]-'a')
match(pos+1,next+1,min(min_indx,s1_car[pos].second),max(s1_car[pos].second,max_indx));

match(pos+1,next,min_indx,max_indx);

return ;
}
int main()

{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s1>>s2;
    for(ll i=0;i<s1.length();i++){
    s1_car.push_back(ii(s1[i]-'a',i));
    }
    sort(s2.begin(),s2.end());
    sort(s1_car.begin(),s1_car.end());
    match(0,0,LLONG_MAX,LLONG_MIN);

    if(test)
    cout<<"YES\n";
    else
    cout<<"NO\n";

    return 0;
}
