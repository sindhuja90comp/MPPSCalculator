#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath> // For isnan()
#include <cfloat> // For NAN on some older systems

// Function to calculate the mean
double calculateMean(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        return NAN;
    }
    double sum = 0;
    for (size_t i = 0; i < numbers.size(); ++i) { // Use index-based loop
        sum += numbers[i];
    }
    return sum / numbers.size();
}

// Function to calculate the median
double calculateMedian(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        return NAN;
    }
    std::vector<int> sortedNumbers = numbers; // Copy the vector
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    size_t size = sortedNumbers.size();
    if (size % 2 == 0) {
        return (sortedNumbers[size / 2 - 1] + sortedNumbers[size / 2]) / 2.0;
    } else {
        return sortedNumbers[size / 2];
    }
}

// Function to calculate the mode(s)
std::vector<int> calculateMode(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        return std::vector<int>(); // Use constructor for empty vector
    }
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    size_t size = sortedNumbers.size();

    int maxCount = 0;
    int currentCount = 1;
    std::vector<int> modes;

    for (size_t i = 1; i < size; ++i) { // Use index-based loop
        if (sortedNumbers[i] == sortedNumbers[i - 1]) {
            currentCount++;
        } else {
            if (currentCount > maxCount) {
                maxCount = currentCount;
                modes.clear();
                modes.push_back(sortedNumbers[i - 1]);
            } else if (currentCount == maxCount) {
                modes.push_back(sortedNumbers[i - 1]);
            }
            currentCount = 1;
        }
    }
     if (currentCount > maxCount) {
        modes.clear();
        modes.push_back(sortedNumbers[size-1]);
    }
    else if(currentCount == maxCount){
         modes.push_back(sortedNumbers[size-1]);
    }
    return modes;
}

int main() {
    std::cout << "Welcome to the Statistics Calculator! Enter a list of integers (with spaces) or type 'done': " << std::endl;

    std::string inputLine;
    std::vector<int> numbers;

    while (std::getline(std::cin, inputLine)) {
        if (inputLine == "done") {
            break;
        }

        std::stringstream ss(inputLine);
        int number;
        bool validInput = true;
        while (ss >> number) {
            numbers.push_back(number);
        }
        if (numbers.empty() && inputLine.empty())
        {
             std::cout << "No integers were entered. Please provide a list of integers or 'done': " << std::endl;
             continue;

        }

        if (ss.fail() && !ss.eof()) {
            std::cout << "Invalid input. Please enter integers separated by spaces, or 'done': " << std::endl;
            numbers.clear(); // Clear the vector for the next input
            continue; // Go back to the beginning of the while loop
        }
        break; // Exit the loop if input is valid

    }
    if (numbers.empty())
    {
        std::cout << "No numbers entered. Exiting." << std::endl;
        return 0;
    }

    double mean = calculateMean(numbers);
    if (std::isnan(mean)) {
        std::cout << "Mean: No data provided" << std::endl;
    } else {
        std::cout << "Mean: " << mean << std::endl;
    }

    double median = calculateMedian(numbers);
    if (std::isnan(median)) {
        std::cout << "Median: No data provided" << std::endl;
    } else {
        std::cout << "Median: " << median << std::endl;
    }

    std::vector<int> modes = calculateMode(numbers);
    if (modes.empty()) {
        std::cout << "Mode: No mode found" << std::endl;
    } else {
        std::cout << "Mode(s): ";
        for (size_t i = 0; i < modes.size(); ++i) { // Use index based loop
            std::cout << modes[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
