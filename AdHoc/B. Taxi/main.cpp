#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    ll nbr4=0,nbr3=0,nbr2=0,nbr1=0;
    while(n--){
        int x;
        cin>>x;
         if(x==1){nbr1++;}
         if(x==2){nbr2++;}
         if(x==3){nbr3++;}
         if(x==4){nbr4++;}


    }
    ll res=nbr4+nbr3;
    nbr1-=nbr3;
    res+=(nbr2/2);
    nbr2=nbr2%2;
    if(nbr2>0){
        res+=1;
    if(nbr1<=2){nbr1=0;}
    else{nbr1-=2;}
    }

        if(nbr1>0){res+=(nbr1/4);
                    nbr1=(nbr1%4);
                    if(nbr1>0){
                        res++;
                    }
    }

    cout<<res<<endl;

    return 0;
}
