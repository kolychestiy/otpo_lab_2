#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text.h"
#include "_text.h"

void split(text txt)
{
    node *cur = txt->begin;
    while(cur != NULL && cur != txt->cursor->line){
        cur = cur->next;
    }

    if (cur == NULL){
        printf("cursor no set\n");
        return;
    }

    if (cur != txt->cursor->line){
        return;
    }

    node *nd;
    if ((nd = (node *) malloc(sizeof(node))) == NULL) {
        fprintf(stderr, "Not enough memory!\n");
        exit(EXIT_FAILURE);
    }

    nd->next = cur->next;
    nd->previous = cur;
    cur->next = nd;

    strncpy(nd->contents, (cur->contents + txt->cursor->position), MAXLINE);

// делать в конце, так как иначе не сможем скопировать корректно
    cur->contents[txt->cursor->position] = 0;
}
