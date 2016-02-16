#include <iostream>
#include <cmath>

using namespace std;

//void fib3(int k)
//{
//    int ck,ck1,ck2;
//    for (int counter = 1; counter < k; counter++ )
//    {
//        if (k < 2)
//        {
//            ck=ck1=1;
//        }
//        else
//        {
//            ck2=ck1;
//            ck1=ck;
//            ck += ck2;
//        }
//    }
//    cout <<ck<< endl;
//}

void fib2(int k, int& ck, int& ck1)
{
    if (k < 2)
        ck=ck1=1;
    else
    {
        fib2(k-1,ck1,ck);
        ck += ck1;
    }
}

int fib2a(int k)
{
    int ck,ck1;
    fib2(k,ck,ck1);
    return ck;
}

double limfib()
{
    const double tolerance = 1e-8;
    double r = 0;

    for (int k=1 ; ; ++k)
    {
        int ck,ck1;
        fib2(k,ck,ck1);
        double rk= double(ck) / ck1;
        if (fabs(r - rk) < tolerance)
            return rk;
        r=rk;
    }
}
// returns square root of x
double sqr( double x )
{
    return x*x;
}
//find roots ax^2+bx+c=0
bool realRoots(int a, int b, int c, double& x1, double& x2)
{
    double D2 = sqr(b)/(4.*sqr(a)) -c/a;
    if (D2 < 0)
    {
        return false;
    }
    else
    {
        x1 = -(b/(2.*a))+sqrt(D2);
        x2 = -(b/(2.*a))-sqrt(D2);
        return true;
    }

}

bool identify(double x, int& a, int& b, int& c)
{
    int N=10;
    const double tolerance = 1e-7;
    for (a=-N;a<=N;a++)
        for (b=-N;b<=N;b++)
            for (c=-N;c<=N;c++)
            {
                double x1,x2;
                if (realRoots(a, b, c, x1, x2))
                {
                    if (fabs(x1-x) < tolerance)
                        return true;
                    if (fabs(x2-x) < tolerance)
                        return true;
                }
            }
}


int main()
{
//fib3(5);

//    int ck,ck1;
    //fib2a(2, ck, ck1);

//    cout <<fib2a(4)<< endl;
//    cout <<limfib()<< endl;
//    double x1,x2;
//    if (realRoots(1,-5,600,x1,x2))
//            cout <<x1<< endl<<x2<< endl;
//    else
//        cout <<"no real roots"<< endl;

    int a, b, c;
     if(identify(limfib(),a,b,c))
        cout <<a<<endl<<b<<endl<<c<<endl;
    else
        cout <<"oh no..."<<endl;
    return 0;
}

