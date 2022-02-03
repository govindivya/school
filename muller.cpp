#include <bits/stdc++.h>
using namespace std;
const double e = 0.00000000000001;
const int max_iteration = 1000000;

double fx(double x)
{
   return x * x - 3 * x - 10;
}
void muller(double x0, double x1, double x2)
{
   for (int i = 1; i <= max_iteration; i++)
   {
      double w = (fx(x2) - fx(x1)) / (x2 - x1) + (fx(x2) - fx(x0)) / (x2 - x0) + (fx(x1) - fx(x0)) / (x1 - x0);
      double numerator = 2 * fx(x2);
      double temp1 = 4 * fx(x2) * ((fx(x1) - fx(x0) / (x1 - x0) - (fx(x2) - fx(x1) / (x2 - x1))) / (x0 - x2));
      if ((w * w - temp1) < 0)
      {
         cout << "Ans not found beacuse of complex root :\n";
         return;
      }
      double denominator = max(w + sqrt(w * w - temp1), w - sqrt(w * w - temp1));
      double x=x2-numerator/denominator;
      if(abs(x-x2)<e){
         cout<<"root is :"<<x<<"\n";
         return;
      }
      x0=x1;
      x1=x2;
      x2=x;
   }
   cout << "Method failed !\n";
}
int main()
{
   double x0,x1,x2;
   cout<<"Enter initial approximations : ";
   cin>>x0>>x1>>x2;
   muller(x0,x1,x2);
   return 0;
}