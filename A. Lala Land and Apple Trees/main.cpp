#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

int n;
vii r;
vii l;

int main()
{
    cin>>n;

    for(int i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        if(a<0)
        l.push_back(ii(-1*a,b));
        else
        r.push_back(ii(a,b));
    }
    sort(r.begin(),r.end());
    sort(l.begin(),l.end());
    ll somme=0;
    int i=0;
    for(int i=0;i<(min(l.size(),r.size())+1);i++){
    if(i<r.size()&&i<l.size())
    somme+=(l[i].second+r[i].second);
    else if (i==l.size()&&i<r.size())
    somme+=r[i].second;
    else if (i==r.size()&&i<l.size())
    somme+=l[i].second;
    }

    cout<<somme<<endl;
    return 0;
}
