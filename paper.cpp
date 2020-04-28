//
// Created by barca on 4/27/2020.
//

#include "paper.h"
#include "graphics.h"
#include "item.h"

using namespace std;

Paper::Paper() {
    color = "white";
    timesWon = 0;
    verteces.resize(13);
    verteces[0] = {50,0};
    verteces[1] = {20,0};
    verteces[2] = {20,50};
    verteces[3] = {50,50};
}

string Paper::getColor() const{
    return color;
}

void Paper::setColor(string c){
    color = c;
}

int Paper::getTimesWon() const{
    return timesWon;
}

void Paper::setTimesWon(int w){
    timesWon = w;
}

void Paper::draw() const {
    glBegin(GL_QUADS);
    glColor3f(0, 1, 0);
    draw_point(verteces[0]);
    draw_point(verteces[3]);
    draw_point(verteces[2]);
    draw_point(verteces[1]);
    glEnd();
}