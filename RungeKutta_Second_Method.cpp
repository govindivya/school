#include <bits/stdc++.h>
using namespace std;

const double h = 0.2;

double get_Fxy(double x, double y)
{
    return -2 * x * y * y;
}

void runge_Kutta_Second(double x0, double y0, double x)
{
    while (x0 < x)
    {
        double k1 = h * get_Fxy(x0, y0);
        double k2 = h * get_Fxy(x0 + h / 2, y0 + k1 / 2);
        y0 += k2;
        x0 += h;
        cout << " k1: " << k1 << " k2: " << k2 << "\n";
        cout << "Y at " << x0 << " is " << y0 << "\n";
    }
    cout << "The solution at " << x0 << " is : " << y0 << "\n";
}
int main()
{
    double x0, y0, x;
    cout << "Enter x0 and f(x0): ";
    cin >> x0 >> y0;
    cout << "Enter x at which you want to calculate f(x): ";
    cin >> x;
    runge_Kutta_Second(x0,y0,x);
    return 0;
}