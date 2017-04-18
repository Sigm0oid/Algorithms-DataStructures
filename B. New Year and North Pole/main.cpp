#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n ;
    //vector <pair<long,string> > v ;
    bool ok = true ;
    long long d=0;
    for (int i=0;i<n;i++)
    {
         long long x ;
        string s ;
        cin >> x >> s ;
        if (d==0 && s!="South")
        {
            ok=false ;
            break;
        }
        else if (d==20000 && s!="North")
        {
            ok=false ;
            break ;
        }
        else
        {
            if (s=="South")
            {
                d+=x ;

                if(d>20000)
               {

                ok=false ;
                break ;
               }

                d%=40000;
            }
            else if (s=="North")
            {

                d-=x ;
                if(d<0)
                {
                ok=false ;
                break ;
                }
                d%=40000;
            }
        }
    }
    if (ok==true && d==0)
    {
      cout << "YES" << endl ;
    }
    else
        {
            cout << "NO" << endl ;
        }
    return 0;
}
