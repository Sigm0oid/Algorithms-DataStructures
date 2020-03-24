#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
  int n,x;
   cin>>n>>x;
    int tab[n];
    ll res=0;
    map<int,int> nums;
    for(int i=0;i<n;i++)
    {
    cin>>tab[i];

    if(nums.find(tab[i])!=nums.end())
    {
    res+=nums[tab[i]];
    }

    nums[tab[i]^x]++;
    }
    cout<<res<<endl;
    return 0;
}
