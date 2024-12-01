#include <iostream>
#include <fstream>
#include <set>
#include <sstream>


int main(int argc, char** argv){

    if (argc != 2) {
        std::cout << "\nto run the puzzle type: \n\n" << argv[0] << " <file.csv>\n" << std::endl;
        return 0;
    }

    std::cout << "Day 1 of the advent of code!" << std::endl;
    std::cout << "Puzzle 1:" << std::endl;

    // Read from the text file
    std::ifstream MyInput(argv[1]);

    // store the list in a multiset. data will be ordered automatically
    std::multiset<int> firstList;
    std::multiset<int> secondList;
    
    // read a line and use a stringstream to split the numbers
    std::string line;
    while (getline (MyInput, line)) {

        std::stringstream ss(line);
        std::string number;
        // read first number
        ss >> number;
        firstList.insert(std::stoi(number));
        // read second number
        ss >> number;
        secondList.insert(std::stoi(number));
    }

    // compute the total distance abs(a[i] - b[i])
    int totalDistance = 0;

    auto secondListIterator = secondList.begin();
    for (auto& firstListIterator : firstList){
        totalDistance += abs(firstListIterator - *secondListIterator);
        secondListIterator++;
    }
    std::cout << "Result: " << totalDistance << std::endl;

    // Close the file
    MyInput.close();

    return 0;
}