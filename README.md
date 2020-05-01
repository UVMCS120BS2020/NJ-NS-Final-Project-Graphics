# NJ-NS-Final-Project-Graphics
Nolan Jimmo and Noah Stracqualursi

## Introduction
The primary goal of our project was to create a visual, 2-person, rock, paper, scissors game using C++ and OpenGL/Glut.
We have implemented what we believe to be a good, fun game of rock paper scissors that not only incorporates the visual
aspect of the game, but also keeps score and provides a platform for multiple rounds of the game between two players.

The instructions for game-play are included in the game window, but essentially, each player has 3 keys on their "side"
of the keyboard. For player one Rock = a, Paper = s and Scissors = d. For player 2, left arrow = rock, down arrow = paper
and right arrow = scissors. It is suggested that the players use some sort of divider in the middle of the keyboard so
that they can not see each other pushing the keys. Next, each player makes their selection, and after both players have
chosen an item, the selected items, along with their labels will appear on the screen, as well as a message displaying
who won the game, and the updated score. The players can then clear the board with the c key, and play as many rounds
as they would like.

## Project Requirements 
First and foremost, this game is fully functional and we believe it to be an impressive project/implementation.
It incorporates graphics as the main aspect of understanding and playing the game, as well as responds to a number of
keyboard keys. There are 3 choice keys for each player, as well as the c key for clearing the board once a round is over.
Each of the items that is drawn on the screen is drawn using and overridden draw() function in each of the respective
classes. We also incorporated the use of polymorphism by creating a parent "Item" class, which we used to create a vector
of smart pointers, pushing each of the 2 players item objects on to. We then called the draw functions on the appropriate
index of that vector, exemplifying polymorphism because of the fact that we are calling draw on each of the indexes of 
the vector, which have the same parent class, but different draw methods are being executed depending on the type of the
child class.

## A few notes
There are a few quirky things we had to do to achieve our end goal. The first is the fact that OpenGL/GLUT don't make it
very easy to display text. We knew that text rendering was an integral part of the game, not only for the instructions
and labels, but especially for the score keeping aspect of the game. What we ended up doing what using a function called
PrintString() (declared in graphics.cpp) which takes in a position for the text, and the actual desired text output and
prints it to the screen. We used the glutBitmapCharacter() function to achieve the output to the window. However,
glutBitmapCharacter requires an a c-style character array pointer as a parameter, so we were forced to use the older
c-style pointers in that case. We understand that isn't the way it should be done within C++ when smart pointers are
available, but because of the need for text rendering and this being one of the simplest ways we could find to do it, 
we just went with it. We also used a StackOverflow post on the subject of text rendering to help us with the PrintString()
function, and the URL citation for that post is listed above the function.

The other thing, is that in order to have access to the glutBitmapCharacter() function, we need to include the stdc++.h
header file that defines the function. We ran into a slight issue with that include statement being valid on MacOS 
machines, so we basically just included that file in the repository so that any machine who clones the repository will
have immediate access to all of the necessary files and will be able to build the project "out of the box".
