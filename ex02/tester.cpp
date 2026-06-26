#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	std::cout << "--- ex02 tester ---" << std::endl;
	try
	{
		Bureaucrat mid("Mid", 50);
		RobotomyRequestForm robot("Marvin");
		mid.executeForm(robot);
		mid.signForm(robot);
		mid.executeForm(robot);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
