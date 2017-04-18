#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
ll r;
int n;
vii points;
unordered_map <bitset<50>,ll> dp1;
unordered_map <bitset<50>,ll> dp2;
bool check(bitset<50> bits){
ll minx=LONG_MAX,miny=LONG_MAX,maxx=LONG_MIN,maxy=LONG_MIN;
for(int i=0;i<n;i++){
    if(bits.test(i))
    {
        minx=min(minx,points[i].first);
        maxx=max(maxx,points[i].first);
        miny=min(miny,points[i].second);
        maxy=max(maxy,points[i].second);
        if(abs(maxx-minx)>r||abs(maxy-miny)>r)
        return false;
    }

}
return true;
}

ll getsecondbest(bitset<50> bits){
if(check(bits))
    {
        return bits.count();
    }
ll res=0;
if(dp2.find(bits)!=dp2.end())
return dp2[bits];

for(int i=0;i<n;i++){
    if(bits[i]==1)
        {
        bits[i]=0;
        res=max(res,getsecondbest(bits));
        bits[i]=1;
        }
    }
return dp2[bits]=res;
}


ll getbest (bitset<50> bits){
if(check(bits))
    {
        ll tmp=bits.count();
        for(int i=0;i<n;i++)
        bits.flip(i);
        tmp+=getsecondbest(bits);
        return tmp;

    }
ll res=0;
if(dp1.find(bits)!=dp1.end())
return dp1[bits];

for(int i=0;i<n;i++){
    if(bits[i]==1)
        {
        bits[i]=0;
        res=max(res,getbest(bits));
        bits[i]=1;
        }
    }
return  dp1[bits]=res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    points.clear();
    bitset<50>bits;
    bits.reset();
    dp1.clear();
    dp2.clear();
    cin>>n>>r;
        for(int i=0;i<n;i++)
        {
            bits[i]=1;
            ll x,y;
            cin>>x>>y;
            points.push_back(ii(x,y));

        }
    cout<<"Case #"<<i+1<<": "<<getbest(bits)<<endl;
    }
    return 0;
}
