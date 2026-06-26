# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 16:59:31 by aybelaou          #+#    #+#              #
#    Updated: 2025/07/04 15:35:30 by aybelaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -----------------------------------Colors------------------------------------

ORANGE				= \033[38;2;255;165;0m
BOLD_ORANGE			= \033[1;38;5;214m
BG_YELLOW			= \033[48;5;214m
MAGENTA				= \033[0;35m
BOLD_MAGENTA		= \033[1;35m
RESET				= \033[0m

# ---------------------------------Compilation---------------------------------

NAME			= MommyIWantToBeA
TESTER_NAME		= ex01_tester
CPP				= c++
CPPFLAGS		= -Wall -Wextra -Werror -std=c++98
LDFLAGS			=
RM				= rm -rf

OBJ_DIR			= obj
SRC				= main.cpp Bureaucrat.cpp Form.cpp
TESTER_SRC		= tester.cpp Bureaucrat.cpp Form.cpp

OBJ				= $(SRC:%.cpp=$(OBJ_DIR)/%.o)
TESTER_OBJ		= $(TESTER_SRC:%.cpp=$(OBJ_DIR)/%.o)

# -----------------------------------Rules-------------------------------------

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
	@echo "$(MAGENTA)Removing the executable...$(RESET)"
	@$(RM) $(NAME) $(TESTER_NAME)
	@echo "$(BOLD_MAGENTA)Executable removed!$(RESET)"

clean:
	@echo "$(MAGENTA)Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR)
	@echo "$(BOLD_MAGENTA)All object files cleaned!$(RESET)"

re: fclean all
	@echo "$(BG_YELLOW)Cleaned and rebuilt everything!$(RESET)"

.PHONY: all tester clean fclean re
