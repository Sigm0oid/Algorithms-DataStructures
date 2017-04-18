#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long  n,a,b,c,k;
    cin>>n>>a>>b>>c;

    long long res=LLONG_MAX;

    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            for(int k=0;k<10;k++)
            if(((n+k+2*j+3*i)%4)==0)
             {
             //cout<<"possible with "<<i<<" "<<j<<" "<<k<<" pricce "<<k*a+j*b+i*c<<endl;
             res=min(res,k*a+j*b+i*c);
             }
    cout<<res<<endl;
    return 0;
}
