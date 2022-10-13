#include "try.h"

#include <cmath>
#include <exception>
#include <iomanip>
#include <iostream>
#include <stack>
#include <string>

using s21::Data;

double Data::Cos(double x) {
  double answr = 0;
  answr = round(cos(x) * 10000000) / 10000000;
  // if (answr == 0) {
  //   answr = 0;
  // }
  return answr;
}

double Data::Sin(double x) {
  double answr = 0;
  answr = round(sin(x) * 10000000) / 10000000;
  // if (answr == 0) {
  //   answr = 0;
  // }
  return answr;
}

double Data::Tan(double x) { return (Sin(x) / Cos(x)); }

void Data::setData(const std::string &data) {
  str_ = data;
  setSize();
}

void Data::setSize() { size_ = str_.length(); }

bool Data::isUnary() {
  if (unaryMinus_ == 1) {
    subStr_ = '-';
    unaryMinus_ = 0;
    return 1;
  }
  if (unaryPlus_ == 1) {
    subStr_ = '+';
    unaryPlus_ = 0;
    // return 1;
    return 0;
  }
  return 0;
}

void Data::setUnary() {
  // if (str[i] == '-' && unaryMinus == 0) {
  //   unaryMinus = 1;
  //   i++;
  // } else if (str[i] == '+' && unaryPlus == 0) {
  //   unaryPlus = 1;
  //   i++;
  // } else if (str[i] == '-' && unaryMinus == 1) {
  //   unaryMinus = 0;
  //   i++;
  // } else if (str[i] == '+' && unaryPlus == 1) {
  //   unaryPlus = 0;
  //   i++;
  // }
  if (str_[i] == '-') {
    unaryMinus_ = !unaryMinus_;
    i++;
  }
  if (str_[i] == '+') {
    unaryPlus_ = !unaryPlus_;
    i++;
  }
}

int Data::priority(char symbol) {
  if (symbol == '+' || symbol == '-') return 1;
  if (symbol == '*' || symbol == '/') return 2;
  if (symbol == '^') return 3;
  if (symbol == 'c' || symbol == 't' || symbol == 'e' || symbol == 's' ||
      symbol == 'q' || symbol == 'l' || symbol == 'g' || symbol == 'b' ||
      symbol == 'r' || symbol == 'u' || symbol == 'd' || symbol == 'j' ||
      symbol == 'k' || symbol == 'p')
    return 4;

  return 0;
}

void Data::findMod() {
  if (str_[i] == 'm' && str_[i + 1] == 'o' && str_[i + 2] == 'd') {
    strStack.push('m');
    i = i + 3;
  }
}

void Data::findCos() {
  if (str_[i] == 'c' && str_[i + 1] == 'o' && str_[i + 2] == 's') {
    if (!isUnary()) {
      strStack.push('c');
    } else {
      strStack.push('b');
    }
    i = i + 3;
  }
}

void Data::findSin() {
  if (str_[i] == 's' && str_[i + 1] == 'i' && str_[i + 2] == 'n') {
    if (!isUnary()) {
      strStack.push('s');
    } else {
      strStack.push('d');
    }
    i = i + 3;
  }
}

void Data::findTan() {
  if (str_[i] == 't' && str_[i + 1] == 'a' && str_[i + 2] == 'n') {
    if (!isUnary()) {
      strStack.push('t');
    } else {
      strStack.push('r');
    }
    i = i + 3;
  }
}

void Data::findAcos() {
  if (str_[i] == 'a' && str_[i + 1] == 'c' && str_[i + 2] == 'o' &&
      str_[i + 3] == 's') {
    if (!isUnary()) {
      strStack.push('o');
    } else {
      strStack.push('f');
    }
    i = i + 4;
  }
}

void Data::findAsin() {
  if (str_[i] == 'a' && str_[i + 1] == 's' && str_[i + 2] == 'i' &&
      str_[i + 3] == 'n') {
    if (!isUnary()) {
      strStack.push('n');
    } else {
      strStack.push('h');
    }
    i = i + 4;
  }
}

void Data::findAtan() {
  if (str_[i] == 'a' && str_[i + 1] == 't' && str_[i + 2] == 'a' &&
      str_[i + 3] == 'n') {
    if (!isUnary()) {
      strStack.push('a');
    } else {
      strStack.push('i');
    }
    i = i + 4;
  }
}

