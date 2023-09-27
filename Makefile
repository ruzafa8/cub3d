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
LIBS	:= $(LIBMLX)/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a -L "/Users/aruzafa-/.brew/opt/glfw/lib/"

# Compiling flags
CC       = gcc
CFLAGS   = -Wextra -Wall -Werror -Wunreachable-code -Ofast
HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/

# Source files
SRC      = main.c
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
all: title libmlx libft $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(CC) -g $(OBJECTS) $(LIBS) $(HEADERS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
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

	@echo "___________              .__                               .__                              .___                       ________ ________   "
	@echo "\_   _____/__  _________ |  |   ________________      ____ |  |     _____  __ __  ____    __| _/____     ____   ____   \_____  \\______ \  "
	@echo " |    __)_\  \/  /\____ \|  |  /  _ \_  __ \__  \   _/ __ \|  |    /     \|  |  \/    \  / __ |/  _ \  _/ __ \ /    \    _(__  < |    |  \ "
	@echo " |        \>    < |  |_> >  |_(  <_> )  | \// __ \_ \  ___/|  |__ |  Y Y  \  |  /   |  \/ /_/ (  <_> ) \  ___/|   |  \  /       \|    \   \"
	@echo "/_______  /__/\_ \|   __/|____/\____/|__|  (____  /  \___  >____/ |__|_|  /____/|___|  /\____ |\____/   \___  >___|  / /______  /_______  /"
	@echo "        \/      \/|__|                          \/       \/             \/           \/      \/             \/     \/         \/        \/ "