#include <bits/stdc++.h>

using namespace std;
typedef vector<pair<int,int> > vii;
typedef pair<int,int> ii;
int main()
{
    int n;
    cin>>n;
    vii student;
    for(int i=0;i<n;i++){
    int x;
    cin>>x;
    student.push_back(ii(-1*x,i));
    }
    sort(student.begin(),student.end());
    int res[n];
    memset(res,0,sizeof res);
    int cmp=1;
    for(int i=0;i<student.size();i++){
    res[student[i].second]=cmp;
    cmp++;

    }
    for(int i=1;i<student.size();i++){
    if(student[i].first==student[i-1].first)
    res[student[i].second]=res[student[i-1].second];

    }
    for(int i=0;i<n;i++)
    cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}
