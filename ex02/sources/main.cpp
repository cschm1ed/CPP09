/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:00:14 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/11 14:00:14 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <colors.hpp>
#include <PmergeMe.hpp>
#include <vector>
#include <deque>

int main(int argc, char **argv) {
	std::vector<int> vec;
	std::deque<int> deq;

	if (argc == 1) {
		std::cout << SYS << RED"ERROR: please provide arguments to be sorted\n"R;
	}
	if (PmergeMe::checkArgs(argv) == false) {
		return 1;
	}


}
