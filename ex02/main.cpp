/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:01:45 by aybelaou          #+#    #+#             */
/*   Updated: 2026/04/20 17:01:47 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cassert>
#include <fstream>

static void testForm(AForm& form, int signGrade, int execGrade)
{
	std::cout << "Testing " << form << std::endl;
	assert(form.getGradeToSign() == signGrade);
	assert(form.getGradeToExecute() == execGrade);
	assert(!form.getIsSigned());
	Bureaucrat boss("Boss", 1);
	Bureaucrat signer("ExactSigner", signGrade);
	Bureaucrat weakSigner("WeakSigner", signGrade + 1);
	Bureaucrat executor("ExactExecutor", execGrade);
	Bureaucrat weakExecutor("WeakExecutor", execGrade + 1);
	bool caught = false;
	try
	{
		form.execute(boss);
	}
	catch (const AForm::FormNotSignedException& e)
	{
		caught = true;
		std::cout << e.what() << std::endl;
	}
	assert(caught);
	boss.executeForm(form);
	weakSigner.signForm(form);
	assert(!form.getIsSigned());
	signer.signForm(form);
	assert(form.getIsSigned());
	caught = false;
	try
	{
		form.execute(weakExecutor);
	}
	catch (const AForm::GradeTooLowException& e)
	{
		caught = true;
		std::cout << e.what() << std::endl;
	}
	assert(caught);
	weakExecutor.executeForm(form);
	form.execute(executor);
	executor.executeForm(form);
}

int main()
{
	std::cout << "--- ex02 main tests ---" << std::endl;
	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robo("Bender");
	PresidentialPardonForm pardon("Arthur Dent");
	testForm(shrub, 145, 137);
	testForm(robo, 72, 45);
	testForm(pardon, 25, 5);
	std::ifstream trees("home_shrubbery");
	assert(trees.is_open() && trees.peek() != std::ifstream::traits_type::eof());

	Bureaucrat executor("Robotomist", 45);
	for (int i = 0; i < 10; ++i)
		executor.executeForm(robo);
	std::cout << "All ex02 tests passed." << std::endl;
	return (0);
}
