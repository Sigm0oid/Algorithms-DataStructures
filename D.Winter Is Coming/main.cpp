#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n=0,k=0;
ll tab[300200];

int main()
{
    cin>>n>>k;
    ll cnt=0;
    vector<ll> summer;
    bool ispositive=true;
    ll nbr_seg_neg=0;
    for(ll i=0;i<n;i++){
        cin>>tab[i];
        if(tab[i]<0)
           {
           cnt++;
           if(ispositive==true)
           nbr_seg_neg++;
           ispositive=false;

           }
           else
           ispositive=true;


    }
    ll tmp_cmp=0;
    for(ll i=0;i<n;i++){
        if(tab[i]>=0)
        tmp_cmp++;
        else{
            if(tmp_cmp>0)
            summer.push_back(tmp_cmp);
            tmp_cmp=0;
        }
    }
    //if first seg is positive delet it from vector
    if(tab[0]>=0&&summer.size()>0)
    summer.erase(summer.begin());


    if(cnt>k)
    cout<<"-1"<<endl;
    else if(cnt==0)
    cout<<"0"<<endl;
    else{
        k-=cnt;
        sort(summer.begin(),summer.end());
        ll sol1=(nbr_seg_neg*2);
        while(k>0&&summer.size()>0){
        if(summer[0]>k)
        break;
        k-=summer[0];
        sol1-=2;
        summer.erase(summer.begin());
        }
        if(k>=tmp_cmp)
        sol1--;
        cout<<sol1<<endl;

      }


    return 0;
}
