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
    int timesWon;

public:
    Rock();

    std::string getColor();

    void setColor(std::string c);

    int getTimesWon() const;

    void setTimesWon(int w);

    void draw() const override;

};



#endif //NJ_NS_FINAL_PROJECT_GRAPHICS_ROCK_H
