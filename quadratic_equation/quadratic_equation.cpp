#include <iostream>
#include <cmath>
#include <cassert>
#include <limits>
#include "quadratic_equation.hpp"



//set a, b and c
QuadraticEquation& QuadraticEquation::set(double a, double b, double c){
    assert(a != 0 && "'a' must be greater than or less than zero");
    a_ = a;
    b_ = b;
    c_ = c;
    return *this;
}

double QuadraticEquation::get_x1(){
    return x1_;
}

double QuadraticEquation::get_x2(){
    return x2_;
}

int QuadraticEquation::get_root_count(){
    return root_count_;
}

//calculate roots
QuadraticEquation& QuadraticEquation::calculate(){
    double D = b_ * b_ - 4 * a_ * c_;
    
    if(D > 0){
        //calculate two roots
        x1_ = (-b_ - sqrt(D)) / (2 * a_);
        x2_ = (-b_ + sqrt(D)) / (2 * a_);
        root_count_ = 2;
    } else if (D == 0){
        //calculate one root
        x1_ = -b_ / (2 * a_);
        x2_ = std::numeric_limits<double>::quiet_NaN();
        root_count_ = 1;
    } else {
        x1_ = std::numeric_limits<double>::quiet_NaN();
        x2_ = std::numeric_limits<double>::quiet_NaN();
        root_count_ = 0;
    }

    return *this;
}

//result calculate
void QuadraticEquation::show(){
    if(root_count_ == 2)
        std::cout<<"The equation has two roots. x1 = "<<x1_<<",  x2 = "<<x2_<<std::endl;
    else if(root_count_ == 1)
        std::cout<<"The equation has one root. x1 = "<<x1_<<std::endl;
    else
        std::cout<<"The equation has no roots"<<std::endl;     
}
