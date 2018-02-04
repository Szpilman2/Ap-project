//
// Created by peyman on 1/31/18.
//

#ifndef OTHELLO_RESULT_MENU_H
#define OTHELLO_RESULT_MENU_H

#include <QtWidgets/QWidget>
#include <QtWidgets>
class result : public QWidget{
    Q_OBJECT
public:
    result(int height, int width,int player_score,int CPU_score, QWidget *parent = 0);

private:
    QVBoxLayout *Q2;
    QLabel *board;
    QLabel *board2;
    QPushButton * btn;
public slots:
    void returnHome();
};
#endif //OTHELLO_RESULT_MENU_H
