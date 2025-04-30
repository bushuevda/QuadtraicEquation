#ifndef QUADRATIC_EQUATION_HPP
#define QUADRATIC_EQUATION_HPP 1

#include <iostream>
#include <cmath>


class QuadraticEquation{
    private:
        double a_;
        double b_;
        double c_;
        double x1_;
        double x2_;
        int root_count_;

    public:
        QuadraticEquation(){}
        double get_x1();
        double get_x2();
        int get_root_count();

        //set a, b and c
        QuadraticEquation& set(double a, double b, double c);

        //calculate roots
        QuadraticEquation& calculate();

        //result calculate
        void show();

};

#endif
