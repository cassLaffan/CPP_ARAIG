#include "Exoskeleton.h"

namespace finalProject{
  Exoskeleton::Exoskeleton(std::string name, float intense, float timeVar){
    //can't have intensity greater than 100%
    if(intense <= 100.00 && intense >= 0 && timeVar >= 0){
      stimulationName = name;
      intensity = intense;
      duration = timeVar;
    }

    else{
      throw "Your numbers are off! exo";
    }
  }

  void Exoskeleton::display(std::ostream& ostr) const{
    ostr << "     TYPE: " << stimulationName << std::endl;
    ostr << "     INTENSITY: " << intensity << std::endl;
    ostr << "     DURATION: " << duration << std::endl;
  }
}
