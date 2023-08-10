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
#include <cstdlib>

bool fetchDates(std::string const & filename, BitcoinExchange & exchange);

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

	if (fetchDates(argv[1], *coinBase) == false) {
		delete coinBase;
		return 1;
	}

	delete	coinBase;
	return 0;
}

bool fetchDates(std::string const & filename, BitcoinExchange & exchange) {
	std::ifstream infile(filename, std::ios_base::in);
	std::string line, date, value;
	float realValue;
	char *pEnd;

	if (!infile) {
		std::cerr << SYS_MSG << RED << "ERROR: could not open file 'data.csv'\n"R;
		return false;
	}
	while (getline(infile, line)) {
		date = line.substr(0, line.find(' '));
		value = line.substr(line.find('|') + 1);
		realValue = exchange.getPrice(date) * strtof(value.c_str(), &pEnd);
		std::cout << date <<  " => " << strtof(value.c_str(), &pEnd) << " = " << realValue << "\n";
	}
	return true;
}

bool isValidDate(std::string const & date) {

	return true;
}

bool isValidPrice(char const *pEnd, float const numPrice, std::string const & price) {
	if (*pEnd) {
		std::cout << YELLOW"bad input => " << price << "\n"R;
		return false;
	}
	if (numPrice < 0) {
		std::cout << YELLOW"Error: not a positive number.\n"R;
		return false;
	}
	return true;
}
