#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int nb1=0,nb2=0;
    for(int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        if(c=='A')
        nb1++;
        else
        nb2++;
    }
    if(nb1>nb2)
    cout<<"Anton"<<endl;
    else if(nb2>nb1)
    cout<<"Danik"<<endl;
    return 0;
}
