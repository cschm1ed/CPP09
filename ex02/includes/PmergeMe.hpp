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

class PmergeMe {

public:

	PmergeMe(PmergeMe const &other);

	~PmergeMe();

	PmergeMe &operator=(PmergeMe const &rhs);

	static bool checkArgs(char **argv);

private:

	static bool isInt(char *str);

	PmergeMe();

};


#endif //CPP09_PMERGEME_HPP
