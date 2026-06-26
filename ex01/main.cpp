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

int	main(void)
{
	std::cout << "--- ex01 main tests ---" << std::endl;
	try
	{
		Bureaucrat	boss("Boss", 1);
		Bureaucrat	junior("Junior", 120);
		Form		tax("TaxForm", 100, 80);

		std::cout << boss << std::endl;
		std::cout << junior << std::endl;
		std::cout << tax << std::endl;
		junior.signForm(tax);
		boss.signForm(tax);
		std::cout << tax << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form invalid("Broken", 0, 20);
		std::cout << invalid << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
