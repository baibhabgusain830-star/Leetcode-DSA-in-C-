// Define a separate Node structure for the linked list.
// Must be defined BEFORE MyLinkedList so the compiler knows what a Node is.
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Define the main MyLinkedList structure.
// Keeping track of 'size' makes out-of-bounds checking O(1) time.
typedef struct {
    Node* head;
    int size;
} MyLinkedList;

// Initializes the MyLinkedList object.
MyLinkedList* myLinkedListCreate() {
    // Allocate memory for the list manager
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

// Get the value of the index-th node in the linked list. 
// If the index is invalid, return -1.
int myLinkedListGet(MyLinkedList* obj, int index) {
    // O(1) bounds check using our size variable
    if (index < 0 || index >= obj->size) {
        return -1;
    }
    
    Node* curr = obj->head;
    // Traverse the list until we reach the desired index
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    
    return curr->val;
}

// Add a node of value val before the first element of the linked list.
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    
    // Point the new node to the current head, then update head pointer
    newNode->next = obj->head;
    obj->head = newNode;
    obj->size++; 
}

// Append a node of value val as the last element of the linked list.
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    
    // If the list is empty, adding to the tail is the same as adding to the head
    if (obj->size == 0) {
        obj->head = newNode;
    } else {
        // Traverse to the very last node
        Node* curr = obj->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        // Link the last node to the new node
        curr->next = newNode;
    }
    obj->size++;
}

// Add a node of value val before the index-th node in the linked list.
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    // If index is greater than the length, the node will not be inserted
    if (index > obj->size) {
        return;
    }
    
    // If index is 0 or negative, insert at the head
    if (index <= 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    
    // If index equals the length, append at the tail
    if (index == obj->size) {
        myLinkedListAddAtTail(obj, val);
        return;
    }
    
    // General case: Inserting somewhere in the middle
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    
    Node* curr = obj->head;
    // Traverse to the node just *before* the insertion point (index - 1)
    for (int i = 0; i < index - 1; i++) {
        curr = curr->next;
    }
    
    // Wire the new node into the list
    newNode->next = curr->next;
    curr->next = newNode;
    obj->size++;
}

// Delete the index-th node in the linked list, if the index is valid.
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    // Validate the index
    if (index < 0 || index >= obj->size) {
        return;
    }
    
    Node* temp = obj->head;
    
    // Edge case: Deleting the very first node (head)
    if (index == 0) {
        obj->head = temp->next; // Move head pointer to the second node
        free(temp);             // Free the old head
    } else {
        // General case: Traverse to the node just *before* the one to delete
        Node* curr = obj->head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        
        // Store the node to be deleted in a temp variable
        temp = curr->next;
        // Bypass the deleted node
        curr->next = temp->next;
        
        // Free the memory to prevent memory leaks
        free(temp);
    }
    
    obj->size--; // Decrement the size tracker
}

// Free up all allocated memory for the list and its nodes.
void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    
    // Iterate through and free every node
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    
    // Finally, free the main list manager object
    free(obj);
}
