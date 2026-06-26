/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:02:36 by aybelaou          #+#    #+#             */
/*   Updated: 2026/04/20 17:02:37 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern() {}

AForm*	Intern::createShrubbery(const std::string& target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::createRobotomy(const std::string& target) const
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::createPresidential(const std::string& target) const
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target) const
{
	typedef AForm* (Intern::*t_creator)(const std::string&) const;

	static const std::string	names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	static const t_creator	creators[3] = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*creators[i])(target));
		}
	}
	std::cout << "Intern couldn't create " << formName
		<< " because form name is unknown." << std::endl;
	return (0);
}
