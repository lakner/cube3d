# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile_Unix.mk                                   :+:      :+:    :+:    #
#                                                      +:+                     #
#    By: W2Wizard <w2.wizzard@gmail.com>              +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/26 21:36:38 by W2Wizard      #+#    #+#                  #
#    Updated: 2023/01/08 01:57:47 by dcharala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

#//= Make Rules =//#
$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

# Convert shaders to .c files
$(SRC_DIR)/mlx_%_shader.c: $(SHADER_DIR)/default.%
	@bash tools/compile_shader.sh $< > $@

clean:
	@rm -f $(OBJS) $(SHDR)

fclean: clean
	@rm -f $(NAME)
