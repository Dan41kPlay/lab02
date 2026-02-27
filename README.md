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
<details><summary>actions</summary>

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
</details>

9. Проверьте, что история коммитов доступна в удалёный репозитории.
> Commit history is accessible

### Part II

**Note:** *Работать продолжайте с теми же репоззиториями, что и в первой части задания.*
1. В локальной копии репозитория создайте локальную ветку `patch1`.
```bash
$ git checkout -b patch1
```

2. Внесите изменения в ветке `patch1` по исправлению кода и избавления от `using namespace std;`.
```bash
$ nano hello_world.cpp
$ cat hello_world.cpp
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}
```

3. **commit**, **push** локальную ветку в удалённый репозиторий.
<details><summary>actions</summary>

```bash
$ git commit -am "refactoring: remove 'using namespace std;' from hello_world"
[patch1 da5b20b] refactoring: remove 'using namespace std;' from hello_world
 1 file changed, 4 insertions(+), 6 deletions(-)
$ git push origin patch1
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 4 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 416 bytes | 416.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
remote: 
remote: Create a pull request for 'patch1' on GitHub by visiting:
remote:      https://github.com/Dan41kPlay/lab02/pull/new/patch1
remote: 
To https://github.com/Dan41kPlay/lab02.git
 * [new branch]      patch1 -> patch1
```
</details>

4. Проверьте, что ветка `patch1` доступна в удалёный репозитории.
> Branch `patch1` is accessible

5. Создайте pull-request `patch1 -> master`.
> Created a PR via github.com

6. В локальной копии в ветке `patch1` добавьте в исходный код комментарии.
```bash
$ nano hello_world.cpp
$ cat hello_world.cpp
#include <iostream>
#include <string>

int main() {
    std::string name; // name of the user will be stored here
    std::cout << "Enter your name: "; // prompt the user to enter their name
    std::cin >> name; // read the name
    std::cout << "Hello world from " << name << std::endl; // print greetings to the world from the user
    return 0; // end program
}
```

7. **commit**, **push**.
<details><summary>actions</summary>

```bash
$ git commit -am "add comments to hello_world, update readme"
[patch1 bab97cd] add comments to hello_world, update readme
 2 files changed, 22 insertions(+), 5 deletions(-)
$ git push origin patch1
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 4 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (4/4), 780 bytes | 780.00 KiB/s, done.
Total 4 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/Dan41kPlay/lab02.git
   c524886..bab97cd  patch1 -> patch1
```
</details>

8. Проверьте, что новые изменения есть в созданном на **шаге 5** pull-request
> New changes did appear in the PR

9. В удалённый репозитории выполните  слияние PR `patch1 -> master` и удалите ветку `patch1` в удаленном репозитории.
> Merged `patch1` into `main` and deleted branch `patch1` via github.com

10. Локально выполните **pull**.
<details><summary>actions</summary>

```bash
$ git checkout main
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
$ git pull origin main
remote: Enumerating objects: 1, done.
remote: Counting objects: 100% (1/1), done.
remote: Total 1 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (1/1), 921 bytes | 921.00 KiB/s, done.
From https://github.com/Dan41kPlay/lab02
 * branch            main       -> FETCH_HEAD
   9d66859..d72d9c9  main       -> origin/main
Updating 9d66859..d72d9c9
Fast-forward
 README.md       | 77 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 hello_world.cpp | 12 +++++-------
 2 files changed, 82 insertions(+), 7 deletions(-)
```
</details>

11. С помощью команды **git log** просмотрите историю в локальной версии ветки `master`.
<details><summary>actions</summary>

```bash
$ git log --oneline --graph --all
*   d72d9c9 (HEAD -> main, origin/main) Merge pull request #1 from Dan41kPlay/patch1
|\  
| * 9363fa3 (origin/patch1, patch1) update readme once again
| * bab97cd add comments to hello_world, update readme
| * c524886 update readme
| * da5b20b refactoring: remove 'using namespace std;' from hello_world
|/  
* 9d66859 update readme; part 1 is finished
* f677fbd update readme
* 16275df add name prompt to hello_world
* f93f8a5 create hello_world program in c++ (needs refactoring)
* bf0ac1b add step01 to readme
* a193c8a add readme file
* 941c4d3 Initial commit
```
</details>

12. Удалите локальную ветку `patch1`.
```bash
$ git brach -d patch1
```

### Part III

**Note:** *Работать продолжайте с теми же репоззиториями, что и в первой части задания.*
1. Создайте новую локальную ветку `patch2`.
```bash
$ git checkout -b patch2
Switched to a new branch 'patch2'
```

