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

int	main(void)
{
	std::cout << "--- ex03 main tests ---" << std::endl;
	Intern		intern;
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	mid("Mid", 70);
	AForm*		forms[4];

	forms[0] = intern.makeForm("shrubbery creation", "garden");
	forms[1] = intern.makeForm("robotomy request", "Bender");
	forms[2] = intern.makeForm("presidential pardon", "Arthur Dent");
	forms[3] = intern.makeForm("not existing", "nobody");
	for (int i = 0; i < 4; ++i)
	{
		if (forms[i])
		{
			mid.signForm(*forms[i]);
			boss.signForm(*forms[i]);
			boss.executeForm(*forms[i]);
			delete forms[i];
		}
	}
	return (0);
}
