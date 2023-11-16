#include <iostream>
#include <cmath>

void gradient_descent(double* x,
        double* y, double s, double eps,
        double(*f)(double, double),
        double(*gx)(double, double),
        double(*gy)(double, double))
{
    double val= f(*x, *y), delta;
    do {
        *x-= s * gx(*x, *y);
        *y-= s * gy(*x, *y);
        double new_val= f(*x, *y);
        delta= abs(new_val - val);
        val= new_val;
    } while (delta > eps);
}

template <typename Value, typename P1,
          typename P2, typename F,
          typename G>
Value gradient_descent2(Value x, P1 s,
        P2 eps, F f, G g)
{
    auto val= f(x), delta= val;
    do {
        x-= s * g(x);
        auto new_val= f(x);
        delta= abs(new_val - val);
        val= new_val;
    } while (delta > eps);
}

double f(double x, double y) {
    return std::sin(x) + std::cos(y);
}

double gx(double x, double y) {
    return std::cos(x);
}

double gy(double x, double y) {
    return -std::sin(y);
}

int main(int argc, char *argv[])
{
    double *x= nullptr, *y= nullptr, s= 0.1, eps=0.0001;
    *x = 0.0;
    *y = 0.0;

    std::cout << "First algorithm: gradient_descent(x= " << *x << ", *y= " << y << ", s= " 
              << s << ", eps= " << eps << ", sin(x) + cos(y), cos(x), -sin(y)): ";
    gradient_descent(x, y, s, eps, f, gx, gy);
    std::cout << "x= " << *x << ", y= " << *y << '\n';

    // double x2= 0.0, y2=0.0;
    // std::cout << "Second algorithm: gradient_descent(x= " << x2 << ", y= " << y2 << ", s= " 
    //           << s << ", eps= " << eps << ", sin(x) + cos(y), cos(x), -sin(y)) = "
    //           << gradient_descent2(x2, y2, s, eps, *f, *gx, *gy) << '\n';

    return EXIT_SUCCESS;
}

