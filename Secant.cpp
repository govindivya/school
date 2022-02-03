#include <bits/stdc++.h>
using namespace std;
const double e = 0.00000000000001;
const int max_iteration = 1000000;

double fx(double x)
{
   return x*x-3*x-10;
}
double deriFx(double x)
{
   2*x-3;
}
//  x0 and x1 are initial approximation
void secant(double x0, double x1)
{
   double q0 = fx(x0);
   double q1 = fx(x1);
   double x;
   for (int i = 1; i <= max_iteration; i++)
   {
      x = x1 - q1 * (x1 - x0) / (q1 - q0);
      if (abs(x - x1) < e)
      {
         cout << "root is :" << x << "\n";
         return;
      }
      x0 = x1;
      q0 = q1;
      x1 = x;
      q1 = fx(x);
   }
   cout<<"Method failed !\n";
}
int main()
{
   double x0,x1;
   cout<<"Enter initial approximation: ";
   cin>>x0>>x1;
   secant(x0,x1);
   return 0;
}