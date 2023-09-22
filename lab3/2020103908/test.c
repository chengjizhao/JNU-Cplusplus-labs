#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// 自定义的Vector容器结构
typedef struct {
    int capacity;
    int size;
    int* elements;
} Vector;

// 初始化Vector容器
void initVector(Vector* vector, int capacity) {
    vector->capacity = capacity;
    vector->size = 0;
    vector->elements = (int*)malloc(capacity * sizeof(int));
}

// 在Vector容器中进行元素的随机插入
void insertIntoVector(Vector* vector, int index, int element) {
    if (vector->size == vector->capacity) {
        printf("Vector is full\n");
        return;
    }

    if (index < 0 || index > vector->size) {
        printf("Invalid index\n");
        return;
    }

    for (int i = vector->size; i > index; --i) {
        vector->elements[i] = vector->elements[i - 1];
    }

    vector->elements[index] = element;
    vector->size++;
}

// 自定义的List容器结构
typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

typedef struct {
    ListNode* head;
    int size;
} List;

// 初始化List容器
void initList(List* list) {
    list->head = NULL;
    list->size = 0;
}

// 在List容器中进行元素的随机插入
void insertIntoList(List* list, int index, int element) {
    if (index < 0 || index > list->size) {
        printf("Invalid index\n");
        return;
    }

    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = element;

    if (index == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        ListNode* current = list->head;
        int i = 0;

        while (current != NULL && i < index - 1) {
            current = current->next;
            i++;
        }

        if (current != NULL) {
            newNode->next = current->next;
            current->next = newNode;
        } else {
            printf("Invalid index\n");
            free(newNode);
            return;
        }
    }

    list->size++;
}

int main() {
    const int num_elements = 10000;  // 要插入的元素数量

    Vector vector;
    List list;

    // 初始化Vector容器
    initVector(&vector, num_elements);

    // 获取开始时间点
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // 在Vector容器中进行元素的随机插入
    for (int i = 0; i < num_elements; ++i) {
        int index = rand() % (vector.size + 1);
        int element = rand() % 10000;
        insertIntoVector(&vector, index, element);
    }

    // 获取结束时间点
    gettimeofday(&end, NULL);

    // 计算插入操作的时间
    int timeuse = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("Vector 插入时间: %d 微秒\n", timeuse);

    // 初始化List容器
    initList(&list);

    // 获取开始时间点
    gettimeofday(&start, NULL);

    // 在List容器中进行元素的随机插入
    for (int i = 0; i < num_elements; ++i) {
        int index = rand() % (list.size + 1);
        int element = rand() % 10000;
        insertIntoList(&list, index, element);
    }

    // 获取结束时间点
    gettimeofday(&end, NULL);

    // 计算插入操作的时间
    timeuse = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("List 插入时间: %d 微秒\n", timeuse);

    return 0;
}
