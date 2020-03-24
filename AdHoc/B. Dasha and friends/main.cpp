#include <bits/stdc++.h>

using namespace std;
int n,l;
vector<int> tab1;
vector<int> tab2;
vector<int> test;
bool comp(vector<int> t1,vector<int> t2){
//for(int i=0;i<t2.size();i++)
//cout<<t1[i]<<" ";
//cout<<endl;
sort(t1.begin(),t1.end());
sort(t2.begin(),t2.end());
for(int i=0;i<t2.size();i++)
if(t2[i]!=t1[i])
return false;

return true;
}
int main()
{

    cin>>n>>l;
    tab1.resize(n);
    tab2.resize(n);
    test.resize(n);
    for(int i=0;i<n;i++){
    cin>>tab1[i];
    }
    for(int i=0;i<n;i++){
    cin>>tab2[i];
    }
    bool ok=false;
    for(int i=0;i<=l;i++){
        for(int j=0;j<n;j++)
        {
        test[j]=(tab1[j]+i)%l;
        }
        if(comp(test,tab2))
        {
        ok=true;
        break;
        }

    }
    if(ok)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    return 0;
}
