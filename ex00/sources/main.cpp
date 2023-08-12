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
#include <cstring>

#define MAX_PRICE 1000
#define MIN_PRICE 0
#define DATABASE "data.csv"

static void isValidPrice(const float price, int &errorCode) {
	if (price < MIN_PRICE)
		errorCode = 3;
	if (price > MAX_PRICE)
		errorCode = 4;
}

static void isValidDate(const char *date, int &errorCode) {
	int year, month, day, charsRead;

	if (sscanf(date, "%4d-%d-%d%n", &year, &month, &day, &charsRead) != 3) {
		errorCode = 2;
		return;
	}
	if (charsRead != 10) {
		errorCode = 1;
		return;
	}
	if (year < 0 || year > 9999
		|| month < 0 || month > 31
		|| day < 0 || day > 31) {
		errorCode = 2;
	}
}

void printError(const int errorCode, const char *line) {
	std::string errorMessages[] = {"bad input => ", "invalid date => ", "not a positive number => ",
								   "too large a number => ", "line too long."};

	std::cout << RED"Error: "R << errorMessages[errorCode - 1];
	if (errorCode != 5)
		std::cout << line;
	std::cout << "\n";
}

bool fetchDates(std::string const &filename, BitcoinExchange &exchange) {
	std::ifstream infile(filename, std::ios_base::in);
	std::string line;
	char date[100];
	int numCharsRead, errorCode;
	float numericValue = -1;
	bool first = true;

	if (!infile) {
		std::cerr << SYS_MSG << RED << "ERROR: could not open file 'data.csv'\n"R;
		return false;
	}
	while (getline(infile, line)) {
		errorCode = 0;

		if (first && line == "date | value") {
			first = false;
			continue;
		}

		if (line.length() > 100) {
			printError(5, line.c_str());
			continue;
		}

		if (sscanf(line.c_str(), "%11s | %f%n", date, &numericValue, &numCharsRead) != 2
			|| numCharsRead != static_cast<int>(line.length())) {
			printError(1, line.c_str());
			continue;
		}

		isValidDate(date, errorCode);
		isValidPrice(numericValue, errorCode);
		if (errorCode) {
			printError(errorCode, line.c_str());
			continue;
		}

		float realValue = exchange.getPrice(date) * numericValue;
		std::cout << date << " => " << numericValue << " = " << realValue << "\n";
		first = false;
	}
	return true;
}

int main(int argc, char **argv) {
	BitcoinExchange *coinBase = nullptr;

	if (argc != 2) {
		std::cerr << SYS_MSG << RED"ERROR: wrong amount of arguments\n"R;
		return 1;
	}
	try {
		coinBase = new BitcoinExchange(DATABASE);
	} catch (std::exception &e) {
		std::cerr << SYS_MSG << RED << e.what() << "\n"R;
		delete coinBase;
		return 1;
	}
	if (!fetchDates(argv[1], *coinBase)) {
		delete coinBase;
		return 1;
	}

	delete coinBase;
	return 0;
}
