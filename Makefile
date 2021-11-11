CC = x86_64-w64-mingw32-g++
SRCDIR = src
BUILDDIR = obj
TARGET = bin/shcpoc.exe
 
SRCEXT = cpp
SOURCES = $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS = -g -Wall -static 
LIB := -Llib -lmingw32 -lSDL2main -lSDL2 -mwindows -Wl,--dynamicbase -Wl,--nxcompat -Wl,--high-entropy-va -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lsetupapi -lversion -luuid
INC := -Iinclude

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	$(RM) -r $(BUILDDIR) $(TARGET)