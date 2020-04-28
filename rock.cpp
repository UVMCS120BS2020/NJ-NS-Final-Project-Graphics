//
// Created by barca on 4/27/2020.
//

#include "rock.h"
#include "graphics.h"
#include "item.h"

using namespace std;

Rock::Rock() {
    color = "grey";
    timesWon = 0;
    verteces.resize(13);
    verteces[0] = {0,0}; //down right
    verteces[1] = {-50,0}; //down left
    verteces[2] = {-50,50}; //up left
    verteces[3] = {0,50}; //up right
}

string Rock::getColor(){
    return color;
}

void Rock::setColor(string c){
    color = c;
}

int Rock::getTimesWon() const{
    return timesWon;
}

void Rock::setTimesWon(int w){
    timesWon = w;
}

void Rock::draw() const {
    glBegin(GL_QUADS);
    glColor3f(1, 1, 0);
    draw_point(verteces[0]);
    draw_point(verteces[3]);
    draw_point(verteces[2]);
    draw_point(verteces[1]);
    glEnd();
}