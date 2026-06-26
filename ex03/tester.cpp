#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << "--- ex03 tester ---" << std::endl;
	Intern		intern;
	Bureaucrat	exec("Exec", 1);
	AForm*		form = intern.makeForm("robotomy request", "Marvin");

	if (form)
	{
		exec.signForm(*form);
		exec.executeForm(*form);
		delete form;
	}
	return (0);
}
