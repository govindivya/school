#include <bits/stdc++.h>

using namespace std;
const int max_iteration = 100000;
const double e = 0.000000001;
double a = INT64_MIN;
double b = INT64_MAX;

double fx(double x)
{
   return x * x * x - x * x + 2;
}
// Prints root of solution(x) with error in EPSILON

void predict_Correct_a_b()
{
   for (double i = -10000000; i < 1000000; i += 0.1)
   {
      if (fx(i) < 0)
      {
         a = i;
      }
      if (fx(i) > 0)
      {
         b = i;
      }
   }
}
void bisection(double a1 = a, double b1 = b)
{
   if (b1 == INT64_MAX || a1 == INT64_MIN)
   {
      cout << "Method is failed to find correct interval !\n";
   }
   if (fx(a1) * fx(b1) > 0)
   {
      cout << "You have not assumed correct value of  a and b\n";
      return;
   }
   double c = a1;
   int i = 1;
   while ((b1 - a1) >= e && i <= max_iteration)
   {
      // Find middle point
      c = (a1 + b1) / 2;
      // Check if middle point is root
      if (fx(c) == 0.0)
         break;
      // Decide the side to repeat the steps
      else if (fx(c) * fx(a1) < 0)
         b1 = c;
      else
         a1 = c;
      // cout << "a is :" << a1 << endl;
      // cout << "b is :" << b1 << endl;
      i++;
   }
   cout << "The value of root is : " << c;
}
// main function
int main()
{
   cout << "Enter 1 for enter a and b manually or 2 for automatic evaluation :\n";
   int n;
   cin >> n;
   if (n == 1)
   {
      double a, b;
      cout << "Enter a and b: ";
      cin >> a >> b;
      bisection(a, b);
      return 0;
   }
   predict_Correct_a_b();
   bisection();
   return 0;
}