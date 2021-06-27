//
//  linkedlist.h
//
//  This file consist of a doubly linked list that can store values of any type.
//  The nodes of the linked list can be deleted, traversed backwards, and
//  traversed forwards. The file also consist of methods that can return the
//  number of values in the linked list and the last value in the linked list.
//

#ifndef linkedlist_h
#define linkedlist_h
#include <iostream>
#include <cassert>
using namespace std;

template <typename T> // Initiate a template data type

// The linked list class contains the linked list, and the methods that will be
// used on the linked list.
class LinkedList
{
private:
    // Initiate the linked list
    struct Node
    {
        int data;
        Node* next;
        Node* prev;
    };

    Node *head; // Front of linked list
    Node *tail; // Back of linked list
    
    int size_t; // Total size of linked list
    T lastValue;   // Represents the last value in a linked list

    void traverse(Node* nodePtr, int count);  // Recursively traverses the List
    void addFront(const T data); // Adds node to the front of the linked list
    void addBefore(Node*, const T data); // Adds node before a node in a linked list
    void addEnd(const T data);  // Adds node to the end of a linked list
    bool isEmpty() const;  // Returns true if linked list is empty

public:
    // Constructor
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    
    // Destructor
    ~LinkedList()
    {
        Node *nodePtr;
        nodePtr = head;
        
        while (nodePtr != NULL)
        {
            // Garbage keeps track of node to be deleted
            Node *garbage = nodePtr;

            // Move on to the next node
            nodePtr = nodePtr -> next;
            
            //Free the garbage
            delete garbage;
        }
    }
    
    bool remove(const T data); // removes a value from the list
    void insert(const T data); // adds a value to the list
    bool contains(const T data) const; // test if value is in the list
    int length() const; // Returns the number of length elements
    void print_forwards () const; // prints the list from head to tail void
    void print_backwards() const; // prints the list from tail to head
    T getLast(); // find last element recursively
};

/*---------------------------------------------------------------------
                               isEmpty
This method returns true if the linked list is empty.
---------------------------------------------------------------------*/
template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return (head == NULL);
}

/*---------------------------------------------------------------------
                                addFront
 The value in this method is the value data of type T. It will be stored
 in an allocated node within the function. The method Alloctes a new
 node, assings the data parameter to the node, then adds the node to the
 from of the list
 ---------------------------------------------------------------------*/
template <typename T>
void LinkedList<T>::addFront(const T data)
{
    // Create a new node
    Node *newNode;
    newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    
    //If list is empty
    if(head == NULL)
    {
        tail = newNode;
        size_t = 0;
    } else
    {
        head->prev = newNode;
    }
    
    // Assign the head pointer to temp
    head = newNode;
    
    // Increase Linked list size
    size_t += 1;
}

/*---------------------------------------------------------------------
                               addBefore
 The method's parameters consist of the node in the linked list that will
 be after the new node being added, and the data that the allocated node
 will carry. The method adds a new node before a current node in the list
 that will be either higher, or equal to the value of the new node.
---------------------------------------------------------------------*/
template <typename T>
void LinkedList<T>::addBefore(Node *nodePtr, const T data)
{
    // Allocate new node
    Node *newNode;
    newNode = new Node();
    
    // Add the node before nodePtr
    newNode->data = data;
    newNode->prev = nodePtr->prev;
    newNode->next = nodePtr;
    nodePtr->prev->next = newNode;
    nodePtr->prev = newNode;
    
    //If node is to be inserted before first node
    if(nodePtr->prev == NULL)
    {
        head = newNode;
    }
    
    // Increase the size of the linked list
    size_t += 1;
}

/*---------------------------------------------------------------------
                               addEnd
 The addEnd method will take in a parameter of type T repreenting the
 value of the new node. The new node being allocated be added at the
 end of the linked list.
---------------------------------------------------------------------*/
template <typename T>
void LinkedList<T>::addEnd(const T data)
{
    // Allocate new node
    Node *temp;
    temp = new Node();
    
    // Add new node to the end of the linked list
    temp->data = data;
    temp->prev = tail;
    temp->next = NULL;
    
    // if list is empty
    if(head == NULL)
        head = temp;
    else
        tail->next = temp;
    
    tail = temp;
    
    // Increase the length of linked list
    size_t += 1;
}

/*---------------------------------------------------------------------
                               insert
 The main purpose of this method is to pass the value that the will
 represent the value of the new node being inserted. The method will then
 determine where the node will be inserted according to the size of the
 data type and weather or not the list is empty. The method will call
 addEnd if node is to be added to end, addBefore if node is to be added
 in the middle, or addFront if node is to be added in the front.
---------------------------------------------------------------------*/
template <typename T>
void LinkedList<T>::insert(const T data)
{
    // Create pointer
    Node *nodePtr;
    
    // if New node is to be added to front
    if(head == NULL || head->data >= data)
    {
        addFront(data);
    } else
    {
        // Assign pointer to head
        nodePtr = head;
        
        // Find the intersection point
        while (nodePtr != NULL && nodePtr->data < data)
        {
            nodePtr = nodePtr->next;
        }
        
        // If node is to be added at the end
        if(nodePtr == NULL)
        {
            addEnd(data);
        }
        // If node is to added in middle
        else
        {
            addBefore(nodePtr, data);
        }
            
    }
}

