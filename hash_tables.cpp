#include <iostream>
using namespace std;

const int SIZE = 25;
int hashtable[SIZE];

// Initialize table with -1
void initialize() {
    for(int i = 0; i < SIZE; i++)
        hashtable[i] = -1;
}

// Simple hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert value
void insert(int key) {
    int index = hashFunction(key);
    if(hashtable[index] == -1)
        hashtable[index] = key;
    else
        cout << "Collision at index " << index << " for key " << key << endl;
}

// Display table
void display() {
    for(int i = 0; i < SIZE; i++)
        cout << i << " -> " << hashtable[i] << endl;
}

int main() {
    initialize();
    insert(52);
    insert(129);
    insert(500);
    insert(273);
    insert(49);

    display();
    return 0;
}



//handling collision in linear probling


// Insert with Linear Probing
void insert(int key) {
    int index = hashFunction(key);
    int startIndex = index;
    while(hashtable[index] != -1) {
        index = (index + 1) % SIZE; // move to next slot
        if(index == startIndex) {
            cout << "Hash table full!" << endl;
            return;
        }
    }
    hashtable[index] = key;
}

// Search with Linear Probing
bool search(int key) {
    int index = hashFunction(key);
    int startIndex = index;
    while(hashtable[index] != -1) {
        if(hashtable[index] == key)
            return true;
        index = (index + 1) % SIZE;
        if(index == startIndex)
            break;
    }
    return false;
}

void deleteKey(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while (hashtable[index] != -1) {  // stop at empty slot
        if (hashtable[index] == key) {
            hashtable[index] = -2;    // mark as DELETED
            cout << "Key deleted\n";
            return;
        }

        index = (index + 1) % SIZE;

        if (index == startIndex) {
            break;  // full cycle done
        }
    }

    cout << "Key not found\n";
}


void display() {
    for(int i = 0; i < SIZE; i++)
        cout << i << " -> " << hashtable[i] << endl;
}

int main() {
    initialize();
    insert(52);
    insert(77);  // Collision with 52
    insert(129);
    insert(500);
    insert(273);
    insert(49);

    display();

    cout << "Search 77: " << (search(77) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (search(100) ? "Found" : "Not Found") << endl;

    return 0;
}



//by using linked list

#include <iostream>
using namespace std;

/* Node of linked list */
struct Node {
    int data;
    Node* next;
};

/* Hash Table Class */
class HashTable {
    int size;
    Node** table;   // array of pointers (each index of table considerd as the head of linked list)

public:
    // Constructor
    HashTable(int s) {
        size = s;
        table = new Node*[size];

        for (int i = 0; i < size; i++)
            table[i] = NULL;
    }

    // Hash function
    int hashFunction(int key) {
        return key % size;
    }

    // INSERT
    void insert(int key) {
        int index = hashFunction(key);

        Node* newNode = new Node;
        newNode->data = key;
        newNode->next = table[index];

        table[index] = newNode;
    }

    // SEARCH
    bool search(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];

        while (temp != NULL) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // DELETE
    void remove(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = NULL;

        while (temp != NULL) {
            if (temp->data == key) {
                if (prev == NULL) {
                    table[index] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Deleted: " << key << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Key not found\n";
    }

    // DISPLAY
    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " : ";
            Node* temp = table[i];
            while (temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};


//linear probbing + rehashing

#include <iostream>
using namespace std;

class HashTable {
    int* table;
    int size;
    int count;   // number of elements

public:
    HashTable(int s) {
        size = s;
        count = 0;
        table = new int[size];
        for(int i = 0; i < size; i++)
            table[i] = -1;   // -1 means empty
    }
    int hashFunction(int key) {
        return key % size;
    }
    void insert(int key) {
        // Check load factor
        float loadFactor = (float)count / size;

        if (loadFactor >= 0.7) {
            rehash();
        }

        int index = hashFunction(key);

        while (table[index] != -1) {
            index = (index + 1) % size;
        }

        table[index] = key;
        count++;
    }
    void rehash() {
        cout << "Rehashing...\n";

        int oldSize = size;
        int* oldTable = table;

        size = size * 2;            // increase size
        table = new int[size];
        count = 0;

        for(int i = 0; i < size; i++)
            table[i] = -1;

        for(int i = 0; i < oldSize; i++) {
            if (oldTable[i] != -1) {
                insert(oldTable[i]);   // reinsert
            }
        }

        delete[] oldTable;
    }
    void display() {
        for(int i = 0; i < size; i++) {
            cout << i << " : " << table[i] << endl;
        }
    }
};




int main() {
    HashTable ht(7); // Initial small table to demonstrate rehashing

    // Insert values
    ht.insert(13);
    ht.insert(15);
    ht.insert(24);
    ht.insert(6);
    ht.insert(23);  // Triggers rehash

    ht.display();

    cout << "Search 23: " << (ht.search(23) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (ht.search(100) ? "Found" : "Not Found") << endl;

    HashTable h(5);

    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);   // triggers rehashing
    h.insert(50);

    h.display();

    return 0;
}
