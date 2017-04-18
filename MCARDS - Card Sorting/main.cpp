#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
ll c,n;
vii cards;
vi ordre;
ll dp[410];
bool compare(ii card1,ii card2){

if(card2.first==-1)
return true;
if (card1.first==-1)
return false;

if(card1.first==card2.first)
return(card1.second>card2.second) ;
ll i=ordre.size()-1;
ll j=i;
while(ordre[i]!=card1.first)
i--;
while(ordre[j]!=card2.first)
j--;

return(i<j);

}

ll LIS(ll i,ii last_card){
if(i>=(n*c))
return 0;
if(dp[i]==-1)
dp[i]=LIS(i+1,cards[i]);

if(compare(cards[i],last_card)){
ll res1,res2;
 res1=1+dp[i];
 res2=LIS(i+1,last_card);

return max(res1,res2);
}
return LIS(i+1,last_card);


}





int main()
{
    //freopen("CARDS.IN","r",stdin);
    //freopen("CARDS.OUT","w",stdout);
    cin>>c>>n;
    ll tmp=c*n;
    while(tmp--){
    ll a,b;
    cin>>a>>b;
    cards.push_back(ii(a,b));
    }
    ll maxx=LLONG_MIN;
    ordre.clear();
    for(int i=0;i<c;i++){
    ordre.push_back(i+1);
    }

    do{

    memset(dp,-1,sizeof dp);
    maxx=max(maxx,LIS(0,ii(-1,-1)));
    }while(next_permutation(ordre.begin(),ordre.begin()+c));
    cout<<(c*n)-maxx<<endl;
    return 0;
}
