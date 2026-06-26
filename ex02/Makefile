# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/20 16:13:25 by aybelaou          #+#    #+#              #
#    Updated: 2026/04/20 17:01:49 by aybelaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ORANGE				= \033[38;2;255;165;0m
BOLD_ORANGE			= \033[1;38;5;214m
BG_YELLOW			= \033[48;5;214m
MAGENTA				= \033[0;35m
BOLD_MAGENTA		= \033[1;35m
RESET				= \033[0m

NAME				= NoYouNeedForm28B
TESTER_NAME			= ex02_tester
CPP					= c++
CPPFLAGS			= -Wall -Wextra -Werror -std=c++98
LDFLAGS				=
RM					= rm -rf

OBJ_DIR				= obj
SRC					= main.cpp Bureaucrat.cpp AForm.cpp \
					ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
					PresidentialPardonForm.cpp
TESTER_SRC			= tester.cpp Bureaucrat.cpp AForm.cpp \
					ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
					PresidentialPardonForm.cpp

OBJ					= $(SRC:%.cpp=$(OBJ_DIR)/%.o)
TESTER_OBJ			= $(TESTER_SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

tester: $(TESTER_NAME)

$(NAME): $(OBJ)
	@echo "$(ORANGE)Building $(NAME)...$(RESET)"
	@$(CPP) $(OBJ) $(CPPFLAGS) $(LDFLAGS) -o $(NAME)
	@echo "$(BOLD_ORANGE)$(NAME) is ready!$(RESET)"

$(TESTER_NAME): $(TESTER_OBJ)
	@echo "$(ORANGE)Building $(TESTER_NAME)...$(RESET)"
	@$(CPP) $(TESTER_OBJ) $(CPPFLAGS) $(LDFLAGS) -o $(TESTER_NAME)
	@echo "$(BOLD_ORANGE)$(TESTER_NAME) is ready!$(RESET)"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "$(ORANGE)Compiling $<...$(RESET)"
	@$(CPP) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

fclean: clean
	@echo "$(MAGENTA)Removing executables...$(RESET)"
	@$(RM) $(NAME) $(TESTER_NAME)
	@echo "$(BOLD_MAGENTA)Executables removed!$(RESET)"

clean:
	@echo "$(MAGENTA)Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR)
	@echo "$(BOLD_MAGENTA)All object files cleaned!$(RESET)"

re: fclean all
	@echo "$(BG_YELLOW)Cleaned and rebuilt everything!$(RESET)"

.PHONY: all tester clean fclean re
