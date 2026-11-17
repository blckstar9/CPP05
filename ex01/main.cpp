/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:13:25 by aybelaou          #+#    #+#             */
/*   Updated: 2026/04/20 16:13:25 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cassert>

static void testInvalidGrades(int signGrade, int execGrade)
{
	bool caught = false;
	try
	{
		Form invalid("Invalid", signGrade, execGrade);
	}
	catch (const Form::GradeTooHighException& e)
	{
		assert(signGrade < 1 || execGrade < 1);
		caught = true;
		std::cout << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException& e)
	{
		assert(signGrade > 150 || execGrade > 150);
		caught = true;
		std::cout << e.what() << std::endl;
	}
	assert(caught);
}

int main()
{
	std::cout << "--- ex01 main tests ---" << std::endl;
	testInvalidGrades(0, 80);
	testInvalidGrades(151, 80);
	testInvalidGrades(100, 0);
	testInvalidGrades(100, 151);
	Form highest("Highest", 1, 1);
	Form lowest("Lowest", 150, 150);
	assert(highest.getGradeToSign() == 1 && highest.getGradeToExecute() == 1);
	assert(lowest.getGradeToSign() == 150 && lowest.getGradeToExecute() == 150);

	Bureaucrat exact("Exact", 100);
	Bureaucrat insufficient("Insufficient", 101);
	Form tax("TaxForm", 100, 80);
	assert(!tax.getIsSigned());
	bool caught = false;
	try
	{
		tax.beSigned(insufficient);
	}
	catch (const Form::GradeTooLowException& e)
	{
		caught = true;
		std::cout << e.what() << std::endl;
	}
	assert(caught && !tax.getIsSigned());
	insufficient.signForm(tax);
	assert(!tax.getIsSigned());
	exact.signForm(tax);
	assert(tax.getIsSigned());
	std::cout << tax << std::endl;
	std::cout << "All ex01 tests passed." << std::endl;
	return (0);
}
