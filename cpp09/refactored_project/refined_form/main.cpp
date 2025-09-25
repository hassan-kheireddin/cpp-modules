#include "PmergeME.hpp"

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeME <numbers>" << std::endl;
        return 1;
    }
    
    try {
        PmergeME sorter;
        sorter.processInput(argv);
        sorter.sortAndDisplay();
        
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}