#include "dataStorage.hpp"


class healthDatall
{
    public:
    healthDatall()
    {
        this->pHead = nullptr;
        this->pTail = nullptr;
    }
    ~healthDatall()
    {
        dataNode* pCur = this->pHead;
        dataNode* deleteNode = nullptr;

        while(pCur != nullptr) // traverses through and deletes nodes
        {
            deleteNode = pCur;
            pCur = pCur->getNext();
            deleteNode->~dataNode();
        }

    }
    void loadFromFile();

    void insert(dataNode* newNode);
    
    void printList();

    void newnodeinsert();

    void exitwritetofile();
    
    void editNode(dataNode* editNode);

    private:

    dataNode* pHead;
    dataNode* pTail;
};

void healthDatall::loadFromFile()
{
    std::ifstream infile("fitnessData.txt");
    std::string line;
    while(getline(infile, line)) // read in each line from txt file and store in string
    {
        std::string date;
        int weight, benchPressMax, ProteinIntake;
        char linecpy[100];
        strcpy(linecpy, line.c_str()); // copy string to cstring
        date = strtok(linecpy, ",");
        weight = atoi((strtok(NULL, ",")));
        benchPressMax = atoi(strtok(NULL, ","));
        ProteinIntake = atoi(strtok(NULL, ","));
        dataNode* newNode = new dataNode(date, weight, benchPressMax, ProteinIntake); // create new node containing data from one day
        this->insert(newNode);
    }
    infile.close();
}

void healthDatall::insert(dataNode* newNode)
{
    if (this->pHead == nullptr && this->pTail == nullptr)
    {
        this->pHead = newNode;
        this->pTail = newNode;
    }
    else
    {
        dataNode* pCur = this->pHead;
        while(pCur->getNext() != nullptr)
        {
            pCur = pCur->getNext();
        }
        pCur->setNext(newNode);
        this->pTail = newNode;
        newNode->setPrev(pCur);
    }
}

void healthDatall::printList()
{
    dataNode* pCur = this->pHead;
    while(pCur != nullptr)
    {
        cout << "Date: " << pCur->getdate() << ", Weight (lbs): " << pCur->getweight() << ", PenchPressMax (lbs): " << pCur->getBPM() << ", Protein Intake (g): " << pCur->getprotein() << endl;
        pCur = pCur->getNext();
    }
}

void healthDatall::newnodeinsert()
{
    std::string date;
    int weight = 0, BPM = 0, Protein = 0; // initialize Variables
    auto now = std::chrono::system_clock::now(); 
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    date = std::ctime(&now_time_t); // get date
    date.erase(date.size()-1, 1);
    date.erase(date.size()-13, 9); // format date and get rid of unnecesary data
    if (this->pTail->getdate() == date) // checks if data has already been entered for certain day
    {
        int choice;
        cout << "Data already recorded for today, would you like it edit? (Y = 1/N = 2): "; // prompt user for choice 
        cin >> choice; // read in choice
        if(choice == 1)
        {
            this->editNode(this->pTail);
            return;
        }
        return; // if user doesn't say yes
    }
     cout << "Enter weight in lbs: ";
    cin >> weight;
    cout << "\nEnter bench press max: ";
    cin >> BPM;
    cout << "Enter grams of protein consumed today: ";
    cin >> Protein;
    dataNode* newNode = new dataNode(date, weight, BPM, Protein);
    this->insert(newNode);
}

void healthDatall::exitwritetofile()
{
    std::ofstream outfile("fitnessData.txt");
    dataNode* pCur = this->pHead;
    while (pCur != nullptr)
    {
        if(this->pHead != pCur)
        {
            outfile << endl;
        }
        outfile << pCur->getdate() << "," << pCur->getweight() << "," << pCur->getBPM() << "," << pCur->getprotein();
        pCur = pCur->getNext();
    }  
    outfile.close();
}

void healthDatall::editNode(dataNode* editNode)
{
    int choice;
    int integer = 0;
    cout  << "Would you like to enter new weight? (Y = 1/N = 2): ";
    cin >> choice;
    if (choice == 1)
    {
        cout << "Enter new weight in lbs: ";
        cin >> integer;
        editNode->setWeight(integer);
    }
    cout  << "Would you like to enter new bench press max? (Y = 1/N = 2): ";
    cin >> choice;
    if (choice == 1)
    {
        cout << "Enter new Bench Press Max in lbs: ";
        cin >> integer;
        editNode->setBPM(integer);
    }
    cout  << "Would you like to enter new protein intake? (Y = 1/N = 2): ";
    cin >> choice;
    if (choice == 1)
    {
        cout << "Enter new weight in lbs: ";
        cin >> integer;
        editNode->setProtein(integer);
    }
}