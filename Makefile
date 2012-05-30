##
## Makefile for Makefile in /home/lyvet_r//tek2ed/MyLS/my_ls
## 
## Made by randy lyvet
## Login   <lyvet_r@epitech.net>
## 
## Started on  Mon Nov  7 15:53:02 2011 randy lyvet
## Last update Tue May 29 14:10:34 2012 yuguo cao
##

NAME		=	bomberman

NAMEFILE	=	$(NAME)

INC_DIR		=	include/
INC_LIB_SRC	=	libs/sources
LIB_DIR		=	libs/
SRC_DIR		=	src/
OBJ_DIR		=	obj/
LIBS		=	m X11
SRCS_C		=	$(notdir $(wildcard $(SRC_DIR)/*.cpp))
SRCS_O		=	$(addprefix $(OBJ_DIR), $(patsubst %.cpp, %.o, $(SRCS_C)))
SRCS_H		=	$(wildcard $(INC_DIR)/*.hpp)

SVN		=	svn co svn+ssh://kscm@koala-rendus.epitech.net/$(SVN_NAME)
SVN_NAME	=	#Nom du depos#

CC		=	@g++ $(GDL_LIB) $(LSFML_LIB)
GDL_LIB		=	-I./include/GDL/ -L./libs/GDL -Wl,--rpath=./libs/GDL -lgdl_gl -lGL -lGLU
LSFML_LIB	=	-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
CFLAGS		=	-W -Wall -g3 -ggdb
DEBUGFLAGS	=	-g3 -ansi -pedantic
LFLAGS		=	$(addprefix -l, $(LIBS)) $(addprefix -L, $(LIB_DIR)) \
			$(patsubst lib%.a, -l%, $(notdir $(wildcard $(LIB_DIR)*.a)))
IFLAGS		=	$(addprefix -I, $(INC_DIR))

############~COULEURS~##############
GREEN		=	32
RED		=	31
WHITE_BLUE	=	36
DARK_BLUE	=	1;34
###################################
${NAME}		:	$(SRCS_O)
		@echo -e " \033[1;$(WHITE_BLUE)m"'\n  -------- Begin Link -------- '"\033[0;0;00m"''
		$(CC) -o $(NAME) $(SRCS_O) $(CFLAGS) $(LFLAGS) $(IFLAGS) $(PARSE_LINK)
		@echo "Terminer, un petit 'make cafe' avant de commencer ?"

all		:	$(NAME)

clean		:
		@rm -f ./obj/*~ ./obj/#*# ./obj/*.o ./src/*~ ./src/#*# ./include/*~ ./include/#*# ./*~ ./#*#

fclean		:	clean
		@rm -f $(NAME)

re		:	fclean all

run		:	all
		./$(NAME)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.cpp $(SRCS_H)
		@echo -e -n ' [ '"\033[$(GREEN)m"' BUILDING '
		@echo -e -n $@
		@echo -e ''"\033[0;0;00m"' ] '
		$(CC) -c -o $@ $< $(CFLAGS) $(LFLAGS) $(IFLAGS) $(PARSE)

################~UTILITAIRES~##########################

svn		:
		$(SVN)

norme		:
		@echo -e -n '\033[$(RED)m Norme des .cpp \033[0;0;00m '
		@/u/all/lyvet_r/public/script/tools/norme/normeastek src/*
		@echo -e -n '\033[$(RED)m Norme des .hpp \033[0;0;00m '
		@/u/all/lyvet_r/public/script/tools/norme/normeastek include/*

gnorme		:
		@echo -e -n '\033[$(RED)m Norme des .cpp \033[0;0;00m '
		@/u/all/lyvet_r/public/script/tools/norme/normeastek -nocheat src/*
		@echo -e -n '\033[$(RED)m Norme des .hpp \033[0;0;00m '
		@/u/all/lyvet_r/public/script/tools/norme/normeastek -nocheat include/*

mklib		:
		@echo -e -n '\033[$(GREEN)m COMPILATION \033[0;0;00m '
		@echo -e lib$(NAME).a
		@ar rc lib$(NAME).a $(SRCS_O)
		@ar tv lib$(NAME).a
		@echo -e '\033[$(GREEN)m RANLIB \033[0;0;00m '
		@ranlib lib$(NAME).a
		@echo -e '\033[$(GREEN)m TERMINER \033[0;0;00m '

cl		:
		rm -r -f $(SRC_DIR)*.cpp~
		rm -r -f $(INC_DIR)*.hpp~

begin		:
		@echo -e -n '\033[$(DARK_BLUE)m CREATING DIR obj/ \033[0;0;00m \n'
		@mkdir -p $(OBJ_DIR)
		@echo -e -n '\033[$(DARK_BLUE)m CREATING DIR src/ \033[0;0;00m \n'
		@mkdir -p $(SRC_DIR)
		@echo -e -n '\033[$(DARK_BLUE)m CREATING DIR include/ \033[0;0;00m \n'
		@mkdir -p $(INC_DIR)

dead		:	fclean
		@rm -rf $(OBJ_DIR)
		@rm -rf $(SRC_DIR)
		@rm -rf $(LIB_DIR)
		@rm -rf $(INC_DIR)
		@echo "Theyr all dead :("

####################~FUN~#########################
home		:
		@firefox "www.epitech.eu/intra/"
love		:
		@firefox "http://x-art.com/"
epilepsy	:
		@firefox "http://www.albinoblacksheep.com/flash/epilepsy"
cafe		:
		@cat /u/all/lyvet_r/public/cafe
pedobear	:
		@cat /u/all/lyvet_r/public/pedobear
alien		:
		@cat /u/all/lyvet_r/public/alien
##play:
##	@/u/all/lyvet_r/public/script/ninvaders-0.1.1/nInvaders
##########################################