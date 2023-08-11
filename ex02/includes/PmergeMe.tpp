/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:29:41 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/11 14:29:44 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

template<typename T>
void PmergeMe::fillContainer(T &container, char **argv) {
	int n;
	char *pEnd;

	for (int i = 0; argv[i]; ++i) {
		n = static_cast<int>(strtod(argv[i], &pEnd));
		container.push_back(n);
	}
}

template<typename T>
void PmergeMe::printContainer(const T &container) {
	std::vector<int>::const_iterator it;

	for (it = container.begin(); it != container.end() && it - container.begin() < 5; ++it) {
		std::cout << *it << " ";
	}
	if (it != container.end()) {
		std::cout << "[...]";
	}
	std::cout << "\n";
}

template<typename T>
long PmergeMe::measureSortTime(T &cont) {
	time_t start, end;

	time(&start);
	FJMIS(cont);
	time(&end);
	return end - start;
}

template<typename T>
double PmergeMe::FJMIS(T &cont) {
	int straggler = -1;
	int tmp;
	std::vector<std::vector<int> > pairs;
	typename T::iterator it;
	typename T::const_iterator ite;

	if (cont.size() % 2) {
		straggler = cont.back();
		cont.pop_back;
	}
	for (it = cont.begin(); it != ite; it += 2) {
		pairs[it - cont.begin() / 2][0] = *it;
		pairs[it - cont.begin() / 2][1] = *(it + 1);
	}

	ite = pairs.end();
	for (it = pairs.begin(); it != ite; ++it) {
		if ((*it)[0] > (*it)[1]) {
			tmp = (*it)[0];
			(*it)[0] = (*it)[1];
			(*it)[1] = tmp;
		}
	}

	PmergeMe::mergeSortVector(pairs);

	std::vector<int> S;
	std::vector<int> pend;

	ite = pairs.end();
	for (it = pairs.begin(); it != ite; ++it) {
		S.push_back((*it)[1]);
		pend.push_back((*it)[0]);
	}
	if (straggler != -1)
		pend.push_back(straggler);
	PmergeMe::binaryInsertionSortVector(S, pend);
}

void PmergeMe::binaryInsertionSortVector(std::vector<int> &dst, std::vector<int> &src) {
	std::vector<int>::const_iterator itSrc;
	std::vector<int>::iterator itDest;

	for (itSrc = src.begin(); itSrc != src.end(); ++itSrc) {
		int insert = *itSrc;

		itDest = dst.begin();
		while (*itDest < insert) {
			itDest += itDest - dst.end();

		}
	}
}

void PmergeMe::mergeSortVector(std::vector<std::vector<int> > &vec) {

}
