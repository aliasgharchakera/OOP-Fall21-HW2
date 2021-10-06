#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Structure to keep track of various locations
struct Point
{
    int x;
    int y;

    Point(int _x, int _y): x(_x), y(_y)
    {

    }
};
//Structure for the Player object
struct Player
{
    int food;
    int health;
    bool alive;
    int x;
    int y;
    Player()
    {
        food = 64;
        health = 10;
        alive = true;
    }
    void loseHealth()
    {
        if(health>0)
            health--;
        if(health==0)
            alive = false;
    }
    void gainHealth()
    {
        if(health<10)
            health++;
    }
};

typedef const int cint;         //Google typedef to see what this means
typedef const Point cPoint;

char* CreateDungeon(int, int, Point&, Point&);      //Creates the dungeon
void Traversal(char*, Point&, cPoint&, cint, cint); //Used for moving inside dungeon
void Combat(Player&, int);  //Used for simulating combat
void TrapStatements();  //3 statements that show at random when the player activates a trap
void FoodStatements();  //3 statements that show at random when the player finds food
void HitStatements();   //3 statements that show at random when the player hits enemy
void GetHitStatements();//3 statements that show at random when the player gets hit
void display(char* dungeon, cint width, cint height);
int main ()
{
    srand(time(0));

    int width; int height;
    cout << "Enter the width of the dungeon: "; cin >> width;
    cout << "Enter the height of the dungeon: "; cin >> height;
    /*
    *   ADD YOUR CODE HERE IF REQUIRED
    */

    Point startPoint(1,1);
    Point exitPoint(0,0);
    char* dungeon = nullptr;
    dungeon = CreateDungeon(width, height, startPoint, exitPoint);
    display(dungeon, width, height);
    Traversal(dungeon, startPoint, exitPoint, width, height);

    /*
    *   ADD YOUR CODE HERE IF REQUIRED
    */

    return 0;
}

void TrapStatements()
{
    /*
    *   ADD YOUR CODE HERE AS REQUIRED

    */
   int r = rand() % 2;
   if(r==0){
       cout<<"You have hit a trap!"<<endl;
   }
   else if(r==1){
       cout<<"You fell in a hole!"<<endl;
   }
   else{
       cout<<"You were abducted by aliens!!"<<endl;
   } 
}


void FoodStatements()
{
    /*
    *   ADD YOUR CODE HERE AS REQUIRED
    */
   int r = rand()%2;
   if(r==0){
       cout<<"Picked up energy drink!!"<<endl;
   }
   else if (r==1){
       cout<<"Picked up Krazy Hamborger!!"<<endl;
   }
   else{
    cout<<"You ate DzNuts(Dried Fruit)!!"<<endl;
   }
}

void HitStatements()
{
    /*
    *   ADD YOUR CODE HERE AS REQUIRED
    */
}

void GetHitStatements()
{
    /*
    *   ADD YOUR CODE HERE AS REQUIRED
    */
}

