# COMP2113project
Group 83: KwokKaTin: Kwok Ka Tin(3035684843)

          Edward-choi: Choi Yik Ho(3035684415)
         
Game Title: Battleship with a Twist

Game Instructions: Normal Battleship rules apply. The twist is that some squares are special squares. Hitting them triggers a special game. Winning the game gives benefits, losing gives harm.

                   Example of special game: - RPS
                                            - Number Guessing Game(開口中)
                                            - IQ Question
                                            - Math
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
    Strcuture to record location of ships
3. Dynamic memory management
    Use Dynamic memory management to save ship locations, special squares locations, etc.
4. File input/output (e.g., for loading/saving game status)
    Game status exported in a simple text file. The game is loaded by importing the same file
5. Program codes in multiple files
    Special games stored in multiple files and access them using Makefile
