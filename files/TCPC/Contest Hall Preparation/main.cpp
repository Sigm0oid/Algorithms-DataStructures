#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    int n,m;
    cin>>n>>m;
    int mat[100][100];
    for (int j=0;j<n;j++){
    for(int l=0;l<m;l++){
    cin>>mat[j][l];
    }
    }
    for (int j=1;j<n;j++){
    for(int l=1;l<m;l++){
    if((m[j][l])==(m[j-1][l+1])){

    }
    }
    }


    }
    return 0;
}
