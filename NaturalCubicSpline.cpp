#include <bits/stdc++.h>
using namespace std;

class NaturalCubicSpline
{
private:
  double **M, *m, *B, *a, *b, *c, *d, *fx, *x;
  //  M repersent coefficient matrix to solve all 2nd order diffrential of f(x)
  //  B=(f(xi)-2*f(x(i+1))-f(x(i+2)))
  // m is solution of Mm=B
  //  a b c d are coeeficient of spline of form si(x)=(sum of s(i) over
  //  a b c and d are cofficients of cubic polynomial
  // 0 to n)[ai(x-xi)^3+bi(x-xi)^2+ci(x-xi)+di]
  //  x reperesents set of all points
  //  fx repersents f(x) for all x
  int points;
  double step_size;

public:
  NaturalCubicSpline(int p, int s)
  {
    points = p;
    step_size = s;
    M = new double *[p - 2];
    for (int i = 0; i < p - 2; i++)
    {
      M[i] = new double[p - 2];
    }
    B = new double[p - 2];
    m = new double[p - 2];
    x = new double[p];
    fx = new double[p];
    a = new double[p - 1];
    b = new double[p - 1];
    c = new double[p - 1];
    d = new double[p - 1];
  }
  void getX()
  {
    cout << "\nEnter value of x at " << this->points << " points :";
    for (int i = 0; i < this->points; i++)
    {
      cin >> x[i];
    }
  }
  void getFx()
  {
    cout << "\nEnter value of f(x) at " << this->points << "  points :";
    for (int i = 0; i < this->points; i++)
    {
      double num;
      cin >> num;
      this->fx[i] = num;
    }
  }
  void calcM()
  {
    int a1 = -1, a2 = 0, a3 = 1;
    int n = this->points;
    for (int i = 0; i < n - 2; i++)
    {
      if (a1 >= 0 && a1 < n - 2)
      {
        this->M[i][a1] = 1;
      }
      if (a2 >= 0 && a2 < n - 2)
      {
        this->M[i][a2] = 4;
      }
      if (a3 >= 0 && a3 < n - 2)
      {
        this->M[i][a3] = 1;
      }
      a1++;
      a2++;
      a3++;
    }
  }
  void calcB()
  {
    // b[i]= y[i]-2*y[i+1]+ y[i+2];
    int n = this->points - 2;
    for (int i = 0; i < n - 2; i++)
    {
      this->B[i] = (this->fx[i] - 2 * this->fx[i + 1] + this->fx[i + 2]) * 6 / (this->step_size * this->step_size);
    }
  }
  //  solution of Mm=B using guassian elimintaion
  void solve_Eqn_Gauss()
  {
    int n = this->points - 2;
    for (int i = 0; i < n; i++)
    {
      //  condition to find the maximum of diagonal element in row lower to current row
      if (i < n - 1)
      {
        double max = INT64_MIN;
        int max_row = i;
        for (int j = i; j < n; j++)
        {
          if (M[j][i] > max)
          {
            max = M[j][i];
            max_row = j;
          }
        }
        // swapping the row
        for (int j = 0; j < n; j++)
        {
          double temp1 = M[max_row][j];
          M[max_row][j] = M[i][j];
          M[i][j] = temp1;
        }
        double temp1 = B[max_row];
        B[max_row] = B[i];
        B[i] = temp1;
      }
      double temp1 = M[i][i];
      for (int j = 0; j < n; j++)
      {
        M[i][j] /= temp1;
      }
      B[i] /= temp1;
      for (int j = 0; j < n; j++)
      {
        if (j != i)
        {
          double temp2 = M[j][i];
          for (int k = 0; k < n; k++)
            M[j][k] -= temp2 * M[i][k];
          B[j] -= temp2 * B[i];
        }
      }
    }

    for (int i = 0; i < n; i++)
    {
      m[i] = B[i];
    }
  }
  void resize_m()
  {
    double *copy_m = new double[points];
    copy_m[0] = 0;
    copy_m[points - 1] = 0;
    for (int i = 1; i < points - 1; i++)
    {
      copy_m[i] = m[i - 1];
    }
    delete m;
    m = copy_m;
  }
  void solve_Ai()
  {
    int n = this->points;
    for (int i = 0; i < n - 1; i++)
    {
      this->a[i] = (this->m[i + 1] - this->m[i]) / (6 * this->step_size);
    }
  }
  void solve_Bi()
  {
    int n = this->points;
    for (int i = 0; i < n - 1; i++)
    {
      this->b[i] = this->m[i] / 2;
    }
  }
  void solve_Ci()
  {
    int n = this->points;
    for (int i = 0; i < n - 1; i++)
    {
      this->c[i] = (this->fx[i + 1] - this->fx[i]) / this->step_size - (this->m[i + 1] + 2 * this->m[i]) * this->step_size / 6;
    }
  }
  void solve_Di()
  {
    int n = this->points;
    for (int i = 0; i < n - 1; i++)
    {
      this->d[i] = this->fx[i];
    }
  }
  void approximate_Cofficients()
  {
    double e = 0.000000000000000001;
    for (int i = 0; i < points - 1; i++)
    {
      if (abs(a[i]) < e)
      {
        a[i] = 0;
      }
      if (abs(b[i]) < e)
      {
        b[i] = 0;
      }
      if (abs(c[i]) < e)
      {
        c[i] = 0;
      }
      if (abs(d[i]) < e)
      {
        d[i] = 0;
      }
    }
  }
  void calculate_Value_At()
  {
    double x1;
    cout << "Enter the x :";
    cin >> x1;
    int interval = 0;
    if (x1 > x[points - 1] || x1 < x[0])
    {
      cout << "given point is out of range !\n";
      return;
    }
    for (int i = 0; i < points - 1; i++)
    {
      if (x1 >= x[i] && x1 <= x[i + 1])
      {
        interval = i;
        break;
      }
    }

    double value = a[interval] * pow(x1 - x[interval], 3) + b[interval] * pow(x1 - x[interval], 2) + c[interval] * (x1 - x[interval]) + d[interval];
    cout << "Value of f(x) at " << x1 << " is :" << value << " \n";
  }

  ~NaturalCubicSpline()
  {
    for (int i = 0; i < points - 2; i++)
    {
      delete M[i];
    }
    delete B;
    delete m;
    delete a;
    ;
    delete b;
    delete c;
    delete d;
    delete x;
    delete fx;
    M = NULL;
    m = NULL;
    B = NULL;
    a = NULL;
    b = NULL;
    c = NULL;
    d = NULL;
    x = NULL;
    fx = NULL;
  }
  void callAll()
  {
    getX();
    getFx();
    calcM();
    calcB();
    solve_Eqn_Gauss();
    resize_m();
    solve_Ai();
    solve_Bi();
    solve_Ci();
    solve_Di();
    approximate_Cofficients();
    calculate_Value_At();
  }
};
int main()
{
  double step;
  int points;
  cout<<"Enter no of points: ";
  cin>>points;
  cout<<"Enter step size: ";
  cin>>step;
  NaturalCubicSpline A(points,step);
  A.callAll();
}
