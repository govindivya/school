#include <bits/stdc++.h>
using namespace std;

class HermitePolynomials
{
private:
    double *x, *fx, *f_derivative, *sequence, **solution;
    int order, points;

public:
    HermitePolynomials(int n)
    {
        order = 2 * n + 1;
        points = n;
        fx = new double[n];
        f_derivative = new double[n];
        x = new double[n];
        sequence = new double[order + 1];
        solution = new double *[order + 1];
        for (int i = 0; i <= order; i++)
        {
            solution[i] = new double[order + 1];
        }
    }
    void get_X()
    {
        cout << "Enter value of x at " << points << " points\n";
        for (int i = 0; i < points; i++)
        {
            cin >> x[i];
        }
    }
    void get_fx()
    {
        cout << "Enter value of f(x) at " << points << " points\n";
        for (int i = 0; i < points; i++)
        {
            cin >> fx[i];
        }
    }
    void get_f_derivative()
    {
        cout << "Enter value of derivative of f(x) at " << points << " points\n";
        for (int i = 0; i < points; i++)
        {
            cin >> f_derivative[i];
        }
    }
    void calc_Cofficients()
    {
        for (int i = 0; i < points; i++)
        {
            sequence[2 * i] = x[i];
            sequence[2 * i + 1] = x[i];
            solution[2 * i][0] = fx[i];
            solution[2 * i + 1][0] = fx[i];
            solution[2 * i + 1][1] = f_derivative[i];
            if (i != 0)
            {
                solution[2 * i][1] = (solution[2 * i][0] - solution[2 * i - 1][0]) / (sequence[2 * i] - sequence[2 * i - 1]);
            }
        }

        for (int i = 2; i <= order; i++)
        {
            for (int j = 2; j <= i; j++)
            {
                solution[i][j] = (solution[i][j - 1] - solution[i - 1][j - 1]) / (sequence[i] = sequence[i - j]);
            }
        }
    }
    void solve_Poly_At(double x1)
    {
        double value = 0;
        double intermdeiate_term = 1;
        for (int i = 0; i <= order; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i == 0)
                {
                    value += solution[0][0];
                    continue;
                }
                else if (i == j)
                {
                    if (j % 2 == 0)
                    {
                        intermdeiate_term *= (x1 - x[i / 2 - 1]);
                    }
                    else
                    {
                        intermdeiate_term *= (x1 - x[i/2]);
                    }

                    value+=solution[i][j]*intermdeiate_term;
                }
            }
        }
        cout<<"The calculated value is "<<value<<" \n";
    }
    ~HermitePolynomials()
    {
        for (int i = 0; i <= points; i++)
        {
            delete solution[i];
        }
        delete f_derivative;
        delete fx;
        delete x;
        delete sequence;
        sequence = NULL;
        solution = NULL;
        f_derivative = NULL;
        fx = NULL;
        x = NULL;
        cout << "destructor called\n";
    }
};
main()
{
    cout<<"Enter no of points";
    int p;
    cin>>p;
    HermitePolynomials A(p);
    A.get_X();
    A.get_fx();
    A.get_f_derivative();
    A.calc_Cofficients();
    cout<<"Enter value at which you want to calculate value :";
    double x;
    cin>>x;
    A.solve_Poly_At(x);
}