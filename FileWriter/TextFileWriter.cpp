#include "TextFileWriter.h"


TextFileWriter::TextFileWriter() {
}

fstream TextFileWriter::loadFile(const char *a_filename, bool a_readOnly) {
	m_readOnly = a_readOnly;
	if (a_readOnly) {
		fstream tempFile(a_filename, ios_base::in); // File must exist
		return tempFile;
	} else {
		fstream tempFile(a_filename, ios_base::out); // Create file if it doesn't exist
		tempFile.open(a_filename, ios_base::out | ios_base::in); // And open for reading and writing
		return tempFile;
	}
}

void TextFileWriter::writeFile(const char *a_filename, vector<char*> a_content) {
	fstream writeFile = loadFile(a_filename, false);

	if (writeFile.is_open()) {
		for (char *textLine : a_content) {
			writeFile << textLine << "\n";
			cout << "Write: " << textLine << endl;
		}
		writeFile.close();
	}
}

vector<string> TextFileWriter::readFile(const char *a_filename) {
	fstream readFile = loadFile(a_filename, true);
	vector<string> output;
	if (readFile.is_open()) {
		cout << "Reading: ";
		string line;
		while(std::getline(readFile, line)) {
			cout << "t: " << line << endl;
			//readFile.read((char*)&line, sizeof(string));
			output.push_back(line);
		}
		for (string s : output)
			cout << s << endl;
		readFile.close();
	}
	return output;
}