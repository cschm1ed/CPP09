/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:02:27 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/11 12:02:27 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <colors.hpp>
#include <RPN.hpp>
#include <sstream>

int main(int argc, char **argv) {
	std::string strToken;
	RPN rpn;

	if (argc != 2) {
		std::cout << SYS << RED"ERROR: please provide one argument to perform calculations\n"R;
		return 1;
	}

	std::stringstream ss(argv[1]);

	while (getline(ss, strToken, ' ')) {
		try {
			rpn.addToken(strToken);
		} catch (std::exception &e) {
			std::cerr << SYS_MSG << RED << e.what() << "\n"R;
			return 0;
		}
	}
	std::cout << rpn.getResult() << "\n"R;
	return 0;
}
