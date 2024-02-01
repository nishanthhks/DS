#include <stdlib.h>
typedef struct {
    int* stack;
    int top;
    int min;
    int size;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->stack = (int*)malloc(sizeof(int) * 10); // initial size of 10
    obj->top = -1;
    obj->min = INT_MAX;
    obj->size = 10;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    if (obj->top == obj->size - 1) {
        obj->size *= 2;
        obj->stack = (int*)realloc(obj->stack, sizeof(int) * obj->size);
    }
    obj->stack[++obj->top] = val;
    obj->min = val < obj->min ? val : obj->min;
}

void minStackPop(MinStack* obj) {
    if (obj->top == -1)
        return;
    if (obj->stack[obj->top--] == obj->min) {
        int min = INT_MAX;
        for (int i = 0; i <= obj->top; i++) {
            min = obj->stack[i] < min ? obj->stack[i] : min;
        }
        obj->min = min;
    }
}

int minStackTop(MinStack* obj) {
    if (obj->top == -1)
        return -1;
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) { return obj->min; }

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj);
}