CFLAGS = -c -g -Wall
CC = g++
OS = "unknown"

SRCDIR = .
OBJDIR = .

SRC = $(wildcard $(SRCDIR)/*.cpp)
FILES = $(basename $(notdir $(SRC)))
OBJ = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(FILES)))

# Add objectiveC library for MacOSX.
ifneq ($(strip $(shell $(CC) -v 2>&1 | grep -i "Apple")),)
 GL_INCLUDE = -I/usr/X11R6/include
 GL_LIBRARIES = -framework OpenGL -framework GLUT
 BROWSER = dillo
 OS = "__APPLE__"
endif
# Nothing to be done for Linux :o)
ifneq ($(strip $(shell $(CC) -v 2>&1 | grep -i "Linux")),)
 OS = "__LINUX__"
 GL_INCLUDE = -I/usr/include/GL
 GL_LIBDIR = -L. -L/usr/X11R6/lib
 GL_LIBRARIES = -lglut -lGL -lm -lGLU # -lXmu -lXext -lXi -lX11
 BROWSER = mozilla
endif
#

job: tp2 #dox

tp2: $(OBJ)

	$(CC) $(GL_LIBDIR) $(OBJ) $(GL_LIBRARIES) -D$(OS) -o $(OBJDIR)/$@

#	ln -s $(OBJDIR)/$@ $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp

	$(CC) $(GL_INCLUDE) $(CFLAGS) -D$(OS) -o $@ $<

dox:
	rm -rf doc
	doxygen

clean:

	@echo "operating system = $(OS), $(GL_INCLUDE) $(GL_LIBDIR)	"
#	rm -rf $(OBJDIR)/* DOCS/* tp2
	rm -rf $(OBJ) tp2

