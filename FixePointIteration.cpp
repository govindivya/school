#include <bits/stdc++.h>
using namespace std;
const double e = 0.00000000000000001;
const int max_Iteration = 10000;

double fx(double x)
{
    return (x*x-10)/3;
}
void solve_fixed_point(double x0)
{

    for (int i = 1; i <= max_Iteration; i++)
    {
        double x = fx(x0);
        if (abs(x - x0) < e)
        {
            cout << "The root is :" << x << "\n";
            return;
        }
        x0 = x;
    }
    cout << "Method failed !\n";
}

int main()
{
   solve_fixed_point(4);
}