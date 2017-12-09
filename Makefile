##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile of my_ls program
##

SRCDIR		=	src

OBJDIR		=	build

SRCS		=	$(shell find $(SRCDIR) -name '*.c')

SRCDIRS		=	$(shell find $(SRCDIR) -type d | sed 's/\/$(SRCDIR)/./g')

OBJS		=	$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

PROJECT		=	mysh

CFLAGS		=	-I./include -L./lib
CFLAGS		+=	$(DEBUG)

all:		buildrepo $(OBJS)
		@ar rc $(PROJECT) $(OBJS)

lala:
		@gcc -o my_printf main.c -I./include -lmy

$(OBJDIR)/%.o: 	$(SRCDIR)/%.c
		@gcc -c $< -o $@ $(CFLAGS)

tests_run:	all
		@make -C tests/

buildrepo:
		@$(call make-repo)

clean:
		@rm -rf $(OBJS)
		@rm -rf vgcore.*

fclean:		clean
		@rm -rf $(PROJECT)

re:		fclean all

define make-repo
	for dir in $(dir $(OBJS)); \
	do \
		mkdir -p $$dir; \
	done
endef
