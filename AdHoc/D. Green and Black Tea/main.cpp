#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
        ll n,k,a,b;
        int tea[2];
        char tea_char[2]={'G','B'};
        cin>>n>>k>>tea[0]>>tea[1];
        string s="";
        int first;
        int maax;
        int now;
        if(tea[0]>tea[1])
        {
        now=0;
        }
        else
        {
        now=1;
        }

        for(int i=0;i<n;i++){
        //cout<<s<<endl;
            if(tea[now]==0){
            break;
            }
             tea[now]--;
             s+=tea_char[now];
            for(int j=1;j<k&&tea[now]>=tea[1-now]&&tea[now]>0;j++)
                {
                tea[now]--;
                s+=tea_char[now];
                }
            now=(1-now);
            //cout<<tea[now]<<endl;
            }

        if(s.length()<n){
        cout<<"NO"<<endl;}
        else{
        cout<<s<<endl;
        }
    return 0;
}
