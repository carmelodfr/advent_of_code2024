#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <unordered_map>

int main(int argc, char** argv){

    if (argc != 2) {
        std::cout << "\nto run the puzzle type: \n\n" << argv[0] << " <file.csv>\n" << std::endl;
        return 0;
    }

    std::cout << "Day 1 of the advent of code!" << std::endl;
    std::cout << "Puzzle 2:" << std::endl;
    
    
    // Read from the text file
    std::ifstream MyInput(argv[1]);

    // Data will be stored in unordered map so it will be easy to count for all the elements.
    std::unordered_map<int,int> firstList;
    std::unordered_map<int,int> secondList;

    // read the file line by line
    std::string line;
    while (getline (MyInput, line)) {
        std::stringstream ss(line);
        
        // read first number of the line
        std::string number;
        ss >> number;
        int value = std::stoi(number);
        // if not present add the value in the map, else increment 
        if (firstList.find(value) == firstList.end()){
            firstList[value] = 1;
        }
        else {
            firstList[value] = firstList[value] + 1;
        }
        // do the same for the second number        
        ss >> number;
        value = std::stoi(number);
        if (secondList.find(value) == secondList.end()){
            secondList[value] = 1;
        }
        else {
            secondList[value] = secondList[value] + 1;
        }
    }

    // similarity score will count how much the element in the list appears in the second list
    int similarityScore = 0;

    for (auto& firstListIterator : firstList){
        // get the element of the first list
        int valueToCheck = firstListIterator.first;
        // if is present in the second list
        if ( secondList.find(valueToCheck) != secondList.end()){
            // multiply to get the similarity score.
            // since the value is the same for all the occurrences, also muultiply by the number of times
            // it apperas in the first list
            similarityScore += valueToCheck * firstListIterator.second *  secondList[valueToCheck];
        }
    }
    std::cout << "Result: " << similarityScore << std::endl;

    // Close the file
    MyInput.close();

    return 0;
}