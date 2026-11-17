/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:25:37 by aybelaou          #+#    #+#             */
/*   Updated: 2026/02/13 17:57:44 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cassert>

static void testInvalidGrade(int grade)
{
	bool caught = false;
	try
	{
		Bureaucrat invalid("Invalid", grade);
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		assert(grade < 1);
		caught = true;
		std::cout << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		assert(grade > 150);
		caught = true;
		std::cout << e.what() << std::endl;
	}
	assert(caught);
}

int main()
{
	std::cout << "--- ex00 main tests ---" << std::endl;
	Bureaucrat bob("Bob", 42);
	bob.incrementGrade();
	assert(bob.getGrade() == 41);
	bob.decrementGrade();
	assert(bob.getGrade() == 42);
	std::cout << bob << std::endl;
	testInvalidGrade(0);
	testInvalidGrade(151);

	Bureaucrat top("Top", 1);
	Bureaucrat bottom("Bottom", 150);
	bool caught = false;
	try
	{
		top.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		caught = true;
		std::cout << e.what() << std::endl;
	}
	assert(caught && top.getGrade() == 1);
	caught = false;
	try
	{
		bottom.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		caught = true;
		std::cout << e.what() << std::endl;
	}
	assert(caught && bottom.getGrade() == 150);
	top.decrementGrade();
	bottom.incrementGrade();
	assert(top.getGrade() == 2 && bottom.getGrade() == 149);
	std::cout << "All ex00 tests passed." << std::endl;
	return (0);
}
