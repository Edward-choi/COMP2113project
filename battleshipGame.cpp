#include <iostream>
#include <string>
#include <fstream>
#include "mc1.h"
#include "mc2.h"
#include "mc3.h"
#include "mc4.h"
#include "rps.h"
#include "numberGuess.h"

using namespace std;

struct ships {
    string Carrier[5];
    string Battleship[4];
    string Destroyer[3];
    string Submarine[3];
    string Patrol[2];
} player,cpu;

//To output the grid board in a 11*11 square
//char board[11][11]: The grid array to be displayed
void showBoard(char board[11][11]) {
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

//To arrange a ship onto a grid
//Parameters:
//board-The grid for placing ships
//x-A char to identify a ship
//k-how many squares a ship occupies
void place_Boats(char board[11][11], char x, int k) {
    while (true) {
        cout << "From which square to which square? ";
        string start;
        string end;
        char empty = '~';
        int count = 0;
        cin >> start >> end;
        int x1 = int(start[0]) - 65;
        int y1 = int(start[1]) - 48;
        int x2 = int(end[0]) - 65;
        int y2 = int(end[1]) - 48;
        if (start.length() != 2 || end.length() != 2) {
            cout << "Incorrect index format!" << '\n';
            continue;
        }
        if ((x1 < 0 || x1 > 9) && (x2 < 0 || x1 > 9)) {
            cout << "Row index must be between 'A' and 'J'!" << '\n';
            continue;
        }
        if ((y1 < 0 || y1 > 9) && (y2 < 0 || y1 > 9)) {
            cout << "Column index must be between 0 and 9!" << '\n';
            continue;
        }
        if (x1 != x2 && y1 != y2) {
            cout << "Boat must be placed horizontally or vertically!" << '\n';
            continue;
        }if ((x2 - x1 + 1 != k) && (y2 - y1 + 1 != k)) {
            cout << "The squares occupied doen't match!" << '\n';
            continue;
        } else {
            for (int i = x1; i < x2+1; i++) {
                for (int j = y1; j < y2+1; j++) {
                    if (board[i+1][j+1] == empty) {
                        count++;
                    }
                }
            }
            if (count == k) {
                for (int i = x1; i < x2+1; i++) {
                    for (int j = y1; j < y2+1; j++) {
                        board[i+1][j+1] = x;
                    }
                }
            } else {
                cout << "Ships cannot overlap each other!" << '\n';
                continue;
            }
        }
        showBoard(board);
        break;
    }
}

//Allows the player to arrange all ships on their grid and start the game
void initializePlayer(char board[11][11]) {
    
    board[0][0] = '/';
    for (int i = 1; i < 11; i++) {
        board[i][0] = char(64+i);
        board[0][i] = char(47+i);       
        for (int j = 1; j < 11; j++) {
            board[i][j] = '~';
        }
    }
    
    showBoard(board);
    cout << "Place your Carrier (5 squares)" << '\n';
    place_Boats(board, 'C', 5);
    cout << "Place your Battleship (4 squares)" << '\n';
    place_Boats(board, 'B', 4);
    cout << "Place your Destroyer (3 squares)" << '\n';
    place_Boats(board, 'D', 3);
    cout << "Place your Submarine (3 squares)" << '\n';
    place_Boats(board, 'S', 3);
    cout << "Place your Patrol Boat (2 squares)" << '\n';
    place_Boats(board, 'P', 2);
}

//Let the player's opponent(Computer) to arrange its Carrier onto its grid
void CPUplaceCarrier(char board[11][11]) {
    while (true) {
        srand(time(0));
        int x = rand() % 10, y = rand() % 10;
        if (rand()%2 == 0) {
            if (y > 6 || y < 1 || x > 10 || x < 1) {
                continue;
            } else {
                for (int i = y; i < y+5; i++) {
                    board[x][i] = 'C';
                }
            }
        } else {
            if (x > 6 || x < 1 || y > 10 || y < 1) {
                continue;
            } else {
                for (int i = x; i < x+5; i++) {
                    board[i][y] = 'C';
                }
            }
        }
        break;
    }
}

//Let the player's opponent to arrange its Battleship onto its grid without overlapping other ships
void CPUplaceBattleship(char board[11][11]) {
    while (true) {
        bool overlap = false;
        int x = rand() % 10, y = rand() % 10;
        if (rand()%2 == 1) {
            if (y > 7 || y < 1 || x > 10 || x < 1) {
                continue;
            } else {
                for (int i = y; i < y+4; i++) {
                    if (board[x][i] != '~') {
                        overlap = true;
                    }
                }
                if (overlap) {
                    continue;
                } else {
                    for (int i = y; i < y+4; i++) {
                        board[x][i] = 'B';
                    }
                }
            }
        } else {
            if(x > 7 || x < 1 || y > 10 || y < 1) {
                continue;
            } else {
                for (int i = x; i < x+4; i++) {
                    if (board[i][y] != '~') {
                        overlap = true;
                    }
                }
                if (overlap) {
                    continue;
                } else {
                    for (int i = x; i < x+4; i++) {
                        board[i][y] = 'B';
                    }
                }
            }
        }
        break;
    }
}

//Let the player's opponent to arrange its Destroyer/Submarine onto its grid without overlapping other ships
//char ship: whether a destroyer or a submarine is being arranged
void CPUplaceSubmaroyer(char board[11][11], char ship) {
    while (true) {
        bool overlap = false;
        int x = rand() % 10, y = rand() % 10;
        if (rand()%2 == 1) {
            if (y > 8 || y < 1 || x > 10 || x < 1) {
                continue;
            } else {
                for (int i = y; i < y+3; i++) {
                    if (board[x][i] != '~') {
                        overlap = true;
                    }
                }
                if (overlap) {
                    continue;
                } else {
                    for (int i = y; i < y+3; i++) {
                        board[x][i] = ship;
                    }
                }
            }
        } else {
            if(x > 8 || x < 1 || y > 10 || y < 1) {
                continue;
            } else {
                for (int i = x; i < x+3; i++) {
                    if (board[i][y] != '~') {
                        overlap = true;
                    }
                }
                if (overlap) {
                    continue;
                } else {
                    for (int i = x; i < x+3; i++) {
                        board[i][y] = ship;
                    }
                }
            }
        }
        break;
    }
}

//Let the player's opponent to arrange its Patrol Boat onto its grid without overlapping other ships
void CPUplacePatrol(char board[11][11]) {
    while (true) {
        bool overlap = false;
        int x = rand() % 10, y = rand() % 10;
        if (rand()%2 == 1) {
            if (y > 9 || y < 1 || x > 10 || x < 1) {
                continue;
            } else {
                for (int i = y; i < y+2; i++) {
                    if (board[x][i] != '~') {
                        overlap = true;
                    }
                }
                if (overlap) {
                    continue;
                } else {
                    for (int i = y; i < y+2; i++) {
                        board[x][i] = 'P';
                    }
                }
            }
        } else {
            if(x > 9 || x < 1 || y > 10 || y < 1) {
                continue;
            } else {
                for (int i = x; i < x+2; i++) {
                    if (board[i][y] != '~') {
                        overlap = true;
                    }
                }
                if (overlap) {
                    continue;
                } else {
                    for (int i = x; i < x+2; i++) {
                        board[i][y] = 'P';
                    }
                }
            }
        }
        break;
    }
}

//Allows the Computer to arrange all its ship into its grid
//Makes a grid that will be shown to the player
void initializeCPU(char realboard[11][11], char outputboard[11][11]) {
    realboard[0][0] = '/';
    for (int i = 1; i < 11; i++) {
        realboard[i][0] = char(64+i);
        realboard[0][i] = char(47+i);       
        for (int j = 1; j < 11; j++) {
            realboard[i][j] = '~';
        }
    }
    CPUplaceCarrier(realboard);
    CPUplaceBattleship(realboard);
    CPUplaceSubmaroyer(realboard, 'D');
    CPUplaceSubmaroyer(realboard, 'S');
    CPUplacePatrol(realboard);
    
    outputboard[0][0] = '/';
    for (int i = 1; i < 11; i++) {
        outputboard[i][0] = char(64+i);
        outputboard[0][i] = char(47+i);       
        for (int j = 1; j < 11; j++) {
            outputboard[i][j] = '~';
        }
    }
}

//Arrange special squares onto the Computer's grid
void specialSquares(char board[11][11]) {
    int k = 0;
    while (k < 10) {
        int x = (rand() % 10) + 1, y = (rand() % 10) + 1;
        if (board[x][y] == '~') {
            if (k > 5) {
                board[x][y] = 'Q';
            } else if (k > 2) {
                board[x][y] = 'R';
            } else {
                board[x][y] = 'N';
            }
        } else {
            continue;
        }
        k++;
    }
}

//Stores the location of a ship into an array
//string Carrier[5]: An array that stores the location index of the Carrier, etc.
void shipLocate(char board[11][11], string Carrier[5], string Battleship[4], string Destroyer[3], string Submarine[3], string Patrol[2]) {
    int c = 0, b = 0, d = 0, s = 0, p = 0;
    for (int i = 1; i < 11; i++) {
        for (int j = 1; j < 11; j++) {
            string index = to_string(i-1) + to_string(j-1);
            if (board[i][j] == 'C') {
                Carrier[c] = index;
                c++;
            } else if (board[i][j] == 'B') {
                Battleship[b] = index;
                b++;
            } else if (board[i][j] == 'D') {
                Destroyer[d] = index;
                d++;
            } else if (board[i][j] == 'S') {
                Submarine[s] = index;
                s++;
            } else if (board[i][j] == 'P') {
                Patrol[p] = index;
                p++;
            }
        }
    }
}

//Finds out a random location index of a random ship and returns the index
string showShip(string Carrier[5], string Battleship[4], string Destroyer[3], string Submarine[3], string Patrol[2]) {
    int k = rand() % 5, i = rand(), xc;
    char x, y;
    string location = "";
    if (k == 0) {
        i = i % 5;
        xc = int(Carrier[i][0]);
        x = char(xc+17);
        y = Carrier[i][1];
        location.append(1, x);
        location.append(1, y);
    } else if (k == 1) {
        i = i % 4;
        xc = int(Battleship[i][0]);
        x = char(xc+17);
        y = Battleship[i][1];
        location.append(1, x);
        location.append(1, y);
    } else if (k == 2) {
        i = i % 3;
        xc = int(Destroyer[i][0]);
        x = char(xc+17);
        y = Destroyer[i][1];
        location.append(1, x);
        location.append(1, y);
    } else if (k == 3) {
        i = i % 3;
        xc = int(Submarine[i][0]);
        x = char(xc+17);
        y = Submarine[i][1];
        location.append(1, x);
        location.append(1, y);
    } else {
        i = i % 2;
        xc = int(Patrol[i][0]);
        x = char(xc+17);
        y = Patrol[i][1];
        location.append(1, x);
        location.append(1, y);
    }
    return location;
}

//Destroys a random ship on the grid
void shipExplode(char board[11][11], string Carrier[5], string Battleship[4], string Destroyer[3], string Submarine[3], string Patrol[2]) {
    int x, y, k;
    k = rand() % 5;
    if (k == 0) {
        for (int i = 0; i < 5; i++) {
            x = int(Carrier[i][0]) - 47;
            y = int(Carrier[i][1]) - 47;
            board[x][y] = 'o';
        }
    } else if (k == 1) {
        for (int i = 0; i < 4; i++) {
            x = int(Battleship[i][0]) - 47;
            y = int(Battleship[i][1]) - 47;
            board[x][y] = 'o';
        }
    } else if (k == 2) {
        for (int i = 0; i < 3; i++) {
            x = int(Destroyer[i][0]) - 47;
            y = int(Destroyer[i][1]) - 47;
            board[x][y] = 'o';
        }
    } else if (k == 3) {
        for (int i = 0; i < 3; i++) {
            x = int(Submarine[i][0]) - 47;
            y = int(Submarine[i][1]) - 47;
            board[x][y] = 'o';
        }
    } else {
        for (int i = 0; i < 2; i++) {
            x = int(Patrol[i][0]) - 47;
            y = int(Patrol[i][1]) - 47;
            board[x][y] = 'o';
        }
    }
}

//Checks if the Carrier on the grid has exploded
//Returns true if it has exploded, false if it's not
bool carrierLost(char board[11][11], string Carrier[5]) {
    int count = 0;
    for (int i = 0; i < 5; i++) {
        int x = (Carrier[i][0] - '0');
        int y = (Carrier[i][1] - '0');
        if (board[x+1][y+1] == 'o') {
            count++; 
        }
    }
    if (count == 5) {
        return true;
    } else {
        return false;
    }
}

//Check if the Battleship on the grid is wrecked
bool battleshipLost(char board[11][11], string Battleship[4]) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        int x = (Battleship[i][0] - '0');
        int y = (Battleship[i][1] - '0');
        if (board[x+1][y+1] == 'o') {
            count++; 
        }
    }
    if (count == 4) {
        return true;
    } else {
        return false;
    }
}

