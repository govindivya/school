#include <bits/stdc++.h>
using namespace std;

const double e = 0.0000000001;
int max_itertaion = 10000;

class JacobiMethod
{
private:
    double **A, *b, *x, *x0;
    int n;

public:
    JacobiMethod(int n1)
    {
        n = n1;
        A = new double *[n1];
        for (int i = 0; i < n1; i++)
        {
            A[i] = new double[n1];
        }
        b = new double[n1];
        x = new double[n1];
        x0 = new double[n1];
    }
    void get_A()
    {
        cout << "Enter elements of diagonal dominants matrix A : \n";
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {
                cin >> A[i][j];
            }
            cout << "\n";
        }
    }
    void get_b()
    {
        cout << "Enter elements of b : \n";
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
    }
    void get_initail_X()
    {
        cout << "Enter initial approximation : \n";
        for (int i = 0; i < n; i++)
        {
            cin >> x0[i];
        }
    }

    void printSolution()
    {
        for (int i = 0; i < n; i++)
        {
            cout << x[i] << "  ";
        }
        cout << "\n";
    }
    void solve_Jacobi()
    {
        for (int k = 1; k <= max_itertaion; k++)
        {
            for (int i = 0; i < n; i++)
            {
                double temp = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j != i)
                    {
                        temp += A[i][j] * x0[j];
                    }
                }
                x[i] = (-temp + b[i]) / A[i][i];
            }
            bool isTrue = true;
            for (int i = 0; i < n; i++)
            {
                if (abs(x[i] - x0[i]) > e)
                {
                    // using x0[i] causes  lower convergence rate w.r.t guassseidal  .......
                    isTrue = false;
                }
            }
            if (isTrue)
            {
                cout << "Total iteration count is :" << k << "\n";
                return;
            }
            for (int i = 0; i < n; i++)
            {
                x0[i] = x[i];
            }
        }
        cout<<"Method does not converges for given matrix :\n";
    }
    ~JacobiMethod()
    {
        for (int i = 0; i < n; i++)
        {
            delete A[i];
        }
        delete b;
        delete x;
        delete x0;
        A = NULL;
        b = NULL;
        x = NULL;
        x0 = NULL;
    }
};
int main()
{
    cout<<"Enter no of eqns: ";
    int n;
    cin>>n;
    JacobiMethod A(n);
    A.get_A();
    A.get_b();
    A.get_initail_X();
    A.solve_Jacobi();
    A.printSolution();
}