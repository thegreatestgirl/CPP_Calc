#ifndef SRC_TRY_H_
#define SRC_TRY_H_

#include <exception>
#include <iostream>
#include <stack>
#include <string>

namespace s21 {

class Data {
  std::string str_;
  std::string subStr_;
  double xValue_;
  int size_;
  double a_;
  double b_;
  char sym_;
  int i = 0;
  int unaryMinus_ = 0;  // 0 - no unary minus
  int unaryPlus_ = 0;   // 0 - no unary plus
  std::stack<char> strStack;
  std::stack<double> doubleStack;
  void setSize();
  void count();
  void countWithOneArg(char sym, double a);
  void countWithTwoArgs(char sym, double a);
  void parser();
  // void print();
  bool isUnary();
  void setUnary();
  int priority(char symbol);

  double Cos(double x);
  double Sin(double x);
  double Tan(double x);

  void findNumber();
  void findExponentialForm();
  void findPi();
  void findX();
  void findOperation();
  void findOpenBracket();
  void findCloseBracket();

  void findFunction();

  void findMod();
  void findCos();
  void findSin();
  void findTan();
  void findAcos();
  void findAsin();
  void findAtan();
  void findSqrt();
  void findLn();
  void findLog();

  int openBracketsAmount = 0;
  int closeBracketsAmount = 0;

  void incrementOfOpenBracketsAmount();
  void incrementOfCloseBracketsAmount();

  void checkOnBracketsNumber();
  void checkOnEmptyArgs();

 public:
  //   Data();
  //   ~Data();
  void setData(const std::string &data);
  void setXValue(double x);
  double getAnswer();
  void clearAll();
};
}  // namespace s21

#endif  // SRC_TRY_H_
