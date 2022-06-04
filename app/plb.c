/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text.h"

static void plb_line(int index, char *contents, int cursor, void *data);

void plb(text txt)
{
    process_forward(txt, plb_line, NULL);
}

static void plb_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);
    
    if (cursor == -1){
        return;
    }

    for (int i = 0; i < cursor; i++){
        printf("%c", contents[i]);
    }
    printf("|");

    printf("\n");
}
