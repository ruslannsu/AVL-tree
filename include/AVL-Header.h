#pragma once
#include <stdbool.h>

typedef int Data;

typedef struct Node
{
    char height;
    Data data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct MemoryBuffer
{
    int n;
    int counter;
    void *memory;
} MemoryBuffer;

MemoryBuffer AllocateMemory(int n, int node_size);

Node *TreeAdd(Node *tree, Data data, MemoryBuffer *t_pointer);

char Height(Node *node);

bool IsTreeEmpty(int n);
