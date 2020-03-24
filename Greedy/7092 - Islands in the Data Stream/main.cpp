#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> nums;
ll isibizi(){
ll res=0;

for(int i=1;i<=10;i++){
    for(int j=i;j<11;j++){
   // cout<<i<<" "<<j<<endl;
        ll miin=INT_MAX;
        for(int k=i;k<=j;k++){
            miin=min(miin,nums[k]);
        }
        if(miin>nums[i-1]&&miin>nums[j+1])
        res++;
    }
}
return res;

}
int main()
{
    ll t;
    cin>>t;
    while(t--){
    ll nb_test,n;
    nums.clear();
    cin>>nb_test;
        for(int i=0;i<12;i++)
        {
        ll x;
        cin>>x;
        nums.push_back(x);
        }
    cout<<nb_test<<" "<<isibizi()<<endl;


    }
    return 0;
}
