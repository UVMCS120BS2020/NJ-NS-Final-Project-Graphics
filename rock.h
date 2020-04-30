//
// Created by barca on 4/27/2020.
//

#ifndef NJ_NS_FINAL_PROJECT_GRAPHICS_ROCK_H
#define NJ_NS_FINAL_PROJECT_GRAPHICS_ROCK_H

#include "item.h"
#include <string>

class Rock : public Item {
private:
    std::string color;

public:
    Rock();

    std::vector<point> getVerteces();

    void setVerteces(std::vector<point> vs);

    void draw() const override;

};



#endif //NJ_NS_FINAL_PROJECT_GRAPHICS_ROCK_H
