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

static void showclassified_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран, заменяя буквы звездочками
 */
void showclassified(text txt)
{
    process_forward(txt, showclassified_line, NULL);
}

static void showclassified_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);
    
    char *cur = contents;

    while(*cur){
    	if (!cursor--){
    		printf("|");
    	}

    	if ((*cur >= 'a' && *cur <= 'z') || (*cur >= 'A' && *cur <= 'Z')){
    		printf("*");
    	}else{
    		printf("%c", *cur);
    	}
    	cur++;
    }

    if (!cursor){
    	printf("|");
    }

    printf("\n");
}
