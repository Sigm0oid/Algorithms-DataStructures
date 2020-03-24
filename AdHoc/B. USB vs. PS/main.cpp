#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll tab[3];
    memset(tab,0,sizeof tab);
    cin>>tab[0]>>tab[1]>>tab[2];
    int m;
    vector<ll>  usb;
    vector<ll>  ps2;
    cin>>m;
    for(ll i=0;i<m;i++){
    ll x;
    string s;
    cin>>x>>s;
    if(s=="USB")
    usb.push_back(x);
    else
    ps2.push_back(x);
    }
    sort(ps2.begin(),ps2.end());
    sort(usb.begin(),usb.end());
    ll i=0,j=0;
    ll somme=0;
    ll cmp=0;
    while(tab[0]>0&&i<usb.size()){
    somme+=usb[i];
    cmp++;
    i++;
    tab[0]--;
    }
    while(tab[1]>0&&j<ps2.size()){
    somme+=ps2[j];
    j++;
    tab[1]--;
    cmp++;
    }
    while(tab[2]>0&&(i<usb.size()||j<ps2.size())){
    if(i<usb.size()&&j<ps2.size())
    {
     somme+=min(ps2[j],usb[i]);
     if(usb[i]<ps2[j])
     i++;
     else
     j++;


    }
    else if (i<usb.size()){
        somme+=usb[i];
        i++;
    }else{
        somme+=ps2[j];
        j++;
    }
    tab[2]--;
    cmp++;
    }

    cout<<cmp<<" "<<somme<<endl;
    return 0;
}

