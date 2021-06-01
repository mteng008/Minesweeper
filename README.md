# Minesweeper 

 Authors: \[Matthew Teng](https://github.com/mteng008)\, \[Jason Yeung](https://github.com/yeungjason12)\, 
 
## Project Description

 Our project proposal is to create our own minesweeper game. This is interesting to us because we all enjoy playing video games in our spare time and thought it would be fun to try our hand at making our own. Matthew used to play tons of minesweeper walking to and from classes. We thought it would be a great way to involve our field of study with our hobbies. We plan to use C++, PuTTy, GitHub, googletest, Valgrind, and MS Visual Studio to produce a minesweeper game as an executable. The input will be several menu options before the game begins including: create new game, resume game, and see high score. Upon game creation, the player will have the option to set the size of the board as well as the number of mines or select one of the preset difficulty options with a preset board size and mine count. In game, the player has the option to first select an unswept tile and has the option to either sweep or flag it, and will interact with the game by inputting the x and y coordinates that represent the board. Outputs would include menu generation and confirmation of selections. Other outputs include the minesweeper board itself and the board state following player input. The two design patterns we will be using are strategy and factory design patterns. We chose the factory pattern because we need to be able to generate different games based on the user's choice. The feature we will be implementing with this pattern is the ability to select a game of the user's desired difficulty. The problem we anticipated encountering was having too many objects for different games and over-complexifying the project. With this design pattern, we will be able to create a signle user- selected object per game. We also chose the strategy design pattern because each game object is created differently. More specifically, we need to deal with whether the game being created is using predetermined setings or user-determined ones.

## Class Diagram

 Class Diagram : [MineSweeperUMLDiagram.pdf](https://github.com/cs100/final-project-mteng008_jyeun018_pdadi001-clowntown/files/6445202/MineSweeperUMLDiagram.pdf)

 Description : We are going to have a base game class that is going to store the size of the board, amount of mines, and a 2d vector of tile pointers. We are also going to have another class associated with the game class called Tile. This class will return bool values to check for mines and flags. We will also have 4 classes inherited from game: easy, medium, hard, and custom. These 4 classes represent the difficulty level of the game, where custom allows the players to set their own tiles and mine size.

 ## Screenshots

 Before running the application: https://gyazo.com/c150c72a244933490f7ef39d1debf627
 
 Runtime/Menu: https://gyazo.com/ac947048dd1ad3f40d4c6d62234d93f1
 
 New Game on Medium Difficulty: https://gyazo.com/2ac852a74cbb0ae796fc2d1b392cf595
 
 Example of a losing game: https://gyazo.com/27f688abd7dd545bbf104d5dc7fbfb3b
 
 ## Installation/Usage
 
 To play our game, just run the main executable: ./play_game 
The game will appear as an output within PuTTy. There is no need to install any sort of GUI or third party application, just run the code in a compiler/IDE.

When selecting a difficulty, please enter the corresponding letter. During the game, you type your move as a "x y" point, your first number(x-coordinate) followed by a space, followed by your second number(y-coordinate). For example a move could be typed as:8 5
 
 ## Testing

 Our project was tested using google tests and specific unit tests to ensure the game runes smoothly, such as testing the menu, if the difficulty produces the correct amount of tiles. We built executables using CMake as well as ran Valgrind to avoid any memory leaks. 
 
