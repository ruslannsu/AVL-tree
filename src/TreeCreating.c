#include "AVL-Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

char Height(Node *node)
{
    if (node != NULL)
    {
        return node->height;
    } 
    else
    {
        return 0;
    }
}

static Node *GetMemory(MemoryBuffer *t_pointer)
{
    Node *node;
    if (t_pointer->counter == t_pointer->n)
    {
        return NULL;
    }
    node = (Node*)(t_pointer->counter * sizeof(Node) + (char*)t_pointer->memory);
    (t_pointer->counter)++;
    return node;
}

static int BalanceFactor(Node *node)
{
    return Height(node->right) - Height(node->left);
}

static void FixHeight(Node *node)
{
    char leftHeight = Height(node->left);
    char rightHeight = Height(node->right);
    if (leftHeight > rightHeight)
    {
        node->height = leftHeight + 1;
    } 
    else
    {
        node->height = rightHeight + 1;
    }
}

static Node *RotateRight(Node *node)
{
    Node *q = node->left;
    node->left = q->right;
    q->right = node;
    FixHeight(node);
    FixHeight(q);
    return q;
}

static Node *RotateLeft(Node *node)
{
    Node *q = node->right;
    node->right = q->left;
    q->left = node;
    FixHeight(node);
    FixHeight(q);
    return q;
}

static Node *TreeBalance(Node *node)
{
    FixHeight(node);
    if (BalanceFactor(node) == 2) 
    {
        if (BalanceFactor(node->right) < 0)
        {
            node->right = RotateRight(node->right);
        }
        return RotateLeft(node);
    }
    if (BalanceFactor(node) == -2)
    {
        if (BalanceFactor(node->left) > 0)
        {
            node->left = RotateLeft(node->left);
        }
        return RotateRight(node);
    }
    return node;
}

Node *TreeAdd (Node *tree, Data data, MemoryBuffer *t_pointer)
{
    if (tree == NULL)
    {
        Node *t;
        t = GetMemory(t_pointer);
        t->data = data;
        t->height = 1;
        t->left = t->right = NULL;
        return t;
    }
    if (data < tree->data)
    {
        tree->left = TreeAdd(tree->left, data, t_pointer);
    }
    else
    {
        tree->right = TreeAdd(tree->right, data, t_pointer);
    }
    return TreeBalance(tree);
}


MemoryBuffer AllocateMemory(int n, int node_size)
{
    MemoryBuffer t;
    t.n = n;
    t.counter = 0;
    t.memory = malloc(n * node_size);
    assert(t.memory != NULL);
    return t;
}

bool IsTreeEmpty(int n)
{
    return n == 0;
}

