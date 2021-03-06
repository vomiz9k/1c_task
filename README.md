# 1c_task
Вступительное задание на кафедру 1С

## Алгоритм решения:
В основе алгоритма лежит то, что потенциальное количество возможных ключей не очень большое, что позволяет на этапе обработки входного файла получить все встречающиеся в файле ключи записать их в подходящую структуру данных(о том, какая подходящая - см. ниже), а после обрабатывать запросы за достаточно быстрое время.

Более детально: на этапе обработки текста считываем со входного файла по 5 слов (или менее, если файл подходит к концу или заведомо меньше), генерируем из них ключ, который затем помещаем в бор, записывая в каждой вершине бора позицию слова, где начинается данный ключ. Далее, при каждом запросе, просто смотрим, есть ли в боре нужное слово, и если есть - то выводим позицию слова.



Так же имеется два варианта того, как считывать файл: по слову или целиком. Одно будет эффективнее по времени, другое - по памяти, поэтому в различных случаях можно считывать файл по-разному. См. ветку full-file.

## Фичи:
Ключ и текст, как и подобается любому паролю, устойчивы к регистру и состоят только из латинских символов.

## Сборка
```bash
cmake ./ && make
```

## Запуск
```bash
decoder <filename>
```

## Задача

В огромном тексте содержится тайный шифр. Чтобы его прочитать, необходимо взять слово-ключ (которое может быть самым разным, но не превышает по длине пяти букв) и найти последовательность из нескольких слов таких, что первая буква первого слова, вторая -- второго, третья -- третьего и так далее будут образовывать слово-ключ. Номер первого слова необходимо вывести. 

Реализуйте структуру, которая принимает текст, обрабатывает его, а потом эффективно отвечает на запросы, возвращая номер первого слова по ключу. Слова разделены пробелами и переводами строк, символы не учитываются. Если подходящих последовательностей несколько, выведите любой из ответов.

Например, текст -- это задание, ключ -- “чек”, ответ -- 31

Текст представляет из себя .txt - файл размером до 2ГБ, а запросы и ответы на них должны вводиться/выводиться в консоль.

