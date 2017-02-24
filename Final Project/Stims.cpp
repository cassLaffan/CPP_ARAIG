#include "Stims.h"

namespace finalProject{

  Stims::Stims(std::string name, muscleGroups group, float intense, unsigned int frequent, float timeAmount){
    //can't have intensity greater than 100%
    if(intense <= 100.00 && intense >= 0 && timeAmount >= 0){
      stimulationName = name;
      location = group;
      intensity = intense;
      frequency = frequent;
      duration = timeAmount;
    }

    else{
      throw "Your numbers are off! stim";
    }

  }

  void Stims::display(std::ostream& ostr) const{
    ostr << "     TYPE: " << stimulationName << std::endl;
    ostr << "     LOCATION:  ";
    if(location == abs){
      ostr << "abs" << std::endl;
    }
    else if(location == front){
      ostr << "front" << std::endl;
    }
    else if(location == back){
      ostr << "back" << std::endl;
    }
    else{
      ostr << "traps" << std::endl;
    }
    ostr << "     INTENSITY: " << intensity << std::endl;
    ostr << "     FREQUENCY: " << frequency << std::endl;
    ostr << "     DURATION: " << duration << std::endl;
  }
}
