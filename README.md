# Homework
## by: Zakirov Daniel (IU8-23)

### Part I

1. Создайте пустой репозиторий на сервисе github.com (или gitlab.com, или bitbucket.com).
> Created an empty repository on github.com with MIT license
2. Выполните инструкцию по созданию первого коммита на странице репозитория, созданного на предыдещем шаге.
<details><summary>actions</summary>

```bash
$ git init
Initialized empty Git repository in /home/dp/Documents/sem02_TP/lab02/.git/
$ git branch -m main
$ git remote add https://github.com/Dan41kPlay/lab02.git
$ git pull https://github.com/Dan41kPlay/lab02.git main
From https://github.com/Dan41kPlay/lab02
 * branch            main       -> FETCH_HEAD
$ git add README.md
$ git commit -m "add readme file"
[main a193c8a] add readme file
 1 file changed, 43 insertions(+)
 create mode 100644 README.md
$ git push -u origin main
Enumerating objects: 4, done.
Counting objects: 100% (4/4), done.
Delta compression using up to 4 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 1.78 KiB | 1.78 MiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To https://github.com/Dan41kPlay/lab02.git
   941c4d3..a193c8a  main -> main
branch 'main' set up to track 'origin/main'.
```
</details>

3. Создайте файл `hello_world.cpp` в локальной копии репозитория (который должен был появиться на шаге 2). Реализуйте программу **Hello world** на языке C++ используя плохой стиль кода. Например, после заголовочных файлов вставьте строку `using namespace std;`.
```bash
$ nano hello_world.cpp
$ cat hello_world.cpp
#include <iostream>

using namespace std;

int main() {
    cout << "Hello world" << endl;
    return 0;
}
```

4. Добавьте этот файл в локальную копию репозитория.
```bash
$ git add hello_world.cpp
```

5. Закоммитьте изменения с *осмысленным* сообщением.
```bash
$ git commit -m "create hello_world program in c++ (needs refactoring)"
[main f93f8a5] create hello_world program in c++ (needs refactoring)
 1 file changed, 8 insertions(+)
 create mode 100644 hello_world.cpp
```

6. Изменитьте исходный код так, чтобы программа через стандартный поток ввода запрашивалось имя пользователя. А в стандартный поток вывода печаталось сообщение `Hello world from @name`, где `@name` имя пользователя.
```bash
$ nano hello_world.cpp
$ cat hello_world.cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello world from " << name << endl;
    return 0;
}
```

7. Закоммитьте новую версию программы. Почему не надо добавлять файл повторно `git add`?
```bash
$ git commit -am "add name prompt to hello_world"
[main 16275df] add name prompt to hello_world
 1 file changed, 5 insertions(+), 1 deletion(-)
```

> no `git add` because -a flag includes every tracked changed file into the commit

8. Запуште изменения в удалёный репозиторий.
```bash
$ git push -u origin main
Enumerating objects: 14, done.
Counting objects: 100% (14/14), done.
Delta compression using up to 4 threads
Compressing objects: 100% (12/12), done.
Writing objects: 100% (12/12), 2.13 KiB | 1.07 MiB/s, done.
Total 12 (delta 4), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (4/4), completed with 1 local object.
To https://github.com/Dan41kPlay/lab02.git
   a193c8a..f677fbd  main -> main
branch 'main' set up to track 'origin/main'.
```

9. Проверьте, что история коммитов доступна в удалёный репозитории.
> Commit history is accessible

### Part II

**Note:** *Работать продолжайте с теми же репоззиториями, что и в первой части задания.*
1. В локальной копии репозитория создайте локальную ветку `patch1`.
2. Внесите изменения в ветке `patch1` по исправлению кода и избавления от `using namespace std;`.
3. **commit**, **push** локальную ветку в удалённый репозиторий.
4. Проверьте, что ветка `patch1` доступна в удалёный репозитории.
5. Создайте pull-request `patch1 -> master`.
6. В локальной копии в ветке `patch1` добавьте в исходный код комментарии.
7. **commit**, **push**.
8. Проверьте, что новые изменения есть в созданном на **шаге 5** pull-request
9. В удалённый репозитории выполните  слияние PR `patch1 -> master` и удалите ветку `patch1` в удаленном репозитории.
10. Локально выполните **pull**.
11. С помощью команды **git log** просмотрите историю в локальной версии ветки `master`.
12. Удалите локальную ветку `patch1`.

### Part III

**Note:** *Работать продолжайте с теми же репоззиториями, что и в первой части задания.*
1. Создайте новую локальную ветку `patch2`.
2. Измените *code style* с помощью утилиты [**clang-format**](http://clang.llvm.org/docs/ClangFormat.html). Например, используя опцию `-style=Mozilla`.
3. **commit**, **push**, создайте pull-request `patch2 -> master`.
4. В ветке **master** в удаленном репозитории измените комментарии, например, расставьте знаки препинания, переведите комментарии на другой язык.
5. Убедитесь, что в pull-request появились *конфликтны*.
6. Для этого локально выполните **pull** + **rebase** (точную последовательность команд, следует узнать самостоятельно). **Исправьте конфликты**.
7. Сделайте *force push* в ветку `patch2`
8. Убедитель, что в pull-request пропали конфликтны. 
9. Вмержите pull-request `patch2 -> master`.
