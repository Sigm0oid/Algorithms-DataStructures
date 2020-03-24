#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> tab;
    tab.resize(n);
    bool ok=true;
    for(int i=0;i<n;i++){
    cin>>tab[i];
    }
    for(int i=0;i<n-1;i++){
    if(tab[i]<0){
    ok=false;}
    if(tab[i]>0){
    if(tab[i]%2==1){
    tab[i+1]-=1;
    }
    }
    }
    if(tab[n-1]%2==1||tab[n-1]<0){
    ok=false;
    }
    if(ok){
    cout<<"YES"<<endl;}
    else {
    cout<<"NO"<<endl;}
    return 0;
}
