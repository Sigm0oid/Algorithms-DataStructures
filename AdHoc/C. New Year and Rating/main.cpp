#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int main()
{
        ll n;
        cin>>n;
        vector<pair<int,int> > tab;
        for(ll i =0;i<n;i++){
            ll c,d;
            cin>>c>>d;
            tab.push_back(ii(c,d));

        }
            vector<int> next_div;
        for(int i=0;i<n-1;i++){
            next_div.push_back(tab[i+1].second);
        }
        int minrat=INT_MIN;
        int maxrat=INT_MAX;
        bool possible=true;
        for(int i=0;i<n-1;i++){
            if(tab[i].second==1&&next_div[i]==2&&tab[i].first>=0){
             possible=false;
             break;
            }
            if(tab[i].second==2&&next_div[i]==1&&tab[i].first<=0){
             possible=false;
             break;
            }

        }
        vector<ii> poss;
        for(int i=0;i<n-1;i++){
            if(next_div==tab[i].second){
                poss.push_back(ii(INT_MAX,INT_MIN));

            }
            if(tab[i].second==1){
                poss.push_back(1899-tab[i].first,1900);
            }
            if(tab[i].second==2){
                poss.push_back(1899,1900-tab[i].first);
            }

            maxrat=min(maxrat,poss[i].first);
            minrat=max(minrat,poss[i].second);

        }

    return 0;
}

