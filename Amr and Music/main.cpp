#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<pair<int,int> > tab;
    for(int i=0;i<n;i++){
    int x;
    cin>>x;
    tab.push_back(make_pair(x,i+1));}
    sort(tab.begin(),tab.end());
    int i=0,res=0;
    vector<int> r;
    while(k>0&&i<tab.size()){
    k-=tab[i].first;
    if(k>=0){
    res++;
    r.push_back(tab[i].second);
    }
    i++;
    }
    cout<<res<<endl;
    for(int i=0;i<r.size();i++)
    cout<<r[i]<<" ";
    cout<<endl;
    return 0;
}
