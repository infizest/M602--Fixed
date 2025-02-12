#include "data_fetcher.h"
#include "csv_parser.h"
#include "analysis.h"
#include <iostream>
#include <fstream>
#include <vector>

void saveResultsToCSV(const std::string& filename, const std::vector<std::string>& data) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& line : data) {
            file << line << "\n";  // Ensure correct line formatting
        }
        file.close();
        std::cout << "✅ Data successfully saved to " << filename << std::endl;
    } else {
        std::cerr << "❌ Error: Unable to save data to file!" << std::endl;
    }
}

int main() {
    std::string url = "https://raw.githubusercontent.com/infizest/M602--Fixed/main/owid-co2-data.csv";
    
    std::cout << "📡 Fetching data from API..." << std::endl;
    std::string apiData = fetchDataFromAPI(url);

    std::string filename = "carbon_data.csv";
    
    if (!apiData.empty()) {
        std::ofstream file(filename);
        file << apiData;
        file.close();
    } else {
        std::cerr << "❌ Error: Failed to fetch data from API." << std::endl;
        return 1;
    }

    std::cout << "📂 Reading data from CSV..." << std::endl;
    std::vector<std::vector<std::string>> csvData = parseCSV(filename);

    std::cout << "📊 Analyzing Carbon Footprint..." << std::endl;
    std::vector<std::string> results = analyzeCarbonFootprint(csvData);

    std::string outputFile = "output_carbon_data.csv";
    saveResultsToCSV(outputFile, results);

    return 0;
}
