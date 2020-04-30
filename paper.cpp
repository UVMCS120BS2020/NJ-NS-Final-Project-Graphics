//
// Created by barca on 4/27/2020.
//

#include "paper.h"
#include "graphics.h"
#include "item.h"

using namespace std;

Paper::Paper() {
    color = "white";
    verteces.resize(13);
    verteces[0] = {-90,-20};
    verteces[1] = {-180,-20};
    verteces[2] = {-180,80};
    verteces[3] = {-90,80};
}

vector<point> Paper::getVerteces(){
    return verteces;
}

void Paper::setVerteces(vector<point> vs){
    verteces = vs;
}

void Paper::draw() const {
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    draw_point(verteces[0]);
    glColor3f(0.8, 0.8, 0.8);
    draw_point(verteces[3]);
    glColor3f(0.7, 0.7, 0.7);
    draw_point(verteces[2]);
    glColor3f(0.9, 0.9, 0.9);
    draw_point(verteces[1]);
    glEnd();
}