#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <math.h>
#include "Equat.h"


Equation::Equation (QWidget *pwgt) : QWidget(pwgt)
{
    m_a1 = new QLabel("X^2+");
    m_b1 = new QLabel("X+");
    m_c1 = new QLabel("=0");
    m_x1 = new QLabel("X1=");
    m_x2 = new QLabel("X2=");

    m_answer1 = new QLabel;
    m_answer1->setFrameStyle(QFrame::Box | QFrame::Raised);
    m_answer2 = new QLabel;
    m_answer2->setFrameStyle(QFrame::Box | QFrame::Raised);

    m_alfa = new QLineEdit;
    m_betta = new QLineEdit;
    m_gamma = new QLineEdit;

    m_butRun = new QPushButton ("Run");


    QObject::connect(
                m_butRun, SIGNAL(clicked()) ,
                SLOT (slotButtonClicked()));



   //Layout setup

    QVBoxLayout* mainLayout = new QVBoxLayout;
    QHBoxLayout* firstLayout = new QHBoxLayout;
    QHBoxLayout* secondLayout = new QHBoxLayout;

    firstLayout->setMargin(5);
    firstLayout->setSpacing(5);
    firstLayout->addWidget(m_alfa);
    firstLayout->addWidget(m_a1);
    firstLayout->addWidget(m_betta);
    firstLayout->addWidget(m_b1);
    firstLayout->addWidget(m_gamma);
    firstLayout->addWidget(m_c1);

    secondLayout->setMargin(5);
    secondLayout->setSpacing(5);
    secondLayout->addWidget(m_x1);
    secondLayout->addWidget(m_answer1);
    secondLayout->addWidget(m_x2);
    secondLayout->addWidget(m_answer2);
    secondLayout->addWidget(m_butRun);

    mainLayout->setMargin(5);
    mainLayout->setSpacing(5);
    mainLayout->addLayout(firstLayout);
    mainLayout->addLayout(secondLayout);

    setLayout(mainLayout);
}


void Equation::slotButtonClicked()
{
    m_first = m_alfa->text();
    double m_fir = m_first.toDouble();
    m_second = m_betta->text();
    double m_sec = m_second.toDouble();
    m_third = m_gamma->text();
    double m_th = m_third.toDouble();
    double m_xp =0;
    double m_xm =0;

    if ((m_sec ==0)&&(m_th !=0))
    {
        m_answer1->setText("no roots");
        m_answer2->setText("no roots");
    }
    else if (m_fir !=0)
    {
        m_xp = ((-1*m_sec)- sqrt(m_sec*m_sec - 4*m_fir*m_th))/(2*m_fir);
        m_xm = ((-1*m_sec)+ sqrt(m_sec*m_sec - 4*m_fir*m_th))/(2*m_fir);
        m_answer1 -> setNum(m_xp);
        m_answer2 -> setNum(m_xm);
    }
    else
    {
        m_xp = ((-1*m_th) / m_sec);
        m_answer1 -> setNum(m_xp);
        m_answer2->setText("one root only");
    }
}



