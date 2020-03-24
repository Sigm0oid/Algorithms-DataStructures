#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
map<int,int> factors;
int n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
    int x;
    cin>>x;
    int racine=sqrt(x);
    for(int j=2;j<=racine;j++){
        if(x%j==0)
        factors[j]++;
        while(x%j==0){
        x/=j;
        }


    }
    if(x>1)
        factors[x]++;
    }
    int ans=1;
    for(auto i=factors.begin();i!=factors.end();i++){
    //cout<<i->first<<i->second<<endl;
    ans=max(ans,i->second);
    }
    cout<<ans<<endl;

}
