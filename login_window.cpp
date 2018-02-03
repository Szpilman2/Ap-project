//
// Created by peyman on 1/30/18.
#include "login_window.h"
login::login(int height,int width,QWidget * parent) :QWidget(parent) {
    QRect rec = QApplication::desktop()->screenGeometry();
    this->setGeometry(rec.width() / 2 - width / 2, rec.height() / 2 - height / 2, width, height);
    l1=new QLabel("your name :");
    le1=new QLineEdit("");
    start=new QPushButton("start game!");
    start->setFixedSize(80,30);
    lvlmenu=new QComboBox();
    lvlmenu->setFixedSize(80,30);
    lvlmenu->addItem("Noob");
    lvlmenu->addItem("medium");
    lvlmenu->addItem("rook");
    lvlmenu->addItem("grook");
    Q1=new QVBoxLayout;
    Q2=new QHBoxLayout;
    Q2->addWidget(l1);
    Q2->addWidget(le1);
    Q1->addLayout(Q2);
    Q1->addWidget(lvlmenu);
    Q1->addWidget(start);
    setLayout(Q1);
    connect(start,SIGNAL(clicked(bool)),this,SLOT(request_login()));
    show();
}
void login::request_login() {
    this->deleteLater();
    game *mygame=new game(1000,800,le1->text(),lvlmenu->currentIndex());


}
//

