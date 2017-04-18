#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
unordered_map<ll,vector<ll> > bids;
map<ll,ll> maximum_bids;
vector<ii> maximum_bids_vector,tmp;
ll n,q;
int main()
{

    cin>>n;
    while(n--){
        ll a,b;
        cin>>a>>b;
        bids[a].push_back(b);

            }
    for(auto i=bids.begin();i!=bids.end();i++)
    {
        maximum_bids_vector.push_back(ii(i->second.back(),i->first));

    }
    sort(maximum_bids_vector.begin(),maximum_bids_vector.end());




    set<ll> rem;
    cin>>q;
    while(q--){
    rem.clear();
    ll nb;
    cin>>nb;

    while(nb--){
    ll a;cin>>a;
    rem.insert(a);
    }
    tmp.clear();
    int max1=-1,max2=0;
    for(ll i=maximum_bids_vector.size()-1;i>=0;i--){
        if(rem.count(maximum_bids_vector[i].second)!=1){
            if(max1==-1)max1=maximum_bids_vector[i].second;
            else {
                max2=maximum_bids_vector[i].second;
                break;
            }

        }
    }

    if(max1==-1)
    cout<<"0 0"<<endl;
    else if(max2==0)
    {
    cout<<max1<<" "<<bids[max1][0]<<endl;

    }else
    //ll res=;
    cout<<max1<<" "<<bids[max1][upper_bound(bids[max1].begin(),bids[max1].end(),bids[max2].back())-bids[max1].begin()]<<endl;

    }


    return 0;
}
