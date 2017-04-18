#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;

ll nb_attack,nb_jedi;
ll dp[1010][110][110];
vi  attacks,jedi;

ll isibizi(ll pos,ll time_left1,ll time_left2 ){
//cout<<" pos "<<pos<<" time_left 1 "<<time_left1<<" time 2 "<<time_left2<<endl;
if(pos>=nb_attack)
return 0;
if(pos>0){

time_left1-=(attacks[pos]-attacks[pos-1]);
time_left2-=(attacks[pos]-attacks[pos-1]);
    }

time_left1=max(time_left1,0LL);
time_left2=max(time_left2,0LL);


if( dp[pos][time_left1][time_left2]!=-1){
  //  cout<<" already calculated " <<" pos "<<pos<<" time_left 1 "<<time_left1<<" time 2 "<<time_left2<<endl;
   return  dp[pos][time_left1][time_left2];}

ll res=0;
//if(time_left1==0&&time_left2==0)
res=max(res,isibizi(pos+1,time_left1,time_left2));
if(time_left1<=0){
     res=max(res,1+isibizi(pos+1,jedi[0],time_left2));
    }
if(time_left2<=0&nb_jedi>1){
     res=max(res,1+isibizi(pos+1,time_left1,jedi[1]) );
    }

return dp[pos][time_left1][time_left2]=res;
}



int main()
{
    freopen("jedi.in","r",stdin);
    ll t;
    cin>>t;
    while(t--){
    memset(dp,-1,sizeof dp);


    cin >>nb_attack;
    attacks.clear();
    attacks.resize(nb_attack);

    for(ll i=0;i<nb_attack;i++)
        cin>>attacks[i];

    cin>>nb_jedi;
    jedi.clear();
    jedi.resize(nb_jedi);
    for(ll i=0;i<nb_jedi;i++)
        cin>>jedi[i];
    sort(attacks.begin(),attacks.end());
    cout<<nb_attack-isibizi(0,0,0)<<endl;


    }
    return 0;

}
