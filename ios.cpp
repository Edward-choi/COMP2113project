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
