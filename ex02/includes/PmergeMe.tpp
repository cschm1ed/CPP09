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

template<typename Container>
void PmergeMe::printContainer(const Container &container) {
	typename Container::const_iterator it;

	for (it = container.begin(); it != container.end() && it - container.begin() < 10; ++it) {
		std::cout << *it << " ";
	}
	if (it != container.end()) {
		std::cout << "[...]";
	}
	std::cout << "\n";
}


template<typename Container>
void PmergeMe::binaryInsertionSort(Container &S, Container &pend) {
	typename Container::iterator it;
	typename Container::iterator pos;

	for (it = pend.begin(); it != pend.end(); ++it) {
		pos = PmergeMe::findPos<Container>(*it, S.begin(), S.end());
		S.insert(pos, *it);
	}
}

template<typename Container>
typename Container::iterator PmergeMe::findPos(int value, typename Container::iterator start,
											   typename Container::iterator end) {
	if (start == end)
		return start;
	if (end - start == 1) {
		if (value < *start)
			return start;
		else
			return end;
	}
	typename Container::iterator mid;

	mid = start + ((end - start) / 2);
	if (*mid > value) {
		return PmergeMe::findPos<Container>(value, start, mid);
	}
	return PmergeMe::findPos<Container>(value, mid, end);
}

template<typename Container>
void PmergeMe::merge(typename Container::iterator start, typename Container::iterator mid,
					 typename Container::iterator end) {
	Container tmp;
	typename Container::iterator left = start;
	typename Container::iterator right = mid;

	while (left != mid || right != end) {
		if ((left != mid && *left < *right) || right == end) {
			tmp.push_back(*left);
			left++;
		} else {
			tmp.push_back(*right);
			*right++;
		}
	}

	typename Container::const_iterator itTmp;
	for (itTmp = tmp.begin(); itTmp != tmp.end(); ++itTmp) {
		*start = *itTmp;
		start++;
	}
}

template<typename Container>
void PmergeMe::mergeSort(typename Container::iterator start, typename Container::iterator end) {
	if (end - start <= 1)
		return;
	typename Container::iterator mid;

	mid = start + ((end - start) / 2);
	PmergeMe::mergeSort<Container>(start, mid);
	PmergeMe::mergeSort<Container>(mid, end);
	PmergeMe::merge<Container>(start, mid, end);
}

template<typename Container>
void PmergeMe::FJMIS(Container &c) {
	Container S,pend;
	typename Container::iterator mid = c.begin() + ((c.end() - c.begin()) / 2);
	typename Container::iterator it;
	int tmp, straggler = -1;


	if (c.size() == 1)
		return ;
	if (c.size() % 2) {
		straggler = c.back();
		c.pop_back();
	}

	for (it = c.begin(); mid != c.end(); ++mid) {
		if (*mid > *it) {
			tmp = *mid;
			*mid = *it;
			*it = tmp;
		}
		it++;
	}

	mid = c.begin() + ((c.end() - c.begin()) / 2);
	if (straggler > 0) {
		pend.push_back(straggler);
	}

	for (it = c.begin(); it != mid; ++it) {
		S.push_back(*it);
	}

	while (mid != c.end()) {
		pend.push_back(*mid);
		mid++;
	}

	PmergeMe::mergeSort<Container>(S.begin(), S.end());
	PmergeMe::binaryInsertionSort(S, pend);

	c = S;
}
