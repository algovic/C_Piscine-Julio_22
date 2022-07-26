TARGET  = rush-02

OBJS    = main.o ft_find_in_dic.o ft_print_value.o

CFLAGS  = -Wall -Werror -Wextra

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

$(TARGET) : $(OBJS)
	gcc $(CFLAGS)  $(OBJS) -o $(TARGET)

%.o : %.c
	gcc -c $(CFLAGS)  $< -o $@

.PHONY: clean fclean
clean:
	@rm -f *.o $(TARGET)

fclean: clean
	@rm -f $(NAME)


