#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("out.out","w",stdout);
int t;
cin>>t;
while(t--){
int x,y,z;
bool sol=false;
cin>>x>>y>>z;    {
for(int i=-100;i<=100;i++){
        for(int j=-100;j<=100;j++){
            for(int k=-100;k<=100;k++){
                    if(!sol){
                        if((i+j+k==x)&&(i*j*k==y)&&(((i*i)+(j*j)+(k*k))==z)&&((i!=j)&&(j!=k)&&(k!=i))){
                           sol=true;
                           cout<<i<<" "<<j<<" "<<k<<endl;
                           }
                    }

                }
        }
}
if(!sol){
    cout<<"No solution."<<endl;
}

}
}
 return 0;
}
