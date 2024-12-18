#include <gtest.h>
#include "polinom.h"
#include "polinom.cpp"

TEST(Polinom, can_create_empty_polinom) {
    ASSERT_NO_THROW(Polinom());
}

TEST(Polinom, can_create_polinom_from_string) {
    ASSERT_NO_THROW(Polinom("2x^2 + 3xy + y^2 - 5z"));
}

TEST(Polinom, can_handle_single_term_polynom) {
    Polinom p("2x^2");
    ASSERT_EQ(p.calculate(1, 0, 0), 2);
}

TEST(Polinom, can_add_two_polynomials) {
    Polinom p1("2x^2 + 3xy + y^2");
    Polinom p2("x^2 - y^2 + z");
    Polinom result = p1 + p2;
    ASSERT_EQ(result.calculate(1, 1, 1), 7);  
}

TEST(Polinom, can_subtract_two_polynomials) {
    Polinom p1("2x^2 + 3xy + y^2");
    Polinom p2("x^2 - y^2 + z");
    Polinom result = p1 - p2;
    ASSERT_EQ(result.calculate(1, 1, 1), 5);  
}

TEST(Polinom, can_multiply_polinom_by_scalar) {
    Polinom p("x^2 + y^2 + z^2");
    Polinom result = p * 2.0;
    ASSERT_EQ(result.calculate(1, 1, 1), 6);  
}

TEST(Polinom, can_multiply_scalar_by_polinom) {
    Polinom p("x^2 + y^2 + z^2");
    Polinom result = 2.0 * p;
    ASSERT_EQ(result.calculate(1, 1, 1), 6);
}

TEST(Polinom, can_multiply_two_polynomials) {
    Polinom p1("x + y");
    Polinom p2("x - y");
    Polinom result = p1 * p2;
    ASSERT_EQ(result.calculate(2, 1, 0), 3); 
}

TEST(Polinom, can_calculate_derivative_with_respect_to_x) {
    Polinom p("3x^2y + 4xz + 2");
    Polinom result = p.derivative('x');
    ASSERT_EQ(result.calculate(1, 1, 1), 10);  
}

TEST(Polinom, can_calculate_derivative_with_respect_to_y) {
    Polinom p("3x^2y + 4yz + 2");
    Polinom result = p.derivative('y');
    ASSERT_EQ(result.calculate(1, 1, 1), 7);  
}

TEST(Polinom, can_calculate_derivative_with_respect_to_z) {
    Polinom p("3x^2z + 4yz + 2z");
    Polinom result = p.derivative('z');
    ASSERT_EQ(result.calculate(1, 1, 1), 9); 
}

TEST(Polinom, can_handle_zero_polynomial) {
    Polinom p("0");
    ASSERT_EQ(p.calculate(1, 1, 1), 0);
}

TEST(Polinom, can_handle_polynomial_with_large_exponents) {
    ASSERT_THROW(Polinom("x^10"), std::invalid_argument);
}

TEST(Polinom, can_handle_single_variable_with_no_exponent) {
    Polinom p("x");
    ASSERT_EQ(p.calculate(2, 0, 0), 2);
}

TEST(Polinom, can_handle_constant_term) {
    Polinom p("5");
    ASSERT_EQ(p.calculate(1, 1, 1), 5);
}

TEST(Polinom, can_handle_invalid_character) {
    ASSERT_THROW(Polinom("2x + 3y + 4k"), std::invalid_argument);
}

TEST(Polinom, can_handle_multiple_terms_with_same_degree) {
    Polinom p("2x^2 + 3x^2");
    ASSERT_EQ(p.calculate(1, 0, 0), 5);
}

TEST(Polinom, can_handle_leading_negative_term) {
    Polinom p("-x^2 + 3x - 2");
    ASSERT_EQ(p.calculate(1, 1, 1), 0); 
}

TEST(Polinom, can_handle_all_zero_coefficients) {
    Polinom p("0x^2 + 0y + 0");
    ASSERT_EQ(p.calculate(1, 1, 1), 0);
}

TEST(Polinom, can_handle_addition_with_zero_polynomial) {
    Polinom p1("2x^2 + 3xy");
    Polinom p2("0");
    Polinom result = p1 + p2;
    ASSERT_EQ(result.calculate(1, 1, 1), 5); 
}

TEST(Polinom, can_handle_subtraction_with_zero_polynomial) {
    Polinom p1("2x^2 + 3xy");
    Polinom p2("0");
    Polinom result = p1 - p2;
    ASSERT_EQ(result.calculate(1, 1, 1), 5);  
}

TEST(Polinom, can_handle_multiplication_with_zero_polynomial) {
    Polinom p1("2x^2 + 3xy");
    Polinom p2("0");
    Polinom result = p1 * p2;
    ASSERT_EQ(result.calculate(1, 1, 1), 0); 
}

TEST(Polinom, can_handle_derivative_with_zero_polynomial) {
    Polinom p("0");
    Polinom result = p.derivative('x');
    ASSERT_EQ(result.calculate(1, 1, 1), 0);
}

TEST(Polinom, can_handle_polynomial_with_no_variables) {
    Polinom p("5 + 3");
    ASSERT_EQ(p.calculate(1, 1, 1), 8);
}

TEST(Polinom, can_handle_large_polynomial) {
    Polinom p("x^2 + y^2 + z^2 + 2xy + 2xz + 2yz + 3x + 3y + 3z + 4");
    ASSERT_EQ(p.calculate(1, 1, 1), 22); 
}

TEST(Polinom, can_handle_negative_coefficients) {
    Polinom p("-2x^2 - 3xy - y^2");
    ASSERT_EQ(p.calculate(1, 1, 1), -6);  
}