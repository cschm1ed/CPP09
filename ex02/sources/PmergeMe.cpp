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
	(void) other;
	std::cout << "PmergeMe copy constructor called\n";
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
	(void) rhs;
	return *this;
}

bool PmergeMe::checkArgs(char **argv) {
	for (int i = 0; argv[i]; ++i) {
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
	if (n < 0 || n > std::numeric_limits<int>::max() || static_cast<int>(n) != n)
		return (false);

	return true;
}

void PmergeMe::mergeSort(std::vector<std::vector<int> >::iterator start, std::vector<std::vector<int> >::iterator end) {
	if (end - start <= 1)
		return ;
	std::vector<std::vector<int> >::iterator mid = start + ((end - start) / 2);

	mergeSort(start, mid);
	mergeSort(mid, end);
	merge(start, mid, end);
}

void PmergeMe::merge(std::vector<std::vector<int> >::iterator start, std::vector<std::vector<int> >::iterator mid, std::vector<std::vector<int> >::iterator end) {
	std::vector<std::vector<int> > tmp;
	std::vector<std::vector<int> >::iterator left = start;
	std::vector<std::vector<int> >::iterator right = mid;

	while (left != mid || right != end) {
		if ((left != mid && (*left)[1] < (*right)[1]) || right == end) {
			tmp.push_back(*left);
			left ++;
		}
		else {
			tmp.push_back(*right);
			*right ++;
		}
	}
	std::vector<std::vector<int> >::iterator itTmp;
	for (itTmp = tmp.begin(); itTmp != tmp.end(); ++itTmp) {
		*start = *itTmp;
		start ++;
	}
}
