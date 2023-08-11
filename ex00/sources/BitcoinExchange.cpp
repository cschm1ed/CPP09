/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:52:54 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/10 14:53:07 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange() {
	std::cout << "BitcoinExchange default constructor called\n";
}

BitcoinExchange::BitcoinExchange(std::string const &databaseFilename) {
	std::cout << BLUE"BitcoinExchange constructor called\n"R;
	readFile(databaseFilename);
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << MAGENTA"BitcoinExchange default destructor called\n"R;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) : _db(other._db) {
	std::cout << "BitcoinExchange copy constructor called\n";
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	if (&rhs != this) {
		_db = rhs._db;
	}
	return *this;
}

const char *BitcoinExchange::openFileFailure::what() const throw() {
	return "ERROR: could not open file 'data.csv'\n";
}

void BitcoinExchange::readFile(std::string const &filename) {
	std::string line, date, price;
	char *pEnd;
	std::ifstream ifstream(filename, std::ios_base::in);

	if (!ifstream) {
		throw openFileFailure();
	}
	while (std::getline(ifstream, line)) {
		date = line.substr(0, line.find(','));
		price = line.substr(line.find(',') + 1);
		_db[date] = strtof(price.c_str(), &pEnd);
	}
}

float BitcoinExchange::getPrice(const std::string &date) {
	std::map<std::string, float>::const_iterator it = _db.upper_bound(date);

	if (it != _db.begin()) {
		it--;
	}
	return it->second;
}
