#include <bits/stdc++.h>

using namespace std;

void min_max(int a,int b,int * pnt_max,int *pnt_min){

(*pnt_max)=a;
(*pnt_min)=b;
    if(a<b) {
    (*pnt_max)=b;
    (*pnt_min)=a;
    }
return ;
}
int main()
{
    int a,b;
    int miin,maax;
    int *pnt_min=&miin;
    int *pnt_max=&maax;
    cout<<" par Adress "<<endl;
    cout<<" Donner la veleur de A"<<endl;
    cin>>a;
    cout<<" Donner la veleur de B"<<endl;
    cin>>b;
    min_max(a,b,pnt_max,pnt_min);
    cout<<" le min est "<<miin<<endl;
    cout<<" le max est "<<maax<<endl;

    cout<<" par Refernce  "<<endl;
    int &ref_b=b;
    int &ref_a=a;
    min_max(ref_a,ref_b,pnt_max,pnt_min);
    cout<<" le min est "<<miin<<endl;
    cout<<" le max est "<<maax<<endl;

    return 0;
}

