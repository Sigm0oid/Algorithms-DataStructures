#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
ll n,q;
vector<ll> teams;

int main()
{
//freopen("in.txt","r",stdin);
    ll  t;
    scanf("%lld",&t);
    while(t--){
    scanf("%lld %lld",&n,&q);
    teams.assign(n+1,0);
    priority_queue<ii,vector<ii>,greater<ii> > pq;
    for(ll i=1;i<=n;i++)
    pq.push(ii(0,i));
    ll current_top=1;
    ll res=0;
    for(ll i=1;i<=q;i++){
        ll x,p;
        scanf("%lld %lld",&x,&p);
        teams[x]+=p;
        pq.push(ii(teams[x]*-1,x));
        /// test if top team score
        while((-1*pq.top().first)!=(teams[pq.top().second]))
        pq.pop();
        if(pq.top().second!=current_top)
         {
         res=i;
         current_top=pq.top().second;
         }

        }

        printf("%lld\n",res);


        }

        //cout<<res<<endl;

    return 0;
}
