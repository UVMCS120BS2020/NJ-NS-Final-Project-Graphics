//
// Created by barca on 4/27/2020.
//
#include "item.h"
#include "graphics.h"


Item::Item(){
    player = 0;
    verteces.clear();
    verteces.resize(30);
}

void Item :: draw_point(const point &p) const {
    glVertex2f(p.x, p.y);
}