void Data::findSqrt() {
  if (str_[i] == 's' && str_[i + 1] == 'q' && str_[i + 2] == 'r' &&
      str_[i + 3] == 't') {
    if (!isUnary()) {
      strStack.push('q');
    } else {
      strStack.push('j');
    }
    i = i + 4;
  }
}

void Data::findLn() {
  if (str_[i] == 'l' && str_[i + 1] == 'n') {
    if (!isUnary()) {
      strStack.push('l');
    } else {
      strStack.push('k');
    }
    i = i + 2;
  }
}

void Data::findLog() {
  if (str_[i] == 'l' && str_[i + 1] == 'o' && str_[i + 2] == 'g') {
    if (!isUnary()) {
      strStack.push('g');
    } else {
      strStack.push('p');
    }
    i = i + 3;
  }
}

void Data::findFunction() {
  findMod();
  findCos();
  findSin();
  findTan();
  findAcos();
  findAsin();
  findAtan();
  findSqrt();
  findLn();
  findLog();
}

void Data::findNumber() {
  subStr_ = "";
  isUnary();  //////////??????? откуда лишний минус
  while ((str_[i] >= '0' && str_[i] <= '9') || str_[i] == '.' ||
         str_[i] == 'e') {
    subStr_ = subStr_ + str_[i];
    i++;
    findExponentialForm();
  }
  doubleStack.push(std::stod(subStr_));
}

void Data::findExponentialForm() {
  if (str_[i - 1] == 'e' && (str_[i] == '+' || str_[i] == '-')) {
    if (str_[i - 2] < '0' || str_[i - 2] > '9') {
      throw std::runtime_error("Incorrect value");
    }
    subStr_ = subStr_ + str_[i];
    i++;
  }
}

void Data::findPi() {
  if (isUnary()) {
    doubleStack.push((-1) * acos(-1));
  } else {
    doubleStack.push(acos(-1));
  }
  i++;
}

void Data::findOperation() {
  if (!strStack.empty() && (priority(str_[i]) <= priority(strStack.top())))
    count();
  strStack.push(str_[i]);
  i++;
}

void Data::findOpenBracket() {
  // unaryMinus = 0;
  // unaryPlus = 0;
  incrementOfOpenBracketsAmount();
  strStack.push(str_[i]);
  i++;
  setUnary();
}

void Data::findCloseBracket() {
  incrementOfCloseBracketsAmount();
  if (strStack.empty()) throw std::runtime_error("Incorrect value");
  while (strStack.top() != '(') {
    count();
  }
  strStack.pop();
  i++;
}

void Data::findX() {
  if (isUnary()) {
    doubleStack.push((-1) * xValue_);
  } else {
    doubleStack.push(xValue_);
  }
  i++;
}

void Data::parser() {
  while (str_[i]) {
    if (i == 0) {
      setUnary();
    }
    if (str_[i] == '(') {
      findOpenBracket();
    } else if (str_[i] == ')') {
      findCloseBracket();
    } else if ((str_[i] >= '0' && str_[i] <= '9') || str_[i] == 'e') {
      findNumber();
    } else if ((str_[i] == '+' && unaryPlus_ == 0) ||
               (str_[i] == '-' && unaryMinus_ == 0) || str_[i] == '*' ||
               str_[i] == '/' || str_[i] == '^') {
      findOperation();
    } else if (str_[i] == 'm' || str_[i] == 'c' || str_[i] == 's' ||
               str_[i] == 't' || str_[i] == 'a' || str_[i] == 'l') {
      findFunction();
    } else if (str_[i] == 'p') {
      findPi();
    } else if (str_[i] == 'x') {
      findX();
    } else {
      throw std::runtime_error("Incorrect value");
    }
    if (i == size_) break;
  }
  checkOnBracketsNumber();
  while (!strStack.empty()) {
    count();
  }
}

void Data::checkOnBracketsNumber() {
  if (openBracketsAmount != closeBracketsAmount)
    throw std::runtime_error("Incorrect value");
}

