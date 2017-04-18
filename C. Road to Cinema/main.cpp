#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<ii > vii;
int n,k,s,t;
vii cars;
vector<int> gas;
int main()
{
    cin>>n>>k>>s>>t;
    cars.resize(n);
    gas.resize(k);
    for(int i=0;i<n;i++)
    cin>>cars[i].first>>cars[i].second;
    for(int i=0;i<k;i++)
    cin>>gas[i];
    sort(gas.begin(),gas.end());
    sort(cars.begin(),cars.end());
    int max_dist=s;
    for(int i=1;i<k;i++){
    max_dist=min(gas[i]-gas[i-1],max_dist);
    }
    int ans=-1;
    max_dist=min(max_dist,s-gas[k-1]);
    for(int i=0;i<n;i++){
    if(cars[i].second>=max_dist&&t<=s)
    ans=
    }

    return 0;
}
