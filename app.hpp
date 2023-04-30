#include "healthDataList.hpp"

class app
{
    public:
        void runApp();
        void load(std::ifstream *loadFile);

    private:

};

void app::runApp()
{
    
    healthDatall healthData;
    // create list to store file data in
    healthData.loadFromFile();
    int choice; 
    bool exit = false;
    while(exit == false)  
    {
        cout << "** Fitness Tracker **" << endl << "1.) Record Info\n" << "2.) View Complete Raw Health Data\n"  << "0.) Exit Program" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1: // Record Info
            {
            healthData.newnodeinsert();
            break;
            }
            case 2: // View Data
            {
            healthData.printList();
            break;
            }
            case 0: // ecit
            {
            exit = true;
            break;
            }
        }
    }
    healthData.exitwritetofile();
    
}

