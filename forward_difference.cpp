#include <bits/stdc++.h>
using namespace std;

void solve(double *x, double *f, int n)
{
    double F[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
        F[i][0] = f[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=i; j++)
        {
            F[i][j] = (F[i][j - 1] - F[i - 1][j - 1]) / (x[i] - x[i-j]);
        }
    }
  
    double F1[n + 1];
    for (int i = 0; i <= n; i++)
        F1[i] = F[i][i];
 
    cout<<F1[0];

    for (int k = 1; k <= n; k++)
    {
        if(F1[k]>=0)
         cout << " + " << F1[k];
        else 
          cout<<"  "<<F1[k];
       
        for (int j = 0; j <= k - 1; j++)
        {
            cout << "( x -" << x[j] << " )";
        }
    }
    


}

int main()
{
    int n;
    cout<<"Enter degree of polynomial :  ";
    cin >> n;
    double x[n + 1], f[n + 1];
     cout<<"\n Enter the "<<n+1<<"  values of x :  ";
    for (int i = 0; i <= n; i++)
        cin >> x[i];
    cout<<"\n Enter the values of f(x) at " << n+1<<" points   :  ";  
    for (int i = 0; i <= n; i++)
        cin >> f[i];
    cout<<"\n";
    solve(x, f, n);
}