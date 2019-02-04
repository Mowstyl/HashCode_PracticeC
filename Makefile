TARGET = HashCodeTest
CC = gcc

IDIR = deps
ODIR = obj
LDIR = headers
SDIR = src
OUTD = bin

LIBS = -lm
CFLAGS = -pthread -I$(IDIR) -I$(LDIR) -std=iso9899:2018 -Wall -Wextra -Werror -pedantic-errors -m64

ifneq (a,$(shell echo "a"))
RM = del /F /Q
MKDIR_P = mkdir
BAR = \\
EXT = .exe
else
RM = rm -f
MKDIR_P = mkdir -p
BAR = /
EXT =
$(info $(BAR))
endif

.PHONY: clean all default directories

default: $(TARGET)
all: directories default

directories:
	$(MKDIR_P) $(ODIR)
	$(MKDIR_P) $(OUTD)

_DEPS = $(wildcard $(LDIR)/*.h)
DEPS = $(patsubst %,%,$(_DEPS))

_OBJ = $(wildcard $(SDIR)/*.c)
OBJ = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o,$(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $(OUTD)/$@$(EXT) $^ $(CFLAGS) $(LIBS)

clean:
	$(RM) $(ODIR)$(BAR)*.o
	$(RM) $(OUTD)$(BAR)*

run:
	$(OUTD)/$(TARGET)$(EXT) $(ARGS)
