#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
vector<iii> intervals;
ll k,n;
int used[300010];
ll bestdeb,bestend,bestsomme=LLONG_MIN;
vector<ll> bought(300010);
void match(ll nb){
if(nb==0){
        //cout<<"posssible matching "<<endl;
        vector<ll> tmpbought;
        ll tmpbestdeb=LLONG_MIN,tmpbestend=LLONG_MAX,tmpbestsomme=0;
    for(ll i=0;i<n;i++){
       if(used[i]==1){
           tmpbestdeb=max(tmpbestdeb,intervals[i].second.first);
           tmpbestend=min(tmpbestend,intervals[i].second.second);
       tmpbought.push_back(i);
     //  cout<<i<<" ";
       //used[i]=0;
       }
    }
    //cout<<endl;
    //cout<<tmpbestdeb<<" " <<tmpbestend<<endl;
tmpbestsomme=(tmpbestend-tmpbestdeb+1);
if(tmpbestsomme>bestsomme){
    bestsomme=tmpbestsomme;
    for(int i=0;i<k;i++){
        bought[i]=tmpbought[i];
    }
}
return ;
}
for(int i=0;i<n;i++){

    if(used[i]==0)
    {
        used[i]=1;
        match(nb-1);
        used[i]=0;
    }
}
return;
}
int main()
{
    cin>>n>>k;
    for(ll i=0;i<n;i++){
        ll deb,fin;
        cin>>deb>>fin;
        intervals.push_back(iii((fin-deb)+1,ii(deb,fin)));
    }
//    for(int i=0;i<n;i++){
//        cout<<intervals[i].first<<" "<<intervals[i].second.first<<" "<<intervals[i].second.second<<endl;
//    }
    memset(used,0,sizeof used);
    match(k);
    cout<<max((ll)0,bestsomme)<<endl;
    for(ll i=0;i<k;i++){
        cout<<bought[i]+1<<" ";
    }
    cout<<endl;
    return 0;
}
