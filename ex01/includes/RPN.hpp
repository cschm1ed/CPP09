/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:04:39 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/11 12:04:44 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP09_RPN_HPP
#define CPP09_RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <colors.hpp>

class RPN {

public:
	RPN();

	RPN(RPN const &other);

	~RPN();

	RPN &operator=(RPN const &rhs);

	void addToken(std::string const &token);

	std::string getResult() const;

	class InvalidTokenException : public std::exception {
		const char *what() const _NOEXCEPT;
	};

	class DivisionByZeroException : public std::exception {
		const char *what() const _NOEXCEPT;
	};

	class InvalidOperatorAdd : public std::exception {
		const char *what() const _NOEXCEPT;
	};

private:

	bool tokenIsValid(std::string const &token, bool &isOperator) const;

	std::stack<double> _stack;

};


#endif //CPP09_RPN_HPP
