#include "data_fetcher.h"
#include "csv_parser.h"
#include "analysis.h"
#include <iostream>

int main() {
    std::string url = "https://raw.githubusercontent.com/infizest/M602--Fixed/refs/heads/main/owid-co2-data.csv";
    std::string apiData = fetchDataFromAPI(url);
    
    std::string filename = "carbon_data.csv";
    std::vector<std::vector<std::string>> csvData = parseCSV(filename);

    analyzeCarbonFootprint(csvData);
    
    return 0;
}

