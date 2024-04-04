#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstdint>
#include <string>
using namespace std;
namespace fs = std::filesystem;

class FileSystemObject {
public:
	virtual ~FileSystemObject() {}
	virtual void Create(const string& path) = 0;
	virtual void Delete(const string& path) = 0;
	virtual void Rename(const string& oldPath, const string& newPath) = 0;
	virtual void Copy(const string& sourcePath, const string& destinationPath) = 0;
	virtual void Move(const string& oldPath, const string& newPath) = 0;
	virtual void ShowSize(const string& path) = 0;
};