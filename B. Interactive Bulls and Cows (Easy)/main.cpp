#include <bits/stdc++.h>

using namespace std;

vector<int> to_use;
int main()
{
    int i=0;
   vector<int> to_use;
    string stab[10]={"0000","1111","2222","3333","4444","5555","6666","7777","8888","9999"};
        //find num exist;

    for(int i=0;i<10&&to_use.size()<4;i++){
        string s=stab[i];
        cout<<s<<endl;
        fflush(stdout);
        int a,b;
        cin>>a>>b;
        if(a+b>0){
            for(int j=0;j<a+b;j++)
                to_use.push_back(i);
        }
    }
//    cout<<" bonjour"<<endl;
//    for(int i=0;i<to_use.size();i++){
//        cout<<to_use[i]<<" ";
    //}
    //i have the four numbers;
     int a,b;
      do{

        string s="";
                s+='0'+to_use[0];
                s+='0'+to_use[1];
                s+='0'+to_use[2];
                s+='0'+to_use[3];
        cout<<s<<endl;
        fflush(stdout);
        cin>>a>>b;
    }
    while(next_permutation(to_use.begin(),to_use.end())&&a!=4);
    return 0;
}
