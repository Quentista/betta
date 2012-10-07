#include <QtGui>
#include <math.h>
#include "equat.h"


Equation::Equation (QWidget *pwgt) : QWidget(pwgt)
{
    m_a1 = new QLabel("X^2+");
    m_b1 = new QLabel("X+");
    m_c1 = new QLabel("=0");
    m_x1 = new QLabel("X1=");
    m_x2 = new QLabel("X2=");

    m_ans1 = new QLCDNumber(12);
    m_ans1 ->setSegmentStyle(QLCDNumber::Flat);
    m_ans2 = new QLCDNumber(12);
    m_ans2 ->setSegmentStyle(QLCDNumber::Flat);


    m_a = new QDoubleSpinBox;
    m_a->setRange(-9999, 9999);

    m_b = new QDoubleSpinBox;
    m_b->setRange(-9999, 9999);

    m_c = new QDoubleSpinBox;
    m_c->setRange(-9999, 9999);

    m_run = new QPushButton ("Run");


    QObject::connect(m_run, SIGNAL(clicked()) ,
                     SLOT (slotButtonClicked()));







   //Layout setup

    QGridLayout* firstLay = new QGridLayout;

    firstLay -> addWidget(m_a, 0,0);
    firstLay -> addWidget(m_b, 0,2);
    firstLay -> addWidget(m_c, 0,4);

    firstLay -> addWidget(m_a1, 0,1);
    firstLay -> addWidget(m_b1, 0,3);
    firstLay -> addWidget(m_c1, 0,5);
    firstLay -> addWidget(m_x1, 1,0);
    firstLay -> addWidget(m_x2,1,2);

    firstLay -> addWidget(m_ans1, 1,1);
    firstLay -> addWidget(m_ans2, 1,3);

    firstLay -> addWidget(m_run, 1 , 4, 1, 3);

    setLayout(firstLay);

}



void Equation::slotButtonClicked()
{
    double n_fir = m_a -> value();
    double n_sec = m_b ->value();
    double n_thir = m_c ->value();
    double n_xp =0;
    double n_xm =0;

    n_xp = ((-1*n_sec)- sqrt(n_sec*n_sec - 4*n_fir*n_thir))/(2*n_fir);
    n_xm = ((-1*n_sec)+ sqrt(n_sec*n_sec - 4*n_fir*n_thir))/(2*n_fir);
    m_ans1 -> display (n_xp);
    m_ans2 -> display (n_xm);


}

