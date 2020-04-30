//
// Created by barca on 4/27/2020.
//

#include "rock.h"
#include "graphics.h"
#include "item.h"

using namespace std;

Rock::Rock() {
    color = "grey";
    verteces.resize(9);
    verteces[0] = {-50,0};
    verteces[1] = {-180,0};
    verteces[2] = {-130,40};
    verteces[3] = {-100,40};
    verteces[4] = {-115,45};
    verteces[5] = {-155,30};
    verteces[6] = {-75,30};
    verteces[7] = {-48,-10};
    verteces[8] = {-182, -10};
}

vector<point> Rock::getVerteces(){
    return verteces;
}

void Rock::setVerteces(vector<point> vs){
    verteces = vs;
}

void Rock::draw() const {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.4, 0.4, 0.4);
    draw_point(verteces[7]);
    draw_point(verteces[0]);
    glColor3f(0.3, 0.3, 0.3);
    draw_point(verteces[6]);
    draw_point(verteces[3]);
    glColor3f(0.5, 0.5, 0.5);
    draw_point(verteces[4]);
    draw_point(verteces[2]);
    glColor3f(0.4, 0.4, 0.4);
    draw_point(verteces[5]);
    draw_point(verteces[1]);
    glColor3f(0.3, 0.3, 0.3);
    draw_point(verteces[8]);
    glEnd();
}