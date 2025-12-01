#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void calculatePassword(std::string rotation, int& count, int& position)
{
    int mag = std::stoi(rotation.substr(1));
    if (rotation[0] == 'L')
    {
        mag *= -1;
    }
    
    position = (position + mag) % 100;
    if (position < 0)
    {
        position += 100;
    }
    if (position == 0)
    {
        count++;
    }
}

int main()
{
    // loop throught the text file
    // Rotate with + or - with right and left respectively, cap it with % 99
    // Count how many 0's it lands on
    // print the count
    int passwordCount = 0;
    int currentPosition = 50;
    std::ifstream file("input011.txt");
    
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            //std::cout << currentPosition << std::endl << passwordCount << std::endl;
            calculatePassword(line, passwordCount, currentPosition);
        }
    }
    else 
    {
        std::cerr << "Couldn't open file" << std::endl;
    }
    
    std::cout << "Password: " << passwordCount << std::endl;
}