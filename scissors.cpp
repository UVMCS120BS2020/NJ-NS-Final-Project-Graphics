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
    verteces[0] = {100,0};
    verteces[1] = {70,0};
    verteces[2] = {70,50};
    verteces[3] = {100,50};
}

string Scissors::getColor() const{
    return color;
}

void Scissors::setColor(string c){
    color = c;
}

int Scissors::getTimesWon() const{
    return timesWon;
}

void Scissors::setTimesWon(int w){
    timesWon = w;
}

void Scissors::draw() const {
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    draw_point(verteces[0]);
    draw_point(verteces[3]);
    draw_point(verteces[2]);
    draw_point(verteces[1]);
    glEnd();
}