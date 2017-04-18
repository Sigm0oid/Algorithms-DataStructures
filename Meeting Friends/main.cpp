#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,y,z;
    cin>>x>>y>>z;
    int minx =min(x,y);
    int maxx=max(x,y);
        minx=min(minx,z);
        maxx=max(maxx,z);
        int point;
        // =(maxx+minx)/2;
        int moy;
        if(x!=minx&&x!=maxx){
            moy=x;
        }
         if(y!=minx&&y!=maxx){
            moy=y;
        }
         if(z!=minx&&z!=maxx){
            moy=z;
        }
        point =moy;


        cout<<(abs(x-point)+abs(y-point)+abs(z-point))<<endl;
    return 0;
}
