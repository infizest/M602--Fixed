#include "data_fetcher.h"
#include "csv_parser.h"
#include "analysis.h"
#include <iostream>

int main() {
    std::string url = "https://example.com/api/data";
    std::string apiData = fetchDataFromAPI(url);
    
    std::string filename = "carbon_data.csv";
    std::vector<std::vector<std::string>> csvData = parseCSV(filename);

    analyzeCarbonFootprint(csvData);
    
    return 0;
}

