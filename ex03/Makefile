# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/20 16:13:25 by aybelaou          #+#    #+#              #
#    Updated: 2026/04/20 16:13:25 by aybelaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ORANGE				= \033[38;2;255;165;0m
BOLD_ORANGE			= \033[1;38;5;214m
BG_YELLOW			= \033[48;5;214m
MAGENTA				= \033[0;35m
BOLD_MAGENTA		= \033[1;35m
RESET				= \033[0m

NAME				= AtLeastThisBeatsCoffee
CPP					= c++
CPPFLAGS			= -Wall -Wextra -Werror -std=c++98
LDFLAGS				=
RM					= rm -rf

OBJ_DIR				= obj
SRC					= main.cpp Bureaucrat.cpp AForm.cpp \
					ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
					PresidentialPardonForm.cpp Intern.cpp

OBJ					= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo -e "$(ORANGE)Building $(NAME)...$(RESET)"
	@$(CPP) $(OBJ) $(CPPFLAGS) $(LDFLAGS) -o $(NAME)
	@echo -e "$(BOLD_ORANGE)$(NAME) is ready!$(RESET)"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo -e "$(ORANGE)Compiling $<...$(RESET)"
	@$(CPP) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

fclean: clean
	@echo -e "$(MAGENTA)Removing executables...$(RESET)"
	@$(RM) $(NAME)
	@echo -e "$(BOLD_MAGENTA)Executables removed!$(RESET)"

clean:
	@echo -e "$(MAGENTA)Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR) *.o
	@echo -e "$(BOLD_MAGENTA)All object files cleaned!$(RESET)"

re: fclean all
	@echo -e "$(BG_YELLOW)Cleaned and rebuilt everything!$(RESET)"

.PHONY: all clean fclean re