2. Измените *code style* с помощью утилиты [**clang-format**](http://clang.llvm.org/docs/ClangFormat.html). Например, используя опцию `-style=Mozilla`.
```bash
$ clang-format -style=Mozilla -i hello_world.cpp
```

3. **commit**, **push**, создайте pull-request `patch2 -> master`.
<details><summary>actions</summary>

```bash
$ git commit -am "apply Mozilla code style to hello_world"
[patch2 20d75d2] apply Mozilla code style to hello_world
 1 file changed, 9 insertions(+), 6 deletions(-)
$ git push origin patch2
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 4 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 401 bytes | 401.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
remote: 
remote: Create a pull request for 'patch2' on GitHub by visiting:
remote:      https://github.com/Dan41kPlay/lab02/pull/new/patch2
remote: 
To https://github.com/Dan41kPlay/lab02.git
 * [new branch]      patch2 -> patch2
```
</details>

4. В ветке **master** в удаленном репозитории измените комментарии, например, расставьте знаки препинания, переведите комментарии на другой язык.
<details><summary>actions</summary>

```bash
$ git checkout main
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
$ nano hello_world.cpp 
$ git commit -am "updated comments in hello_world"
[main 4db6187] updated comments in hello_world
 1 file changed, 1 insertion(+), 1 deletion(-)
$ git push origin main
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 4 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 352 bytes | 352.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/Dan41kPlay/lab02.git
   509f069..4db6187  main -> main
```
</details>

5. Убедитесь, что в pull-request появились *конфликтны*.
> Conflicts did in fact appear

6. Для этого локально выполните **pull** + **rebase** (точную последовательность команд, следует узнать самостоятельно). **Исправьте конфликты**.
<details><summary>actions</summary>

```bash
$ git checkout patch2
Switched to branch 'patch2'
$ git pull --rebase origin main
From https://github.com/Dan41kPlay/lab02
 * branch            main       -> FETCH_HEAD
Auto-merging hello_world.cpp
CONFLICT (content): Merge conflict in hello_world.cpp
error: could not apply 20d75d2... apply Mozilla code style to hello_world
Could not apply 20d75d2... apply Mozilla code style to hello_world
$ cat hello_world.cpp
#include <iostream>
#include <string>

<<<<<<< HEAD
int main() {
    std::string name; // name of the user will be stored here (umm aktually this is a different comment now get rekt)
    std::cout << "Enter your name: "; // prompt the user to enter their name
    std::cin >> name; // read the name
    std::cout << "Hello world from " << name << std::endl; // print greetings to the world from the user
    return 0; // end program
=======
int
main()
{
  std::string name;                 // name of the user will be stored here
  std::cout << "Enter your name: "; // prompt the user to enter their name
  std::cin >> name;                 // read the name
  std::cout << "Hello world from " << name
            << std::endl; // print greetings to the world from the user
  return 0;               // end program
>>>>>>> patch2
}
$ nano hello_world.cpp 
$ git add hello_world.cpp 
$ git rebase --continue
[detached HEAD 4b2617b] apply Mozilla code style to hello_world
 1 file changed, 9 insertions(+), 6 deletions(-)
Successfully rebased and updated refs/heads/patch2.
```
</details>

7. Сделайте *force push* в ветку `patch2`
<details><summary>actions</summary>

```bash
$ git push --force-with-lease origin patch2
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 4 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 426 bytes | 426.00 KiB/s, done.
Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/Dan41kPlay/lab02.git
 + 20d75d2...4b2617b patch2 -> patch2 (forced update)
```
</details>

8. Убедитель, что в pull-request пропали конфликтны. 
> Conflicts did in fact disappear

9. Вмержите pull-request `patch2 -> master`.
> Merged `patch2` into `main` via github.com and returned to `main` and updated it locally
<details><summary>actions</summary>

```bash
$ git checkout main
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
$ git pull origin main
remote: Enumerating objects: 1, done.
remote: Counting objects: 100% (1/1), done.
remote: Total 1 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (1/1), 915 bytes | 915.00 KiB/s, done.
From https://github.com/Dan41kPlay/lab02
 * branch            main       -> FETCH_HEAD
   4db6187..a1f38e6  main       -> origin/main
Updating 4db6187..a1f38e6
Fast-forward
 hello_world.cpp | 15 +++++++++------
 1 file changed, 9 insertions(+), 6 deletions(-)
$ git branch -d patch2
```
</details>

