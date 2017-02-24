#include "Profile.h"

namespace finalProject{

  Profile::Profile(const char* fileName, std::ostream& ostr, ARAIG_Sensors& araigs):something(ostr){
    std::ifstream sample;
    sample.open(fileName);

    if(sample.is_open()){
      //getting student information
      getline(sample, stFirstName, ',');
      getline(sample, stLastName, ',');
      sample >> stNumber;
      sample.ignore();
      sample.ignore();

      //getting instructor information
      getline(sample, iFirstName, ',');
      getline(sample, iLastName, ',');
      sample >> iNumber;
      sample.ignore();
      sample.ignore();

      //min and max
      sample >> cali.maxIntensity;
      sample.ignore();
      sample >> cali.minIntensity;
      sample.ignore();
      sample.ignore();

      do{
        //get string for task name
        std::string tempTitle;
        getline(sample, tempTitle, '\n');
        if(tempTitle[tempTitle.size() - 1] == '\r'){
          tempTitle = tempTitle.substr(0, tempTitle.size() - 1);
        }
        //get task from ARAIG
        if(sample.good()){
          ToRun.push_back(araigs.getTask(tempTitle));
        }
        //push it into the ToRun vector
      }while(sample.good());


    }
  }

  void Profile::displayToRun(std::ostream& ostr){
    ostr << "Tasks to be run:" << std::endl;
    for(int i = 0; i < ToRun.size(); i++){
    	ToRun[i]->dump(ostr);
    }
  }

  void Profile::displayCompleted(std::ostream& ostr){
    ostr << "Completed tasks:" << std::endl;
    for(int i = 0; i < Completed.size(); i++){
      Completed[i]->dump(ostr);
    }
  }

  void Profile::displayNextTask(std::ostream& ostr){
    ToRun.front()->dump(ostr);
  }

  void Profile::displayLastTask(std::ostream& ostr){
    Completed.back()->dump(ostr);
  }

  void Profile::shrinkToRun(){
  	//take the ToRun vector and shrink it to its new size to avoid having a bigger vector than we need
  	//though this probably takes up more run time
  	//the range for this is ToRun[1] - ToRun.size, taking off the first item

  	std::vector<Task*> temp;
  	for(int i = 1; i < ToRun.size(); i++){
  		temp.push_back(ToRun[i]);
  	}
  	//reassign the ToRun vector to this new vector of ToRun.size() - 1
  	ToRun = temp;
  }

  void Profile::run(){
    int j = 0;
    std::cout << "To perform the next task, press any key. To stop, type 'Stop'." << std::endl;
    std::string userInput = " ";
    int k = (int)(ToRun.size());


    while(userInput != "Stop" && userInput != "stop" && j != k){
      //display current task and execute

      std::cout << "Run task: " << std::endl;
      displayNextTask(std::cout);
      //push the just completed task into the Completed vector
      //so for completion and thuroughness, I have the program output the next stimulation
      //so that they can see what they are doing next
      Completed.push_back(std::move(ToRun[0]));
      shrinkToRun();
      std::cout << "Press any key to continue, or type 'Stop' to stop." << std::endl;
      std::cin >> userInput;
      j++;
    }

    if(ToRun.size() == 0){
      std::cout << "There are no more tasks to run on this profile." << std::endl;
    }

  }

  void Profile::saveAs(){
    //saves the profile with the tasks that still need to be run to the ostrean object
    something << "Student: " << stFirstName << " " << stLastName << " - " << stNumber << std::endl;
    something << "Instructor: " << iFirstName << " " << iLastName << " - " << iNumber << std::endl;
    something << "Student calibration: " << std::endl;

    something << "MAX: " << cali.maxIntensity << std::endl;
    something << "MIN: " << cali.minIntensity << std::endl;

    displayToRun(something);
    displayCompleted(something);
  }
}
