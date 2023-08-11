/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:04:39 by cschmied          #+#    #+#             */
/*   Updated: 2023/08/11 12:05:07 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN() {
}

RPN::~RPN() {
}

RPN::RPN(RPN const &other) {
	_stack = other._stack;
	std::cout << "RPN copy constructor called\n";
}

RPN &RPN::operator=(RPN const &rhs) {
	if (this != &rhs) {
		_stack = rhs._stack;
	}
	return *this;
}

std::string RPN::getResult() const {
	std::stringstream ss;
	std::string ret;

	if (_stack.size() > 1) {
		return YELLOW"Error: No definitive result."R;
	} else if (_stack.size() == 0) {
		return YELLOW"Error: stack is empty"R;
	}
	ss << _stack.top();
	ss >> ret;
	return ret;
}

bool RPN::tokenIsValid(const std::string &token, bool &isOperator) const {
	if (token.length() != 1) {
		return false;
	}
	if (isdigit(token[0])) {
		return true;
	}
	isOperator = true;
	return true;
}

void RPN::addToken(const std::string &token) {
	bool isOperator = false;
	char *pEnd;

	if (!tokenIsValid(token, isOperator)) {
		throw InvalidTokenException();
	}
	if (isOperator && _stack.size() < 2) {
		throw InvalidOperatorAdd();
	}
	if (isOperator) {
		double b = _stack.top();
		_stack.pop();
		double a = _stack.top();
		_stack.pop();
		switch (token[0]) {
			case '*':
				_stack.push(a * b);
				return;
			case '/':
				if (b == 0) {
					throw DivisionByZeroException();
				}
				_stack.push(a / b);
				return;
			case '-':
				_stack.push(a - b);
				return;
			case '+':
				_stack.push(a + b);
				return;
			default:
				throw InvalidTokenException();
		}
	} else {
		_stack.push(strtod(token.c_str(), &pEnd));
	}
}

const char *RPN::InvalidTokenException::what() const throw() {
	return "Error: tried to add invalid token.";
}

const char *RPN::DivisionByZeroException::what() const throw() {
	return "Error: attempted division by zero.";
}

const char *RPN::InvalidOperatorAdd::what() const throw() {
	return "Error: tried to add operate on only one number.";
}
