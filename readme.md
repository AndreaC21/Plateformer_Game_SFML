Projet C++
UE : Moteur graphique et Audio

Carpentier Andréa M2 ILJ
Année 2020-2021

## Compilation et Exécution

Nécessite SFML 2.5.1\
Le projet comporte un makefile, utilisez juste la commande “ make “

Puis tapez “ ./jeu “
## Contenu du projet

### Fichiers :
* Displayable.hpp et Displayable.cc
* Plateforme.hpp et Plateforme.cc
* Personnage.hpp et Personnage.cc
* Armes.hpp et Armes.cc
* Collectable.hpp et Collectable.cc
* Ennemi.hpp et Ennemi.cc
* Animation.hpp et Animation.cc
* Niveau.hpp et Niveau.cc
* Main.cc
* MakeFile
* ReadMe.pdf

### Dossiers :
* Font : contient la police utilisez pour les text.
* Images : contient les sprites du personnage, des décors, des élément UI
* Sons : contient les éléments sonores et musique de fond.

## Contrôle

### Menu :

* Touche 1 du pad numérique : lance le niveau 1
* Touche 2 du pad numérique : lance le niveau 2
* Touche 3 du pad numérique : lance le niveau 3

### Dans un niveau :

* Flèche de droite : déplacement du personnage vers la droite
* Flèche de gauche : déplacement du personnage vers la gauche
* Flèche du haut : ( uniquement au niveau 3 ) lance un couteau
* Barre espace : saut
* Echap : affichage du panel pause
* Touche N : ( à la fin du niveau ) lancement du niveau suivant

### En pause, dans un niveau :

* Echap : retour menu
* Entrée : reprendre le niveau
