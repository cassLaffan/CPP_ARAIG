#ifndef PROFILE_H_
#define PROFILE_H_

#include <string>
#include <vector>
#include <queue>

#include "Stimulation.h"
#include "Stims.h"
#include "Exoskeleton.h"
#include "Task.h"
#include "ARAIG_Sensors.h"

namespace finalProject{
  struct Calibration{
    int maxIntensity;
    int minIntensity;
  };

  class Profile{
    std::string stFirstName;
    std::string stLastName;
    int stNumber;
    std::string iFirstName;
    std::string iLastName;
    int iNumber;
    std::ostream& something;

    Calibration cali;
    std::vector<Task*> ToRun;
    std::vector<Task*> Completed;

  public:

    Profile(const char*, std::ostream&, ARAIG_Sensors&);

    void displayToRun(std::ostream&);
    void displayCompleted(std::ostream&);
    void displayNextTask(std::ostream&);
    void displayLastTask(std::ostream&);
    void shrinkToRun();

    void run();

    void saveAs();
  };

}

#endif
