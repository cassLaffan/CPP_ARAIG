#ifndef ARAIG_SENSORS_H_
#define ARAIG_SENSORS_H_

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "Exoskeleton.h"
#include "Stimulation.h"
#include "Stims.h"
#include "Task.h"

namespace finalProject{
  class ARAIG_Sensors{
    std::vector<Stimulation*> stimulationList;
    std::vector<Task*> taskList;

  public:
    ARAIG_Sensors(std::ifstream&, std::ifstream&);
    ~ARAIG_Sensors();
    void dump(std::ostream&);
    Task* getTask(std::string);
  };
}


#endif