void Traversal(char* dungeon, Point& startPoint, cPoint& exitPoint, cint width, cint height)
{
    /*
    *   ADD YOUR CODE HERE AS REQUIRED. DEFINE NEW FUNCTIONS IF IT GETS LONG.
    */
   char direction, location;
   Player P;
   P.x = startPoint.x; P.y = startPoint.y;
   while (P.food > 0){
        cout << "Enter W to go up \nEnter S to go down \nEnter D to go right \nEnter A to go left\n";
        cin >> direction;
        if ((direction == 'w') |(direction == 'W')){
            if (dungeon[(P.y - 1)*width + P.x] != 'W'){
                location = dungeon[(P.y - 1)*width + P.x];
                cout << "Possible move up, " << location << endl;
                P.y--;
                if (location == 'T'){
                    P.health--;
                    TrapStatements();
                }
                else if (location == 'H'){
                    P.health++;
                    cout << "You received 1 health" << endl;
                }
                else if (location == 'F'){
                    int food;
                    food = rand () % 5 + 4;
                    P.food += food;
                    FoodStatements();
                }
                else if (location == 'E'){

                }
                else if (location == 'X'){
                    cout << "You won!" << endl;
                    break;
                }
                if (P.food == 0){
                    cout << "You died!" << endl;
                }
            }
            else{
                P.food--;
                cout << "Cant go there!" <<endl;
            }
        }
        else if ((direction == 'd') |(direction == 'D')){
            if (dungeon[(P.y)*width + (P.x + 1)] != 'W'){
                location = dungeon[(P.y)*width + (P.x + 1)];
                cout << "Possible move right, " << location << endl;
                P.x++;
                if (location == 'T'){
                    P.health--;
                    TrapStatements();
                }
                else if (location == 'H'){
                    P.health++;
                    cout << "You received 1 health" << endl;
                }
                else if (location == 'F'){
                    int food;
                    food = rand () % 5 + 4;
                    P.food += food;
                    FoodStatements();
                }
                else if (location == 'E'){

                }
                else if (location == 'X'){
                    cout << "You won!" << endl;
                    break;
                }
                if (P.food == 0){
                    cout << "You died!" << endl;
                }
            }
            else{
                P.food--;
                cout << "Cant go there!" <<endl;
            }
        }
        else if ((direction == 's') |(direction == 'S')){
            if (dungeon[(P.y + 1)*width + P.x] != 'W'){
                location = dungeon[(P.y + 1)*width + P.x];
                cout << "Possible move down, " << location << endl;
                P.y++;
                if (location == 'T'){
                    P.health--;
                    TrapStatements();
                }
                else if (location == 'H'){
                    P.health++;
                    cout << "You received 1 health" << endl;
                }
                else if (location == 'F'){
                    int food;
                    food = rand () % 5 + 4;
                    P.food += food;
                    FoodStatements();
                }
                else if (location == 'E'){

                }
                else if (location == 'X'){
                    cout << "You won!" << endl;
                    break;
                }
                if (P.food == 0){
                    cout << "You died!" << endl;
                }
            }
            else{
                P.food--;
                cout << "Cant go there!" <<endl;
            }
        }
        else if ((direction == 'a') |(direction == 'A')){
            if (dungeon[(P.y)*width + (P.x - 1)] != 'W'){
                location = dungeon[(P.y)*width + (P.x - 1)];
                cout << "Possible move left, " << location << endl;
                P.x--;
                if (location == 'T'){
                    P.health--;
                    TrapStatements();
                }
                else if (location == 'H'){
                    cout << "You received 1 health" << endl;
                    P.health++;
                }
                else if (location == 'F'){
                    int food;
                    food = rand () % 5 + 4;
                    P.food += food;
                    FoodStatements();
                }
                else if (location == 'E'){

                }
                else if (location == 'X'){
                    cout << "You won!" << endl;
                    break;
                }
                if (P.food == 0){
                    cout << "You died!" << endl;
                }
            }
            else{
                P.food--;
                cout << "Cant go there!" <<endl;
            }
        }
        else if ((direction == 'x') | (direction == 'X')){
            cout << "You died!" << endl;
            break;
        }
        else{
            cout << "Please enter a valid command" << endl;
            P.food--;
        } 
   }
   //exitPoint.x = P.x; exitPoint.y = P.y;
   cout << "Game Ended!" << endl;
}

void Combat(Player& player, int enemies)
{
    /*
    *   ADD YOUR CODE HERE AS REQUIRED
    */
}

char *CreateDungeon(int width, int height,Point &startPoint, Point &exitPoint)
{
    /*
    *   ADD YOUR CODE HERE AS REQUIRED. DEFINE NEW FUNCTIONS IF IT GETS LONG.
    */
   char *dungeon;
   dungeon = new char [width*height];
   int bruh;
   for (int i = 0; i < width*height; i++){
       dungeon[i] = ' ';
   }
   for (int i = 0; i < width*height; i++){
       bruh = i%width;
       //cout << bruh << ", " << i << endl;
       if ((i < width) | (bruh == 0) | (bruh == (width - 1)) | (i > width*(height - 1))){
            dungeon[i] = 'W';
       }
       else if ((rand () % 5 + 1) == 1){
            int var2;
            //cout << "bruh" <<endl;
            var2 = rand () % 100;
            if (var2 < 16)
                dungeon[i] = 'E';
            else if (var2 > 15 and var2 < 31)
                dungeon[i] = 'H';
            else if (var2 > 30 and var2 < 46)
                dungeon[i] = 'T';
            else if (var2 > 45 and var2 < 61)
                dungeon[i] = 'F';
            else 
                dungeon[i] = 'W';
       }
   }
   dungeon[width + 1] = 'P';
   dungeon[width*height - width - 2] = 'X';
   return dungeon;
}

void display(char* dungeon, cint width, cint height){
    for (int i = 0; i < width*height; i ++){
        if ((i !=0) & (i%(width) == 0)){
            cout << endl;
        }
        cout << dungeon[i] << " ";
    }
    cout << endl;
}
