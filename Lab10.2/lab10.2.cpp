#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

string readFileContent(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Could not open file: " << filename << endl;
        return "";
    }
    stringstream buffer;
    buffer << inFile.rdbuf();
    inFile.close();
    return buffer.str();
}

string processContent(const string& content) {
    string processed;
    bool spaceBeforePunct = false;

    for (size_t i = 0; i < content.length(); ++i) {
        if (isspace(content[i])) {
            spaceBeforePunct = true;
            continue;
        }
        else if (spaceBeforePunct && ispunct(content[i])) {
            processed += content[i];
            spaceBeforePunct = false;
            continue;
        }
        else {
            if (spaceBeforePunct) {
                processed += ' ';
                spaceBeforePunct = false;
            }
            processed += content[i];
        }
    }
    return processed;
}

void saveFileContent(const string& filename, const string& content) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Could not open file for writing: " << filename << endl;
        return;
    }
    outFile << content;
    outFile.close();
    cout << "The file has been processed and saved as " << filename << endl;
}

int main() {
    string inputFilename = "t1.txt";
    string outputFilename = "t2.txt";
    string content = readFileContent(inputFilename);
    string processedContent = processContent(content);
    saveFileContent(outputFilename, processedContent);

    return 0;
}