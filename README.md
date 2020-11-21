# COMP2113project
Group 83: 
          KwokKaTin: Kwok Ka Tin(3035684843)      Edward-choi: Choi Yik Ho(3035684415)
         
Game Title: Battleship with a Twist

Game Instructions: The player is a Brave summoned to the Three Kingdoms to help the Shu Kingdom defend the Wei Army in the Battle of Red Cliffs. Normal Battleship rules apply. The twist is that some squares are special squares. Hitting them triggers a special game. Winning the game gives benefits, losing gives harm. The input is case-sensitive.

                   Example of special game: - RPS
                                            - Number Guessing Game(開口中)
                                            - IQ Question
                   Examples of benefits:    - Player may shoot multiple times in one turn
                                            - Player may hit two squares at once like a shotgun
                                            - Hint on location of enemy's ship
                                            - etc.
                   Examples of harm:        - Lost a turn
                                            - Player's ship explodes by itself 
                                            - etc.
Features to be implemented:
1. Generation of random game sets or events:
    Ship locations, Special Squares location, Special games played, Benefits and Harm given, etc.
2. Data structures for storing game status:
    Strcuture to record location of different types of ships.
3. Dynamic memory management
    Use Dynamic memory management to create a linked list to store the input of player in the RPS game for comparing the player input and cpu input.
4. File input/output (e.g., for loading/saving game status)
    Game status (maps) exported in a simple text file. The game is loaded by importing the same file and read the data in the maps.
5. Program codes in multiple files
    Special games stored in multiple files and access them using Makefile
   
Compilation instructions: Download all Makefile, .cpp and .h files. Compile them with the command "make main". Then all .cpp and .h files will be compiled automatically.
Execution instructions: Execute the main.cpp with the command "./main". 
