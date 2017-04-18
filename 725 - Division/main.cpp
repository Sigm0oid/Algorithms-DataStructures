#include <bits/stdc++.h>

using namespace std;

int main()
{
   // freopen("out.out","w",stdout);
    ios_base::sync_with_stdio(false);
    int n;
    bool test=false;
    while((cin>>n)&&(n>0)){

            if(test){  cout<<endl;}
            if(!test){test=true;}
            int cmp=0;

        for(int fghij=1234;fghij<=98765/n;fghij++){
                int abcde=fghij*n;
            int tmp,used=(fghij<10000);
            tmp=abcde;while(tmp){ used|=1<<(tmp%10);tmp/=10;}
            tmp=fghij;while(tmp){ used|=1<<(tmp%10);tmp/=10;}
            if(used==(1<<10)-1){
                    if(abcde<10000){cout<<0;}
                cout<<abcde<<" / ";
                  if(fghij<10000){cout<<0;}
                  cout<<fghij<<" = "<<n<<endl;
                cmp++;
            }


        }if(cmp==0){
    cout<<"There are no solutions for "<<n<<"."<<endl;
    }


    }


    return 0;
}
