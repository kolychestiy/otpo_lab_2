# Ошибка №1
- Описание: move ломается, если текст не задан
- Тест: move, empty_txt
- Входные данные: 1, 1
- Ожидаемый результат: изначально не задан
- Фактический результат: ошибка времени выполнения 
- Возможная причина: cur_line->contents, при cur_line == NULL
- Статус: исправлена. добавлена проверка на NULL, и соответствующее сообщение об ошибке

# Ошибка №2
- Описание: split ломается, если отсутсвует строка для разбиения
- Тест: split, no_cursor_line
- Входные данные: 
- Ожидаемый результат: изначально не задан
- Фактический результат: ошибка времени выполнения 
- Возможная причина: cur->next и подобное, при cur == NULL
- Статус: исправлена. добавлена проверка на NULL, и вывод сообщения об ошибке.