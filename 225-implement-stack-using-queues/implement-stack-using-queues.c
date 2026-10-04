typedef struct {
    int q1[100];
    int front1;
    int rear1;
    int size1;
    
    int q2[100];
    int front2;
    int rear2;
    int size2;
} MyStack;


MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->front1 = 0; 
    obj->rear1 = 0; 
    obj->size1 = 0;
    
    obj->front2 = 0; 
    obj->rear2 = 0; 
    obj->size2 = 0;
    
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    // 1. Enqueue the new element to the empty temporary queue (q2)
    obj->q2[obj->rear2] = x;
    obj->rear2 = (obj->rear2 + 1) % 100;
    obj->size2++;

    // 2. Dequeue all elements from the main queue (q1) and enqueue them to q2
    while (obj->size1 > 0) {
        int temp = obj->q1[obj->front1];
        obj->front1 = (obj->front1 + 1) % 100;
        obj->size1--;

        obj->q2[obj->rear2] = temp;
        obj->rear2 = (obj->rear2 + 1) % 100;
        obj->size2++;
    }

    // 3. Move everything from q2 back into q1 so q1 remains the main storage
    while (obj->size2 > 0) {
        int temp = obj->q2[obj->front2];
        obj->front2 = (obj->front2 + 1) % 100;
        obj->size2--;

        obj->q1[obj->rear1] = temp;
        obj->rear1 = (obj->rear1 + 1) % 100;
        obj->size1++;
    }
}

int myStackPop(MyStack* obj) {
    int topElement = obj->q1[obj->front1];
    obj->front1 = (obj->front1 + 1) % 100;
    obj->size1--;
    return topElement;
}

int myStackTop(MyStack* obj) {
    return obj->q1[obj->front1];
}

bool myStackEmpty(MyStack* obj) {
    return obj->size1 == 0;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
 */