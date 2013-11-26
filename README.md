Project Title

contributors: bishwa9, davsuss
url: https://github.com/davsuss/WebMon

Two player, modified Pokemon Game

The game will allow a player to catch, train, and battle other trainers.

Game Mechanics:
Player can sign-in using a username or start a game.
Each player can have 3 useable pokemon that he/she has to catch.
These pokemon will be shown upon log-in. New players will be given a choice for their first pokemon.
A button, Random encounter, will be available for the player to fight pokemon. 
The player can either catch the pokemon or defeat it to train. 
When a player defeats a pokemon, the player's pokemon will gain experience. 
Also, depending on the pokemon defeated, the player's pokemon will gain 'Effort Values', which will aid in the growth of a certain stat of the pokemon.
A pokemon has four stats: Attack, Defense, Speed, HP. 
	Attack, determines how much damage the pokemon can do.
	Defense, determins how well a pokemon can take an attack
	Speed, determines which of the two pokemon attacks first
	HP, is how many life points the pokemon has
The actual stat is based on the level of the pokemon. A pokemon can be 1-20 level. 20 being the highest. 
Pokemon can also evolve. When a pokemon becomes a certain level, the pokemon can evolve and gain better stats.
The game will contain 16 pokemon.

Technical:
The player will be on the client side, while the game mechanics will be handled by a server.
Two clients can fight each other via the server
The server has no GUI, while the client will contain a gui to enable the player to play.

The GUI will be built upon the MVC model. 
	The model will be stored in a single object which controls the storage and retrival of all the information that the client current knows about the current state.
	The controller will recieve the new information about the server and send back the information accordingly. 
	The view will be based upon QFrames and QWidgets which send signals to the controller and recives command from that same object.
The GUI will not do any computation since that is ported to the server
	The advantage of this is that if we need to update the game, we don't have to necessarily update each game client, just the server side.

Transmission Protocol:
This is the transmission protocol which will be used for the communication between the client and the server.
Protocol: 
BEGIN:MESSAGE:END


Request Trainer+ Pokemon:
REQUEST:TRAINER:TrainerName/ID

    returns: 
Trainer (with party pokemon)
ID, Level, name, HP, moves

Request Specific Pokemon
REQUEST:POKEMON:{POKEMONID}

    returns:
All Stats, Level, and Exp

Request Random Encounter
ACTION:RANDOMENCOUNTER

    returns:Pokemon - ID, Level, name, Hp

Action Attacking
ACTION:ATTACK:{ATTACKNAME}

    returns:

Action Pokemon PokeCenter
ACTION:POKEMONPOKECENTER

    returns:
Action Disconnect 
ACTION:DISCONNECT
    returns:

Action Release Pokemon
ACTION:POKEMONRELEASE:POKEMONID

Action Attempt Pokemon Catch
ACTION:POKEMONCATCH:{POKEMONID}

    returns: Success or Failure with Pokemon ID, Name, Hp, and Exp
Action Return Pokemon
ACTION:RETURNPOKEMON:{NEWPOKEMONNUMBER}

    returns: 

Action Challenge Trainer
ACTION:PLAYERCHALLENGE:TRAINERID
    NOT IMPLEMENTED RIGHT NOW
    returns:

