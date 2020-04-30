//
// Created by barca on 4/27/2020.
//

#include "scissors.h"
#include "graphics.h"

using namespace std;

Scissors::Scissors() {
    color = "black";
    verteces.resize(21);
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

    verteces[13] = {-35,15};
    verteces[14] = {-60,15};
    verteces[15] = {-60,-10};
    verteces[16] = {-35,-10};

    verteces[17] = {-40,10};
    verteces[18] = {-55,10};
    verteces[19] = {-55,-5};
    verteces[20] = {-40,-5};

}

vector<point> Scissors::getVerteces(){
    return verteces;
}

void Scissors::setVerteces(vector<point> vs){
    verteces = vs;
}

void Scissors::draw() const {
#ifdef __APPLE__
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 1, 1);
    draw_point(verteces[4]);
    glColor3f(0.8, 0.8, 0.8);
    draw_point(verteces[1]);
    glColor3f(0.7, 0.7, 0.7);
    draw_point(verteces[0]);
    draw_point(verteces[2]);
    glColor3f(1, 1, 1);
    draw_point(verteces[3]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    draw_point(verteces[5]);
    draw_point(verteces[6]);
    draw_point(verteces[7]);
    draw_point(verteces[8]);

    draw_point(verteces[13]);
    draw_point(verteces[14]);
    draw_point(verteces[15]);
    draw_point(verteces[16]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    draw_point(verteces[9]);
    draw_point(verteces[10]);
    draw_point(verteces[11]);
    draw_point(verteces[12]);

    draw_point(verteces[17]);
    draw_point(verteces[18]);
    draw_point(verteces[19]);
    draw_point(verteces[20]);
    glEnd();
#else
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    draw_point(verteces[9]);
    draw_point(verteces[10]);
    draw_point(verteces[11]);
    draw_point(verteces[12]);

    draw_point(verteces[17]);
    draw_point(verteces[18]);
    draw_point(verteces[19]);
    draw_point(verteces[20]);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    draw_point(verteces[5]);
    draw_point(verteces[6]);
    draw_point(verteces[7]);
    draw_point(verteces[8]);

    draw_point(verteces[13]);
    draw_point(verteces[14]);
    draw_point(verteces[15]);
    draw_point(verteces[16]);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 1, 1);
    draw_point(verteces[4]);
    glColor3f(0.8, 0.8, 0.8);
    draw_point(verteces[1]);
    glColor3f(0.7, 0.7, 0.7);
    draw_point(verteces[0]);
    draw_point(verteces[2]);
    glColor3f(1, 1, 1);
    draw_point(verteces[3]);
    glEnd();
#endif


}