#include "analysis.h"
#include <iostream>

void analyzeCarbonFootprint(const std::vector<std::vector<std::string>>& data) {
    std::cout << "Carbon Footprint Analysis:\n";
    for (const auto& row : data) {
        if (row.size() > 1) {
            std::cout << "Company: " << row[0] << " - Emissions: " << row[1] << " metric tons\n";
        }
    }
}

