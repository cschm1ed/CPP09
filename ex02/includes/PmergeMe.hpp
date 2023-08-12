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

	template<typename container>
	static void FJMIS(container &c);


private:

	PmergeMe();

	template<typename container>
	static void mergeSort(typename container::iterator start, typename container::iterator end);

	template<typename container>
	static void
	merge(typename container::iterator start, typename container::iterator mid, typename container::iterator end);

	template<typename container>
	static typename container::iterator
	findPos(int value, typename container::iterator start, typename container::iterator end);

	template<typename container>
	static void binaryInsertionSort(container &S, container &pend);

	static bool isInt(char *str);

};


#endif //CPP09_PMERGEME_HPP