//Check if the Destroyer/Submarine on the grid is obliterated
bool destroyerLost(char board[11][11], string Destroyer[3]) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        int x = (Destroyer[i][0] - '0');
        int y = (Destroyer[i][1] - '0');
        if (board[x+1][y+1] == 'o') {
            count++; 
        }
    }
    if (count == 3) {
        return true;
    } else {
        return false;
    }
}

//Check if the Patrol Boat on the grid is annihilated
bool patrolLost(char board[11][11], string Patrol[2]) {
    int count = 0;
    for (int i = 0; i < 2; i++) {
        int x = (Patrol[i][0] - '0');
        int y = (Patrol[i][1] - '0');
        if (board[x+1][y+1] == 'o') {
            count++; 
        }
    }
    if (count == 2) {
        return true;
    } else {
        return false;
    }
}

//Check if all the ships on the grid has been sunk
//Returns true if no ships remains, false if at least one ship is on the grid
bool noShips(char board[11][11], string Carrier[5], string Battleship[4], string Destroyer[3], string Submarine[3], string Patrol[2]) {
    if (carrierLost(board, Carrier) && battleshipLost(board, Battleship) && destroyerLost(board, Destroyer) && destroyerLost(board, Submarine) && patrolLost(board, Patrol)) {
        return true;
    } else {
        return false;
    }
}

