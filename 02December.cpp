#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void validate(long long id, long long &sum)
{
    std::string acID = std::to_string(id);
    std::string former, latter;
    former = acID.substr(0, acID.size()/2);
    latter = acID.substr(acID.size()/2);
    if (former == latter) 
    {
        sum += id;
        std::cout << id << " is an invalid id!" << std::endl;
    }
}

int main()
{
    std::string line;
    long long totalInvalid = 0;
    std::ifstream file("input.txt");
    if (file.is_open())
    {
        std::getline(file, line);
    }
    else
    {
        std::cerr << "Cant open the file" << std::endl;
        return 1;
    }
    
    std::string rangeValues = "";
    std::vector<long long> ranges;
    for (int i = 0, len = line.length(); i < len; i++)
    {
        if (line[i] != '-' && line[i] != ',') rangeValues += line[i];

        else 
        {
            try
            {
                ranges.push_back(std::stoll(rangeValues));
            }
            catch(const std::out_of_range& e)
            {
                std::cerr << e.what() << '\n';
                std::cout << "\033[31m";
                for (long long i:ranges)
                {
                    std::cerr << i << std::endl;
                }
                std::cout << "\033[0m";
            }
            
            rangeValues = "";
        }
    }
    
    ranges.push_back(std::stoll(rangeValues));
    
    for (int i = 0, len = ranges.size(); i < len; i += 2)
    {
        long long upper, lower;
        upper = ranges[i + 1];
        lower = ranges[i];
        for (long long id = lower; id <= upper; id++)
        {
            validate(id, totalInvalid);
        }
    }

    std::cout << totalInvalid << std::endl;
    
    return 0;
}