#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w,h,n;
    cin>>n>>w>>h;

    vector<int> fact;
    while(n!=0){
    if(n==1){
    fact.push_back(1);
    n=0;
    }
    else{
    int diviseur=2;
    while(n%diviseur!=0){
    diviseur++;}
    n/=diviseur;
    fact.push_back(diviseur);
    }
    }
    sort(fact.begin(),fact.end());
    float W=w,H=h;
    for(int i=0;i<fact.size();i++){
    //cout<<fact[i]<<" ";
    if(W>H){
    W/=fact[i];}
    else{
     H/=fact[i];}
    }
   // cout<<endl;
    cout<<min(H,W)*min(H,W)<<endl;
    return 0;
}
