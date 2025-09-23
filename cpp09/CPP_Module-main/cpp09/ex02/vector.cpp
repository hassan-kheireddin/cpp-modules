#include "PmergeMe.hpp"

std::vector<int>	loop(std::vector<int> &data)
{
    std::vector<std::pair<int, int> > data_pairs;
	std::vector<int> main;
    std::vector<int> pend;
	std::vector<int> new_main;
    std::vector<int> new_pend;
    std::vector<int> result;
    bool isodd;
    
	if (data.empty())
        return std::vector<int>();
	if (data.size() == 1)
        return data;
	if (data.size() == 2)
	{
        result = data;
        count_vector++;
        if (result[0] > result[1])
            std::swap(result[0], result[1]);
		return result;
	}
    isodd = (data.size() % 2 == 1);
    std::vector<int>::iterator it = data.begin();
	while (it != data.end())
	{

        if ((it + 1) == data.end())
            break;
        count_vector++;
        if (*it > *(it + 1))
        {
            main.push_back(*it);
            pend.push_back(*(it + 1));
        }
        else
        {
            pend.push_back(*it);
            main.push_back(*(it + 1));
        }
        it += 2;
	}
	if (isodd)
		pend.push_back(data.back());
	new_main = loop(main);

	new_pend.clear();
	new_pend.resize(new_main.size());

	for (size_t i = 0; i < new_main.size(); ++i)
	{
		for (size_t j = 0; j < main.size(); ++j)
		{
			if (main[j] == new_main[i])
			{
				new_pend[i] = pend[j];
				break;
			}
		}
	}
    if (isodd)
		new_pend.push_back(pend.back());
    insert_sort(new_main, new_pend);

	return new_main;
}

void setup_merge(char **av,std::vector<int> &data)
{

	for (int i = 1; av[i]; i++)
    {
        std::string arg = av[i];
        std::stringstream ss(arg);
        std::string number;
        while (std::getline(ss, number, ' '))
        {
            if (number.empty())
                continue;
            data.push_back(std::atoi(number.c_str()));
        }
    }
    count_vector = 0;
    std::cout << "before:         ";
        for (std::size_t i = 0; i < data.size(); ++i)
        {
            std::cout << data[i];
            if (i < data.size())
                std::cout << " ";
        }
        std::cout << std::endl;
	data = loop(data);
    
    
}

std::vector<int>    JacobthalIndices(int size)
{
    std::vector<int> jacobSequence;
    int jacobIndex = 3;
    while (Jacobthal_number_generator(jacobIndex) <= size)
    {
        jacobSequence.push_back(Jacobthal_number_generator(jacobIndex));
        jacobIndex++;
    }
    return jacobSequence;
}

int binary_Search(std::vector<int>& main, int pend, int high)
{
    if (main.empty())
        return 0;
    int low = 0;
    if (high >= static_cast<int>(main.size()))
        high = main.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        count_vector++;
        if (main[mid] == pend)
        {
            return mid;
        }
        else if (main[mid] > pend)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (low < static_cast<int>(main.size()) && pend < main[low])
        return low;
    
    return main.size();
}

void    edit(std::vector<int> &jacob, std::vector<int> pend)
{
    std::vector<int>::iterator it = jacob.begin();
    std::vector<int> pushedNumbers;
    std::vector<int> temp;
    while (it != jacob.end())
    {
        int x;
        if (*it >= 0)
        {
            x = *it;
            while (x > 1)
            {
                if (std::find(pushedNumbers.begin(), pushedNumbers.end(), x) == pushedNumbers.end())
                {
                    temp.push_back(x);
                    pushedNumbers.push_back(x);
                }
                else
                    break;
                x--;
            }
        }
        it++;
    }
    if (temp.size() == pend.size())
        jacob = temp;
    else
    {
        int x = pend.size();
        while (temp.size() < pend.size())
        {
            if (std::find(pushedNumbers.begin(), pushedNumbers.end(), x) == pushedNumbers.end())
            {
                temp.push_back(x);
                pushedNumbers.push_back(x);
            }
            else
                break;
            x--;
        }
        jacob = temp;
    }
}

void    replace(std::vector<int>& main, std::vector<int>& pend, std::vector<int>& jacob)
{
    std::vector<int>::iterator it = jacob.begin();
    int high = 3;
    main.insert(main.begin(), pend[0]);
    while (it != jacob.end())
    {
        if (it != jacob.begin() && *it > *(it - 1))
            high = 2 * high + 1;
        if (*it <= static_cast<int>(pend.size()) && *it != 1)
        {
            int index = binary_Search(main, pend[*it - 1], high - 1);
            if (index != -1)
                main.insert(main.begin() + index, pend[*it - 1]);
        }
        it++;
    }
}

void    insert_sort(std::vector<int> &main, std::vector<int> &pend)
{

    std::vector<int> jacob = JacobthalIndices(pend.size());
    edit(jacob, pend);
    replace(main, pend, jacob);

}
