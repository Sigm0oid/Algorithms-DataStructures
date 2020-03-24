#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int ligne=(k/(m*2));
    if((k%(m*2))>0)
    ligne++;
    int col;char pos;
    k=(k%(m*2));
    if(k==0)
    {
        col=m;
        pos='R';
    }

    else{
     col=(k/2);
    if(k%2>0)
    col++;

    if(k%2>0)
    pos='L';
    else
    pos='R';
    }
    cout<<ligne<<" "<<col<<" "<<pos<<endl;
    return 0;
}
