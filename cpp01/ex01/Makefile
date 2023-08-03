NAME =	moarBrainz


SRC_PATH =	./

SRC =\
	main.cpp		\
	Zombie.cpp		\
	zombieHorde.cpp


DIR_INCS =\
	include/

INCLUDES =\
	$(addprefix -I , $(DIR_INCS))


LIBS =\


DIR_BUILD =		.build/
OBJS =			$(patsubst %.cpp, $(DIR_BUILD)%.o, $(SRC))
DEPS =			$(patsubst %.cpp, $(DIR_BUILD)%.d, $(SRC))
DEPS_FLAGS =	-MMD -MP
CPPFLAGS =		-Wall -Wextra -Werror -std=c++98 #-fsanitize=address
RM =			rm -rf
AR =			ar rcs


.PHONY:		all
all:
			$(MAKE) $(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CPPFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME)

.PHONY:	bonus
bonus:	all

.PHONY:	clean
clean:
		$(RM) $(DIR_BUILD)

.PHONY:	fclean
fclean:	clean
		$(RM) $(NAME)

.PHONY:	re
re:		fclean
		$(MAKE) all

-include $(DEPS)

$(DIR_BUILD)%.o : $(SRC_PATH)%.cpp
		@mkdir -p $(shell dirname $@)
		$(CXX) $(CPPFLAGS) $(DEPS_FLAGS) $(INCLUDES) -c $< -o $@
