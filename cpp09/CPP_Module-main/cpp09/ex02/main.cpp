#include "PmergeMe.hpp"

int count_deque = 0;
int count_vector = 0;

void    print_containers(std::vector<int> data_vector, std::deque<int> data_deque)
{
    std::cout << "After vector:   ";
    for (std::size_t i = 0; i < data_vector.size(); ++i)
    {
        std::cout << data_vector[i];
        if (i < data_vector.size())
            std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << "After deque:    ";
    for (std::size_t i = 0; i < data_deque.size(); ++i)
    {
        std::cout << data_deque[i];
        if (i < data_deque.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Usage: ./PmergeMe <numbers>" << std::endl;
        return (1);
    }
    try
    {
        check_numbers(av);
        
        std::vector<int> final_vector;
        std::deque<int> final_deque;


        clock_t start_vector = clock();
        std::vector<int> data_vector;
        setup_merge(av, data_vector);

        clock_t end_vector = clock();
        double time_vector = static_cast<double>(end_vector - start_vector) / CLOCKS_PER_SEC ;

        clock_t start_deque = clock();
        std::deque<int> data_deque;
        setup_merge(av, data_deque);

        clock_t end_deque = clock();
        double time_deque = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC ;

        print_containers(data_vector, data_deque);
        std::cout << "Time to process a range of " << data_deque.size() << " elements with std::deque: ";
        std::cout << std::fixed << std::setprecision(6) << time_deque << " us" << std::endl;
        
        std::cout << "Time to process a range of " << data_vector.size() << " elements with std::vector: ";
        std::cout << std::fixed << std::setprecision(6) << time_vector << " us" << std::endl;

        std::cout << "Total moves for vector-based sorting: " << count_vector << std::endl;
        std::cout << "Total moves for deque-based sorting: " << count_deque << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return (0);
}
