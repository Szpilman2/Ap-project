//
// Created by peyman on 1/31/18.
//
#include "result_menu.h"
#include "login_window.h"

result::result(int height, int width, int player_score, int CPU_score, QWidget *parent) {
    QRect rec = QApplication::desktop() -> screenGeometry();
    this -> setGeometry(rec.width() / 2 - width / 2, rec.height() / 2 - height / 2, width, height);
    Q2=new QVBoxLayout;
    board=new QLabel;
    board2=new QLabel;
    btn=new QPushButton("return home");
    if(player_score>CPU_score)
    {
        board->setText("you won :)");
    }
    if(player_score==CPU_score)
    {
        board->setText("Draw");
    }
    if(player_score<CPU_score)
    {
        board->setText("you lose :(");
    }
    std::string str="result: "+std::to_string(player_score);
    str=str+" - ";
    str=str+std::to_string(CPU_score);
    board2->setText(QString::fromStdString(str));
    Q2->addWidget(board);
    Q2->addWidget(board2);
    Q2->addWidget(btn);
    connect(btn,SIGNAL(clicked(bool)),this,SLOT(returnHome()));
    setLayout(Q2);
    show();
}
void result::returnHome() {
    this->deleteLater();
    login *a=new login(200,320);
}
