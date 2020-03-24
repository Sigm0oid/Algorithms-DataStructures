#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;
bool apartient(int x,int y){
    //cout<<"distance of "<<x<<" "<<y<<" is "<<(((pow(x,2)+pow(y,2))))<<endl;
return((((x*x)+y*y))<=2500);
}

static double r2d(double d) {
  return (d*180/(double) M_PI);
}

int main()
{
    freopen("progress_pie.txt","r",stdin);
    freopen("progress_pie_out.txt","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
            cout<<"Case #"<<i+1<<": ";
        int p,x,y;
        cin>>p>>x>>y;
        x-=50;
        y-=50;
        double angle = atan2( y, x);
        angle=r2d(angle);
        angle=(90-angle);
        if(angle<0)
            angle+=360;
        //cout<<"the angle is "<<angle<<"pi angle is "<<(p*360)/100.00<<endl;
        if((apartient(x,y)&&(angle<=(p*360/100.00)))||(x==0&&y==0&&p>0)){
            cout<<"black"<<endl;
        }
        else
        cout<<"white"<<endl;


    }
    return 0;
}
