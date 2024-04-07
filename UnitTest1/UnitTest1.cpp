#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab10.2/lab10.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestProcessContent)
		{
			string testInput = "Hello , world !";
			string expectedOutput = "Hello, world!";
			string actualOutput = processContent(testInput);

			Assert::AreEqual(expectedOutput, actualOutput);
		}

        TEST_METHOD(TestReadFileContent)
        {
            string filename = "testReadFile.txt";
            ofstream outFile(filename);
            string fileContent = "This is a test file content.";
            if (outFile.is_open()) {
                outFile << fileContent;
                outFile.close();
            }
            string readContent = readFileContent(filename);

            Assert::AreEqual(fileContent, readContent);
            remove(filename.c_str());
        }

        TEST_METHOD(TestSaveFileContent)
        {
            string filename = "testSaveFile.txt";
            string fileContent = "Test content for saving to a file.";
            saveFileContent(filename, fileContent);
            ifstream inFile(filename);
            stringstream buffer;
            if (inFile.is_open()) {
                buffer << inFile.rdbuf();
                inFile.close();
            }

            Assert::AreEqual(fileContent, buffer.str());
            remove(filename.c_str());
        }
	};
}
