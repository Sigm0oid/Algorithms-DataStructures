#include <bits/stdc++.h>

using namespace std;
int mounth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int m,n;
    cin>>m>>n;

    int res=(mounth[m-1]+abs(1-n))/7;
    if(((mounth[m-1]+abs(1-n))%7)>0)
    res++;
    cout<<res<<endl;
    return 0;
}
