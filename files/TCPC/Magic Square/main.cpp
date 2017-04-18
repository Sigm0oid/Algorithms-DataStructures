#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int m[n][n];
    int somme_diag=0;
    int somme_antidiag=0;
    vector <int> v;
    int taille=1;
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    cin>>m[i][j];}}
    for (int i=0;i<n;i++){
    somme_diag+=m[i][i];
    somme_antidiag+=m[i][n-i-1];
    }

    if(somme_diag!=somme_antidiag){
    v.push_back(0);
    taille++;}
    int somme_col=0;
    int somme_row=0;
    for(int i=0;i<n;i++){
    somme_col=0;
    somme_row=0;
    for(int j=0;j<n;j++){
    somme_col+=m[i][j];
    somme_row+=m[j][i];
    }
    if(somme_col!=somme_diag){
    v.push_back(i+1);
    taille++;}
    if(somme_row!=somme_diag){
    v.push_back(-1*(i+1));
    taille++;}

    }
    if(taille==1){cout<<"0"<<endl;}else{
    cout<<taille-1<<endl;
    sort(v.begin(),v.end());
    for(int i=0;i<taille-1;i++){
    cout<<v[i]<<endl;}}

    return 0;
}
