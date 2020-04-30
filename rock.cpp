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
    verteces[0] = {-50,0}; //down right
    verteces[1] = {-180,0}; //down left
    verteces[2] = {-130,40}; //up left
    verteces[3] = {-100,40}; //up right
    verteces[4] = {-115,45};
    verteces[5] = {-155,30};
    verteces[6] = {-75,30};
}

vector<point> Rock::getVerteces(){
    return verteces;
}

void Rock::setVerteces(vector<point> vs){
    verteces = vs;
}

int Rock::getTimesWon() const{
    return timesWon;
}

void Rock::setTimesWon(int w){
    timesWon = w;
}

void Rock::draw() const {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 1, 0);
    draw_point(verteces[0]);
    draw_point(verteces[6]);
    draw_point(verteces[3]);
    draw_point(verteces[4]);
    draw_point(verteces[2]);
    draw_point(verteces[5]);
    draw_point(verteces[1]);
    glEnd();
}