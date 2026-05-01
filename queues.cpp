#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int size;
    int front, rear;

public:
    Queue(int s) {
        size = s;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == size - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (isEmpty()) front = 0;
        arr[++rear] = x;
        cout << x << " inserted\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << arr[front] << " removed\n";
        if (front == rear)
            front = rear = -1;
        else
            front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue q(5);   // size given by user/programmer

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    return 0;
}
#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int size;
    int front, rear;

public:
    // Constructor
    CircularQueue(int s) {
        size = s;
        arr = new int[size];
        front = rear = -1;
    }

    // Check empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check full
    bool isFull() {
        return ((rear + 1) % size == front);
    }

    // Insert element
    void enqueue(int x) {
        if (isFull()) {
            cout << "Circular Queue Overflow\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = x;
        cout << x << " inserted\n";
    }

    // Delete element
    void dequeue() {
        if (isEmpty()) {
            cout << "Circular Queue Underflow\n";
            return;
        }

        cout << arr[front] << " removed\n";

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    // Peek front
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    // Display elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

    // Destructor
    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue cq(5);   // 👈 size decided here

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.display();

    cq.dequeue();
    cq.enqueue(50);
    cq.display();

    return 0;
}

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    // Check empty
    bool isEmpty() {
        return (front == NULL);
    }

    // Insert element
    void enqueue(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;

        if (isEmpty()) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        cout << x << " inserted\n";
    }

    // Delete element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        cout << front->data << " removed\n";

        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }

    // Peek front
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        } else {
            cout << "Front element: " << front->data << endl;
        }
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.peek();
    q.display();

    return 0;
}
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class CircularQueue {
    Node *front, *rear;

public:
    CircularQueue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    // Insert element
    void enqueue(int x) {
        Node* temp = new Node();
        temp->data = x;

        if (isEmpty()) {
            front = rear = temp;
            rear->next = front;   // circular link
        } else {
            rear->next = temp;
            rear = temp;
            rear->next = front;   // maintain circle
        }
        cout << x << " inserted\n";
    }

    // Delete element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        // Only one node
        if (front == rear) {
            cout << front->data << " removed\n";
            delete front;
            front = rear = NULL;
        } else {
            Node* temp = front;
            cout << front->data << " removed\n";
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    // Peek
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        } else {
            cout << "Front element: " << front->data << endl;
        }
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main() {
    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();

    cq.dequeue();
    cq.display();

    cq.enqueue(40);
    cq.display();

    return 0;
}
