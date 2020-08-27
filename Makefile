
#OBJS specifies which files to compile as part of the project
OBJS = main.cpp TextureHolder.cpp Player.cpp Collision.cpp Game.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -g -Wall

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lsfml-system -lsfml-window -lsfml-graphics

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = Game

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
