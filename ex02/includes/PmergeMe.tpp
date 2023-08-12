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
void PmergeMe::FJMIS(T &cont) {
	int tmp, straggler = -1;
	std::vector<std::vector<int> >	pairs;
	std::vector<std::vector<int> >::iterator itPairs;
	typename T::iterator it;


	if (cont.size() % 2) {
		straggler = cont.back();
		cont.pop_back();
	}
	for (it = cont.begin(); it != cont.end(); it += 2) {
		std::vector<int> pair;
		pair.push_back(*it);
		pair.push_back(*(it + 1));
		pairs.push_back(pair);
	}

	for (itPairs = pairs.begin(); itPairs != pairs.end(); ++itPairs) {
		if ((*itPairs)[0] > (*itPairs)[1]) {
			tmp = (*itPairs)[0];
			(*itPairs)[0] = (*itPairs)[1];
			(*itPairs)[1] = tmp;
		}
	}

	mergeSort(pairs.begin(), pairs.end());

	T S;
	T pend;

	for (itPairs = pairs.begin(); itPairs != pairs.end(); ++itPairs) {
		S.push_back((*itPairs)[1]);
		pend.push_back((*itPairs)[0]);
	}
	if (straggler != -1)
		pend.push_back(straggler);
	PmergeMe::binaryInsertionSort(S, pend);
	if (straggler != -1) {
		S.insert(PmergeMe::findLocation<T>(straggler, S.begin(), S.end()), straggler);
	}
}

template<typename T>
void PmergeMe::binaryInsertionSort(T & dst, T & src) {
	typename T::const_iterator itSrc;
	typename T::iterator itDest;
	typename T::iterator pos;

	for (itSrc = src.begin(); itSrc != src.end(); ++itSrc) {
		pos = PmergeMe::findLocation<T>(*itSrc, dst.begin(), dst.end());
		dst.insert(pos, *itSrc);
	}
}

template<typename T>
typename T::iterator PmergeMe::findLocation(int value, typename T::iterator start, typename T::iterator end) {
	typename T::iterator mid;

	if (end - start <= 1)
		return start;
	if (*start <= value && *(start + 1)  >= value) {
		return start;
	}
	mid = start + ((end - start) / 2);
	if (*mid > value)
		return PmergeMe::findLocation<T>(value, start, mid);
	return PmergeMe::findLocation<T>(value, mid, end);
}
