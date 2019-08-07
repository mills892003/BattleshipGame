//  This is a program that mimicks the battleship game
//
//  Created by Milan Patel on 12/10/18.
//  Copyright © 2018 Milan Patel. All rights reserved.
//


#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <cstring>

const int a=24;                    //Const delcared for passing 2D array
const int b=24;

int Fire(int,int,char[a][b]);      //User firing hit/miss function
int FleetSunk(char[a][b]);

using namespace std;

//****************************************************************************************************

int main()
{
    ifstream inputfile;         //Set input and output steams
    ofstream outputfile;
    
    int x,y;                    //firing coordinates
    int hitmiss;
    char gameboard[a][b];     //declare array gameboard
    
    
    inputfile.open("battlefield.txt");        //open input file
    outputfile.open("finalbattlefield.txt"); //open output file
    
    for(int i=0;i<25;i++)
    {
        for(int j=0; j<25; j++)
        {
    inputfile >> gameboard[i][j];        //read input file and store coordinates for gameboard
        }
    }
    
//****************************************************************************************************
    
    
    
    
    //Game Loop
    
for(int gameover=0;gameover<1;gameover)
{
    
    
    cout<<"Please enter coordinates(25x25)"<<endl;
    cout<<"X: ";
    cin>>x;
    cout<<endl;                                         //Prompt and accept user firing coordinates
    cout<<"Y: ";
    cin>>y;
    cout<<endl;
    
    x = x-1;                                            //Adjust coordinates for C++ values
    y = y-1;
    
    hitmiss = Fire(y,x,gameboard);                      //Call the Fire function to determine hit/miss/hitagain
    
    if(hitmiss == 0)
    {
        gameboard[24-y][x] = 'X';
    }
    if(hitmiss == 1)
    {                                                   //Rewrite Gameboard using new hit/miss information
        gameboard[24-y][x] = 'H';
    }
    if(hitmiss == 2)
    {
        gameboard[24-y][x] = 'H';
    }
    
//****************************************************************************************************
    
   gameover = FleetSunk(gameboard);     //Check if game is over
    
    if(gameover == 1)
    {
        cout<<"Game Over"<<endl;
    }
    if(gameover == 0)
    {
        cout<<"Game Continues"<<endl<<endl;
    }
    
//****************************************************************************************************
    
    
}
    cout<<"The Fleet was destroyed!"<<endl;
    
    getchar();      //Hold for
    
        inputfile.close();  //close input file
    return 0;
}


//****************************************************************************************************

int Fire(int x, int y, char gameboard[a][b])
{
    int hitmiss = 0;                               //Declare return variable for hit/miss result
    
    if(gameboard[24-x][y] == '~')
    {
        cout<<"MISS"<<endl;
        hitmiss = 0;
    }
    if(gameboard[24-x][y] == '#')                      //Check board for Hit or Miss
    {
        cout<<"HIT"<<endl;\
        hitmiss = 1;
    }
    if(gameboard[24-x][y] == 'H')
    {
        cout<<"HIT AGAIN"<<endl;
        hitmiss = 2;
    }
    
    return (hitmiss);       //Return hit or miss intel
}

//****************************************************************************************************

int FleetSunk(char gameboard[a][b])
{
    int FleetDestroyed = 1;                 //Default is Fleet is completely destroyed
    
    for(int i=0;i<25;i++)
    {
        for(int j=0; j<25; j++)
        {
            if(gameboard[i][j] == '#')      //Nested For loop to check if any battleships are alive
                FleetDestroyed = 0;         //If any battleships remain mark FleetDestroyed
        }
    }
    return (FleetDestroyed);            //Return Fleet Destruction intel
}

//****************************************************************************************************
