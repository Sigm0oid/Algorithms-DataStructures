#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int goss,insect,ngoss,ninsect;
    for(int i=0;i<n;i++)
    {if(s[i]=='G')
    ngoss=i;
    if (s[i]=='T')
    ninsect=i;
    }
    goss=min(ngoss,ninsect);
    insect=max(ngoss,ninsect);
    bool ok=false;
    for(int i=goss;i<=insect;i+=k)
    {
    //cout<<"Im on "<<i<<endl;
    if(s[i]=='#')
    {ok=false;
    break;
    }
    if(i==insect)
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
