/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:52:54 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/10 14:52:57 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP09_BITCOINEXCHANGE_HPP
#define CPP09_BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <colors.hpp>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <cstring>

class BitcoinExchange {

public:

	BitcoinExchange(std::string const & databaseFilename);

	BitcoinExchange(BitcoinExchange const &other);

	~BitcoinExchange();

	BitcoinExchange &operator=(BitcoinExchange const &rhs);

	class openFileFailure : std::exception {
		const char *what() const _NOEXCEPT;
	};

	float getPrice(std::string const & date);

private:
	BitcoinExchange();
	std::map<std::string, float>	_db;

	void readFile(std::string const & filename);


};


#endif //CPP09_BITCOINEXCHANGE_HPP
