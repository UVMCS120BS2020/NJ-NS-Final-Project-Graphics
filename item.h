//
// Created by barca on 4/27/2020.
//

#ifndef NJ_NS_FINAL_PROJECT_GRAPHICS_ITEM_H
#define NJ_NS_FINAL_PROJECT_GRAPHICS_ITEM_H

#include <vector>

struct point {
    double x;
    double y;
};

class Item{
protected:
    int player;
    std::vector<point> verteces;
    void draw_point(const point &p) const;

public:
    Item();

    virtual void draw() const = 0;
};

#endif //NJ_NS_FINAL_PROJECT_GRAPHICS_ITEM_H
