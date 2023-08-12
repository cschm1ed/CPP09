/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:01:15 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/12 10:01:15 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

void merge(std::vector<int>::iterator start, std::vector<int>::iterator mid, std::vector<int>::iterator end) {
	std::vector<int> tmp;
	std::vector<int>::iterator left = start;
	std::vector<int>::iterator right = mid;

	while (left != mid || right != end) {
		if ((left != mid && *left < *right) || right == end) {
			tmp.push_back(*left);
			left ++;
		}
		else {
			tmp.push_back(*right);
			*right ++;
		}
	}

	std::vector<int>::const_iterator itTmp;
	for (itTmp = tmp.begin(); itTmp != tmp.end(); ++itTmp) {
		*start = *itTmp;
		start ++;
	}
}

void mergeSort(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	if (end - start <= 1)
		return ;
	std::vector<int>::iterator mid;

	mid = start + ((end - start) / 2);
	mergeSort(start, mid);
	mergeSort(mid, end);
	merge(start, mid, end);
}

void	printVec(std::vector<int> const & vec) {
	std::vector<int>::const_iterator it;
	std::vector<int>::const_iterator ite = vec.end();

	for (it = vec.begin(); it != ite; ++it) {
		std::cout << *it << ", ";
	}
	std::cout << "\n";
}

int main() {
	std::vector<int> vec;

	srand(time(NULL));
	for (int i = 0; i < 100; ++i) {
		vec.push_back(rand() % 1000);
	}
	std::cout << "---------------before---------------\n";
	printVec(vec);
	mergeSort(vec.begin(), vec.end());
	std::cout << "---------------after----------------\n";
	printVec(vec);

	return 0;
}
