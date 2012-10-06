#include <QtGui>
#include <math.h>
#include "equat.h"


Equation::Equation (QWidget *pwgt) : QWidget(pwgt)
{
    QLabel* A1 = new QLabel("X^2+");
    QLabel* B1 = new QLabel("X+");
    QLabel* C1 = new QLabel("=0");
    QLabel* X1 = new QLabel("X1=");
    QLabel* X2 = new QLabel("X2=");

    QLCDNumber* Ans1 = new QLCDNumber(12);
    Ans1 ->setSegmentStyle(QLCDNumber::Flat);
    QLCDNumber* Ans2 = new QLCDNumber(12);
    Ans2 ->setSegmentStyle(QLCDNumber::Flat);


    QDoubleSpinBox* A = new QDoubleSpinBox;
    A->setRange(-9999, 9999);

    QDoubleSpinBox* B = new QDoubleSpinBox;
    B->setRange(-9999, 9999);

    QDoubleSpinBox* C = new QDoubleSpinBox;
    C->setRange(-9999, 9999);

    QPushButton* Run = new QPushButton ("Run");


    QObject::connect(Run, SIGNAL(clicked()) ,
                     SLOT (slotButtonClicked()));







   //Layout setup

    QGridLayout* firstLay = new QGridLayout;

    firstLay -> addWidget(A, 0,0);
    firstLay -> addWidget(B, 0,2);
    firstLay -> addWidget(C, 0,4);

    firstLay -> addWidget(A1, 0,1);
    firstLay -> addWidget(B1, 0,3);
    firstLay -> addWidget(C1, 0,5);
    firstLay -> addWidget(X1, 1,0);
    firstLay -> addWidget(X2,1,2);

    firstLay -> addWidget(Ans1, 1,1);
    firstLay -> addWidget(Ans2, 1,3);

    firstLay -> addWidget(Run, 1 , 4, 1, 3);

    setLayout(firstLay);

}



void Equation::slotButtonClicked()
{
    double fir = A -> value();
    double sec = B ->value();
    double thir = C ->value();
    double Xp =0;
    double Xm =0;

    Xp = ((-1*sec)- sqrt(sec*sec - 4*fir*thir))/(2*fir);
    Xm = ((-1*sec)+ sqrt(sec*sec - 4*fir*thir))/(2*fir);
    Ans1 -> display (Xp);
    Ans2 -> display (Xm);


}

