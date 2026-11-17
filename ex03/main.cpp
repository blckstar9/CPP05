/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:02:42 by aybelaou          #+#    #+#             */
/*   Updated: 2026/04/20 17:02:43 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <cassert>

static void testCreatedForm(AForm& form)
{
	Bureaucrat boss("Boss", 1);
	Bureaucrat weak("WeakExecutor", form.getGradeToExecute() + 1);
	assert(!form.getIsSigned());
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
	boss.signForm(form);
	assert(form.getIsSigned());
	caught = false;
	try
	{
		form.execute(weak);
	}
	catch (const AForm::GradeTooLowException& e)
	{
		caught = true;
		std::cout << e.what() << std::endl;
	}
	assert(caught);
	weak.executeForm(form);
	boss.executeForm(form);
}

int main()
{
	std::cout << "--- ex03 main tests ---" << std::endl;
	Intern intern;
	const std::string names[3] = {
		"shrubbery creation", "robotomy request", "presidential pardon"
	};
	const std::string targets[3] = {"garden", "Bender", "Arthur Dent"};
	const std::string classNames[3] = {
		"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"
	};
	for (int i = 0; i < 3; ++i)
	{
		AForm* form = intern.makeForm(names[i], targets[i]);
		assert(form != 0 && form->getName() == classNames[i]);
		try
		{
			testCreatedForm(*form);
		}
		catch (...)
		{
			delete form;
			throw;
		}
		delete form;
	}
	AForm* unknown = intern.makeForm("not existing", "nobody");
	assert(unknown == 0);
	delete unknown;
	std::cout << "All ex03 tests passed." << std::endl;
	return (0);
}
