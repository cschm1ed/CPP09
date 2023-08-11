/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:29:41 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/11 14:29:52 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <PmergeMe.hpp>

PmergeMe::PmergeMe() {
	std::cout << "PmergeMe default constructor called\n";
}

PmergeMe::~PmergeMe() {
	std::cout << "PmergeMe default destructor called\n";
}

PmergeMe::PmergeMe(PmergeMe const &other) {
	std::cout << "PmergeMe copy constructor called\n";
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
	return *this;
}

bool PmergeMe::checkArgs(char **argv) {
	for (int i = 1; argv[i]; ++i) {
		if (!isInt(argv[i])) {
			std::cout << RED"Error: invalid input --> " << argv[i] << "\n"R;
			return false;
		}
	}
	return true;
}

bool PmergeMe::isInt(char *str) {
	 char *pEnd;
	 double n = strtod(str, &pEnd);

	 if (*pEnd || !*str)
		 return false;
	 if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
		 return (false);
	 return true;
}
