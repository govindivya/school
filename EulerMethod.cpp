#include <bits/stdc++.h>
using namespace std;

const double h = 0.01;

double fx(double x, double y)
{
    return x * x * x + y*y;
}
void solve_Euler(double x0, double y0, double x)
{

    double y = y0;
    double x1 = x0;
    while (x1 < x)
    {
        y += h * fx(x1, y);
        cout<<"x is now "<<x1<<"\n";
        cout<<"y is now "<<y<<"\n";
        x1 += h;
    }
    cout << "f(x) at " << x << " is :" << y << "\n";
}

int main()
{
    double x0,y0,x;
    cout<<"Enter x0 and f(x0) :";
    cin>>x0>>y0;
    cout<<"\nEnter x at which you want to calculate f(x):";
    cin>>x;
    cout<<"\n";
    solve_Euler(x0,y0,x);
}