//Saves the grid into a file
//string file:Name of the file
void save(char board[11][11], string file) {
    ofstream fout;
    fout.open(file);
    fout.write((char *) board, 121);
    fout.close();
}

//Loads a grid from a file
void load(char board[11][11], string file) {
    ifstream fin;
    fin.open(file, ios::in);
    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 11; j++){
            fin >> board[i][j];
        }
    }
    fin.close();
}

//Computer attacks the player's grid
void cpuAttack(char board[11][11], string C[5], string B[4], string D[3], string S[3], string P[2]) {
    cout << "Wei Kingdom's turn to attack!" << '\n';
    while (true) {
        int x = rand() % 10 + 1, y = rand() % 10 + 1;
        string index;
        if (board[x][y] == 'o' || board[x][y] == 'X') {
            continue;
        } else {
            char xcoor = char(x+64), ycoor = char(y+47);
            index.append(1, xcoor);
            index.append(1, ycoor);
            cout << "Wei Kingdom attacked " << index << "!" << '\n';
            if (board[x][y] == '~') {
                cout << "Wei Kingdom missed! Your turn." << '\n';
                board[x][y] = 'X';
                showBoard(board);
            } else {
                cout << "Wei Kingdom hit your ship! ";
                board[x][y] = 'o';
                if (noShips(board, C, B, D, S, P)) {
                    break;
                } else {
                    cout << "They get to attack once more. \n";
                    continue;
                }
            }
        }
        break;
    }
}

