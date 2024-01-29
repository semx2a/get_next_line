# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 19:14:12 by seozcan           #+#    #+#              #
#    Updated: 2024/01/29 14:32:58 by seozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include settings.mk

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::DIRECTORIES::

S		=	src/
O		=	obj/
I 		=	inc/
D 		=	dep/

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::CUSTOM FLAGS::

CFLAGS	+=	-I$I

CLFAGS	+=	-Wconversion

CFLAGS	+=	-g3 -fsanitize=address

RM		=	/bin/rm -rf

SPACE 	= 	awk -F ':' '{ printf "%-61s %s\n", $$1 ":", $$2 }'

BUFFER_SIZE	=	1024

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::OBJECTS::

OBJ		=	$(SRC:$S%=$O%.o)

DEP		=	$(SRC:$S%=$D%.d)

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::RULES::

all: header message $(NAME)

$O:
	@mkdir -p $@
	@echo "$(HIGREEN)creating $O folder:[OK]$(NO_COLOR)" | $(SPACE)

$(OBJ): | $O

$(OBJ): $O%.o: $S%
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@
	@echo "$(HIGREEN)compiling $<:[OK]$(NO_COLOR)" | $(SPACE)

$D:
	@mkdir -p $@
	@echo "$(HIGREEN)creating $D folder:[OK]$(NO_COLOR)" | $(SPACE)

$(DEP): | $D

$(DEP): $D%.d: $S%
	@$(CC) $(CFLAGS) -MM -MF $@ -MT "$O$*.o $@" $<
	@echo "$(HIGREEN)compiling $<:[OK]$(NO_COLOR)" | $(SPACE)


$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $^ -o $@
	@echo "$(HIGREEN)compiling $(NAME):[OK]$(NO_COLOR)" | $(SPACE)

cleanobj:
	@$(RM) $(O)
	@echo "$(HIORANGE)removing $O folder:[RM]$(NO_COLOR)" | $(SPACE)


cleandep:
	@$(RM) $(D)
	@echo "$(HIORANGE)removing $D folder:[RM]$(NO_COLOR)" | $(SPACE)

clean: cleanobj cleandep

fclean: header clean
	@$(RM) $(NAME)
	@echo "$(HIORANGE)removing $(NAME):[RM]$(NO_COLOR)" | $(SPACE)

re:	header fclean all

include colors.mk output.mk header.mk

.PHONY:	all clean fclean re