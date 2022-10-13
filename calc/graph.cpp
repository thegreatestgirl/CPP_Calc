#include "graph.h"
#include "controller.h"
#include "ui_graph.h"

graph::graph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graph)
{
    ui->setupUi(this);
}

graph::~graph()
{
    delete ui;
}

void graph::slot(QString s, int X, int Y)
{
    ui->widget->clearGraphs();
    QVector<double> x,y;
    ui->widget->replot();
    ui->widget->addGraph();

    QPen pen;
    pen.setColor(QColor(48, 41, 41, 100));
    pen.setWidthF(2.5);
    ui->widget->graph(0)->setPen(pen);
    ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QPixmap(":/resources/img/smallStr.png")));

    ui->widget->xAxis->setRange(-X, X);
    ui->widget->yAxis->setRange(-Y, Y);
    char* str = new char(s.length());
    QByteArray barr = s.toLatin1();
    double step;
    if (X < 100) {
        step = 0.05;
    } else {
        step = X/100;
    }

    double f;
    strlcpy(str, barr, 256);
    for (double l = -X; l < X; l += step) {
        std::cout << s.toStdString() << " " << l;
        s21::Controller a;
          a.setData(s, l);
          f = a.getAnswer();
          std::cout << " " << f << std::endl;
          if(f<Y) {
            y.append(f);
            x.append(l);
            l=l+0.1;
          }
    }
    delete(str);
    ui->widget->graph(0)->addData(x,y);
    ui->widget->replot();
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget->setInteraction(QCP::iRangeDrag, true);
}
