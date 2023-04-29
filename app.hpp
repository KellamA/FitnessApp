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
        cout << "** Fitness Tracker **" << endl << "1.) Record Info\n" << "2.) View Complete Raw Health Data\n" << endl;
        cin >> choice;
        switch(choice)
        {
            case 1:
            {

            }
            case 2:
            {
            healthData.printList();
            }
            case 0:
            {
            exit = true;
            }
        }
    }
}

