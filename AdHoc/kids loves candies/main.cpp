#include <iostream>

using namespace std;

int main()
{

    int T,K,i,N,nb,j,var_inter,res;
    cin >> T;

    for(i=0;i<T;i++)
    {
    res=0;
        cin >> N >> K ;
        for(int j=0;j<N;j++){
        int x;cin>>x;res+=(x/K);}
        cout <<res<<endl;

    }
    return 0;
}
