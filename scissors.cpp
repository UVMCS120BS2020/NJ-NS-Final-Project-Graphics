//
// Created by barca on 4/27/2020.
//

#include "scissors.h"
#include "graphics.h"

using namespace std;

Scissors::Scissors() {
    color = "red";
    verteces.resize(13);
    verteces[0] = {-50,5};
    verteces[1] = {-180,-10};
    verteces[2] = {-50,25};
    verteces[3] = {-180,40};
    verteces[4] = {-60,15};

    verteces[5] = {-35,45};
    verteces[6] = {-60,45};
    verteces[7] = {-60,20};
    verteces[8] = {-35,20};

    verteces[9] = {-40,40};
    verteces[10] = {-55,40};
    verteces[11] = {-55,25};
    verteces[12] = {-40,25};

    verteces[13] = {-135,-15};
    verteces[14] = {-160,10};
    verteces[15] = {-160,10};
    verteces[16] = {-135,-15};

}

vector<point> Scissors::getVerteces(){
    return verteces;
}

void Scissors::setVerteces(vector<point> vs){
    verteces = vs;
}

void Scissors::draw() const {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 1, 1);
    draw_point(verteces[4]);
    draw_point(verteces[1]);
    draw_point(verteces[0]);
    draw_point(verteces[2]);
    draw_point(verteces[3]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    draw_point(verteces[5]);
    draw_point(verteces[6]);
    draw_point(verteces[7]);
    draw_point(verteces[8]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    draw_point(verteces[9]);
    draw_point(verteces[10]);
    draw_point(verteces[11]);
    draw_point(verteces[12]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    draw_point(verteces[13]);
    draw_point(verteces[14]);
    draw_point(verteces[15]);
    draw_point(verteces[16]);
    glEnd();

}