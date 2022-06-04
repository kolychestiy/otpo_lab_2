#include <stdio.h>
#include "common.h"
#include <assert.h>
#include "text.h"

static void save_line(int index, char *contents, int cursor, void *data);

/**
 * сохраняет содержимое в файл
 */
void save(text txt, char *filename)
{
    FILE *f;

    /* Открываем файл для записи, контролируя ошибки */
    if ((f = fopen(filename, "w")) == NULL) {
        printf("The file %s cannot be opened\n", filename);
        return;
    }

    process_forward(txt, save_line, (void *)f);

    fclose(f);
}

static void save_line(int index, char *contents, int cursor, void *data){
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);

    /* Выводим строку в файл */
    fprintf((FILE *)data, "%s\n", contents);
}
