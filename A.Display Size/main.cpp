#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int nb1=1;
    int nb2=n;
    int diff=n;
    for(int i=1;i<n;i++){
    int j=n/i;
    if((i*j==n)&&(abs(i-j)<diff)){
    nb1=i;
    nb2=j;
    diff=abs(i-j);
    }

    }
    cout<<min(nb1,nb2)<<" "<<max(nb1,nb2)<<endl;
    return 0;
}
