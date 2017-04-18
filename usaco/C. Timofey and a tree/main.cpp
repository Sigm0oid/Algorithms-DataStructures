#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
vector<vii> Adjlist;
ll n;
vector<ll> colors;
vector<int> vis;
map<ll,int> mapcolors;
bool found=false;
ll x=-1,x1=-1;
ll src=0;
void dfs(ll s){
//cout<<" vis "<<s<<endl;
if(found)
return;
vis[s]=1;
for(int i=0;i<Adjlist[s].size();i++){
    ii v=Adjlist[s][i];
    if(vis[v.first]==0)
    {
    if(colors[v.first]==colors[s]||s==src)
    dfs(v.first);
    else{

       // if(colors[s]!=colors[src])
        x=s;
        //else
        x1=v.first;
        found=true;
    }

    }

}

}


int main()
{

    cin>>n;
    colors.resize(n);
    Adjlist.resize(n);
    vis.resize(n);
    for(int i=0;i<n-1;i++)
    {
    ll a,b;
    cin>>a>>b;
    Adjlist[a-1].push_back(ii(b-1,1));
    Adjlist[b-1].push_back(ii(a-1,1));
    }
    for(int i=0;i<n;i++)
    {
        cin>>colors[i];
        mapcolors[colors[i]]++;
    }

//    if(mapcolors.size()>3)
//    cout<<"NO"<<endl;
//    else{
        dfs(0);
        if(found==0)
        cout<<"YES"<<endl<<1<<endl;
        else{
            found=false;
            src=x;
            x=-1;
            ll tmpx1=x1;
            x1=-1;
            vis.assign(n,0);
            dfs(src);
            if(found)
            {
            found=false;
            src=tmpx1;
            x=-1;
            //tmpx1=x1;
            x1=-1;
            vis.assign(n,0);
            dfs(src);
            if(found)
            cout<<"NO"<<endl;
            else{
                cout<<"YES"<<endl<<src+1<<endl;
            }
            }
            else
            cout<<"YES"<<endl<<src+1<<endl;
        //}

    }



    return 0;
}
