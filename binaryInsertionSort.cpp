/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaryInsertionSort.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 10:16:07 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/12 10:16:07 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

void populateS(std::vector<int> &s) {
	s.push_back(11);
	s.push_back(13);
	s.push_back(15);
	s.push_back(19);
	s.push_back(23);
	s.push_back(30);
}

void populatepend(std::vector<int> &pend) {
	pend.push_back(3);
	pend.push_back(1);
	pend.push_back(5);
	pend.push_back(4);
	pend.push_back(10);
	pend.push_back(11);
}

void printVector(std::vector<int> v) {
	std::vector<int>::const_iterator it;

	for (it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << ", ";
	}
}

std::vector<int>::iterator findPos(int value, std::vector<int>::iterator start, std::vector<int>::iterator end) {
	if (start == end)
		return start;
	if (end - start == 1) {
		if (value < *start)
			return start;
		else
			return end;
	}
	std::vector<int>::iterator mid;

	mid = start + ((end - start) / 2);
	if (*mid > value) {
		return findPos(value, start, mid);
	}
	return findPos(value, mid, end);
}

void binaryInsertionSort(std::vector<int> & S, std::vector<int> & pend) {
	std::vector<int>::iterator it;
	std::vector<int>::iterator pos;

	for (it = pend.begin(); it != pend.end(); ++it) {
		pos = findPos(*it, S.begin(), S.end());
		S.insert(pos, *it);
	}
}

int main() {
	std::vector<int> S;
	std::vector<int> pend;

	populateS(S);
	populatepend(pend);
	std::cout << "before: ";
	printVector(S);
	printVector(pend);
	std::cout << "\n";
	binaryInsertionSort(S, pend);
	std::cout << "after: ";
	printVector(S);
	return 0;
}
