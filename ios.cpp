#include <iostream>
#include <fstream>
using namespace std;
 
struct ships {
    string Carrier[5];
    string Battleship[4];
    string Destroyer[3];
    string Submarine[3];
    string Patrol[2];
} playerSave,cpuSave;
 
int shipsWrite()
{
    ofstream fout;
    fout.open("ships.txt", ios::app);
    playerSave.Carrier = player.Carrier;
    playerSave.Battleship = player.Battleship;
    playerSave.Destroyer = player.Destroyer;
    playerSave.Submarine = player.Submarine;
    playerSave.Patrol = player.Patrol;
    cpuSave.Carrier = cpu.Carrier;
    cpuSave.Battleship = cpu.Battleship;
    cpuSave.Destroyer = cpu.Destroyer;
    cpuSave.Submarine = cpu.Submarine;
    cpuSave.Patrol = cpu.Patrol;
    
    fout.write((char*)&playerSave, sizeof(playerSave));
    fout.write((char*)&cpuSave, sizeof(cpuSave));

    return 0;
}
 
int shipsRead()
{
    ifstream fin;
    fin.open("Input.txt", ios::in);
    fin.read((char*)&playerSave, sizeof(playerSave));
    fin.read((char*)&cpuSave, sizeof(cpuSave));
    player.Carrier = playerSave.Carrier;
    player.Battleship = playerSave.Battleship;
    player.Destroyer = playerSave.Destroyer;
    player.Submarine = playerSave.Submarine;
    player.Patrol = playerSave.Patrol;
    cpu.Carrier = cpuSave.Carrier;
    cpu.Battleship = cpuSave.Battleship;
    cpu.Destroyer = cpuSave.Destroyer;
    cpu.Submarine = cpuSave.Submarine;
    cpu.Patrol = cpuSave.Patrol;
    
    return 0;
}
void save()
{
    ofstream fout;
    fout.open("ships.txt", ios::app);
    string** playerBoard2 = new string* [11];
    string** cpuRealBoard2 = new string* [11];
    string** cpuoutputBoard2 = new string* [11];
    for (int i = 0; i < 11; i++) {
        playerBoard2[i] = new string[11];
        cpuRealBoard2[i] = new string[11];
        cpuoutputBoard2[i] = new string[11];
    }
    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 11 j++){
            playerBoard2[i][j] = playerBoard[i][j];
            cpuRealBoard2[i][j] = cpuRealBoard[i][j];
            cpuoutputBoard2[i][j] = cpuoutputBoard[i][j];
        }
    }
    fout.write((char *) playerBoard2, sizeof playerBoard2);
    fout.write((char *) cpuRealBoard2, sizeof cpuRealBoard2);
    fout.write((char *) cpuoutputBoard2, sizeof cpuoutputBoard2);
    fout.close();
}

void load(string** playerBoard2, string** cpuRealBoard, string** cpuoutputBoard)
{
    ifstream fin;
    fin.open("Input.txt", ios::in);
    fin.read((char*)&playerBoard2, sizeof(playerBoard2));
    fin.read((char*)&cpuRealBoard2, sizeof(cpuRealBoard2));
    fin.read((char*)&ccpuoutputBoard2, sizeof(cpuoutputBoard2));

    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 11 j++){
            playerBoard[i][j] = playerBoard2[i][j];
            cpuRealBoard[i][j] = cpuRealBoard2[i][j];
            cpuoutputBoard[i][j] = cpuoutputBoard2[i][j];
        }
    }
    fin.close();
}
