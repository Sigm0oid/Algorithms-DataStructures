#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
float combinaison(int n,int q) //la Combinaison de q éléments parmi n
{
float comb;
if(n==q)
{
return 1;
}
else
if(q==1)
{
 return n;
}
else
{
 comb=(n/q)*combinaison(n-1,q-1);
 return comb;
}
}
int n;
int x[3000];
int y[3000];
ll length(int i,int j){

return((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));

}
map<ll,int> dis;
int main()
{
    freopen("boomerang_constellations.txt","r",stdin);
    freopen("out.out","w",stdout);
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
    cin>>n;
         for(int j=0;j<n;j++){
            cin>>x[j]>>y[j];
         }
         ll res=0;
         for(int j=0;j<n;j++){
         dis.clear();
            for(int k=0;k<n;k++){
                if(k==j)
                continue;
                    dis[length(j,k)]++;

                }
            for(auto j=dis.begin();j!=dis.end();j++)
            res+=((j->second-1)*j->second);

            }
    cout<<"Case #"<<t+1<<": "<<res/2<<endl;
    }
    return 0;
}
