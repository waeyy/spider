##
## Makefile for  in /home/soidik_d/Semestre_05/cpp/Spider
## 
## Made by SOIDIKI Djamil
## Login   <soidik_d@epitech.net>
## 
## Started on  Tue Oct 27 10:02:50 2015 SOIDIKI Djamil
## Last update Wed Nov 18 08:30:02 2015 SOIDIKI Djamil
##

PATH_SOURCES	=	sources/

PATH_INCLUDES	=	includes/

PATH_VENDORS	=	vendors/

NAME		=	spider

SRCS		=	$(PATH_SOURCES)Main.cpp \
			$(PATH_VENDORS)/exception/Exception.cpp \
			$(PATH_VENDORS)/network/Network.cpp \
			$(PATH_VENDORS)/network/Listener.cpp \
			$(PATH_VENDORS)/network/Handler.cpp \
			$(PATH_VENDORS)/network/Secure.cpp

OBJS		=	$(SRCS:.cpp=.o)

TEMP		=	$(PATH_SOURCES)*~ $(PATH_INCLUDES)*~ $(PATH_VENDORS)*~ *~ $(PATH_VENDORS)/network/*~

CXXFLAGS 	=	-Wall -Wextra -Werror -std=c++11 -g

all:			$(NAME)

$(NAME):		$(OBJS)
			g++ -o $(NAME) $(OBJS) -lboost_system -lssl -lcrypto -lpthread

clean:
			rm -f $(OBJS) $(TEMP)

fclean:			clean
			rm -f $(NAME)

re:			fclean all

norm:			re
			rm -f $(OBJS)
