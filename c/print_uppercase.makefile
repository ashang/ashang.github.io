
# Need to installed libglib2.0-dev some system specific install that will
# provide a value for pkg-config
INCLUDES=$(shell pkg-config --libs --cflags glib-2.0)
CC=gcc
PROJECT=print_uppercase

# Targets
full: clean compile

clean:
	-rm -f $(PROJECT)

compile:
	$(CC) $(PROJECT).c -o $(PROJECT) $(INCLUDES)
