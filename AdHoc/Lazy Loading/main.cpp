#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> itemstab;
int n;
int divide(){
if(itemstab[itemstab.size()-1]*itemstab.size()<50)
    return 0;
    if(itemstab[itemstab.size()-1]*itemstab.size()){
        int cmp=0;
        while((cmp+1)*itemstab[itemstab.size()-1]<50)
            cmp++;
        itemstab.erase(itemstab.begin(),itemstab.begin()+cmp);
        itemstab.erase(itemstab.begin()+itemstab.size()-1);
        return 1+divide();
    }
}










int main()
{
  //  fichier input
    freopen("lazy_loading.txt","r",stdin);
    //fichier output
    freopen("lazy_loading_out.txt","w",stdout);
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
    cin>>n;
    itemstab.clear();
        for(int j=0;j<n;j++){
                int wi;
                cin>>wi;
                itemstab.push_back(wi);
        }
    sort(itemstab.begin(),itemstab.end());
    cout<<"Case #"<<k+1<<": "<<divide()<<endl;
    }
    return 0;
}
