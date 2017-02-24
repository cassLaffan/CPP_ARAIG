#ifndef STIMULATION_H_
#define STIMULATION_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

namespace finalProject{

  class Stimulation{
  protected:
    std::string stimulationName;
  public:
       virtual void display(std::ostream&) const = 0;
       std::string getName(){
         return stimulationName;
       }
   };

}
#endif
