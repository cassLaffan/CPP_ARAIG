#include "Task.h"

namespace finalProject{

  Task::Task(){
    name = "";
    stimList.clear();
  }

  Task::Task(Task& arg){
    name = arg.name;
    int i = (int)arg.stimList.size();
    for(int j = 0; j < i; j++){
      stimList.push_back(arg[j]);
    }
  }

  Task::Task(Task&& arg){
    name = arg.name;
    int i = (int)arg.stimList.size();
    for(int j = 0; j < i; j++){
      stimList.push_back(std::move(arg[j]));
    }
  }

  void Task::setName(std::string arg){
    name = arg;
  }

  void Task::operator+=(Stimulation* obj){
    stimList.push_back(obj);
  }

  Stimulation* Task::operator[](const int i){
    std::list<Stimulation*>::iterator j = stimList.begin();
    std::advance(j, i);
    return *j;
  }

  void Task::deletion(std::string arg){
    for(int i = 0; i < stimList.size(); i++){
      if((*this)[i]->getName() == arg){
        stimList.remove((*this)[i]);
      }
    }
  }

  void Task::dump(std::ostream& ostr){
    ostr << "TASK "<< name << std::endl;

    for(int i = 0; i < stimList.size(); i++){
      (*this)[i]->display(ostr);
    }
  }

  void Task::clearStims(){
    stimList.clear();
  }

  std::string Task::returnName(){
    return name;
  }

}
