#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> walks(n);
    vector<int> walks2(n);
    for(int i=0;i<n;i++)
    {
    cin>>walks[i];
    walks2[i]=walks[i];
    }
    int res=0;
    for(int i=1;i<n;i++)
    {
        if(walks[i-1]+walks[i]<k)
        {
        res+=(k-(walks[i-1]+walks[i]));
        walks[i]+=(k-(walks[i-1]+walks[i]));
        }

    }
    cout<<res<<endl;
    for(int i=0;i<n;i++)
    cout<<walks[i]<<" ";
    cout<<endl;

    return 0;
}
