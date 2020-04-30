//
// Created by barca on 4/27/2020.
//

#ifndef NJ_NS_FINAL_PROJECT_GRAPHICS_PAPER_H
#define NJ_NS_FINAL_PROJECT_GRAPHICS_PAPER_H

#include <string>
#include "item.h"

class Paper : public Item {
private:
    std::string color;

public:
    Paper();

    std::vector<point> getVerteces();

    void setVerteces(std::vector<point> vs);


    void draw() const override;

};

#endif //NJ_NS_FINAL_PROJECT_GRAPHICS_PAPER_H
