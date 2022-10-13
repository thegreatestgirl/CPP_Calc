#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../try.h"
#include <QString>
#include <exception>
#include <iostream>
#include <stack>
#include <string>

namespace s21 {

class Controller{
    Data a;
public:
    void setData(QString fromLabel, double x);
    QString getAnswerStr();
    double getAnswer();
};
}  // namespace s21

#endif // CONTROLLER_H
