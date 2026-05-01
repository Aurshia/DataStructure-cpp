# DataStructure-cpp

A collection of fundamental **data structures and algorithms** implemented in C++, covering trees, heaps, hash tables, queues, linked lists, and sorting/searching algorithms.

---

## 📁 File Overview

| File | Topic | Key Concepts |
|---|---|---|
| `bst.cpp` | Binary Search Tree | Insert, search, delete, pre/in-order traversal, isBST, isAVL, findMin/Max |
| `preorder_bascis.cpp` | Binary Tree Basics | Pre/in/post-order traversal, depth, level, parent, sibling, node count, sum |
| `heap.cpp` | Min Heap | Insert, deleteMin, heapify, buildHeap |
| `maxHeap.cpp` | Max Heap | Insert, deleteMax, heapify, buildTree, isMaxHeap |
| `queues.cpp` | Queues | Array queue, circular array queue, linked list queue, circular linked list queue |
| `hash_tables.cpp` | Hash Tables | Basic hashing, linear probing, chaining (linked list), rehashing |
| `sorting.cpp` | Sorting & Searching | Selection sort, bubble sort, merge sort, linear search, binary search |
| `sll.cpp` | Singly Linked List | Node and SLL class definition |
| `practice.cpp` | Practice | Merge sort practice |

---

## 🌳 Binary Search Tree (`bst.cpp`)

A **BST** is a binary tree where every left child is smaller and every right child is larger than the parent.

**Operations implemented:**
- `insert(root, val)` – Inserts a value, ignoring duplicates
- `preorder(curr)` / `inorder(curr)` – Tree traversals
- `isBST(curr, min, max)` – Checks if a binary tree satisfies BST properties
- `isAVL(root)` – Checks if the BST is height-balanced (AVL)
- `search(curr, val)` – Searches for a value
- `delNode(root, key)` – Deletes a node (handles all three cases)
- `findMin(root)` / `findMax(root)` – Finds minimum/maximum values

---

## 🌲 Binary Tree Basics (`preorder_bascis.cpp`)

General binary tree utilities:

- **Traversals:** `preorder`, `inorder`, `postorder`
- `parent(curr, p, par)` – Finds the parent of a given node
- `sibling(curr, p)` – Finds the sibling of a given node
- `dept(curr)` – Returns the depth (height) of the tree
- `getlevel(curr, val, level)` – Returns the level of a given value
- `addAllNodes(curr)` – Returns the sum of all node values
- `count(curr)` – Counts total nodes
- `odd(curr)` / `even(curr)` – Prints odd/even nodes
- `sumOdd(root)` / `sumEven(root)` – Sums odd/even node values

---

## 🏔️ Min Heap (`heap.cpp`)

A **min heap** is a complete binary tree where every parent is smaller than its children.

**Operations implemented:**
- `insert(x)` – Inserts an element and restores heap property
- `deleteMin()` – Removes the minimum element (iterative approach)
- `deleteMinH()` – Removes the minimum using `heapify`
- `heapify(i)` – Restores heap property from index `i` downward
- `buildHeap()` – Builds a min heap from an unordered array in O(n)
- `print()` – Displays all heap elements

---

## 🏔️ Max Heap (`maxHeap.cpp`)

A **max heap** where every parent is larger than its children.

**Operations implemented:**
- `insert(x)` – Inserts an element maintaining max-heap order
- `deletemax()` – Removes the maximum element
- `heapify(i)` – Restores max-heap property from index `i`
- `buildtree()` – Builds a max heap from an array
- `isMaxHeap(h[], n)` – Checks if an array represents a valid max heap
- `print()` – Displays all heap elements

---

## 📬 Queues (`queues.cpp`)

Four queue implementations are provided:

### 1. Array-Based Queue
Standard FIFO queue using a fixed-size array.
- `enqueue(x)`, `dequeue()`, `display()`, `isEmpty()`, `isFull()`

### 2. Circular Array Queue
Avoids wasted space by wrapping indices around with modulo arithmetic.
- `enqueue(x)`, `dequeue()`, `peek()`, `display()`

### 3. Linked List Queue
Dynamic queue with no fixed size limit.
- `enqueue(x)`, `dequeue()`, `peek()`, `display()`

### 4. Circular Linked List Queue
Linked list where the last node points back to the front.
- `enqueue(x)`, `dequeue()`, `peek()`, `display()`

---

## #️⃣ Hash Tables (`hash_tables.cpp`)

Three hash table implementations demonstrating different collision-handling strategies:

### 1. Basic Hash Table (Open Addressing — no collision handling)
- `insert(key)`, `display()`
- Detects and reports collisions

### 2. Linear Probing
- On collision, scans forward for the next empty slot
- `insert(key)`, `search(key)`, `deleteKey(key)`, `display()`
- Uses `-2` as a tombstone for deleted entries

### 3. Chaining with Linked Lists
- Each table slot holds a linked list of colliding keys
- `insert(key)`, `search(key)`, `remove(key)`, `display()`

### 4. Linear Probing with Rehashing
- Automatically resizes (doubles) the table when load factor ≥ 0.7
- `insert(key)`, `rehash()`, `display()`

---

## 🔃 Sorting & Searching (`sorting.cpp`)

### Sorting Algorithms

| Algorithm | Time Complexity (avg) | Space | Stable |
|---|---|---|---|
| Selection Sort | O(n²) | O(1) | No |
| Bubble Sort | O(n²) | O(1) | Yes |
| Merge Sort | O(n log n) | O(n) | Yes |

**When to use which:**
- **Already/nearly sorted data** → Bubble Sort (optimized)
- **Minimum swaps needed** → Selection Sort
- **Stability required** → Bubble Sort
- **Large datasets** → Merge Sort

### Searching Algorithms

| Algorithm | Precondition | Time Complexity |
|---|---|---|
| Linear Search | Unsorted array | O(n) |
| Binary Search | Sorted array | O(log n) |

---

## 🔗 Singly Linked List (`sll.cpp`)

Defines the foundational `node` and `sll` classes for a singly linked list with `head` and `tail` pointers.

---

## 🛠️ How to Compile & Run

Make sure you have `g++` installed, then compile any file:

```bash
g++ bst.cpp -o bst && ./bst
g++ heap.cpp -o heap && ./heap
g++ maxHeap.cpp -o maxHeap && ./maxHeap
g++ queues.cpp -o queues && ./queues
g++ sorting.cpp -o sorting && ./sorting
g++ preorder_bascis.cpp -o preorder_bascis && ./preorder_bascis
```

---

## 📚 Topics Covered

- [x] Binary Search Trees (BST)
- [x] AVL Tree validation
- [x] Binary Tree traversals & utilities
- [x] Min Heap & Max Heap
- [x] Hash Tables (open addressing, chaining, rehashing)
- [x] Queues (array, circular, linked list)
- [x] Singly Linked List
- [x] Sorting (Selection, Bubble, Merge)
- [x] Searching (Linear, Binary)
