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
#include <sstream>
#include <cstring>

#define MAX_PRICE 1000
#define MIN_PRICE 0
#define DATABASE "data.csv"

bool fetchDates(std::string const & filename, BitcoinExchange & exchange);
void isValidDate(const char *str, int &errorCode);
void isValidPrice(const float price, int &errorCode);
void printError(const int errorCode, const char *line);

int main(int argc, char **argv) {
	BitcoinExchange*	coinBase = nullptr;
	if (argc != 2) {
		std::cerr << SYS_MSG <<  RED"ERROR: wrong amount of arguments\n"R;
		return 1;
	}

	try {
		coinBase = new BitcoinExchange(DATABASE);
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
	std::string line;
	char date[11];
	int numCharsRead, errorCode = 0;
	float numericValue = -1;

	if (!infile) {
		std::cerr << SYS_MSG << RED << "ERROR: could not open file 'data.csv'\n"R;
		return false;
	}
	while (getline(infile, line)) {
		if (sscanf(line.c_str(), "%11s | %f%n", date, &numericValue, &numCharsRead) == 2) {
			if (numCharsRead != static_cast<int>(line.length())){
				errorCode = 1;
			}
			isValidDate(date, errorCode);
			isValidPrice(numericValue, errorCode);
		}
		else
			errorCode = 1;
		if (errorCode) {
			printError(errorCode, line.c_str());
		}
		else {
			float realValue = exchange.getPrice(date);
			std::cout << date << " => " << numericValue << " = " << realValue << "\n";
		}
	}
	return true;
}

void printError(const int errorCode, const char *line) {
	std::string errorMessages[] = {"bad input => ", "invalid date => ", "not a positive number =>", "too large a number =>"};

	std::cout << RED"Error: "R << errorMessages[errorCode - 1] << line << "\n";
}

void isValidPrice(const float price, int & errorCode) {
	if (price < 0 || price > 1000)
		errorCode = 3;
}

void isValidDate(const char *date, int &errorCode) {
	int year, month, day, charsRead;

	if (date[11] || !date[10]) {
		errorCode = 1;
		return ;
	}
	if (sscanf(date, "%4d-%2d-%2d%n", &year,  &month, &day, &charsRead) != 3) {
		errorCode = 2;
		return ;
	}
	if (charsRead != 10) {
		std::cout << "chars read";
		errorCode = 2;
		return ;
	}
	if (year < 0 || year > 9999) {
		errorCode = 2;
		return ;
	}
	if (month < 0 || month > 31) {
		errorCode = 2;
		return ;
	}
	if (day < 0 || day > 31) {
		errorCode = 2;
		return ;
	}
}
