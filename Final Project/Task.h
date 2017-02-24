#ifndef TASK_H_
#define TASK_H_

#include <list>
#include <iomanip>
#include <string>
#include "Stimulation.h"
#include "Stims.h"
#include "Exoskeleton.h"

namespace finalProject{

  class Task{
    std::string name;
    //I think this would be so much better with a vector
    //seriously why aren't we using a vector
    std::list<Stimulation*> stimList;

  public:
    Task();
    Task(Task&);
    Task(Task&&);

    void setName(std::string);

    void operator+=(Stimulation*);

    Stimulation* operator[](const int );

    void deletion(std::string name);

    void dump(std::ostream&);

    void execute(std::ostream&);

    void clearStims();

    std::string returnName();

  };

}

#endif
