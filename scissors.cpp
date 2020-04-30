//
// Created by barca on 4/27/2020.
//

#include "scissors.h"
#include "graphics.h"

using namespace std;

Scissors::Scissors() {
    color = "red";
    timesWon = 0;
    verteces.resize(13);
    verteces[0] = {-50,-10};
    verteces[1] = {-180,-10};
    verteces[2] = {-50,40};
    verteces[3] = {-180,40};
    verteces[4] = {-130,15};

}

vector<point> Scissors::getVerteces(){
    return verteces;
}

void Scissors::setVerteces(vector<point> vs){
    verteces = vs;
}

int Scissors::getTimesWon() const{
    return timesWon;
}

void Scissors::setTimesWon(int w){
    timesWon = w;
}

void Scissors::draw() const {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 0, 0);
    draw_point(verteces[0]);
    draw_point(verteces[1]);
    draw_point(verteces[4]);
    draw_point(verteces[2]);
    draw_point(verteces[3]);

    glEnd();
}