#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t sz;

public:
    // Constructor
    LinkedList() : head(nullptr), tail(nullptr), sz(0) {}

    // Destructor
    ~LinkedList() {
        clear();
    }

    // Disable copy (important for now)
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    // Basic utilities
    bool isEmpty() const {
        return sz == 0;
    }

    size_t size() const {
        return sz;
    }

    void clear() {
        Node* curr = head;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = tail = nullptr;
        sz = 0;
    }

    // Insert at front
    void insertFront(const T& val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;

        if (!tail) tail = node;
        sz++;
    }

    // Insert at back (O(1))
    void insertBack(const T& val) {
        Node* node = new Node(val);

        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        sz++;
    }

    // Insert at position (0-based)
    void insertAt(size_t pos, const T& val) {
        if (pos > sz) throw out_of_range("Invalid position");

        if (pos == 0) {
            insertFront(val);
            return;
        }

        if (pos == sz) {
            insertBack(val);
            return;
        }

        Node* curr = head;
        for (size_t i = 0; i < pos - 1; i++) {
            curr = curr->next;
        }

        Node* node = new Node(val);
        node->next = curr->next;
        curr->next = node;
        sz++;
    }

    // Delete first occurrence
    void deleteValue(const T& val) {
        if (!head) return;

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            sz--;

            if (!head) tail = nullptr;
            return;
        }

        Node* curr = head;
        while (curr->next) {
            if (curr->next->data == val) {
                Node* temp = curr->next;
                curr->next = temp->next;

                if (temp == tail) tail = curr;

                delete temp;
                sz--;
                return;
            }
            curr = curr->next;
        }
    }

    // Search
    bool contains(const T& val) const {
        Node* curr = head;
        while (curr) {
            if (curr->data == val) return true;
            curr = curr->next;
        }
        return false;
    }

    // Reverse
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        tail = head;

        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    // Print
    void print() const {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
};