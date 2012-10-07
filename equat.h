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
    QDoubleSpinBox* m_a;
    QDoubleSpinBox* m_b;
    QDoubleSpinBox* m_c;

    QLCDNumber* m_ans1;
    QLCDNumber* m_ans2;


     QLabel* m_a1;
     QLabel* m_b1;
     QLabel* m_c1;
     QLabel* m_x1;
     QLabel* m_x2;

     QPushButton* m_run;





public:
    Equation (QWidget* pwgt = 0);



public slots:
    void slotButtonClicked();


};


#endif // EQUAT_H
