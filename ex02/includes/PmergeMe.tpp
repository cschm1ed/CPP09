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

template<typename T>
void PmergeMe::binaryInsertionSortVector(T & dst, T & src) {
	typename T::const_iterator itSrc;
	typename T::iterator itDest;


}



template<typename T>
void PmergeMe::mergeSort(typename T::iterator start, typename T::iterator end) {
	if (end - start <= 1)
		return ;
	typename T::iterator mid = start + (end - start / 2);

	mergeSort(start, mid);
	mergeSort(mid, end);
	merge(start, mid, end);
}

template<typename T>
void PmergeMe::merge(typename T::iterator start, typename T::iterator mid, typename T::iterator end) {
	T tmp;
	typename T::iterator left = start;
	typename T::iterator right = mid;

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
	typename T::iterator itTmp;
	for (itTmp = tmp.begin(); itTmp != tmp.end(); ++itTmp) {
		*start = *itTmp;
		start ++;
	}
}
