/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:00:14 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/11 14:00:14 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <colors.hpp>
#include <PmergeMe.hpp>
#include <PmergeMe.tpp>
#include <vector>
#include <deque>


/// ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`

int main(int argc, char **argv) {
	double timeVec, timeDeq;
	clock_t start, end;
	std::vector<int> vec;
	std::deque<int> deq;

	if (argc == 1) {
		std::cout << RED"ERROR: please provide arguments to be sorted\n"R;
		return 1;
	}
	else if (!PmergeMe::checkArgs(argv + 1)) {
		return 1;
	}

	PmergeMe::fillContainer(vec, argv + 1);
	PmergeMe::fillContainer(deq, argv + 1);
	std::cout << BLUE"Before:\t"R;
	PmergeMe::printContainer(vec);

	start = clock();
	PmergeMe::FJMIS(vec);
	end = clock();

	timeVec = (double(end - start) / CLOCKS_PER_SEC) * 1e6;

	start = clock();
	PmergeMe::FJMIS(deq);
	end = clock();
	timeDeq = (double(end - start) / CLOCKS_PER_SEC) * 1e6;

	for (size_t i = 0; i + 1 < vec.size(); ++i) {
		if (vec[i + 1] < vec[i]) {
			std::cout << RED"ERROR: sorting failed\n";
		}
	}

	for (size_t i = 0; i + 1 < deq.size(); ++i) {
		if (deq[i + 1] < deq[i]) {
			std::cout << RED"ERROR: sorting failed\n";
		}
	}

	std::cout << MAGENTA"After:\t"R;
	PmergeMe::printContainer(vec);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector<int> : " << timeVec
			  << " us\n"R;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque<int> : " << timeDeq
			  << " us\n"R;

	return 0;
}
