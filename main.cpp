#include <iostream>
#include <cmath>
#include <cassert>
#include "quadratic_equation/quadratic_equation.hpp"


int main(){
    double a, b, c;
    std::cout<<"Quadratic equation have view ax^2 + bx + c = 0, 'a' > 0\n";
    std::cout<<"Enter a: ";
    std::cin>>a;
    std::cout<<"Enter b: ";
    std::cin>>b;
    std::cout<<"Enter c: ";
    std::cin>>c;
    QuadraticEquation qe;
    qe.set(a, b, c).calculate().show();
    return 0;
}