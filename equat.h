#ifndef EQUAT_H
#define EQUAT_H

#include <QWidget>

class QPushButton;
class QLabel;
class QDoubleSpinBox;
class QLCDNumber;

class Equation : public QWidget
{
    Q_OBJECT

private:
    QDoubleSpinBox* A;
    QDoubleSpinBox* B;
    QDoubleSpinBox* C;

    QLCDNumber* Ans1;
    QLCDNumber* Ans2;


     QLabel* A1;
     QLabel* B1;
     QLabel* C1;
     QLabel* X1;
     QLabel* X2;

     QPushButton* Run;





public:
    Equation (QWidget* pwgt = 0);



public slots:
    void slotButtonClicked();


};


#endif // EQUAT_H
