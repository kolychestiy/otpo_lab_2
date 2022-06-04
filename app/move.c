
#include "_text.h"

void move(text txt, int line, int row){
    if (1 > line){
        line = 1;
    }

    if (1 > row){
        row = 1;
    }

    node *cur_line = txt->begin;
    int i = 0;
    while (++i < line && cur_line != txt->end){
        cur_line = cur_line->next;
    }

    if (cur_line == NULL){
        printf("text is empty. you can't move\n");
        return;
    }

    txt->cursor->line = cur_line;
    txt->cursor->position = strlen(cur_line->contents);
    if (row - 1 < txt->cursor->position){
        txt->cursor->position = row - 1;
    }
}
