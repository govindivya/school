#include <bits/stdc++.h>
using namespace std;

class NaturalCubicSpline
{
private:
    double *a, *b, *c, *d, *fx, *x, *l, *u, *z, *h, *alp;
    // a b c d are coeeficient of spline of form  di(x-xi)^3+ci(x-xi)^2bi(x-xi)+ai
    //  a b c and d are cofficients of cubic polynomial
    // 0 to n)[di(x-xi)^3+ci(x-xi)^2bi(x-xi)+ai]
    //  x reperesents set of all points
    //  fx repersents f(x) for all x
    //   h represents each interval size
    //  l u z are used to calculate intermediate results
    int n;

public:
    NaturalCubicSpline(int p)
    {
        n = p;
        x = new double[n + 1];
        fx = new double[n + 1];
        a = new double[n + 1];
        b = new double[n + 1];
        c = new double[n + 1];
        d = new double[n + 1];
        l = new double[n + 1];
        z = new double[n + 1];
        h = new double[n + 1];
        u = new double[n + 1];
        alp = new double[n + 1];
    }
    void getX()
    {
        cout << "\nEnter value of x at " << this->n + 1 << " points :";
        for (int i = 0; i <= n; i++)
        {
            cin >> x[i];
        }
    }
    void getFx()
    {
        cout << "\nEnter value of f(x) at " << this->n + 1 << "  points :";
        for (int i = 0; i <= n; i++)
        {
            double num;
            cin >> num;
            this->fx[i] = num;
        }
    }
    void calculate_ai()
    {
        for (int i = 0; i <= n; i++)
        {
            a[i] = fx[i];
        }
    }
    void calculate_hi()
    {
        for (int i = 0; i <= n - 1; i++)
        {
            h[i] = x[i + 1] - x[i];
        }
    }
    void calculate_aphi()
    {
        for (int i = 0; i <= n - 1; i++)
        {
            alp[i] = 3 / h[i] * (a[i + 1] - a[i]) - 3 / h[i - 1] * (a[i] - a[i - 1]);
        }
    }
    void calculate_ulz()
    {
        l[0] = 1;
        u[0] = 0;
        z[0] = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * u[i - 1];
            u[i] = h[i] / l[i];
            z[i] = (alp[i] - h[i - 1] * z[i - 1]) / l[i];
        }
        l[n] = 1;
        z[n] = 0;
        c[n] = 0;
    }
    void calculat_bcd()
    {
        for (int j = n - 1; j >= 0; j--)
        {
            c[j] = z[j] - u[j] * c[j + 1];
            b[j] = (a[j + 1] - a[j]) / h[j] - h[j] * (c[j + 1] + 2 * c[j]) / 3;
            d[j] = (c[j + 1] - c[j]) / (3 * h[j]);
        }
    }

    void print_Coff()
    {
        for (int i = 0; i < n - 1; i++)
        {
            cout << "a[" << i << "] is :" << a[i] << "\n";
        }
        for (int i = 0; i < n - 1; i++)
        {
            cout << "b[" << i << "] is :" << b[i] << "\n";
        }
        for (int i = 0; i < n - 1; i++)
        {
            cout << "c[" << i << "] is :" << c[i] << "\n";
        }
        for (int i = 0; i < n - 1; i++)
        {
            cout << "d[" << i << "] is :" << d[i] << "\n";
        }
    }
    void get_Value_at()
    {
        double x1;
        cout << "Enter x:";
        cin >> x1;
        if (x1 < x[0] || x1 > x[n])
        {
            cout << "Not a valid point :\n";
            return;
        }
        int temp = 0;
        for (int i = 0; i <= n - 1; i++)
        {
            if (x[i] <= x1 && x1 <= x[i + 1])
            {
                temp = i;
                break;
            }
        }
        double value = a[temp] + b[temp] * (x1 - x[temp]) + c[temp] * pow(x1 - x[temp], 2) + d[temp] * pow(x1 - x[temp], 3);
        cout << "Tha value of f(x) at " << x1 << " is :" << value << "\n";
    }
    void callAll()
    {
        getX();
        getFx();
        calculate_ai();
        calculate_hi();
        calculate_aphi();
        calculate_ulz();
        calculat_bcd();
        print_Coff();
        get_Value_at();
    }
    ~NaturalCubicSpline()
    {

        delete a;
        delete b;
        delete c;
        delete d;
        delete x;
        delete fx;
        delete l;
        delete u;
        delete z;
        delete h;
        delete alp;
        l = NULL;
        u = NULL;
        h = NULL;
        z = NULL;
        alp = NULL;
        a = NULL;
        b = NULL;
        c = NULL;
        d = NULL;
        x = NULL;
        fx = NULL;
        cout << "Object is destructed \n";
    }
};
int main()
{
    int points;
    cout << "Enter n:";
    cin >> points;
    NaturalCubicSpline A(points);
    A.callAll();
}
