#include <bits/stdc++.h>
using namespace std;

class Lagrange
{
private:
    vector<double> *x = new vector<double>();
    vector<double> *fx = new vector<double>();
    vector<double> *L = new vector<double>();

    int order;

public:
    Lagrange(int order)
    {
        this->order = order;
    }
    void setX()
    {
        cout << "Please enter value of x at " << this->order + 1 << " points\n";

        for (int i = 0; i <= order; i++)
        {
            double x;
            cin >> x;
            this->x->push_back(x);
        }
    }
    void setFx_At_N_Points()
    {
        cout << "Please enter value of f(x) at " << this->order + 1 << " points\n";

        for (int i = 0; i <= order; i++)
        {
            double fx;
            cin >> fx;
            this->fx->push_back(fx);
        }
    }

    void initialize_Cofficeinet()
    {
        for (int i = 0; i <= this->order; i++)
        {
            this->L->push_back(1);
        }
    }
    void calc_Cofficient(int k, double x)
    {

        double denominator = 1;
        double numerator = 1;

        for (int i = 0; i <= this->order; i++)
        {
            if (i != k)
            {
                numerator *= (x - this->x->at(i));
                denominator*=(this->x->at(k)-this->x->at(i));
            }
        }
        this->L->at(k)=numerator/denominator;
        return;
    }
    void calc_Value_At(double x)
    {
        for (int i = 0; i <= this->order; i++)
        {
            this->calc_Cofficient(i, x);
        }

        for (int i = 0; i <= this->order; i++)
        {
            cout << this->L->at(i) << "\n";
        }
        double value = 0;
        for (int i = 0; i <= this->order; i++)
        {

            value += this->fx->at(i) * this->L->at(i);
        }
        cout << "The value of polinoimial at " << x << " is " << value << "\n";
    }

    ~Lagrange()
    {
        delete x;
        delete fx;
        delete L;
        L = NULL;
        x = NULL;
        fx = NULL;
    }
};

int main()
{
    int order;
    cout<<"Please enter order of polynomial :";
    cin>>order;
    Lagrange a(order);
    a.setX();
    a.setFx_At_N_Points();
    a.initialize_Cofficeinet();
    double x;
    cout << "Enter the point where you want get value \n";
    cin >> x;
    a.calc_Value_At(x);
}