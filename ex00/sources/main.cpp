/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:51:10 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/10 14:51:10 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <BitcoinExchange.hpp>

int main(int argc, char **argv) {
	BitcoinExchange*	coinBase = nullptr;
	if (argc != 2) {
		std::cerr << SYS_MSG <<  RED"ERROR: wrong amount of arguments\n"R;
		return 1;
	}

	try {
		coinBase = new BitcoinExchange("data.csv");
	} catch (std::exception & e) {
		std::cerr << SYS_MSG << RED << e.what() << "\n"R;
		delete coinBase;
		return 1;
	}

	delete	coinBase;
	return 0;
}
