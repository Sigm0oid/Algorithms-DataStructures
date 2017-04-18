#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int nb1=0,nb2=0;
    for(int  i=0;i<n;i++){
    char c;
    cin>>c;
    if(c=='0')
    nb1++;
    else
    nb2++;}
    cout<<abs(nb1-nb2)<<endl;
    return 0;
}
