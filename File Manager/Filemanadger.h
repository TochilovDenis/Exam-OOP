#pragma once
#include "Directory.h"

class FileManager {
public:
    vector<string> getDirectoryContents(const string& path) {
        vector<string> contents;
        for (const auto& entry : fs::directory_iterator(path)) {
            contents.push_back(entry.path().string());
        }
        return contents;
    }

    void displayDirectoryContents(const string& path) {
        vector<string> contents = getDirectoryContents(path);
        for (const auto& item : contents) {
            cout << item << endl;
        }
    }

    bool matchesMask(const fs::path& path, const string& mask) {
        return path.filename().string().find(mask) != string::npos;
    }

    void SearchFiles(const fs::path& dirPath, const std::string& mask) {
        for (const auto& entry : fs::recursive_directory_iterator(dirPath)) {
            if (entry.is_regular_file() && matchesMask(entry.path(), mask)) {
                cout << entry.path() << endl;
            }
            else {
                cout << "Файл или папку не найден!" << endl;
            }
        }
    }
};