#include <bits/stdc++.h>
using namespace std;

const double  e=0.0000000000000001;
const int max_iteration =1000000;

double fx(double x)
{
    return pow(x,x)+x-4;
}

double derivFx(double x)
{
  return  pow(x,x)*(1+log(x))+1;
}

void newtonRaphson(double x0)
{
    double x;
    for(int i=1;i<=max_iteration;i++)
    {
      cout<<"x is "<<x0<<" ";
    cout<<"f(x) is "<<fx(x0)<<" ";
    cout<<"f_der is "<<derivFx(x0)<<"\n";
       x=x0-fx(x0)/derivFx(x0);
       if(abs(x-x0)<e){
           cout<<"root is :"<<x;
           return;
       }
       x0=x;
    }
    cout<<"Method failed !\n";
}

int main()
{
  newtonRaphson(1);
  cout<< fx(1.66456);
}