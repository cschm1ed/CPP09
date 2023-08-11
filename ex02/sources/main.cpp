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
#include <vector>
#include <deque>
#include <PmergeMe.tpp>

int main(int argc, char **argv) {
	std::vector<int> vec;
	std::deque<int> deq;

	if (argc == 1) {
		std::cout << SYS << RED"ERROR: please provide arguments to be sorted\n"R;
	} else if (!PmergeMe::checkArgs(argv + 1)) {
		return 1;
	}

	PmergeMe::fillContainer(vec, argv + 1);
	PmergeMe::fillContainer(deq, argv + 1);

	std::cout << BLUE"Before:\t"R;
	PmergeMe::printContainer(vec);


	return 0;
}
