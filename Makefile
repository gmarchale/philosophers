NAME		=	philo

FILES		=	main.c\
				parser.c\
				ft_atoi.c\
				init.c\
				routine.c\
				utils.c\
				time.c\

SRCS		=	$(addprefix src/, $(FILES))

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

SANITIZE	=	-fsanitize=thread -g

### RULES ###

$(NAME):		$(OBJS)
				@echo "Compiling..."
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				@echo "Done."

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

sanitize:		$(OBJS)
				@echo "Compiling with sanitize..."
				@$(CC) $(CFLAGS) $(SANITIZE) $(OBJS) -o $(NAME)
				@echo "Done."

all:			$(NAME)

clean:
				@echo "Cleaning..."
				@rm -f $(OBJS)
				@echo "Cleaned."

fclean:			clean
				@rm -f $(NAME)

re :			fclean $(NAME)

.PHONY: sanitize all clean fclean re
