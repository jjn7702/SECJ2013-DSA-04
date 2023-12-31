#include <iostream>
#include <string>
using namespace std;

class Menu {
private:
    string foodId;
    string name;
    string category;
    double price;

public:
    Menu(string foodId, string name, string category, double price)
        : foodId(foodId), name(name), category(category), price(price) {}

    string getFoodId() { return foodId; }
    string getName() { return name; }
    string getCategory() { return category; }
    double getPrice() { return price; }
};

class Node {
public:
    Menu menu;
    Node* next;

    Node(Menu m) : menu(m), next(nullptr) {}
};

class List {
private:
    Node* head;

public:
    List() : head(nullptr) {}

    bool isEmpty() { return head == nullptr; }

    // Display list of menu
    void dispList() {
        Node* temp = head;

        while (temp) {
            cout << "Food ID: " << temp->menu.getFoodId() << ", Name: " << temp->menu.getName()
                 << ", Category: " << temp->menu.getCategory() << ", Price: " << temp->menu.getPrice() << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    // Insert at the first
    void insertFront(Menu arr) {
        Node* newHead = new Node(arr); // pass value into the first node
        if (!isEmpty())
            newHead->next = head;
        head = newHead;
    }

    // Insert at the end
    void insertEnd(Menu arr) {
        Node* temp = head;
        Node* newEnd = new Node(arr);
        if (head == nullptr)
            head = newEnd;
        else {
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newEnd;
        }
    }

    // Insert at the middle
    void insertMiddle(Menu newOne, string middle) {
        Node* newNode = new Node(newOne);
        Node* temp = head;
        int count = 1;

        while(temp->menu.getFoodId() != middle){
            temp = temp->next;
            count++;
        }

            newNode->next = temp->next;
            temp->next = newNode;
    }

    // Insert at the specified position
    void insertSpecified(Menu newOne, string specified) {
        Node* newNode = new Node(newOne);
        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->menu.getFoodId() != specified) {
            prev = temp;
            temp = temp->next;
        }

            newNode->next = temp->next;
            prev->next = newNode;
    }
};

int main() {
    List menuList;

    // Insert at the front
    menuList.insertFront(Menu("ID001", "Burger", "Fast Food", 5.99));
    menuList.dispList();

    menuList.insertFront(Menu("ID002", "Pizza", "Italian", 8.99));
    menuList.dispList();

    // Insert at the end
    menuList.insertEnd(Menu("ID003", "Pasta", "Italian", 6.99));
    menuList.dispList();

    menuList.insertEnd(Menu("ID004", "Salad", "Healthy", 4.99));
    menuList.dispList();

    // Insert at the middle
    menuList.insertMiddle(Menu("ID005", "Sandwich", "Fast Food", 7.99), "ID002");
    menuList.dispList();

    // Insert at the specified position
    menuList.insertSpecified(Menu("ID006", "Sushi", "Japanese", 12.99), "ID003");

    // Display the list
    menuList.dispList();

    return 0;
}

