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