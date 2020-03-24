#include <bits/stdc++.h>

using namespace std;

int main()
{
int n,m;
    cin>>n>>m;
    vector<int> flowers;
    for(int i=0;i<n;i++)
    {int x;
    cin>>x;
    flowers.push_back(x);
    }
    int res=0;
    for(int i=0;i<m;i++)
     {
        int a,b;
        cin>>a>>b;
        int tmp=0;
        for(int j=a-1;j<=b-1;j++){
            tmp+=flowers[j];
        }
        if(tmp>0)
        res+=tmp;
     }
     cout<<res<<endl;




    return 0;
}
