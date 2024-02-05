#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

// Function to trim leading and trailing spaces from a string
string trim(const string& str) {
    size_t first = str.find_first_not_of(' '), last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

int main() {
    string inputFilePath = "input.txt";
    string outputFilePath = "output.txt";
    ifstream inputFile(inputFilePath);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Read lines from the input file
    ostringstream commandBuilder;
    string line;
    while (getline(inputFile, line)) {
        // Trim leading and trailing spaces from the line
        line = trim(line);

        // Remove the line continuation character if present
        line.erase(remove(line.begin(), line.end(), '^'), line.end());

        // Concatenate the trimmed line to the command
        commandBuilder << line;
    }
    inputFile.close();

    ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    // Write the single-line cURL command to the output file
    outputFile << commandBuilder.str();

    outputFile.close();

    cout << "Conversion successful. Single-line cURL command written to " << outputFilePath << endl;

    return 0;
}