/*---------------------------------------------------------------------
                            print_forwrads
 This method traverses through the list in incrementing order while
 print the value that each list holds.
---------------------------------------------------------------------*/
template <typename T>
void LinkedList<T>::print_forwards() const
{
    // Return if list is empty
    if (size_t == 0)
        return;

    // Create a pointer to traverse the list starting at begening
    Node *nodePtr = head;
    
    // Print value while traversing
    while(nodePtr != NULL)
    {
        cout << " " << nodePtr->data;
        nodePtr = nodePtr->next;
    }
    cout << endl;
}

/*---------------------------------------------------------------------
                            print_backwards
 This method traverses through the list in decrementing order while
 print the value that each list holds.
---------------------------------------------------------------------*/
template <typename T>
void LinkedList<T>::print_backwards() const
{
    // Return if list is empty
    if (size_t == 0)
        return;
    
    // Create a node to traverse the list starting at end
    Node *nodePtr = tail;
    
    // // Print value while traversing
    while(nodePtr != NULL)
    {
        cout << " " << nodePtr->data;
        nodePtr = nodePtr->prev;
    }
    cout << endl;
}

/*---------------------------------------------------------------------
                               remove
 The remove method takes in the value of the node that needs to be
 deleted as a parameter, finds a node containing that value, then
 deletes the node with in the linked list. The method will return true
 if the node is found and will return false otherwise.
---------------------------------------------------------------------*/
template <typename T>
bool LinkedList<T>::remove(const T data)
{
    // Create pointer to head
    
    Node *nodePtr = head;
   
    
    //If list is empty
   if (head == NULL || nodePtr == NULL)
       return false;
    
    while (nodePtr != NULL)
    {
        
        if (nodePtr->data == data)
        {
            // If node to be deleted is the head node
            if (head == nodePtr)
                head = nodePtr->next;
            
            // If node is last node in the list
            if (tail == nodePtr)
                tail = nodePtr->prev;
            
            // Change next only if node to be
            // deleted is not last node.
            if (nodePtr->next != NULL)
                nodePtr->next->prev = nodePtr->prev;
            
            // Change prev only if node to be
            // deleted is not first node
            if (nodePtr->prev != NULL)
                nodePtr->prev->next = nodePtr->next;
            
            // Decrease the list size
            size_t -= 1;
            
            // Free memorey
            delete nodePtr;
            
            return true;
        }
        
        nodePtr = nodePtr->next;
    }
    return false;
}

/*---------------------------------------------------------------------
                               contains
 The method takes in a value that potentially resempble the value of a
 node within a linked list. The method will travers the node and if the
 node is found, the methos will return true, otherwise false.
---------------------------------------------------------------------*/
template <typename T>
bool LinkedList<T>::contains(const T data) const
{
    // Creaste a pointer to the head of the list
    Node *nodePtr = head;
    
    // Traverse the list till the data is found
    while (nodePtr->data != data)
    {
        nodePtr = nodePtr->next;
    }
    
    // If data is found, then return true, else return false
    if (nodePtr->data == data)
    {
        return true;
    } else
    {
        return false;
    }
}

/*---------------------------------------------------------------------
                               length
This function return the number of elements in the linked list.
---------------------------------------------------------------------*/
template <typename T>
int LinkedList<T>::length() const
{
    return size_t;
}

/*---------------------------------------------------------------------
                               getLast
 The function uses a recursion function to traverse the list. When the
 recursive function is at the end of the list, it will assign lastValue
 to the value of thhe last node in the list. The getLast method will
 then return lastValue.
---------------------------------------------------------------------*/
template <typename T>
T LinkedList<T>::getLast()
{
    // If the list is empty when getlast is called,
    // the program will terminate with a error code.
    assert(!isEmpty());
    
    // Create a variable that will increment through
    // the recursive fucntion.
    int count = 1;
    Node *nodePtr = head;

    // Call the recursive function to get the last value
    traverse(nodePtr, count);
    return lastValue;
}

/*---------------------------------------------------------------------
                               traverse
 The method is a recursive function meaning that the function will be
 called with in its self. Every time the function is called within its
 self, it pass the parameter fount count and the pointer to the linked
 list. The pointer being passes within the function will be pointing to
 the next node thus traversing the list. The count will be incremented
 then passed through untill its size is equal to the size of the linked
 list. after that, the private valriable, lastvalue will be assigned to
 the last value.
---------------------------------------------------------------------*/
template <typename T>
void LinkedList<T>::traverse(Node *nodePtr, int count)
{
    // If the pinter is pointing to the last node
    if (size_t == count)
    {
        lastValue = nodePtr->data;
    }
    
    // If the pointer is still not at end of list
    else
    {
        count++;
        traverse(nodePtr->next, count);
    }
}
    







#endif /* LinkedList_h */
