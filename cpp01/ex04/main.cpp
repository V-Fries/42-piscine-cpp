#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

static int openInputFile(std::ifstream& inputFile, const std::string& inputFileName);
static int openOutputFile(std::ofstream& outputFile, const std::string& outputFileName);
static void writeModifiedOutput(std::ifstream& inputFile, std::ofstream& outputFile,
								const std::string& stringToReplace,
								const std::string& stringToReplaceWith);
static void printModifedLine(std::string& currentLine, const std::string& stringToReplace,
							 const std::string& stringToReplaceWith,
							 std::ofstream& outputFile);

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Expected 3 arguments\n"
				  << "\t./sedIsForLosers FILE_NAME STR_TO_REPLACE STR_TO_REPLACE_WITH"
				  << std::endl;
		return EXIT_FAILURE;
	}

	const std::string inputFileName(argv[1]);
	const std::string outputFileName(inputFileName + ".replace");
	const std::string stringToReplace(argv[2]);
	const std::string stringToReplaceWith(argv[3]);

	std::ifstream inputFile;
	if (openInputFile(inputFile, inputFileName) == EXIT_FAILURE)
		return EXIT_FAILURE;
	std::ofstream outputFile;
	if (openOutputFile(outputFile, outputFileName) == EXIT_FAILURE)
		return EXIT_FAILURE;

	writeModifiedOutput(inputFile, outputFile, stringToReplace, stringToReplaceWith);
}

static int openInputFile(std::ifstream& inputFile, const std::string& inputFileName)
{
	inputFile.open(inputFileName);
	if (!inputFile)
	{
		std::cerr << "Failed to open " << inputFileName << ": " << strerror(errno)
				  << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

static int openOutputFile(std::ofstream& outputFile, const std::string& outputFileName)
{
	outputFile.open(outputFileName);
	if (!outputFile)
	{
		std::cerr << "Failed to open " << outputFileName << ": " << std::strerror(errno)
				  << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

static void writeModifiedOutput(std::ifstream& inputFile, std::ofstream& outputFile,
								const std::string& stringToReplace,
								const std::string& stringToReplaceWith)
{
	std::string currentLine;
	while (std::getline(inputFile, currentLine))
	{
		printModifedLine(currentLine, stringToReplace, stringToReplaceWith, outputFile);
		if (!inputFile.eof())
			outputFile << std::endl;
	}
}

static void printModifedLine(std::string& currentLine, const std::string& stringToReplace,
							 const std::string& stringToReplaceWith,
							 std::ofstream& outputFile)
{
	std::size_t found = currentLine.find(stringToReplace);
	while (found != std::string::npos)
	{
		outputFile << currentLine.substr(0, found) << stringToReplaceWith;
		const std::size_t newCurrentLineStartingIndex = found + stringToReplace.length();
		const std::size_t newCurrentLineStringLen = currentLine.length() - found
													- stringToReplace.length();
		currentLine = currentLine.substr(newCurrentLineStartingIndex, newCurrentLineStringLen);
		found = currentLine.find(stringToReplace);
	}
	outputFile << currentLine;
}
