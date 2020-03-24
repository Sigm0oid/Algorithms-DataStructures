#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<pair<ll,ll> > nums;
void fuck(int i, long long minx, long long maxx) {
    if (i>=nums.size()) {ranges[minx]=maxx;return;}
    fuck(i+1,((nums[i].first<minx)?nums[i].first:minx),((nums[i].first>maxx)?nums[i].first:maxx));
    fuck(i+1,((nums[i].second<minx)?nums[i].second:minx),((nums[i].second>maxx)?nums[i].second:maxx));
}

int main()
{
    int n,q,t;
    cin>>t;
    while(t--){
        cin>>n>>q;
        ranges.clear();
        nums.clear();
        ll a,b;
        for(int i=0;i<n;i++)
        {
         cin>>a>>b;
         nums.push_back(make_pair(min(a,b),(a,b)));
        }
        fuck(0,nums[0].first,nums[0].first);
        fuck(0,nums[0].second,nums[0].second);
        long long x;
        for(int i=0;i<q;i++){
            cin >> x;
            int yes=1;
            for(map<long long ,long long>::iterator i=ranges.begin();i!=ranges.end();i++){
                if ((x<i->first)||(x>i->second)) yes=0;
            }
            cout << ((yes==1)?"YES":"NOT SURE") << endl;
        }
    }
    return 0;
}
