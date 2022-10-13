#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include <qcustomplot.h>
#include <QVector>
#include <QDialog>

#ifdef __cplusplus
#include "../try.h"
#endif

namespace Ui {
class graph;
}

class graph : public QDialog
{
    Q_OBJECT

public:
    void slot(QString s, int X, int Y);
    explicit graph(QWidget *parent = nullptr);
    ~graph();
private:
    Ui::graph *ui;
};

#endif // GRAPH_H
