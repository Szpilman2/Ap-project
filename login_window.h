//
// Created by peyman on 1/30/18.
//

#ifndef OTHELLO_LOGIN_WINDOW_H
#define OTHELLO_LOGIN_WINDOW_H
#include <QWidget>
#include <QtWidgets>
#include <iostream>
#include "game_page.h"
class login :public QWidget{
Q_OBJECT
public:
    login(int,int,QWidget * parent= 0);
private:
    QVBoxLayout *Q1;
    QHBoxLayout *Q2;
    QLabel* l1;
    QLineEdit *le1;
    QComboBox *lvlmenu;
    QPushButton *start;
public slots:
    void request_login();
};
#endif //OTHELLO_LOGIN_WINDOW_H
