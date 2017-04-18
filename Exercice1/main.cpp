#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
    int &ref_a=a;
    int *point_a=&a;
    cout<<" donner un entier "<<endl;
    cin>>a;
    cout<<" -Variable i"<<a<<endl;
    cout<<" -Variable ref_i="<<ref_a<<endl;
    cout<<" -Variable p_i"<<point_a<<endl;
    cout<<" Leur Adresses"<<endl;
    cout<<" adresse de i "<<&a<<endl;
    cout<<" adresse de ref_i "<<&ref_a<<endl;
    cout<<" adresse de p_i "<<&point_a<<endl;
    cout<<" valeur pointer "<<a<<endl;


    return 0;
}
