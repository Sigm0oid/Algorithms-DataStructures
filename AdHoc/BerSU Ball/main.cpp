#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n1,n2;
    cin>>n1;
    vector<int> boys;
    vector<int> girls;
    for(int i=0;i<n1;i++){
    int x;
    cin>>x;
    boys.push_back(x);
    }
    cin>>n2;
    for(int i=0;i<n2;i++){
    int x;
    cin>>x;
    girls.push_back(x);
    }
    sort(girls.begin(),girls.end());
    sort(boys.begin(),boys.end());
    int i=0,j=0,res=0;
    while(i<boys.size()&&j<girls.size()){
    if(abs(boys[i]-girls[j])<=1)
    {res++;
    i++;j++;}
    else if(boys[i]>girls[j]){
    j++;}
    else
    i++;


    }
    cout<<res<<endl;

    return 0;
}
