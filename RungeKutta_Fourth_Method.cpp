#include <bits/stdc++.h>
using namespace std;

const double h = 0.2;

double get_Fxy(double x, double y)
{
    return x * x * y * y;
}

void runge_Kutta_Fourth(double x0, double y0, double x)
{

    while (x0 < x)
    {
        double k1 = h * get_Fxy(x0, y0);
        double k2 = h * get_Fxy(x0 + h / 2, y0 + k1 / 2);
        double k3 = h * get_Fxy(x0 + h / 2, y0 + k2 / 2);
        double k4 = h * get_Fxy(x0 + h, y0 + k3);
        y0 += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x0 += h;
        cout << " k1: " << k1 << " k2: " << k2 << " k3 :" << k3 << " k4 : " << k4 << "\n";
        cout << "Y at " << x0 << " is " << y0 << "\n";
    }
    cout << "The solution at " << x0 << " is : " << y0 << "\n";
}
int main()
{
    //  double x0, y0, x;
    // cout << "Enter x0 and f(x0): ";
    // cin >> x0 >> y0;
    // cout << "Enter x at which you want to calculate f(x): ";
    // cin >> x;
    runge_Kutta_Fourth(0,1,0.6);
    return 0;
}