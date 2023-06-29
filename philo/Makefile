# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 10:44:06 by lboulatr          #+#    #+#              #
#    Updated: 2023/06/29 08:30:15 by lboulatr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED			            			= \033[1;31m
GREEN								= \033[1;32m
PURPLE								= \033[1;35m
BLUE			        			= \033[0;36m
EOC									= \033[0m

NAME								= philo

BUILD_DIR							= build/

HEADER_DIR							= header/
HEADER_FILE							= philo.h

DIR									= src/
SRC									= 	main.c\
										\
										utils/ft_utils.c\
										utils/ph_parse_args.c\
										utils/ph_get_actual_time.c\
										\
										philo/ph_init.c\
										philo/ph_create_philos.c\
										philo/ph_thread_manager.c\
										philo/ph_actions.c\
										philo/ph_printing.c\
										philo/ph_death.c\
										philo/ph_end.c\

OBJECTS								= $(SRC:%.c=$(BUILD_DIR)%.o)

CC									= cc

CFLAGS								= -Wall -Werror -Wextra

INCLUDE_THREAD						= -pthread

RM									= rm -rf

$(BUILD_DIR)%.o:					$(DIR)%.c $(HEADER_DIR)/$(HEADER_FILE) Makefile
										@mkdir -p $(@D)
										@echo "$(BLUE)[CREATE]$(EOC) $@"
										@$(CC) $(CFLAGS) -I$(HEADER_DIR) -I/usr/include -c $< -o $@

all:								mkbuild $(HEADER_DIR) $(NAME)

mkbuild:							
										@mkdir -p build
										

$(NAME):							$(OBJECTS)
										@$(CC) $(INCLUDE_THREAD) $(CFLAGS) $(OBJECTS) -o $(NAME)
										@echo "$(GREEN) ➤ $(NAME) is ready !$(EOC)"
										
clean:							
										@$(RM) $(OBJECTS)
										@$(RM) $(BUILD_DIR)
										@echo "$(RED)[CLEAN DONE] $(EOC)"

fclean:								clean
										@$(RM) $(NAME) 
										@echo "$(RED)[FCLEAN DONE] $(EOC)"

re:									fclean all
										@$(MAKE) all -silent
										@echo "$(PURPLE)[REMAKE DONE] $(EOC)"

.PHONY:								all $(NAME) clean fclean re mkbuild