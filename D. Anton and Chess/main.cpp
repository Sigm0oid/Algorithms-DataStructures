#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<char,ii> cii;
typedef vector<cii> viii;


viii black;
int n;
int xking,yking;
vector<cii> diag1(1);//top right
vector<cii> diag2(1);//top left
vector<cii> diag3(1);//down left
vector<cii> diag4(1);//down right
vector<cii> row1(1);//right
vector<cii> row2(1);//left
vector<cii> col1(1);//top
vector<cii> col2(1);//down

bool check(){
return(diag1[0].first=='B'||diag1[0].first=='Q'||diag2[0].first=='B'||diag2[0].first=='Q'
||diag3[0].first=='Q'||diag3[0].first=='B'||diag4[0].first=='Q'||diag4[0].first=='B'
||col1[0].first=='R'||col1[0].first=='Q'||col2[0].first=='R'||col2[0].first=='Q'||row1[0].first=='R'||row1[0].first=='Q'||row2[0].first=='R'||row2[0].first=='Q');

}
void place(cii rock){
if(rock.second.first==xking)
{

    if(rock.second.second<yking&&row2[0].second.second<rock.second.second)
    row2[0]=rock;
    else if(rock.second.second>yking&&row1[0].second.second>rock.second.second)
    row1[0]=rock;
return;
}
else if(rock.second.second==yking)
{
    if(rock.second.first<xking&&col1[0].second.first<rock.second.first)
    col1[0]=rock;
    else if(rock.second.first>xking&&col2[0].second.first>rock.second.first)
    col2[0]=rock;

return ;
}
else if(abs(rock.second.first-xking)==abs(rock.second.second-yking))
{
    //cout<<"same diag"<<rock.second.first<<" "<<diag1[0].second.first<<endl;
    if(rock.second.first<xking&& rock.second.second>yking&&diag1[0].second.second>rock.second.second)
     diag1[0]=rock;
    else if(rock.second.first>xking&& rock.second.second<yking&&diag2[0].second.first>rock.second.first)
    diag2[0]=rock;
    else if(rock.second.first<xking&& rock.second.second<yking&&diag3[0].second.first<rock.second.first)
     diag3[0]=rock;
    else if(rock.second.first>xking&& rock.second.second>yking&&diag4[0].second.first>rock.second.first)
    diag4[0]=rock;

return;
}



}
int main()
{
    cin>>n;
    cin>>xking>>yking;
    cii black;
    cii test;

    test.first='A';
    test.second.first=INT_MAX;
    test.second.second=INT_MAX;
    diag4[0]=test;

    diag1[0].first='A';
    diag1[0].second.first=INT_MIN;
    diag1[0].second.second=INT_MAX;

    diag2[0].first='A';
    diag2[0].second.first=INT_MAX;
    diag2[0].second.second=INT_MIN;

    diag3[0].first='A';
    diag3[0].second.first=INT_MIN;
    diag3[0].second.second=INT_MIN;

    col1[0].first='A';
    col1[0].second.first=INT_MIN;
    col1[0].second.second=yking;

    col2[0].first='A';
    col2[0].second.first=INT_MAX;
    col2[0].second.second=yking;

    row1[0].first='A';
    row1[0].second.first=xking;
    row1[0].second.second=INT_MAX;

    row2[0].first='A';
    row2[0].second.first=xking;
    row2[0].second.second=INT_MIN;

    for(int i=0;i<n;i++)
    {cin>>black.first>>black.second.first>>black.second.second;
    place(black);
    }
//    cout<<diag1[0].first<<endl;
//    cout<<diag2[0].first<<endl;
//    cout<<diag3[0].first<<endl;
//    cout<<diag4[0].first<<endl;
//    cout<<row1[0].first<<endl;
//    cout<<row2[0].first<<endl;
//    cout<<col1[0].first<<endl;
//    cout<<col2[0].first<<endl;





    if(check()==true)
    cout<<"YES"<<endl;
        else
    cout<<"NO"<<endl;
    return 0;
}

