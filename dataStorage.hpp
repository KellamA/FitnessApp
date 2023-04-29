#include "header.hpp"

class dataNode
{
public:
    dataNode()
    {

    }
    // Constructor that accepts input parameters for initialization
    dataNode(std::string date, int weight, int bench_press_max, int protein_intake);

    ~dataNode()
    {
      
    }
    //setters
    void setNext(dataNode* nextNode)
    {
        this->pNext = nextNode;
    }
    void setPrev(dataNode* prevNode)
    {
        this->pPrev = prevNode;
    }
    //getters
    dataNode* getNext();
    dataNode* getPrev()
    {
        return this->pPrev;
    }

    int getweight()
    {
        return this->weight;
    }
    int getBPM()
    {
        return this->bench_press_max;
    }
    int getprotein()
    {
        return this->protein_intake;
    }
    std::string getdate()
    {
        return this->date;
    }

private:

    std::string date;
    int weight;
    int bench_press_max;
    int protein_intake;
    dataNode* pNext;
    dataNode* pPrev;

};

dataNode::dataNode(std::string date, int weight, int bench_press_max, int protein_intake)
{
    this->date = date;
    this->weight = weight;
    this->bench_press_max = bench_press_max;
    this->protein_intake = protein_intake;
    this->pNext = nullptr;
    this->pPrev = nullptr;
}

dataNode* dataNode::getNext()
{
    return this->pNext;
}