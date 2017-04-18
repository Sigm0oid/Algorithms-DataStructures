#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
vector<ll> tab;
bool exist(ll a){
    if(a==-1){return true;}
    else{
ll i =0;
bool found=false;
while((i<n)&&(!found)){
    if(tab[i]==a)
        {found=true;}
    i++;
}
return found;
    }

}


int main()
{

    cin>>n;
    tab.resize(n);
    for(ll i=0;i<n;i++){
        cin>>tab[i];
    }
    sort(tab.begin(),tab.end());
    ll nbrgroup=1;
    ll diff=-1;
    ll  cmpdiff=0;

     for(ll i=1;i<n;i++){

            if(tab[i]!=tab[i-1]){
                    nbrgroup++;
           if(tab[i]-tab[i-1]!=diff){
            diff=tab[i]-tab[i-1];
            cmpdiff++;}
            }

    }
//    cout<<"nbr group "<<nbrgroup<<endl;
//    cout<<" cmpdiff "<<cmpdiff<<endl;
//    cout<<" diff "<<diff<<endl;


    bool res=((cmpdiff<=1)&&(nbrgroup<=3));





    if(res){cout<<"YES"<<endl;}
    else{cout<<"NO"<<endl;}

    return 0;
}
