#include "analysis.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

std::vector<std::string> analyzeCarbonFootprint(const std::vector<std::vector<std::string>>& data) {
    std::vector<std::string> results;
    std::unordered_map<std::string, double> maxEmissions;  // Track max emissions per company

    int countryIndex = -1, emissionsIndex = -1;

    if (data.empty()) {
        std::cerr << "❌ Error: CSV data is empty!" << std::endl;
        return results;
    }

    // Identify header indices
    const std::vector<std::string>& headers = data[0];
    for (size_t i = 0; i < headers.size(); i++) {
        if (headers[i] == "country") countryIndex = i;
        if (headers[i] == "co2") emissionsIndex = i;
    }

    if (countryIndex == -1 || emissionsIndex == -1) {
        std::cerr << "❌ Error: Required columns not found in CSV!" << std::endl;
        return results;
    }

    // Process each row
    for (size_t i = 1; i < data.size(); i++) {
        if (data[i].size() > emissionsIndex) {
            std::string company = data[i][countryIndex];  
            std::string emissionsStr = data[i][emissionsIndex];

            if (!company.empty() && !emissionsStr.empty()) {
                try {
                    double emissions = std::stod(emissionsStr);  // Convert to double

                    // Update the maximum emission per company
                    if (maxEmissions.find(company) == maxEmissions.end() || emissions > maxEmissions[company]) {
                        maxEmissions[company] = emissions;
                    }
                } catch (...) {
                    std::cerr << "⚠️ Warning: Invalid emission value for " << company << std::endl;
                }
            }
        }
    }

    // Convert results to the required format
    for (const auto& pair : maxEmissions) {
        results.push_back("Company: " + pair.first + " - Emissions: " + std::to_string(static_cast<int>(pair.second)) + " metric tons");
    }

    return results;
}
