#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <utility>
#include <climits>
#include <iomanip>
#include <set>

extern int count_deque;
extern int count_vector;

int					Jacobthal_number_generator(int n);
void				check_numbers(char **av);

//vector:
void				setup_merge(char **av,std::vector<int> &data);
void				insert_sort(std::vector<int> &main, std::vector<int> &pend);
void				replace(std::vector<int>& main, std::vector<int>& pend, std::vector<int>& jacob);
void				edit(std::vector<int> &jacob, std::vector<int> pend);
int					binary_Search(std::vector<int>& main, int pend, int high);
std::vector<int>    JacobthalIndices(int size);


//deque:
void                setup_merge(char **av,std::deque<int> &data);
void				insert_sort(std::deque<int> &main, std::deque<int> &pend);
void				replace(std::deque<int>& main, std::deque<int>& pend, std::deque<int>& jacob);
void				edit(std::deque<int> &jacob, std::deque<int> pend);
int					binary_Search(std::deque<int>& main, int pend, int high);
std::deque<int>		JacobthalIndices1(int size);

#endif
