typedef struct {
    int queue[100];
    int front;
    int rear;
    int size;
} MyStack;


MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->front = 0;
    obj->rear = 0;
    obj->size = 0;
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    // Enqueue the new element to the back
    obj->queue[obj->rear] = x;
    obj->rear = (obj->rear + 1) % 100;
    obj->size++;

    // Rotate the queue to bring the newly added element to the front
    for (int i = 0; i < obj->size - 1; i++) {
        // Dequeue from front
        int temp = obj->queue[obj->front];
        obj->front = (obj->front + 1) % 100;
        
        // Enqueue to the back
        obj->queue[obj->rear] = temp;
        obj->rear = (obj->rear + 1) % 100;
    }
}

int myStackPop(MyStack* obj) {
    int topElement = obj->queue[obj->front];
    obj->front = (obj->front + 1) % 100;
    obj->size--;
    return topElement;
}

int myStackTop(MyStack* obj) {
    return obj->queue[obj->front];
}

bool myStackEmpty(MyStack* obj) {
    return obj->size == 0;
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