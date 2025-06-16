#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std; 

class Sale {
public:
	
    char name[50];
    int price;
    
    int quantity;

    Sale() {} // Default constructor

    Sale(char n[], int p, int q) {
        strcpy(name, n);
        price = p;
        quantity = q;
    }
};

class Inventory {
protected:
    static const int MAX_ITEMS = 100; // Maximum number of items
    Sale items[MAX_ITEMS];
    int itemCount;

public:
    Inventory() {
        itemCount = 0; // Initialize itemCount in the constructor
    }

    void addItem() {
        if (itemCount >= MAX_ITEMS) {
            cout << "Inventory is full." << endl;
            return;
        }

        char name[50];
        int price, quantity;

        cout << "Name: ";
        cin >> name;
        cout << "Price: ";
        cin >> price;
        cout << "Quantity: ";
        cin >> quantity;

        items[itemCount++] = Sale(name, price, quantity);
        cout << "Saved successfully." << endl;
    }

    void searchItem() {
        char name[50];
        cout << "Enter name to search: ";
        cin >> name;

        for (int i = 0; i < itemCount; ++i) {
            if (strcmp(name, items[i].name) == 0) {
                cout << "Name: " << items[i].name << endl;
                cout << "Price: " << items[i].price << endl;
                cout << "Quantity: " << items[i].quantity << endl << endl;
            }
        }
    }

    void sellItem() {
        char name[50];
        cout << "Enter name of sold item: ";
        cin >> name;

        for (int i = 0; i < itemCount; ++i) {
            if (strcmp(name, items[i].name) == 0) {
                int soldQuantity;
                cout << "Enter sold quantity: ";
                cin >> soldQuantity;
                items[i].quantity -= soldQuantity;
                cout << "Remaining quantity of " << items[i].name << " is: " << items[i].quantity << endl;
            }
        }
    }

    void showAllItems() {
        for (int i = 0; i < itemCount; ++i) {
            cout << "Name: " << items[i].name << endl;
            cout << "Price: " << items[i].price << endl;
            cout << "Quantity: " << items[i].quantity << endl << endl;
        }
    }
};

int main() {
	
    Inventory inventory;
    while (1) {
        int choice;
        cout << "1. Add item" << endl;
        cout << "2. Search item" << endl;
        cout << "3. Sell item" << endl;
        cout << "4. Show all items" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inventory.addItem();
                break;
            case 2:
                inventory.searchItem();
                break;
            case 3:
                inventory.sellItem();
                break;
            case 4:
                inventory.showAllItems();
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid input" << endl << endl;
                break;
        }
    }
    
    
    return 0;
}
