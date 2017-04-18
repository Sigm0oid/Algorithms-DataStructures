#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<string,string> ii;
typedef vector<ii> vii;
typedef pair<ll,string> is;
vii clubs;
vector<string> sol;
bool sol_found=false;
ll n;
ll solve(ll pos,set<pair<ll,string> > used){
if(sol_found)
return 0;
if(pos==n)
{
sol_found=true;
return 0;
}

string option1=clubs[pos].first.substr(0,3);
string option2=clubs[pos].first.substr(0,2)+clubs[pos].second.substr(0,1);


ll res=0;

if((used.find(is(1,option1))==used.end()&&used.find(is(2,option1))==used.end()&&used.find(is(3,option1))==used.end())){


    used.insert(is(1,option1));
    sol[pos]=option1;
    res=1+solve(pos+1,used);
    used.erase(used.find(is(1,option1)));
    }


if(used.find(is(1,option2))==used.end()&&used.find(is(2,option2))==used.end()&&used.find(is(1,option1))==used.end()){

used.insert(is(2,option2));
used.insert(is(3,option1));
sol[pos]=option2;
res=max(res,1+solve(pos+1,used));
}
return res;

}

int main()
{

    scanf("%lld",&n);
    clubs.resize(n);
    for(int i=0;i<n;i++)
    {

      cin>>clubs[i].first;
       cin>>clubs[i].second;

    }
    set<pair<ll,string> >  names;
    sol.resize(n);
    if((solve(0,names))>=n){
    printf("YES\n");
    for(ll i=0;i<n;i++){
    cout<<sol[i]<<'\n';
    }
    printf("\n");
    }
    else
    printf("NO\n");

    return 0;
}
