#include <bits/stdc++.h>
using namespace std;

class Trapeziodal
{
private:
    double *x, *fx, h, a, b;
    int n;

public:
    Trapeziodal(double a1, double b1, int n1)
    {
        a = a1;
        b = b1;
        h = (b - a) / n1;
        n = n1;
        x = new double[n + 1];
        fx = new double[n + 1];
    }
    void calc_fx()
    {
        for (int i = 0; i <= n; i++)
        {
            fx[i] = log(x[i]);
            cout<<"F(x) at  " <<h*i<<"  is " <<fx[i]<<"\n";
        }
    }
    void calc_x()
    {
        x[0] = a;
        for (int i = 1; i <= n; i++)
        {
            x[i] = x[i-1]+h;
        }
    }
    void integrate()
    {
        double sum = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            sum += fx[i];
        }
        sum *= 2;
        sum += fx[0] + fx[n];
        sum *= h;
        sum /= 2;
        cout << "The integral is :" << sum << "\n";
    }
    ~Trapeziodal()
    {
        delete x;
        delete fx;
        x = NULL;
        fx = NULL;
    }
};

int main()
{
    double a,b,n;
    cout << "Enter number of points :";
    cin >> n;
    cout << "Enter a and b respectively : ";
    cin >> a >> b;
    Trapeziodal A(a, b, n-1);
    A.calc_x();
    A.calc_fx();
    A.integrate();
}