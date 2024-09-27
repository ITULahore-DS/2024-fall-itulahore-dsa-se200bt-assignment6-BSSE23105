#include <iostream>
#include "functions.h"
using namespace std;

int main() {
 Queue queueObj;
    Stack stackObj;
    int choice;
    int value;

    do {
        cout << "\t\t\t(Press 0 to exit)\nFrom The Given Menu \n1)Add element In Stack\n2)Add element In Queue\n3)Delete from Stack\n4)Delete from Queue\n5)Print Stack\n6)Print Queue\nChoose which task you want to perform: ";

        cin >> choice;

        switch (choice) {
            case 0: {
                break;
            }
            case 1: {
                cout << "Enter integer that you want to add in Stack: ";
                cin >> value;
                stackObj.push(value);
            }
                break;
            case 2: {
                cout << "Enter integer that you want to add in Queue: ";
                cin >> value;
                queueObj.enqueue(value);
                break;
            }
            case 3: {
                cout << "Deleting from Stack\n";
                stackObj.pop();
                break;
            }
            case 4: {
                cout << "Deleting from Queue\n";
                queueObj.dequeue();
                break;
            }
            case 5: {
                cout << "Printing Stack:\n";
                stackObj.printStack();
                break;
            }
            case 6: {
                cout << "Printing Queue:\n";
                queueObj.printQueue();
            }
            break;

            default:
                cout << "Invalid choice. Please choose again.\n";
        }
    } while (choice != 0);

    return 0;
}
