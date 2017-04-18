#include <bits/stdc++.h>

using namespace std;
int n;
int tab[3];
int main()
{
    cin>>n>>tab[0]>>tab[1]>>tab[2];

    int res=0;
    for(int i=0;i<=4000;i++)
    {
    for(int j=0;j<=4000;j++)
    {

            if(n>=i*tab[0]+j*tab[1]&&((n-(i*tab[0]+j*tab[1]))%tab[2])==0){
            //cout<<" rest "<<endl;
            res=max(res,i+j+(n-(i*tab[0]+j*tab[1]))/tab[2]);

        }
     }
    }
    cout<<res<<endl;
    return 0;
}
