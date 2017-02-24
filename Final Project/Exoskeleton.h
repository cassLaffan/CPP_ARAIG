#ifndef EXOSKELETON_H_
#define EXOSKELETON_H_

#include "Stimulation.h"

namespace finalProject{

  class Exoskeleton:public Stimulation{

    //none of these can be negative
    float intensity; //I'm going to assume percentages can have decimals because they totally can
    float duration; //I'm going to assume seconds have have decimals because they totally can

  public:

    Exoskeleton(std::string, float, float);

    void display(std::ostream&) const;

  };

}

#endif
