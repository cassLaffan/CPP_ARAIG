#include "Stimulation.h"
#include "Profile.h"
#include "Stims.h"
#include "Exoskeleton.h"
#include "Task.h"
#include "ARAIG_Sensors.h"

using namespace finalProject;

int main(int argc, char *argv[]){
  //check for correct amount of arguments
  if(argc != 5){
    throw "Insufficient number of arguments.";
  }

  else{
    //assume that the files are given in the correct order
    try{
      std::ifstream stimFile;
      stimFile.open(argv[2]);
      std::ifstream taskFile;
      taskFile.open(argv[3]);

    //creates ARAIG_Sensors object with the filenames
      ARAIG_Sensors araigObj(stimFile, taskFile);


      std::ofstream outputFile;
      outputFile.open(argv[4]);
      //check if the files are open
      if(!stimFile.is_open() || !taskFile.is_open() || !outputFile.is_open()){
        throw "Unable to open one or more files";
      }
      //creates a Profile object using the ARAIG_sensors object, ostream object and file name
      Profile profileObj(argv[1], outputFile, araigObj);

      //runs the program until the user wants to exit
      std::string userInput;

      std::cout << "To run the tasks in the profile, press any key. To end and get out of here, type 'Exit'" << std::endl;


      while(userInput != "Exit" && userInput != "exit"){
        profileObj.run();
        std::cout << "To run the tasks in the profile, press any key. To end and get out of here, type 'Exit'" << std::endl;
        std::cin >> userInput;
    }
    //the way I interpreted run vs. save as is that run gets the user to run what they wanted to
    //then once the user has run everything, save what has been run vs what needs to be run still to a file

      profileObj.saveAs();

      outputFile.close();
  }catch(const char* msg){std::cout << msg << std::endl;}

  }
  return 0;
}
