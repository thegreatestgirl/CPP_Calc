#include <gtest/gtest.h>

#include <iostream>

#include "try.h"

using s21::Data;

const double PI = 3.141592653589793;

TEST(Sum, sum1) {
  Data a;
  a.setData("2+2");
  ASSERT_EQ(a.getAnswer(), 4);
}

TEST(Sum, sum2) {
  Data a;
  a.setData("2+2+2+2+2+2+2+2");
  ASSERT_EQ(a.getAnswer(), 16);
}

TEST(Sum, sum3) {
  Data a;
  a.setData("12.0000009+0.0000001");
  ASSERT_EQ(a.getAnswer(), 12.000001);
}

TEST(Sub, sub1) {
  Data a;
  a.setData("2-2");
  ASSERT_EQ(a.getAnswer(), 0);
}

TEST(Sub, sub2) {
  Data a;
  a.setData("2-2-2-2-2-2-2-2");
  ASSERT_EQ(a.getAnswer(), -12);
}

TEST(Sub, sub3) {
  Data a;
  a.setData("12-0.0000001");
  ASSERT_EQ(a.getAnswer(), 11.9999999);
}

TEST(Mul, mul1) {
  Data a;
  a.setData("2*2");
  ASSERT_EQ(a.getAnswer(), 4);
}

TEST(Mul, mul2) {
  Data a;
  a.setData("-2*2");
  ASSERT_EQ(a.getAnswer(), -4);
}

TEST(Mul, mul3) {
  Data a;
  a.setData("+2*2");
  ASSERT_EQ(a.getAnswer(), 4);
}

TEST(Div, div1) {
  Data a;
  a.setData("2/2");
  ASSERT_EQ(a.getAnswer(), 1);
}

TEST(Div, div2) {
  Data a;
  a.setData("-5/2");
  ASSERT_EQ(a.getAnswer(), -2.5);
}

TEST(Div, div3) {
  Data a;
  a.setData("5/2");
  ASSERT_EQ(a.getAnswer(), 2.5);
}

TEST(Priority, priority1) {
  Data a;
  a.setData("2+2*2");
  ASSERT_EQ(a.getAnswer(), 6);
}

TEST(Priority, priority2) {
  Data a;
  a.setData("2*2+2");
  ASSERT_EQ(a.getAnswer(), 6);
}

TEST(Priority, priority3) {
  Data a;
  a.setData("2*2+2*2");
  ASSERT_EQ(a.getAnswer(), 8);
}

TEST(Pow, pow1) {
  Data a;
  a.setData("2^2");
  ASSERT_EQ(a.getAnswer(), 4);
}

TEST(Pow, pow2) {
  Data a;
  a.setData("-2^2");
  ASSERT_EQ(a.getAnswer(), 4);
}

TEST(Pow, pow3) {
  Data a;
  a.setData("2^2^2");
  ASSERT_EQ(a.getAnswer(), 16);
}

TEST(Brackets, brackets1) {
  Data a;
  a.setData("(+2+3)*2");
  ASSERT_EQ(a.getAnswer(), 10);
}

TEST(Brackets, brackets2) {
  Data a;
  a.setData("(-2+3)*2");
  ASSERT_EQ(a.getAnswer(), 2);
}

TEST(Brackets, brackets3) {
  Data a;
  a.setData("(-(-(-3)))");
  ASSERT_EQ(a.getAnswer(), -3);
}

TEST(Cos, cos1) {
  Data a;
  a.setData("cos(2*p)");
  ASSERT_EQ(a.getAnswer(), 1);
}

TEST(Cos, cos2) {
  Data a;
  a.setData("cos(p)");
  ASSERT_EQ(a.getAnswer(), -1);
}

TEST(Cos, cos3) {
  Data a;
  a.setData("-cos(2*p)");
  ASSERT_EQ(a.getAnswer(), -1);
}

TEST(Cos, cos4) {
  Data a;
  a.setData("-(-(-cos(p)))");
  ASSERT_EQ(a.getAnswer(), 1);
}

TEST(Sin, sin1) {
  Data a;
  a.setData("sin(p/2)");
  ASSERT_EQ(a.getAnswer(), 1);
}

TEST(Sin, sin2) {
  Data a;
  a.setData("sin(-p/2)");
  ASSERT_EQ(a.getAnswer(), -1);
}

TEST(Sin, sin3) {
  Data a;
  a.setData("-sin(p/2)");
  ASSERT_EQ(a.getAnswer(), -1);
}

TEST(Sin, sin4) {
  Data a;
  a.setData("-(-(-sin(-p/2)))");
  ASSERT_EQ(a.getAnswer(), 1);
}

TEST(Sin, sin5) {
  Data a;
  a.setData("-(-(-sin(-p/2)))+(-(-(-cos(2*p))))");
  ASSERT_EQ(a.getAnswer(), 0);
}

TEST(Mod, mod1) {
  Data a;
  a.setData("(12.5mod3.8)*10");
  ASSERT_EQ(a.getAnswer(), 11);
}

TEST(Mod, mod2) {
  Data a;
  a.setData("(125mod39.845)");
  ASSERT_EQ(a.getAnswer(), 5.465);
}

TEST(Tan, tan1) {
  Data a;
  a.setData("tan(0)");
  ASSERT_EQ(a.getAnswer(), 0);
}

TEST(Tan, tan2) {
  Data a;
  a.setData("tan(p)");
  ASSERT_EQ(a.getAnswer(), 0);
}

TEST(Tan, tan3) {
  Data a;
  a.setData("-tan(p)");
  ASSERT_EQ(a.getAnswer(), 0);
}

