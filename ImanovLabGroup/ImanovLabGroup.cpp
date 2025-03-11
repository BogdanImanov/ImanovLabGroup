// ImanovLabGroup.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>  


using namespace std;


struct Node {

    double data;
    Node* prev;
    Node* next;
    Node(double value) : data(value), prev(nullptr), next(nullptr) {}
};
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    void append(double value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    double sumGreaterThanOrEqualTo15() {
        double sum = 0;
        Node* current = head;

        while (current) {
            if (current->data >= 15) {
                sum += current->data;
            }
            current = current->next;
        }
        return sum;
    }
    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};
int main() {
    setlocale(LC_ALL, "RUS");
    DoublyLinkedList list;
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        double num;
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> num;
        list.append(num);
    }
    double sum = list.sumGreaterThanOrEqualTo15();
    cout << fixed << setprecision(2);
    cout << "Сумма элементов со значениями >= 15: " << sum << endl;
    return 0;
}
