#include <bits/stdc++.h>

using namespace std;
typedef  long long ll;
 ll matrice1[3][3];
 ll base[3][3];
void initialize(){
        matrice1[0][0]=1;
        matrice1[0][1]=2;
        matrice1[0][2]=3;
        matrice1[1][0]=4;
        matrice1[1][1]=5;
        matrice1[1][2]=6;
        matrice1[2][0]=7;
        matrice1[2][1]=8;
        matrice1[2][2]=9;
        base[0][0]=1;
        base[0][1]=1;
        base[0][2]=1;
        base[1][0]=0;
        base[1][1]=0;
        base[1][2]=0;
        base[2][0]=0;
        base[2][1]=0;
        base[2][2]=0;


}
ll somme(){
ll res=0;
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
res=(res+base[i][j])%1000000007;
}
//cout<<endl;
}
return res;
}



void multiply()
{
    ll mul[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++)
                mul[i][j] += base[i][k]*matrice1[k][j];
                mul[i][j]%=1000000007;
        }
    }

    // storing the muliplication resul in a[][]
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            base[i][j] = mul[i][j];  // Updating our matrix
}



int main()
{

    int t;
    cin>>t;

    while(t--){
        initialize();
        ll n;
        cin>>n;
        power(n-1);
        multiply();
        cout<<somme()%1000000007<<endl;
    }

    return 0;
}
