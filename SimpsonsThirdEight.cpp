#include <bits/stdc++.h>
using namespace std;

class SimpsonsThirdEight
{
private:
    double *x, *fx, h, a, b;
    int n;

public:
    SimpsonsThirdEight(double a1, double b1,int n1)
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
            fx[i] = 1/(1+x[i]*x[i]);
            cout<<"F(x) at  " <<h*i<<"  is " <<fx[i]<<"\n";
        }
    }
    void calc_x()
    {
        x[0] = a;
        for (int i = 1; i <= n; i++)
        {
            x[i] = x[i - 1] + h;
        }
    }
    void integrate()
    {
        double sum = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            if (i % 3 != 0)
            {
                sum += 3 * fx[i];
            }
        }
        for (int i = 3; i <= n - 3; i += 3)
        {
            sum += 2 * fx[i];
        }
        sum += fx[0] + fx[n];
        sum *= 3;
        sum *= h;
        sum /= 8;
        cout << "The integral is :" << sum << "\n";
    }
    ~SimpsonsThirdEight()
    {
        delete x;
        delete fx;
        x = NULL;
        fx = NULL;
    }
};

int main()
{
    double a, b;
    int n;
    cout << "Enter n which should be multiple of 3 :";
    cin >> n;
    cout << "Enter a and b respectively : ";
    cin >> a >> b;
    SimpsonsThirdEight A(a, b,n);
    A.calc_x();
    A.calc_fx();
    A.integrate();
}