void Data::countWithOneArg(char sym, double a) {
  switch (sym) {
    case 'c':
      doubleStack.push(Cos(a));
      break;
    case 'b':
      doubleStack.push((-1) * Cos(a));
      break;
    case 's':
      doubleStack.push(Sin(a));
      break;
    case 'd':
      doubleStack.push((-1) * Sin(a));
      break;
    case 't':
      if (Cos(a) == 0) {
        throw std::runtime_error("Incorrect value");
      }
      doubleStack.push(Tan(a));
      break;
    case 'r':
      if (Cos(a) == 0) {
        throw std::runtime_error("Incorrect value");
      }
      doubleStack.push((-1) * Tan(a));
      break;
    case 'o':
      if (a < -1 || a > 1) {
        throw std::runtime_error("Incorrect value");
      }
      doubleStack.push(acos(a));
      break;
    case 'f':
      if (a < -1 || a > 1) {
        throw std::runtime_error("Incorrect value");
      }
      doubleStack.push((-1) * acos(a));
      break;
    case 'n':
      if (a < -1 || a > 1) {
        throw std::runtime_error("Incorrect value");
      }
      doubleStack.push(asin(a));
      break;
    case 'h':
      if (a < -1 || a > 1) {
        throw std::runtime_error("Incorrect value");
      }
      doubleStack.push((-1) * asin(a));
      break;
    case 'a':
      doubleStack.push(atan(a));
      break;
    case 'i':
      doubleStack.push((-1) * atan(a));
      break;
    case 'q':
      if (a < 0) {
        throw std::runtime_error("Incorrect value");
      }
      doubleStack.push(sqrt(a));
      break;
    case 'j':
      if (a < 0) {
        throw std::runtime_error("Incorrect value");
      }
      doubleStack.push((-1) * sqrt(a));
      break;
    case 'l':
      if (a <= 0) {
        throw std::runtime_error("Incorrect value");
      }
      doubleStack.push(log(a));
      break;
    case 'k':
      if (a <= 0) {
        throw std::runtime_error("Incorrect value");
      }
      doubleStack.push((-1) * log(a));
      break;
    case 'g':
      if (a <= 0) {
        throw std::runtime_error("Incorrect value");
      }
      doubleStack.push(log10(a));
      break;
    case 'p':
      if (a <= 0) {
        throw std::runtime_error("Incorrect value");
      }
      doubleStack.push((-1) * log10(a));
      break;
    default:
      countWithTwoArgs(sym, a);
      break;
  }
}

void Data::checkOnEmptyArgs() {
  if (doubleStack.empty()) throw std::runtime_error("Incorrect value");
}

void Data::countWithTwoArgs(char sym, double a) {
  checkOnEmptyArgs();
  b_ = doubleStack.top();
  doubleStack.pop();
  switch (sym) {
    case '+':
      doubleStack.push(a + b_);
      break;
    case '-':
      doubleStack.push(b_ - a);
      break;
    case '*':
      doubleStack.push(a * b_);
      break;
    case '/':
      doubleStack.push(b_ / a);
      break;
    case '^':
      doubleStack.push(pow(b_, a));
      break;
    case 'm':
      doubleStack.push(round(fmod(b_, a) * 10000000) / 10000000);
      break;
    default:
      break;
  }
}

void Data::count() {
  checkOnEmptyArgs();
  a_ = doubleStack.top();
  doubleStack.pop();
  sym_ = strStack.top();
  strStack.pop();
  countWithOneArg(sym_, a_);
}

// void Data::print() {
//   std::cout << "sym stack" << std::endl;
//   while (!strStack.empty()) {
//     std::cout << strStack.top() << std::endl;
//     strStack.pop();
//   }
//   std::cout << "double stack" << std::endl;
//   while (!doubleStack.empty()) {
//     std::cout << doubleStack.top() << std::endl;
//     doubleStack.pop();
//   }
// }

double Data::getAnswer() {
  parser();
  double result = 0;
  if (!doubleStack.empty()) {
    result = doubleStack.top();
    doubleStack.pop();
  }
  clearAll();
  return result;
}

void Data::setXValue(double x) { xValue_ = x; }

void Data::clearAll() {
  while (!strStack.empty()) {
    strStack.pop();
  }
  while (!doubleStack.empty()) {
    doubleStack.pop();
  }
}

void Data::incrementOfOpenBracketsAmount() { openBracketsAmount++; }

void Data::incrementOfCloseBracketsAmount() { closeBracketsAmount++; }

// int main() {
//   Data a;
//   a.setData("+2e2+100");
//   std::cout << "ANSWER: " << std::setprecision(10) << a.getAnswer()
//             << std::endl;
// }
