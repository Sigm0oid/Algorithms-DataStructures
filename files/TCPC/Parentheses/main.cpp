#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s="";
    n*=2;
    for (int i=0;i<n/2;i++)
    {
        s+="(";
    }
    for (int i=n/2;i<n;i++)
    {
        s+=")";
    }
    sort (s.begin(),s.end());
    //vector <string> v;
  //  v.push_back(s);
    while (next_permutation(s.begin(),s.end()))
    {
    //cout<<s<<endl;
 int a=0,b=0;
        bool parenthese=true ;
        for (int i=0;i<n;i++)
        {
            if (s[i]=='(')
                    a++;
            else
                b++;
            if (b>a)
                parenthese= false;
        }
         cout <<a<<" "<<b<<endl;
        if (test== true){
            v.push_back(s);
           }
    }
    sort (v.begin(),v.end());
    for (int i=0;i<v.size();i++)
        cout << v[i] << endl;
    return 0;
}
