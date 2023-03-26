# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slakner <slakner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 01:23:39 by dcharala          #+#    #+#              #
#    Updated: 2023/03/16 21:27:43 by slakner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# tool macros
CXX := clang
CXXFLAGS := -Wall -Wextra -Werror

# path macros
OBJ_PATH := obj
SRC_PATH := src
INC_PATH := include
LFT_PATH := libft
MLX_PATH := MLX42


# library macros
LFT := libft.a
ifeq ($(shell uname), Darwin)
MLX := libmlx42_mac.a
MLXFLAGS := -L"${HOME}/.brew/opt/glfw/lib/" -lglfw
endif
ifeq ($(shell uname), Linux)
MLX := libmlx42_linux.a
MLXFLAGS := -ldl -lglfw -pthread -lm
endif

# compile macros
TARGET := cub3D

# src files & obj files
SRC := $(foreach x, $(SRC_PATH), $(wildcard $(addprefix $(x)/*,.c*)))
OBJ := $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))

# clean files list
DISTCLEAN_LIST := $(OBJ) \
CLEAN_LIST := $(TARGET) \
			  $(DISTCLEAN_LIST)

# default rule
default: makedir all

# non-phony targets
$(TARGET): $(OBJ)
	@make -C $(LFT_PATH)
	$(CXX) $(OBJ) $(LFT_PATH)/$(LFT) $(MLX_PATH)/$(MLX) $(MLXFLAGS) $(CXXFLAGS) -o $(TARGET)
	@echo "make: *** [cub3D] Success"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c*
	$(CXX) $(CXXFLAGS) -I$(INC_PATH) -I$(MLX_PATH)/$(INC_PATH) -c $< -o $@

# phony rules
.PHONY: makedir
makedir:
	@mkdir -p $(OBJ_PATH)

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	@rm -f $(CLEAN_LIST)
	@echo "make: *** [cub3D] Cleaned" $(CLEAN_LIST)
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LFT_PATH)/

.PHONY: distclean
distclean:
	@rm -f $(DISTCLEAN_LIST)
	@echo "make: *** [cub3D] Cleaned" $(CLEAN_LIST)
	@rm -rf $(OBJ_PATH)
	@make fclean -C $(LFT_PATH)/
	@rm -f $(LFT_PATH)/$(LFT)

.PHONY: fclean
fclean:
	@rm -f $(DISTCLEAN_LIST)
	@echo "make: *** [cub3D] Cleaned" $(CLEAN_LIST)
	@rm -rf $(OBJ_PATH)
	@make fclean -C $(LFT_PATH)/
	@rm -f $(LFT_PATH)/$(LFT)

.PHONY: re
re: fclean makedir all
