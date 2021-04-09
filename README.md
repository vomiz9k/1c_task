# 1c_task
Вступительное задание на кафедру 1С

## Алгоритм решения:
В основе алгоритма лежит то, что потенциальное количество возможных ключей не очень большое, что позволяет на этапе обработки входного файла получить все встречающиеся в файле ключи записать их в подходящую структуру данных(о том, какая подходящая - см. ниже), а после обрабатывать запросы за достаточно быстрое время.

Более детально: считываем со входного файла по 5 слов (или менее, если файл подходит к концу или заведомо меньше), генерируем из них ключ, который затем помещаем в бор, записывая в каждой вершине бора позицию слова, где начинается данный ключ. Далее, при каждом запросе, просто смотрим, есть ли в боре нужное слово, и если есть - то выводим позицию слова.

Здесь возможен другой вариант: бор можно заменить на хеш-таблицу, см. реализацию в ветке hash-table.

Так же имеется два варианта того, как считывать файл: по слову или целиком. Одно будет эффективнее по времени, другое - по памяти, поэтому в различных случаях можно считывать файл по-разному. См. ветку full-file.


## Сборка
```bash
cmake ./ && make
```

## Запуск
```bash
decoder <filename>
```