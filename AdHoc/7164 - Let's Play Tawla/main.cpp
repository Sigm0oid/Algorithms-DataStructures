#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    string tab[6]={"Yakk","Doh","Seh","Ghar","Bang","Sheesh"};
    for(int i=0;i<t;i++){
    int a,b;
    cin>>a>>b;
    if((a==5&&b==6)||(a==6&&b==5))
    cout<<"Sheesh Beesh"<<endl;
    else{
    if(a!=b)
    cout<<tab[a-1]<<" "<<tab[b-1]<<endl;
    else{
    switch(a){
    case 1:cout<<"Habb Yakk"<<endl;
    case 2:cout<<"Dobara"<<endl;
    case 3:cout<<"Dousa"<<endl;
    case 4:cout<<"Dorgy"<<endl;
    case 5:cout<<"Dabash"<<endl;
    case 6:cout<<"Dosh"<<endl;
    default:cout<<" "<<endl;
    }


    }
    }
    }
    return 0;
}
