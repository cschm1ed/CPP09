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
	static double FJMIS(T & cont);

	template<typename T>
	static long measureSortTime(T & cont);

	static void mergeSortVector(std::vector<std::vector<int> > & vec);
	static void binaryInsertionSortVector(std::vector<int> & dst, std::vector<int> & src);

	friend std::ostream &operator<<(std::ostream &os, const PmergeMe &me);

private:

	static bool isInt(char *str);

	PmergeMe();

};


#endif //CPP09_PMERGEME_HPP