//Player attacks the Computer's grid
//Or decides to save the game progress
bool playerAttack(char realboard[11][11], char output[11][11], char playerBoard[11][11], int &k, string C[5], string B[4], string D[3], string S[3], string P[2], string pC[5], string pB[4], string pD[3], string pS[3], string pP[2]) {
    cout << "Your turn to attck! \n";
    bool e = false;
    while (!e) {
        showBoard(output);
        cout << "Enter the square you'd like to attack: ";
        string index;
        cin >> index;
        int x = int(index[0]) - 64;
        int y = int(index[1]) - 47;
        if (index == "save") {
            save(playerBoard, "player.txt");
            save(realboard, "real.txt");
            save(output, "out.txt");
            e = true;
            cout << "Game Saved, See you next time!";
            continue;
        }
        if (index.length() != 2) {
            cout << "Incorrect index format! \n";
            continue;
        }
        if (x < 1 || x > 10) {
            cout << "Row index must be between 'A' and 'J'! \n";
            continue;
        }
        if (y < 1 || y > 10) {
            cout << "Column index must be between 0 and 9! \n";
            continue;
        }
        if (output[x][y] != '~') {
            cout << "That square has already been hit. Try again \n";
            continue;
        } else {
            if (realboard[x][y] == '~') {
                cout << "You missed. It's Wei Kingdom's turn. \n";
                output[x][y] = 'X';
                showBoard(output);
            } else if (realboard[x][y] == 'N') {
                output[x][y] = '!';
                if (NumberGuess() == 0) {
                    cout << "One of Wei Kingdom's ships exploded and sunk itself \n";
                    shipExplode(output, C, B, D, S, P);
                } else {
                    cout << "One of your ships exploded and sunk itself \n";
                    shipExplode(playerBoard, pC, pB, pD, pS, pP);
                }
            } else if (realboard[x][y] == 'R') {
                output[x][y] = '!';
                if (RPS() == 0) {
                    continue;
                } else {
                    cpuAttack(playerBoard, pC, pB, pD, pS, pP);
                }
            } else if (realboard[x][y] == 'Q') {
                output[x][y] = '!';
                if (k == 1) {
                    int mc = MC1();
                    if (mc == 0) {
                        cout << "One of Wei Kingdom's ship is at " << showShip(C, B, D, S, P) << '\n';
                    }
                    k++;
                } else if (k == 2) {
                    int mc = MC2();
                    if (mc == 0) {
                        cout << "One of Wei Kingdom's ship is at " << showShip(C, B, D, S, P) << '\n';
                    }
                    k++;
                } else if (k == 3) {
                    int mc = MC3();
                    if (mc == 0) {
                        cout << "One of Wei Kingdom's ship is at " << showShip(C, B, D, S, P) << '\n';
                    }
                    k++;
                } else if (k == 4) {
                    int mc = MC4();
                    if (mc == 0) {
                        cout << "One of Wei Kingdom's ship is at " << showShip(C, B, D, S, P) << '\n';
                    }
                    k++;
                }
            } else {
                cout << "You hit Wei Kingdom's ship!" << '\n';
                output[x][y] = 'o';
                if (noShips(output, C, B, D, S, P)) {
                    break;
                } else {
                    cout << "You may attack once more \n";
                   continue; 
                }
            }
        }
        break;
    }
    return e;
}

