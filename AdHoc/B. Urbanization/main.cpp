#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,n1,n2;
    cin>>n>>n1>>n2;
    vector<int> pepole;
    for(int i=0;i<n;i++)
    {int x;
    cin>>x;
    pepole.push_back(x);
    }
    sort(pepole.begin(),pepole.end());
    double somme1=0,somme2=0;
    for(int i=n-1;i>=0;i--)
    {

    if((n-i)<=(min(n1,n2)))
    somme1+=pepole[i];
    else if((n1+n2)>=(n-i))
    somme2+=pepole[i];
    }
    //cout<<somme1<<" "<<somme2<<endl;
    printf("%.8f \n",somme1/min(n2,n1)+somme2/max(n1,n2));
    return 0;
}
