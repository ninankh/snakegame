
#OBJS specifies which files to compile as part of the project
OBJS = scr/main.cpp scr/game.cpp scr/object.cpp scr/tmanage.cpp scr/map.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w -Wall -Werror -Wextra -Wconversion -Wno-unused-result -Wvla -Wpedantic 

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image -g

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = snakegame

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)