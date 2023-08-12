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

	for (it = container.begin(); it != container.end() && it - container.begin() < 10; ++it) {
		std::cout << *it << " ";
	}
	if (it != container.end()) {
		std::cout << "[...]";
	}
	std::cout << "\n";
}

template<typename container>
void PmergeMe::merge(typename container::iterator start, typename container::iterator mid,
					 typename container::iterator end) {
	container tmp;
	typename container::iterator left = start;
	typename container::iterator right = mid;

	while (left != mid || right != end) {
		if ((left != mid && *left < *right) || right == end) {
			tmp.push_back(*left);
			left++;
		} else {
			tmp.push_back(*right);
			*right++;
		}
	}

	typename container::const_iterator itTmp;
	for (itTmp = tmp.begin(); itTmp != tmp.end(); ++itTmp) {
		*start = *itTmp;
		start++;
	}
}

template<typename container>
void PmergeMe::binaryInsertionSort(container &S, container &pend) {
	typename container::iterator it;
	typename container::iterator pos;

	for (it = pend.begin(); it != pend.end(); ++it) {
		pos = PmergeMe::findPos<container>(*it, S.begin(), S.end());
		S.insert(pos, *it);
	}
}

template<typename container>
typename container::iterator PmergeMe::findPos(int value, typename container::iterator start,
											   typename container::iterator end) {
	if (start == end)
		return start;
	if (end - start == 1) {
		if (value < *start)
			return start;
		else
			return end;
	}
	typename container::iterator mid;

	mid = start + ((end - start) / 2);
	if (*mid > value) {
		return PmergeMe::findPos<container>(value, start, mid);
	}
	return PmergeMe::findPos<container>(value, mid, end);
}

template<typename container>
void PmergeMe::mergeSort(typename container::iterator start, typename container::iterator end) {
	if (end - start <= 1)
		return;
	typename container::iterator mid;

	mid = start + ((end - start) / 2);
	PmergeMe::mergeSort<container>(start, mid);
	PmergeMe::mergeSort<container>(mid, end);
	PmergeMe::merge<container>(start, mid, end);
}

template<typename container>
void PmergeMe::FJMIS(container &c) {
	container pend;
	container S;
	typename container::iterator mid = c.begin() + ((c.end() - c.begin()) / 2);
	typename container::iterator it;
	int tmp, straggler = -1;

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

	PmergeMe::mergeSort<container>(S.begin(), S.end());
	PmergeMe::binaryInsertionSort(S, pend);

	c = S;
}
