#include <iostream>
using namespace std;

class NewtonDiffrence
{
private:
   double *X;
   double **F;
   int order;

public:
    NewtonDiffrence(int ord)
    {
        order=ord;
        F=new double*[ord+1];
        for(int i=0;i<=ord;i++){
            F[i]=new double[ord+1];
        }
       X=new double[ord+1];
    }

    void get_X()
    {
        cout<<"Enter value of x at " <<order+ 1<<" points :\n";
        for (int i = 0; i <= order; i++)
        {
            cin >> X[i];
        }
    }
    void get_fx()
    {
        cout << "enter f(x) at " << this->order + 1 << " points\n";
        for (int i = 0; i <= this->order; i++)
        {
            cin >> F[i][0];
        }
    }

    void calc_Diff()
    {
        for (int i = 1; i <=order; i++)
        {
            for (int j = 1; j <=i; j++)
            {
                F[i][j] = (F[i][j - 1] - F[i - 1][j-1] )/ (X[i] - X[i - j]);
            }
        }
        cout<<"The values  F[i,i]  are!\n";
        for (int i = 0; i <= order; i++)
        {
            for (int j = 0; j <= order; j++)
            {
                if(i==j){
                    cout<<F[i][j]<<"\n";
                }
            }
        }
    }

    ~NewtonDiffrence()
    {
        for (int i = 0; i <= order; i++)
        {
            delete F[i];
        }
        delete X;
        F = NULL;
        X = NULL;
        cout << "Object has been destructed by destructor\n";
    }
};

int main()
{
    cout<<"Enter the order of polynomial \n";
    int order;
    cin>>order;
    NewtonDiffrence A(order);
    A.get_X();
    A.get_fx();
    A.calc_Diff();

}