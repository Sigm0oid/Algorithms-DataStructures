#include <bits/stdc++.h>

using namespace std;

void incrementer(int * pointer){
    (*pointer)++;
return ;
}

void swapping(int * pointer1,int * pointer2){
     swap(*pointer1,*pointer2);
 return ;
}


int main()
{
    int a;
    int b;

    cout<<"donner valeur de A "<<endl;

    cin>>a;
    cout<<"donner valeur de B "<<endl;
    cin>>b;

    cout<<" Appell par Address"<<endl;
    incrementer(&a);
    cout<<"la valeur de  A apres incrementation :"<<a<<endl;
    swapping(&a,&b);
    cout<<" Valeur A apres Permutation "<<a<<endl;
    cout<<" Valeur b apres Permutation "<<b<<endl;

    cout<<" Appell par Reference"<<endl;
    int &ref_a=a;
    int &ref_b=b;
    incrementer(&ref_a);
    cout<<"la valeur de  A apres incrementation :"<<a<<endl;
    swapping(&ref_a,&ref_b);
    cout<<" Valeur A apres Permutation "<<a<<endl;
    cout<<" Valeur b apres Permutation "<<b<<endl;




        return 0;
}
