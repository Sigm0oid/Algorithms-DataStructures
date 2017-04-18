#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef pair<ll,ii> iii;
typedef vector<ll> vi;
ll n;
vi dis;
set <iii>  costs;
void bfs(){
dis[0]=0;
queue <iii> q;
q.push(*costs.begin());
costs.erase(costs.begin());

while(!q.empty()){
    iii v=q.front();q.pop();
    if(v.first==n-1)
    return ;
		for(auto  i=costs.begin();i!=costs.end();i++){

    			if(abs(i->second.first- v.second.first)==abs(i->second.second- v.second.second)&&dis[i->first]==LLONG_MAX){

					dis[i->first]=dis[v.first]+1;

					q.push(*i);
					costs.erase(i);
					}

		}
}

}
int main()
{
	//freopen("great.in","r",stdin) ;

    ll t ;
     scanf("%lld",&t) ;
    while(t--){
	 cin>>n;
 	 costs.clear();
 	 set<iii> tmp_cost;
	 dis.assign(n,LLONG_MAX);
     for(ll i=0;i<n;i++){
		 iii v;
		 ll x;
		     scanf("%lld",&x) ;

		 tmp_cost.insert(iii(i,ii(x,0)));
     }
     for(auto  i=tmp_cost.begin();i!=tmp_cost.end();i++){
		 ll x;
		 scanf("%lld",&x) ;
		 iii v=(*i);
		// tmp_cost.erase(i);
		 v.second.second=x;
		 costs.insert(v);

     }
    // cout<<" there is "<<costs.size()<<" noed "<<endl;
     bfs();
     if(dis[n-1]!=LLONG_MAX)
     printf("%lld\n" ,dis[n-1]);
     else
     printf("-1\n");


    }
    return 0;
}
