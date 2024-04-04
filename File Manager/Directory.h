#pragma once
#include "File.h"
#include <string>
#include <vector>
using namespace std;

class Directory : public FileSystemObject {
public:
	void Create(const string& path) {
		if (!fs::exists(path)) {
			fs::create_directories(path);
			cout << "Директория_ " << path << " _создана." << endl;
		}
		else {
			cout << "Директория_ " << path << " _уже существует." << endl;
		}
	}
	void Delete(const string& path) {
		uintmax_t n = fs::remove_all(path);
		cout << "Удалено_ " << n << " _файлов или директорий" << endl;
	}
	void Rename(const string& oldPath, const string& newPath) {
		try {
			fs::rename(oldPath, newPath);
			cout << "Директория переименована " << newPath << " успешно." << endl;
		}
		catch (fs::filesystem_error& e) {
			cout << "Ошибка при переименовании директории: " << e.what() << endl;
		}
	}
	void Copy(const string& sourcePath, const string& destinationPath) {
		try {
			fs::copy(sourcePath, destinationPath, fs::copy_options::recursive);
			cout << "Директория успешно " << destinationPath << " скопирована." << endl;
		}
		catch (fs::filesystem_error& e) {
			cout << "Ошибка при копировании директории: " << e.what() << endl;
		}

	}
	void Move(const string& oldPath, const string& newPath) {
		try {
			fs::rename(oldPath, newPath);
			cout << "Директория успешно " << newPath << " перемещена." << endl;
		}
		catch (fs::filesystem_error& e) {
			cout << "Ошибка при перемещении директории: " << e.what() << endl;
		}
	}
	uintmax_t getDirectorySize(const fs::path& path) {
		uintmax_t totalSize = 0;
		for (const auto& entry : fs::recursive_directory_iterator(path)) {
			if (entry.is_regular_file()) {
				totalSize += entry.file_size();
			}
		}
		return totalSize;
	}
	void ShowSize(const string& path) {
		uintmax_t dirSize = getDirectorySize(path);
		cout << "Общий размер директории: " << dirSize << " байт" << endl;
	}
};