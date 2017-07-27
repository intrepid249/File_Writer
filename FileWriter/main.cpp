#include <iostream>
#include "main.h"
#include "TextFileWriter.h"

int main() {
	TextFileWriter fWriter;

	vector<char*> textData;
	textData.push_back("Line 1");
	textData.push_back("line2");
	textData.push_back("line23");
	textData.push_back("hiashfadsjk");

	fWriter.writeFile("wolfy2.dataFile", textData);
	fWriter.readFile("wolfy2.dataFile");

	system("pause");
	return EXIT_SUCCESS;
}