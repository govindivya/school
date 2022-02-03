#include <bits/stdc++.h>
using namespace std;

const double h = 0.01; //step or gap bw points

const double e = 0.0000000000000001; // tolerance for approximation
const int max_iteration = 1000000;   // to solve yn iteratively

//  dy/dx=(x²+y²)=f(x,y);

double get_fxy(double x, double y)
{
    return x * x + y * y;
}
//to find  y the    recurence is Y(n)-Y(n-1)+hf(Xn,Yn)=0;
//  or Y(n)-Y(n-1) + h(Xn²+Yn²)=0;
//  or hXn²+hYn²+Y(n-1)-Y(n)=0;

double get_fxy_for_newton_method(double xn, double yn, double yn_1)
{
    return h * yn * yn + h * xn * xn + yn_1 - yn;
}

double get_deri_for_newton_Method(double xn, double yn, double yn_1)
{
    return 2 * h * yn - 1;
}
double solve_Newton(double xn, double yn, double yn_1)
{
    double y = yn;
    for (int i = 0; i < max_iteration; i++)
    {
        double denominator = get_deri_for_newton_Method(xn, yn, yn_1);
        if (denominator != 0)
        {
            y = yn - get_fxy_for_newton_method(xn, yn, yn_1) / denominator;
            if(abs(y-yn)<e){
                return y;
            }
            else
            {
                yn=y;
            }
            
        }
        else{
            cout<<"Cant solve this eqn by implicit Euler method by help of Newton Raphson Method :\n";
            return INT64_MAX;
        }
    }
}

void solve_Euler_Backward(double x0,double y0,double x){
    double x1=x0;
    double y=y0;
    while (x1<x)
    {
        x1+=h;
        y=solve_Newton(x1,y,y);
    }
    cout<<"The value of f(x) is :"<<y<<"\n";
    
}
int main()
{
    double x0,y0,x;
    cout<<"Enter x0 and f(x0) :";
    cin>>x0>>y0;
    cout<<"\nEnter x at which you want to calculate f(x):";
    cin>>x;
    cout<<"\n";
    solve_Euler_Backward(x0,y0,x);
}