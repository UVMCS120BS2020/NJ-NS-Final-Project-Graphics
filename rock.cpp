//
// Created by barca on 4/27/2020.
//

#include "rock.h"
#include "graphics.h"
#include "item.h"

using namespace std;

Rock::Rock() {
    color = "grey";
    verteces.resize(13);
    verteces[0] = {-150,0}; //down right
    verteces[1] = {-180,0}; //down left
    verteces[2] = {-180,30}; //up left
    verteces[3] = {-150,30}; //up right
}

vector<point> Rock::getVerteces(){
    return verteces;
}

void Rock::setVerteces(vector<point> vs){
    verteces = vs;
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