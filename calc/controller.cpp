#include "controller.h"

#include <QString>
#include <cmath>
#include <exception>
#include <iomanip>
#include <iostream>
#include <stack>
#include <string>

using namespace s21;

void Controller::setData(QString fromLabel, double x) {
    a.setData(fromLabel.toStdString());
    a.setXValue(x);
}

QString Controller::getAnswerStr() {
    try {
        return QString::number(a.getAnswer());
    } catch (std::runtime_error) {
       a.clearAll();
       QString error = "Error";
       return error;
    }
}

double Controller::getAnswer() {
    return a.getAnswer();
}
