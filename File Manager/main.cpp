#include "File.h"
#include "Directory.h"
#include "Filemanadger.h"

int main() {
    setlocale(0, "");

    File file;
    Directory dir;

    cout << "\nСоздаем папку и файл:\n";
    dir.Create("D:\\FileManadger\\example\\example");
    dir.Create("D:\\FileManadger\\example\\example3");
    file.Create("D:\\FileManadger\\example\\example\\example.txt");

    cout << "\nПереименования папки и файла:\n";
    dir.Rename("D:\\FileManadger\\example\\example", "D:\\FileManadger\\example\\example1");
    file.Rename("D:\\FileManadger\\example\\example1\\example.txt", "D:\\FileManadger\\example\\example1\\example1.txt");

    cout << "\nКопирование папку и файл:\n";
    dir.Copy("D:\\FileManadger\\example\\example1", "D:\\FileManadger\\example\\example2");
    file.Copy("D:\\FileManadger\\example\\example1\\example1.txt", "D:\\FileManadger\\example\\example1\\example2.txt");

    cout << "\nПеремещение папку и файл:\n";
    dir.Move("D:\\FileManadger\\example\\example3", "D:\\FileManadger\\example\\example1\\example3");
    file.Move("D:\\FileManadger\\example\\example2\\example1.txt", "D:\\FileManadger\\example\\example1\\example2.txt");

    cout << "\nРазмер папки и файла:\n";
    dir.ShowSize("D:\\FileManadger");
    file.ShowSize("D:\\FileManadger\\example\\example1\\example2.txt");

    FileManager fileManager;
    cout << "\nПоказываем содержимое дисков:\n";
    string path = "D:\\FileManadger\\example";

    fileManager.displayDirectoryContents(path);
    cout << "\nПоиск папку и файла:\n";
    fileManager.SearchFiles("D:\\FileManadger", "example2.txt");

    cout << "\nУдаляем папку и файл:\n";
    dir.Delete("D:\\FileManadger\\example");

    return 0;
}

/*
Первое задание
Реализовать простейший файловый менеджер с использованием ООП (классы, наследование и так далее).
Файловый менеджер должен иметь такие возможности:
    1. показывать содержимое дисков;
    2. создавать папки\\файлы;
    3. удалять папки\\файлы;
    4. переименовывать папки\\файлы;
    5. копировать\\переносить папки\\файлы;
    6. вычислять размер папки\\файла;
    7. производить поиск по маске (с поиском по подпапкам) и так далее.
*/