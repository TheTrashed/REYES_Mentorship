TARGET	=	domain_coloring

CC	= 	gcc
CFLAGS	= 	-Wall -O -I./$(SRCDIR)

LINKER	=	gcc
LFLAGS	=	-Wall -lm

BINDIR	=	.
OBJDIR	=	obj
SRCDIR	=	src

SOURCES  :=	$(wildcard $(SRCDIR)/*.c)
INCLUDES :=	$(wildcard $(SRCDIR)/*.h)
OBJECTS  :=	$(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

$(TARGET):	$(OBJECTS)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@

$(OBJECTS):	$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCLUDES) $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(BINDIR)/$(TARGET)
	rm -r $(OBJDIR)
