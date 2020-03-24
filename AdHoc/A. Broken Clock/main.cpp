#include <bits/stdc++.h>

using namespace std;
int test(string s,string s1){

return ((s[0]!=s1[0])+(s[1]!=s1[1]));

}
int main()
{    int format;
    string time;

    cin>>format;
    cin>>time;


    if(time[3]-'0'>5){
        time[3]='0';

    }
    if(format==12){
        int cmp=3;
        int indx=0;
        for(int i=1;i<13;i++)
        {
            string tmp,tmp1;
            tmp1+='0'+(i/10);
            tmp1+='0'+(i%10);
            tmp=time.substr(0,2);
            //cout<<cmp<<" "<<indx<<endl;
            if(cmp>=test(tmp,tmp1))
              {
                  indx=i;
                cmp=test(tmp,tmp1);
              }
        }
        string tmp1;
         tmp1+='0'+(indx/10);
        tmp1+='0'+(indx%10);
         time[0]=tmp1[0];
        time[1]=tmp1[1];

    }
    else{
        if(time[0]-'0'>2){
                time[0]='0';
        }

        if((time[1]-'0'>3)&&(time[0]-'0'==2)){
                time[0]='0';
        }

    }
cout<<time<<endl;

    return 0;
}
