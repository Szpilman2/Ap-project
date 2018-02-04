//
// Created by peyman on 1/31/18.
//

#ifndef OTHELLO_ACCESSORIES_H
#define OTHELLO_ACCESSORIES_H
#include <vector>
class Point{
public:
    int x;
    int y;
    Point(int a,int b);
    Point();
};
class Board{
public:
    int a[8][8];
};
class Suggestion{
public:
    Suggestion();
    Suggestion(int,int);
    int x;
    int y;
    std::vector<Point> reverseCords;
    int flips;
};
static Point cordinations[8];
#endif //OTHELLO_ACCESSORIES_H