#include "ARAIG_Sensors.h"

namespace finalProject{

  ARAIG_Sensors::ARAIG_Sensors(std::ifstream& aStim, std::ifstream& aTask){


    do{
      std::string temp;
      std::string identity;
      getline(aStim, temp, '\n');
      if(temp[temp.size() - 1] == '\r'){
        temp = temp.substr(0, temp.size() - 1);
      }

      std::istringstream item(temp);
      //finding what kind of stimulation it is
      getline(item, identity, ',');


      if(identity == "stim"){
        //temp varaibles for new stim oject
        std::string tempName;
        std::string tempM;
        float tempIntensity;
        unsigned int tempFrequency;
        float tempTime;

        getline(item, tempName, ',');
        getline(item, tempM, ',');

        muscleGroups tempMuscle;
        if(tempM == "abs"){
          tempMuscle = abs;
        }
        else if(tempM == "front"){
           tempMuscle = front;
        }
        else if(tempM == "back"){
          tempMuscle = back;
        }
        else{
          tempMuscle = traps;
        }

        item >> tempIntensity;
        item.ignore();
        item >> tempFrequency;
        item.ignore();
        item >> tempTime;
        item.ignore();

        Stims* tempStim = new Stims(tempName, tempMuscle, tempIntensity, tempFrequency, tempTime);
        if(aStim.good()){
          stimulationList.push_back(tempStim);
        }
      }
      else{
        std::string tempName;
        float tempIntensity;
        float tempTime;
        getline(item, tempName, ',');

        item >> tempIntensity;
        item.ignore();
        item >> tempTime;
        item.ignore();


        Exoskeleton* tempExo = new Exoskeleton(tempName, tempIntensity, tempTime);
        if(aStim.good()){
          stimulationList.push_back(tempExo);
        }
      }

    }while(aStim.good());


    //task stuff
    while(aTask.good()){

      Task* taskItem = new Task();

      std::string temp;

      getline(aTask, temp, '\n');
      if(temp[temp.size() - 1] == '\r'){
        temp = temp.substr(0, temp.size() - 1);
      }
      std::istringstream item(temp);

      std::string tempTASK;

      getline(item, tempTASK, ',');
      std::string tmpName;
      getline(item, tmpName, '\n');
      taskItem->setName(tmpName);

      do{
        if(aTask.peek() != 'T'){
          std::string tempString;
          getline(aTask, tempString, '\n');
          if(tempString[tempString.size() - 1] == '\r'){
            tempString = tempString.substr(0, tempString.size() - 1);
          }

          for(int i = 0; i < stimulationList.size(); i++){
            if(stimulationList[i]->getName().compare(tempString) == 0){
              *taskItem+= stimulationList[i];
            }
          }
        }

      }while(aTask.peek() != 'T' && aTask.peek() != EOF);
      if(aTask.good()){
        taskList.push_back(taskItem);
      }

    }

  }

  ARAIG_Sensors::~ARAIG_Sensors(){
    for(int i = 0; i < taskList.size(); i++){
      delete taskList[i];
    }
    for(int i = 0; i < stimulationList.size(); i++){
      delete stimulationList[i];
    }

  }

  void ARAIG_Sensors::dump(std::ostream& ostr){
    for(int i = 0; i < stimulationList.size(); i++){
    	//displays the stimulations in the list
      stimulationList[i]->display(ostr);
    }
  }

  Task* ARAIG_Sensors::getTask(std::string taskName){
    for(int i = 0; i < taskList.size(); i++){
    	//finds task with matching name then returns it
      if(taskList[i]->returnName() == taskName){
        return taskList[i];
      }
    }

  }
}
