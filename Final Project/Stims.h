#ifndef STIMS_H_
#define STIMS_H_

#include "Stimulation.h"

namespace finalProject{

  enum muscleGroups{abs, front, back, traps};

  class Stims:public Stimulation{
    muscleGroups location;
    //none of these can be negative
    float intensity; //I'm going to assume percentages can have decimals because they totally can
    unsigned int frequency;
    float duration; //I'm going to assume seconds have have decimals because they totally can

  public:

    Stims(std::string, muscleGroups, float, unsigned int, float);

    void display(std::ostream&) const;

  };

}

#endif