TEST(Acos, acos1) {
  Data a;
  a.setData("acos(1)");
  ASSERT_EQ(a.getAnswer(), 0);
}

TEST(Acos, acos2) {
  Data a;
  a.setData("acos(-1)");
  ASSERT_EQ(a.getAnswer(), PI);
}

TEST(Acos, acos3) {
  Data a;
  a.setData("-acos(-1)");
  ASSERT_EQ(a.getAnswer(), -PI);
}

TEST(Asin, asin1) {
  Data a;
  a.setData("asin(1)");
  ASSERT_EQ(a.getAnswer(), PI / 2);
}

TEST(Asin, asin2) {
  Data a;
  a.setData("asin(-1)");
  ASSERT_EQ(a.getAnswer(), -PI / 2);
}

TEST(Asin, asin3) {
  Data a;
  a.setData("-asin(-1)");
  ASSERT_EQ(a.getAnswer(), PI / 2);
}

TEST(Atan, atan1) {
  Data a;
  a.setData("atan(0)");
  ASSERT_EQ(a.getAnswer(), 0);
}

TEST(Atan, atan2) {
  Data a;
  a.setData("-atan(0)");
  ASSERT_EQ(a.getAnswer(), 0);
}

TEST(Sqrt, sqrt1) {
  Data a;
  a.setData("sqrt(0)");
  ASSERT_EQ(a.getAnswer(), 0);
}

TEST(Sqrt, sqrt2) {
  Data a;
  a.setData("sqrt(4)");
  ASSERT_EQ(a.getAnswer(), 2);
}

TEST(Sqrt, sqrt3) {
  Data a;
  a.setData("-sqrt(100000000)");
  ASSERT_EQ(a.getAnswer(), -10000);
}

TEST(Ln, ln1) {
  Data a;
  a.setData("ln(1)");
  ASSERT_EQ(a.getAnswer(), 0);
}

TEST(Ln, ln2) {
  Data a;
  a.setData("-ln(1)");
  ASSERT_EQ(a.getAnswer(), 0);
}

TEST(Log, log1) {
  Data a;
  a.setData("log(10)");
  ASSERT_EQ(a.getAnswer(), 1);
}

TEST(Log, log2) {
  Data a;
  a.setData("-log(100000)");
  ASSERT_EQ(a.getAnswer(), -5);
}

TEST(Pi, pi1) {
  Data a;
  a.setData("(-p)");
  ASSERT_EQ(a.getAnswer(), -PI);
}

TEST(Pi, pi2) {
  Data a;
  a.setData("-p");
  ASSERT_EQ(a.getAnswer(), -PI);
}

TEST(X, x1) {
  Data a;
  a.setData("x");
  a.setXValue(34);
  ASSERT_EQ(a.getAnswer(), 34);
}

TEST(X, x2) {
  Data a;
  a.setData("-x");
  a.setXValue(34);
  ASSERT_EQ(a.getAnswer(), -34);
}

TEST(X, x3) {
  Data a;
  a.setData("x^2");
  a.setXValue(-9);
  ASSERT_EQ(a.getAnswer(), 81);
}

TEST(Ex, ex1) {
  Data a;
  a.setData("-2e+3+3e+3-5e+3");
  ASSERT_EQ(a.getAnswer(), -4000);
}

TEST(Ex, ex2) {
  Data a;
  a.setData("-2e-2");
  ASSERT_EQ(a.getAnswer(), -0.02);
}

TEST(Exception, Exception1) {
  Data a;
  a.setData("ee3");
  ASSERT_THROW(a.getAnswer(), std::invalid_argument);
}

TEST(Exception, Exception2) {
  Data a;
  a.setData("7+(4");
  ASSERT_THROW(a.getAnswer(), std::runtime_error);
}

TEST(Exception, Exception3) {
  Data a;
  a.setData("tan(p/2)");
  ASSERT_THROW(a.getAnswer(), std::runtime_error);
}

TEST(Exception, Exception4) {
  Data a;
  a.setData("-tan(p/2)");
  ASSERT_THROW(a.getAnswer(), std::runtime_error);
}

TEST(Exception, Exception5) {
  Data a;
  a.setData("acos(2)");
  ASSERT_THROW(a.getAnswer(), std::runtime_error);
}

TEST(Exception, Exception6) {
  Data a;
  a.setData("-acos(2)");
  ASSERT_THROW(a.getAnswer(), std::runtime_error);
}

TEST(Exception, Exception7) {
  Data a;
  a.setData("asin(2)");
  ASSERT_THROW(a.getAnswer(), std::runtime_error);
}

TEST(Exception, Exception8) {
  Data a;
  a.setData("-asin(2)");
  ASSERT_THROW(a.getAnswer(), std::runtime_error);
}

TEST(Exception, Exception9) {
  Data a;
  a.setData("sqrt(-2)");
  ASSERT_THROW(a.getAnswer(), std::runtime_error);
}

TEST(Exception, Exception10) {
  Data a;
  a.setData("-sqrt(-2)");
  ASSERT_THROW(a.getAnswer(), std::runtime_error);
}

TEST(Exception, Exception11) {
  Data a;
  a.setData("log(-2)");
  ASSERT_THROW(a.getAnswer(), std::runtime_error);
}

TEST(Exception, Exception12) {
  Data a;
  a.setData("-log(-2)");
  ASSERT_THROW(a.getAnswer(), std::runtime_error);
}

TEST(Exception, Exception13) {
  Data a;
  a.setData("ln(-2)");
  ASSERT_THROW(a.getAnswer(), std::runtime_error);
}

TEST(Exception, Exception14) {
  Data a;
  a.setData("-ln(-2)");
  ASSERT_THROW(a.getAnswer(), std::runtime_error);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
