//
// Created by barca on 4/27/2020.
//

#ifndef NJ_NS_FINAL_PROJECT_GRAPHICS_SCISSORS_H
#define NJ_NS_FINAL_PROJECT_GRAPHICS_SCISSORS_H

#include <string>
#include "item.h"

class Scissors : public Item {
private:
    std::string color;
    int timesWon;

public:
    Scissors();

    std::string getColor() const;

    void setColor(std::string c);

    int getTimesWon() const;

    void setTimesWon(int w);

    void draw() const override;

};

#endif //NJ_NS_FINAL_PROJECT_GRAPHICS_SCISSORS_H
