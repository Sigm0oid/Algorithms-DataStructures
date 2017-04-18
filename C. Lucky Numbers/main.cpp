#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    long long res=0;
     while(n>0){
     res+=(pow(2,n));
     n--;
     }
     cout<<res<<endl;
    return 0;
}
