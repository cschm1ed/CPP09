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

#ifndef CPP09_PMERGEME_HPP
#define CPP09_PMERGEME_HPP

#include <iostream>
#include <colors.hpp>
#include <vector>
#include <deque>

class PmergeMe {

public:

	PmergeMe(PmergeMe const &other);

	~PmergeMe();

	PmergeMe &operator=(PmergeMe const &rhs);

	static bool checkArgs(char **argv);

	template<typename T>
	static void fillContainer(T &container, char **argv);

	template<typename T>
	static void printContainer(const T &container);

	template<typename T>
	static void FJMIS(T & cont);

	template<typename T>
	static long measureSortTime(T & cont);

	static void merge(std::vector<std::vector<int> >::iterator start, std::vector<std::vector<int> >::iterator mid, std::vector<std::vector<int> >::iterator end);

	static void mergeSort(std::vector<std::vector<int> >::iterator start, std::vector<std::vector<int> >::iterator end);

	template<typename T>
	static void binaryInsertionSort(T & dst, T & src);

private:

	template<typename T>
	static typename T::iterator findLocation(int val, typename T::iterator start, typename T::iterator end);

	static bool isInt(char *str);

	PmergeMe();

};


#endif //CPP09_PMERGEME_HPP
