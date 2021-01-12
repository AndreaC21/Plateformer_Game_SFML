CC= g++
CFLAGS= -O
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
EXEC=jeu
SRC=$(wildcard *.cc)
OBJ=$(SRC:.cc=.o)

all: $(EXEC)

jeu: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

displayable.o: displayable.hpp

personnage.o: personnage.hpp 

plateforme.o: plateforme.hpp 

collectable.o:collectable.hpp

niveau.o: niveau.hpp

animation.o : animation.hpp

ennemi.o : ennemi.hpp

armes.o : armes.hpp

%.o: %.cc
	$(CC) -o $@ -c $< $(CFLAGS)
	

clean:
	rm -f *.o core
	
rmproper: clean
	rm -f $(EXEC)
