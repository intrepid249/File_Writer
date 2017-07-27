#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ostream>

using std::ios_base;
using std::fstream;
using std::vector;
using std::string;
using std::cout;
using std::endl;

class TextFileWriter {
private:
	bool m_readOnly;
public:
	TextFileWriter();

	fstream loadFile(const char *a_filename, bool a_readOnly);
	void writeFile(const char *a_filename, vector<char*> a_content);
	vector<string> readFile(const char *a_filename);
	bool isReadOnly() { return m_readOnly; };
};

