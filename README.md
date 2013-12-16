Need QT to run this project. Either download Qt on your system or try to make this program and run it in you ssh account!

ANY QUESTIONS send email to: bishwa9@vt.edu or davsuss@vt.edu

Project Title: Two player, modified Pokemon Game

contributors: bishwa9, davsuss
url: https://github.com/davsuss/WebMon

The game will allow a player to catch, train, and battle other trainers.



BETA Version.

Current Features:

-Can get a random pokemon team with a random move set

-Can train pokemon (level and EV) through fighting appropriately levelled random pokemon

-Can easily change the game mechanics


To run updates on pokedex (Moves, New Pokemon, or Types):

1) go to /Game'sCore/build-PokedexUpdator-Desktop-Debug

2) run ./PokedexUpdator o if already ran the game once

3) check if the game.db file is created

4) move to appropriate sections: /databases and where the webmon server's exe is located

To run the server:

1) navigate to /WebmonServer/build-WebmonServer-Desktop-Debug

2) run make and run ./WebmonServer, if want to reset saved files append 'r'

3) run the exe, a dialog should pop up with the following:

1 

game.db already contains:  

"Moves" 

"Pokedex" 

"TypeEffectiveness" 

saveData.db already contains:  

"CaughtPokemon" 

"Trainers"

to run the client:

1) navigate to the Webmon Client folder

2) if the exe does not already exist, run a qmake and then make

3) run the exe, two window should pop up.
