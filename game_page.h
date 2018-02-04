//
// Created by peyman on 1/30/18.
//

#ifndef OTHELLO_GAME_PAGE_H
#define OTHELLO_GAME_PAGE_H
#include <QWidget>
#include <QtWidgets>
#include <QMouseEvent>
#include <QPainter>
#include <QBrush>
#include "game_core.h"
class game : public QWidget {
Q_OBJECT
public :
    game(int height, int width, QString name, int lvl, QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *ev);
private:
    QString player_name ;
    Core gameCore;
protected:
    void paintEvent(QPaintEvent *);

signals:
    void mousePressed(const QPoint &, int);
};
#endif //OTHELLO_GAME_PAGE_H
