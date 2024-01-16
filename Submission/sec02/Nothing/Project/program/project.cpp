#include <iostream>
#include <fstream>

using namespace std;

class goods{
    private:
        int id;
        string name;
        int price;
        string itemLocation;
    
    public:
        goods(int id, string name, int price, string itemLocation){
            this->id = id;
            this->name = name;
            this->price = price;
            this->itemLocation = itemLocation;
        }

        int getId(){
            return id;
        }

        string getName(){
            return name;
        }

        int getPrice(){
            return price;
        }

        string getItemLocation(){
            return itemLocation;
        }
};

class itemNodeQueue{
    public:
        goods item;
        itemNodeQueue *next;
        itemNodeQueue *prev;
}

class itemQueue{
    public:
        itemNodeQueue *front;
        itemNodeQueue *rear;

        void createQueue(){
            front = NULL;
            rear = NULL;
            size = 0;
        }

        bool isEmpty(){
            if(front == NULL)
                return true;
            else
                return false;
        }
