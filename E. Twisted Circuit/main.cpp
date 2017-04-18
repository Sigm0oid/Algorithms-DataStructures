#include <bits/stdc++.h>

using namespace std;

int main()
{
    bool a,b,c,d;
    cin>>a>>b>>c>>d;
    bool l1,l2,l3,l4;
    l1=a^b;
    l2=c|d;
    l3=c&b;
    l4=a^d;
    //cout<<l1<<l2<<l3<<l4<<endl;
    bool l11=l1&l2,l22=l3|l4;
    cout<<(l11^l22)<<endl;

    return 0;
}
