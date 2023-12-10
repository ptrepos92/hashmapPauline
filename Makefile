DIR=build
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
LIBRARY=libpauline.a
OBJ2=$(addprefix $(DIR)/, $(OBJ))
EXECUTABLE=exec

all: $(LIBRARY) $(EXECUTABLE)

debug :
	@echo $(SRC)
	@echo $(OBJ)
	@echo $(OBJ2)

Install :
	mkdir -p $(DIR)
	cp -p $(LIBRARY) $(DIR)

$(DIR)/liste_chainee.o : liste_chainee.c liste_chainee.h $(DIR)
	gcc -c $< -o $@

$(DIR)/abr.o : abr.c abr.h $(DIR)
	gcc -c $< -o $@

$(DIR)/hashmap.o : hashmap.c hashmap.h $(DIR)
	gcc -c $< -o $@

$(LIBRARY): $(OBJ)
	ar ru $@ $^
	ranlib $@


doc: doxygen Doxyfile 
		
clean:
	rm -f $(DIR)/*.o
	rm -f exec
	
