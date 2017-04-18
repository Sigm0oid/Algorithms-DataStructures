#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
int n;
vi p,rnk;
bool inbound(int i,int j){
    return (i>=0&&j>=0&&i<n&&j<n);
}
int xi[4]={0,-1,0,1};
int yi[4]={1,0,-1,0};
int tab[1010][1010];
ll reff[1010][1010];
ll findSet(ll i){
    if(p[i]==i)
        return i;
    else
        return p[i]=findSet(p[i]);
}
bool SameSet(ll i,ll j){
    ll x=findSet(i);
    ll y=findSet(j);
    return (x==y);
}
void unionSet(ll i,ll j){
    if(!SameSet(i,j)){
        ll x=findSet(i);
        ll y=findSet(j);
        if(rnk[x]>rnk[y])
            p[y]=x;
        else {
            p[x]=y;
            if(rnk[x]==rnk[y]) rnk[y]++;
        }
    }
}
int main()
{
    cin>>n;
    //n--;
    p.assign(n*n+4,-1);
    rnk.assign(n*n+4,0);
    memset(reff, -1, sizeof reff);
    memset(tab, 0, sizeof tab);
    int a,b;
    ll res=-1;
    ll cmp=0;
    p[n*n]=n*n;
    p[n*n+1]=n*n+1;
    while(cin>>a&&a>-1)
    {
        cin>>b;
        a--;b--;
        reff[a][b]=cmp;
        p[cmp]=cmp;
        tab[a][b]=1;
        if (a==0) unionSet(cmp,n*n);
        if (a==n-1) unionSet(cmp,n*n+1);
        for(int k=0;k<4;k++){
            int x1=a+xi[k];
            int y1=b+yi[k];
            if ((inbound(x1,y1))&&(tab[x1][y1]==1)) unionSet(cmp,reff[x1][y1]);
        }
        cmp++;
        if((SameSet(n*n,n*n+1))&&(res==-1)) {res=cmp;}
    }
    cout<<res<<endl;
    return 0;
}
