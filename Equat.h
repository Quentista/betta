#ifndef EQUAT_H
#define EQUAT_H

#include <QWidget>

class QPushButton;
class QLabel;
class QLineEdit;

class Equation : public QWidget
{
    Q_OBJECT


public:
    Equation (QWidget* pwgt = 0);


public slots:
    void slotButtonClicked();


private:
    QLabel* m_a1;
    QLabel* m_b1;
    QLabel* m_c1;
    QLabel* m_x1;
    QLabel* m_x2;

    QLabel* m_answer1;
    QLabel* m_answer2;

    QLineEdit* m_alfa;
    QLineEdit* m_betta;
    QLineEdit* m_gamma;

    QPushButton* m_butRun;
};


#endif // EQUAT_H
