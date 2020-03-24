#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
char stage[1010][1010];
int res[1010][1010];
int n,m;
void calcule(){

for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
if(stage[i][j]=='1')
{

         for(int k=j+1;k<m;k++)
        {
            if(stage[i][k]=='1')
            {
            break;
            }
            else
            res[i][k]++;
        }

         for(int k=j-1;k>=0;k--)
        {
            if(stage[i][k]=='1')
            {
            break;
            }
            else{
            res[i][k]++;
            }
        }

         for(int k=i+1;k<n;k++)
        {
            if(stage[k][j]=='1')
            {
            break;
            }
            else
            res[k][j]++;
        }

         for(int k=i-1;k>=0;k--)
        {
            if(stage[k][j]=='1')
            {
            break;
            }
            else
            res[k][j]++;
        }

}
}
}

}




int main()
{

   cin>>n>>m;
   memset(res,0,sizeof res);

    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
    {
    cin>>stage[i][j];

    }
    }
    ll ans=0;
    calcule();
     for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    ans+=res[i][j];
    cout<<ans<<endl;

    return 0;
}

