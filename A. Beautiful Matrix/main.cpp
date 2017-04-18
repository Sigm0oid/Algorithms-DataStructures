#include <bits/stdc++.h>

using namespace std;

int main()
{
    int posx,posy;
   for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
        int a;
        scanf("%d",&a);
        if(a==1)
        {posx=i+1;
        posy=j+1;}
    }
   }
   printf("%d \n",abs(3-posx)+abs(3-posy));
    return 0;
}
