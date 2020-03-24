#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
ll r;
int n;
vii points;
int used[50];
unordered_map <bitset<50>,int> dp;
bool check(bitset<50> bits){
ll minx=LONG_MAX,miny=LONG_MAX,maxx=LONG_MIN,maxy=LONG_MIN;
for(int i=0;i<n;i++){
    if(bits[i]==1)
    {
        minx=min(minx,points[i].first);
        maxx=max(maxx,points[i].first);
        miny=min(miny,points[i].second);
        maxy=max(maxy,points[i].second);
    }
}
return (abs(maxx-minx)<=r&&abs(maxy-miny)<=r);
}

ll getsecondbest(bitset<50> bits){
if(check(bits))
    {
        return bits.count();
    }
ll res=0;


for(int i=0;i<n;i++){
    if(bits[i]==1)
        {
        bits[i]=0;
        res=max(res,getsecondbest(bits));
        bits[i]=1;
        }
    }
return res;
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


for(int i=0;i<n;i++){
    if(bits[i]==1)
        {
        bits[i]=0;
        res=max(res,getbest(bits));
        bits[i]=1;
        }
    }
return  res;
}
int main()
{
    freopen("fighting_the_zombies.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    points.clear();
    bitset<50>bits;
    bits.reset();
    dp.clear();
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
