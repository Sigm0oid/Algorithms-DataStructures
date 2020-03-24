#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int x=0,y=0,z=0;
    scanf("%d",&n);
    while(n--){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    x+=a;
    y+=b;
    z+=c;
    }
    //cout<<x<<" "<<y<<" "<<z<<endl;
    if(x==0&&y==0&&z==0)
    printf("YES\n");
    else
    printf("NO\n");
    return 0;
}
