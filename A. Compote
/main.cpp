#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int res=0;
    while(a>0){
    a--;
    if(b>=2&&c>=4)
    {
    b-=2;
    c-=4;
    res++;
    }else{

    break;}

    }
    cout<<res<<endl;
    return 0;
}
