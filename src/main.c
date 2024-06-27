#include "AVL-Header.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1)
    {
        return 0;
    }
    if (IsTreeEmpty(n))
    {
        printf("0");
        return 0;
    }
    MemoryBuffer memory = AllocateMemory(n, sizeof(Node));
    Node *p = NULL;
    for (int i = 0; i != n; ++i) 
    {
        int input;
        if (scanf("%d", &input) != 1)
        {
            free(memory.memory);
            return 0;
        }
        p = TreeAdd(p, input, &memory);
    }
    printf("%d", Height(p));
    free(memory.memory);
    return 0;

}
