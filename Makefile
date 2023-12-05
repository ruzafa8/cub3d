# Project name
TARGET   = cub3D

# Directories
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin
LIBDIR   = lib

# Libraries
LIBMLX	:= ./$(LIBDIR)/MLX42
LIBFT	:= ./$(LIBDIR)/libft
LIBS	:= $(LIBMLX)/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a -L "$(HOME)/.brew/opt/glfw/lib/"

# Compiling flags
CC       = gcc
CFLAGS   = -Wextra -Wall -Werror -Wunreachable-code -Ofast
HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/

# Source files
SRC      = main.c\
		   init_data.c\
		   validator/validator_validate_args.c\
		   validator/validator_print_errors.c\
		   validator/validate_is_map.c\
		   validator/validate_colors.c\
		   validator/validate_player.c\
		   validator/validate_border.c\
		   parser/parser_parse.c\
		   parser/parser_free_cub3d.c\
		   parser/parser_map.c\
		   parser/parse_property.c\
		   parser/parse_read_map_fd.c\
		   utils/str_utils.c\
		   utils/str_spaces.c\
		   render/texture.c\

SOURCES  := $(addprefix $(SRCDIR)/, $(SRC))
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

RM       = rm -f

# Colors
RED      = \033[0;31m
GREEN    = \033[0;32m
YELLOW   = \033[0;33m
BLUE     = \033[0;34m
MAGENTA  = \033[0;35m
CYAN     = \033[0;36m
RESET    = \033[0m

.PHONY: all
all: libmlx libft $(BINDIR)/$(TARGET) title

$(BINDIR)/$(TARGET): $(OBJECTS) | $(BINDIR)
	@$(CC) -g $(OBJECTS) $(LIBS) $(HEADERS) -o $@
	@echo "Linking complete!"

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(RM) $(OBJECTS)
	@$(MAKE) -C $(LIBMLX) clean
	@$(MAKE) -C $(LIBFT)
	@echo "Cleanup complete!"

.PHONY: libmlx
libmlx:
	@$(MAKE) -C $(LIBMLX)

.PHONY: libft
libft:
	@$(MAKE) -C $(LIBFT)

.PHONY: fclean
fclean: clean
	@$(RM) $(BINDIR)/$(TARGET)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIBFT) fclean

.PHONY: re
re: clean all

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)

.PHONY: title
title:
	@printf "%b" "$(BLUE)"
	@echo "           _            _____                _           _____   __  "
	@echo "     /\   | |          / ____|              | |         |_  ) \ / /_ "
	@echo "    /  \  | | _____  _| |    _   _  __ _  __| |_ __ __ _ / / \ V /(_)"
	@echo "   / /\ \ | |/ _ \ \/ / |   | | | |/ _' |/ _' | '__/ _' /___| > <    "
	@echo "  / ____ \| |  __/>  <| |___| |_| | (_| | (_| | | | (_| |    / . \ _ "
	@echo " /_/    \_\_|\___/_/\`\|_____\___,_|\__,_|\__,_|_|  \__,_|   /_/ \_(_)"
	@printf "%b" "$(RESET)"


	@echo ' ____                   ___                             '
	@echo '/\  _`\                /\_ \                            '
	@echo '\ \ \L\_\  __  _  _____\//\ \     ___   _ __    __      '
	@echo ' \ \  _\L /\ \/ \/\  __`\\ \ \   / __`\/\` __\/ __`\    '
	@echo '  \ \ \L\ \/>  </\ \ \L\ \\_\ \_/\ \L\ \ \ \//\ \L\.\_  '
	@echo '   \ \____//\_/\_\\ \ ,__//\____\ \____/\ \_\\ \__/.\_\ '
	@echo '    \/___/ \//\/_/ \ \ \/ \/____/\/___/  \/_/ \/__/\/_/ '
	@echo '                    \ \_\                               '
	@echo '                     \/_/                               '
	@echo '        ___                                     __              '
	@echo '       /\_ \                                   /\ \             '
	@echo '     __\//\ \       ___ ___   __  __    ___    \_\ \    ___     '
	@echo '   / __`\\ \ \    /  __` __`\/\ \/\ \ /  _ `\  / _` \  / __`\   '
	@echo '  /\  __/ \_\ \_  /\ \/\ \/\ \ \ \_\ \/\ \/\ \/\ \L\ \/\ \L\ \  '
	@echo '  \ \____\/\____\ \ \_\ \_\ \_\ \____/\ \_\ \_\ \___,_\ \____/  '
	@echo '   \/____/\/____/  \/_/\/_/\/_/\/___/  \/_/\/_/\/__,_ /\/___/   '
	@echo '                                                               '
	@echo '                                                               '
	@echo '                     __    ____      '
	@echo '                   / __`\ /\  _`\    '
	@echo '    __    ___     /\_\L\ \\ \ \/\ \  '
	@echo '  / __`\/  _ `\   \/_/_\_<_\ \ \ \ \ '
	@echo ' /\  __//\ \/\ \    /\ \L\ \\ \ \_\ \'
	@echo ' \ \____\ \_\ \_\   \ \____/ \ \____/'
	@echo '  \/____/\/_/\/_/    \/___/   \/___/ '
	@echo '                                     '
	@echo '                                     '