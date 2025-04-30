#ifndef TEST_QUADRATIC_EQUATION_HPP
#define TEST_QUADRATIC_EQUATION_HPP  1

#include "../libs/cppunit/cppunit.h"
#include "../quadratic_equation/quadratic_equation.hpp"
#include <cmath>
#include <limits>

bool compare_double(double n1, double n2, double eps = 1.0E-4){
    return fabs(n1 - n2) < eps;
}

class TestQuadraticEquation: public Cppunit{

    public:
     
        bool util_test_calc_abc(double a, double b, double c, int root_count, 
            double x1 = std::numeric_limits<double>::quiet_NaN(), 
            double x2 = std::numeric_limits<double>::quiet_NaN()){
           
            QuadraticEquation qe;
            qe.set(a, b, c).calculate();

            if(qe.get_root_count() == 0 && qe.get_root_count() == root_count
                && std::isnan(qe.get_x1())
                && std::isnan(qe.get_x2()))
                return true;
            else if(qe.get_root_count() == 1 && qe.get_root_count() == root_count
                    && compare_double(qe.get_x1(), x1)
                    && std::isnan(qe.get_x2())) 
                return true;
            return(
                qe.get_root_count() == 2
                && qe.get_root_count() == root_count 
                && compare_double(qe.get_x1(), x1)
                && compare_double(qe.get_x2(), x2)
            );
        }

        //--------tesing with two roots----------

        void test_calculate_two_roots(){
            //a = -1, b = 6, c = 7, roots = 2, x1 = 7, x2 = -1
            CHECK(true, util_test_calc_abc(-1, 6, 7, 2, 7, -1));
            //a = 1, b = 5, c = -6, roots = 2, x1 = -6, x2 = 1
            CHECK(true, util_test_calc_abc(1, 5, -6, 2, -6, 1));
            //a = 1, b = 1, c = -6, roots = 2, x1 = -3, x2 = 2
            CHECK(true, util_test_calc_abc(1, 1, -6, 2, -3, 2));
            //a = 4, b = 1, c = -1, roots = 2, x1 = -0.64039, x2 = 0.39039
            CHECK(true, util_test_calc_abc(4, 1, -1, 2, -0.64039, 0.39039));
            //a = 4, b = 11, c = 3, roots = 0, x1 = -2.4430, x2 = -0.30700
            CHECK(true, util_test_calc_abc(4, 11, 3, 2, -2.4430, -0.30700));
        }

        //--------tesing with one root----------
        void test_calculate_one_root(){
            //a = 9, b = -6, c = 1, roots = 1, x1 =  0.33333, x2 = NaN
            CHECK(true, util_test_calc_abc(9, -6, 1, 1,  0.33333));
            //a = 4, b = 4, c = 1, roots = 1, x1 = -0.5, x2 = NaN
            CHECK(true, util_test_calc_abc(4, 4, 1, 1, -0.5));
            //a = 1, b = -6, c = 9, roots = 1, x1 = 3, x2 = NaN
            CHECK(true, util_test_calc_abc(1, -6, 9, 1, 3));
            //a = 1, b = 12, c = 36, roots = 1, x1 = -6, x2 = NaN
            CHECK(true, util_test_calc_abc(1, 12, 36, 1, -6));
            //a = 1, b = 4, c = 4, roots = 1, x1 = -2, x2 = NaN
            CHECK(true, util_test_calc_abc(1, 4, 4, 1, -2));
        }

        //--------tesing without root----------
        void test_calculate_without_roots(){
            //a = 4, b = 2, c = 3, roots = 0, x1 = NaN, x2 = NaN
            CHECK(true, util_test_calc_abc(4, 2, 3, 0));
            //a = 7, b = 6, c = 3, roots = 0, x1 = NaN, x2 = NaN
            CHECK(true, util_test_calc_abc(7, 6, 3, 0));
            //a = 7, b = 6, c = 7, roots = 0, x1 = NaN, x2 = NaN
            CHECK(true, util_test_calc_abc(7, 6, 7, 0));
            //a = -11, b = 1, c = -3, roots = 0, x1 = NaN, x2 = NaN
            CHECK(true, util_test_calc_abc(-11, 1, -3, 0));
            //a = 21, b = -11, c = 5, roots = 0, x1 = NaN, x2 = NaN
            CHECK(true, util_test_calc_abc(21, -11, 5, 0));
        }

        //--------tesing with b = 0, c = 0----------
        void test_a(){
            //a = -1, b = 0, c = 0, roots = 2, x1 = 7, x2 = NaN
            CHECK(true, util_test_calc_abc(-1, 0, 0, 1, 0));
            //a = 5, b = 0, c = 0, roots = 2, x1 = 7, x2 = NaN
            CHECK(true, util_test_calc_abc(5, 0, 0, 1, 0));
            //a = 12, b = 0, c = 0, roots = 2, x1 = 7, x2 = NaN
            CHECK(true, util_test_calc_abc(12, 0, 0, 1, 0));
            //a = 4, b = 0, c = 0, roots = 2, x1 = 7, x2 = NaN
            CHECK(true, util_test_calc_abc(4, 0, 0, 1, 0));
            //a = 7, b = 0, c = 0, roots = 2, x1 = 7, x2 = NaN
            CHECK(true, util_test_calc_abc(7, 0, 0, 1, 0));
        }

        //--------tesing with c = 0----------
        void test_ab(){
            //a = 12, b = 4, c = 0, roots = 2, x1 = -0.33333, x2 = 0
            CHECK(true, util_test_calc_abc(12, 4, 0, 2, -0.33333, 0));
            //a = 5, b = -4, c = 0, roots = 2, x1 = 0, x2 = 0.8
            CHECK(true, util_test_calc_abc(5, -4, 0, 2, 0, 0.8));
            //a = 5, b = 5, c = 0, roots = 2, x1 = -1, x2 = 0
            CHECK(true, util_test_calc_abc(5, 5, 0, 2, -1, 0));
            //a = 13, b = 15, c = 0, roots = 2, x1 = -1.1538, x2 = 0
            CHECK(true, util_test_calc_abc(13, 15, 0, 2, -1.1538, 0));
            //a = -13, b = 15, c = 0, roots = 2, x1 = 1.1538, x2 = 0
            CHECK(true, util_test_calc_abc(-13, 15, 0, 2, 1.1538, 0));
        }

        //--------tesing with b = 0----------
        void test_ac(){
            //a = -1, b = 0, c = 7, roots = 2, x1 = 2.6458, x2 = -2.6458
            CHECK(true, util_test_calc_abc(-1, 0, 7, 2, 2.6458, -2.6458));
            //a = 7, b = 0, c = 7, roots = 0, x1 = NaN, x2 = NaN
            CHECK(true, util_test_calc_abc(7, 0, 7, 0));
            //a = 8, b = 0, c = 7, roots = 0, x1 = NaN, x2 = NaN
            CHECK(true, util_test_calc_abc(8, 0, 7, 0));
            //a = 1, b = 0, c = -17, roots = 2, x1 = -4.1231, x2 = 4.1231
            CHECK(true, util_test_calc_abc(1, 0, -17, 2, -4.1231, 4.1231));
            //a = 3, b = 0, c = -5, roots = 2, x1 = -1.2910, x2 = 4.1231
            CHECK(true, util_test_calc_abc(3, 0, -5, 2, -1.2910, 1.2910));
        }

        void test_list(){
            test_calculate_two_roots();
            test_calculate_one_root();
            test_calculate_without_roots();
            test_a();
            test_ab();
            test_ac();
        }
    };

#endif