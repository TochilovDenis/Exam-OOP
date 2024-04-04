#pragma once
#include "FileSystemObject.h"

class File : public FileSystemObject {
public:
	void Create(const string& path) {
		ofstream ofs(path);
		if (ofs) {
			ofs << "Это текст в новом файле.\n";
			ofs.close();
			cout << "Файл_ " << path << " _создан." << endl;
		}
		else {
			cout << "Не удалось создать файл " << path << endl;
		}
	}
	void Delete(const string& path) {
		if (fs::remove(path)) {
			cout << "Файл_ " << path << " _успешно удален." << endl;
		}
		else {
			cout << "Не удалось удалить файл " << path << endl;
		}
	}
	void Rename(const string& oldPath, const string& newPath) {
		try {
			fs::rename(oldPath, newPath);
			cout << "Файл " << newPath << " переименован успешно." << endl;
		}
		catch (fs::filesystem_error& e) {
			cout << "Ошибка при переименовании файла: " << e.what() << endl;
		}
	}
	void Copy(const string& sourcePath, const string& destinationPath) {
		try {
			fs::copy(sourcePath, destinationPath, fs::copy_options::overwrite_existing);
			cout << "Файл " << destinationPath << " успешно скопирован." << endl;
		}
		catch (fs::filesystem_error& e) {
			cout << "Ошибка при копировании файла: " << e.what() << endl;
		}
	}
	void Move(const string& oldPath, const string& newPath) {
		try {
			fs::rename(oldPath, newPath);
			std::cout << "Файл " << newPath << "успешно перемещен." << std::endl;
		}
		catch (fs::filesystem_error& e) {
			std::cout << "Ошибка при перемещении файла: " << e.what() << std::endl;
		}
	}
	void ShowSize(const string& path) {
		uintmax_t fileSize = fs::file_size(path);
		cout << "Размер файла: " << fileSize << " байт" << endl;
	}
};