int main() {
    int size = 11;
    char playerBoard[11][11];
    char cpuRealBoard[11][11];
    char cpuoutputBoard[11][11];
    bool end = true;
    bool win;
    int q = 1;
    int k = 1;
    int i;
    string *winner = new string;
    cout << "----------Battleship (The Three Kingdoms version)----------\n Type 'new' to start a new game, Type 'load' to load an unfinished game. ";
    string game;
    cin >> game;
    if (game == "new") {
        string name;
        int i;
        cout << "Kong Ming: (ノ*゜▽゜*) Welcome to the Three Kingdoms, Brave! I am elf Kong Ming (孔明) , your guide here! Could you please tell me your name?" << endl;
        cout << "You: ";
        cin >> name;
        cout << "Kong Ming: " << name << "? what a pretty name! Unfortunately, I am very sorry to tell you that our Shu Kingdom (蜀國) is facing an unprecedented crisis: our hateful neighbour, the Wei Kingdom（魏國）is launching an attack on us. They are too strong to be defeated! "<< name << ", you are our last hope. Please help us to beat them! "<< endl;
        cout << "Press 0 to continue ";
        cin >> i;
        cout << "You: Kong Ming, there is no need to worry. I will help you." << endl;
        cout << "Press 0 to continue ";
        cin >> i;
        cout << "Kong Ming: Thank you very much, " << name << "! Now you are going to lead our soldiers to fight with the Wei army led by Cao Cao（曹操）, the king of Wei! Defeat him to rescue our kingdom?" << endl;
        cout << "Press 0 to continue ";
        cin >> i;
        cout << "You: I see... but what should I do to defeat him?" << endl;
        cout << "Press 0 to continue ";
        cin >> i;
        cout << "Kong Ming: The battle will take place in the Red Cliffs（赤壁）. Please sink all Cao's balttleships!" << endl;
        cout << "Press 0 to continue ";
        cin >> i;
        cout << "You: Well, okay..." << endl;
        cout << "Stage 1: Prepare for War \nArrange your ships one by one by typing in the location index of both ends." << '\n';
        initializePlayer(playerBoard);
        initializeCPU(cpuRealBoard, cpuoutputBoard);
        specialSquares(cpuRealBoard);
        cout << "Both players have arranged their ships. The war starts! \nStage 2: Attack your opponents \n";
        k = rand() % 2;
        if (k == 1) {
            cout << "Shu Kingdom (You) attack first" << '\n';
        } else {
            cout << "Wei Kingdom (Your Opponent) attack first" << '\n';
        }        
    } else if (game == "load") {
        load(playerBoard, "player.txt");
        load(cpuRealBoard, "real.txt");
        load(cpuoutputBoard, "out.txt");
    }
    shipLocate(playerBoard, player.Carrier, player.Battleship, player.Destroyer, player.Submarine, player.Patrol);
    shipLocate(cpuRealBoard, cpu.Carrier, cpu.Battleship, cpu.Destroyer, cpu.Submarine, cpu.Patrol);
    while (end) {
        if (k % 2 == 1) {
            if (playerAttack(cpuRealBoard, cpuoutputBoard, playerBoard, q, cpu.Carrier, cpu.Battleship, cpu.Destroyer, cpu.Submarine, cpu.Patrol, player.Carrier, player.Battleship, player.Destroyer, player.Submarine, player.Patrol)) {
                return 0;
            } else {
                if (noShips(cpuoutputBoard, cpu.Carrier, cpu.Battleship, cpu.Destroyer, cpu.Submarine, cpu.Patrol)) {
                    *winner = "Shu Kingdom";
                    win = true;
                    end = false;
                } else {
                    k++;
                }
            }

        } else {
            cpuAttack(playerBoard, player.Carrier, player.Battleship, player.Destroyer, player.Submarine, player.Patrol);
            if (noShips(playerBoard, player.Carrier, player.Battleship, player.Destroyer, player.Submarine, player.Patrol)) {
                *winner = "Wei Kingdom";
                win = false;
                end = false;
            } else {
                k++;
            }
        }
    }
    cout << *winner << " WINS!!! \n";
    if (win) {
        cout << "Kong Ming: Thank you, Brave! You save our kingdom! We will remember your blessing forever!" << endl;
        cout << "Press 0 to continue ";
        cin >> i;
        cout << "You: You are welcome, Kong Ming. It is time for me to leave. Goodbye, and thank you." << endl;
        cout << "Press 0 to continue ";
        cin >> i;
        cout << "Kong Ming: Goodbye, hero." << endl;
    } else {
        cout << "Despite your stubborn resistance， Cao Cao led the Wei army to win the battle" << endl;
        cout << "Press 0 to continue ";
        cin >> i;
        cout << "Cao Cao: What a costly victory! Brave, to me, you are the greatest threat, and I am not going to let you go. Send this him to the prison!" << endl;
        cout << "Press 0 to continue ";
        cin >> i;
        cout << "You: NO!!!" << endl;
    }
    delete winner;
    winner = 0;
    return 0;
}
