#include <bits/stdc++.h>
using namespace std;

// dy/dx=f(x,y)=x+y;
// y(x0)=y0
const double h = 0.1;
double get_fxy(double x, double y)
{
    return x+y;
}
double get_fxy_first_der(double x, double y)
{
    return 1 + get_fxy(x,y);
}
double get_fxy_sec_der(double x, double y)
{
    return get_fxy_first_der(x,y);
}
double get_fxy_third_der(double x, double y)
{
   return get_fxy_sec_der(x,y);
}


void solve_Taylor(double x0,double y0,double x)
{
    double y=y0;
    double x1=x0;
    while(x1<x){
        y=y+h*get_fxy(x1,y)+h*h*get_fxy_first_der(x1,y)/2+h*h*h*get_fxy_third_der(x1,y)/6;
        x1+=h;
    }
    cout<<"F(x) at "<<roundf(x)<< " is "<< y<<"\n";
}
int main()
{
   double x0,y0,x;
   cout<<"Enter x0 and f(x0) :";
   cin>>x0>>y0;
   cout<<"\nEnter at which point you want to calculate f(x) :";
   cin>>x;
   solve_Taylor(x0,y0,x);
}