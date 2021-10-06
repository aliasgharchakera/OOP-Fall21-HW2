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
//void display(char* dungeon, cint width, cint height);
int main ()
{
    srand(time(0));

    int width; int height;
    cout << "Enter the width of the dungeon: "; cin >> width;
    cout << "Enter the height of the dungeon: "; cin >> height;
    while ((width < 8) | (height < 8)){ //in case the input is less than 8
        cout << "The width or height of the dungeon cannot be less than 8" << endl;
        cout << "Enter the width of the dungeon again: "; cin >> width;
        cout << "Enter the height of the dungeon again: "; cin >> height;
    }
    /*
    *   ADD YOUR CODE HERE IF REQUIRED
    */

    Point startPoint(1,1); // taking the starting point as (1, 1) because the first row and column are the boundary walls
    Point exitPoint(0,0);
    char* dungeon = nullptr;
    dungeon = CreateDungeon(width, height, startPoint, exitPoint);
    //display(dungeon, width, height);
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
   int r = rand() % 2;//randomizing statements
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
   int r = rand()%2;//randomizing statements
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
   int r = rand()%2;//randomizing statements
   if (r==0){
       cout<<"You win!!FATALITY!"<<endl;
   } 
   else if(r==1){
       cout<<"Your 42069 kicks sent the opponent straight to HELL!!"<<endl;
   }
   else{
       cout<<"The opponent died mysteriously!"<<endl;
   }
}

void GetHitStatements()
{
    /*
    *   ADD YOUR CODE HERE AS REQUIRED
    */
   int r = rand()%2;//randomizing statements
   if (r==0){
       cout<<"You got RKO'd outta nowhere"<<endl;
   } 
   else if(r==1){
       cout<<"You got HIT!!"<<endl;
   }
   else{
       cout<<"You have been stunned!!"<<endl;
   }
}

void Traversal(char* dungeon, Point& startPoint, cPoint& exitPoint, cint width, cint height)
{
    /*
    *   ADD YOUR CODE HERE AS REQUIRED. DEFINE NEW FUNCTIONS IF IT GETS LONG.
    */
   char direction, location;
   Player P;
   P.x = startPoint.x; P.y = startPoint.y; //initial position is the top left corner
   while (true){
        cout << "Which direction would you like to move in: \n";
        cout << "W to go up \nS to go down \nD to go right \nA to go left \nPress X if you want to give up and die.\n"; //asking for input
        cin >> direction;
        if ((direction == 'w') |(direction == 'W')){ //identifying key presses
            if (dungeon[(P.y - 1)*width + P.x] != 'W'){
                location = dungeon[(P.y - 1)*width + P.x];
                cout << "Possible move up, " << location << endl;
                P.y--;
                if (location == 'T'){ //calling trapstatements because you've walked into a trap
                    P.health--;
                    TrapStatements();
                    cout << "You have " << P.health << " health left\n";
                }
                else if (location == 'H'){
                    if (P.health == 10);
                    else P.health++;
                    cout << "You found some health" << endl;
                    cout << "You have currently " << P.health << " health left\n";
                }
                else if (location == 'F'){
                    int food;
                    food = rand () % 5 + 4;
                    P.food += food;
                    FoodStatements();
                }
                else if (location == 'E'){ //calling combat since enemies have been encountered
                    Combat(P, rand () % 3 + 2);
                }
                else if (location == 'X'){
                    cout << "You won!" << endl;
                    break; //breaking since the game has been won
                }
            }
            else{
                cout << "Cant go there!" <<endl; //way blocked by a wall
            }
        }
        else if ((direction == 'd') |(direction == 'D')){ //identifying key presses
            if (dungeon[(P.y)*width + (P.x + 1)] != 'W'){
                location = dungeon[(P.y)*width + (P.x + 1)];
                cout << "Possible move right, " << location << endl;
                P.x++;
                if (location == 'T'){
                    P.health--;
                    TrapStatements();
                    cout << "You have " << P.health << " health left\n";
                }
                else if (location == 'H'){
                    if (P.health == 10);
                    else P.health++;
                    cout << "You found some health" << endl;
                    cout << "You have currently " << P.health << " health left\n";
                }
                else if (location == 'F'){
                    int food;
                    food = rand () % 5 + 4;
                    P.food += food;
                    FoodStatements();
                }
                else if (location == 'E'){ //calling combat since enemies have been encountered
                    Combat(P, rand () % 3 + 2);
                }
                else if (location == 'X'){
                    cout << "You won!" << endl;
                    break;
                }
            }
            else{
                cout << "Cant go there!" <<endl;
            }
        }
        else if ((direction == 's') |(direction == 'S')){ //identifying key presses
            if (dungeon[(P.y + 1)*width + P.x] != 'W'){
                location = dungeon[(P.y + 1)*width + P.x];
                cout << "Possible move down, " << location << endl;
                P.y++;
                if (location == 'T'){
                    P.health--;
                    TrapStatements();
                    cout << "You have " << P.health << " health left\n";
                }
                else if (location == 'H'){
                    if (P.health == 10);
                    else P.health++;
                    cout << "You found some health" << endl;
                    cout << "You have currently " << P.health << " health left\n";
                }
                else if (location == 'F'){
                    int food;
                    food = rand () % 5 + 4;
                    P.food += food;
                    FoodStatements();
                }
                else if (location == 'E'){ //calling combat since enemies have been encountered
                    Combat(P, rand () % 3 + 2);
                }
                else if (location == 'X'){
                    cout << "You won!" << endl;
                    break;
                }
            }
            else{
                cout << "Cant go there!" <<endl;
            }
        }
        else if ((direction == 'a') |(direction == 'A')){ //identifying key presses
            if (dungeon[(P.y)*width + (P.x - 1)] != 'W'){
                location = dungeon[(P.y)*width + (P.x - 1)];
                cout << "Possible move left, " << location << endl;
                P.x--;
                if (location == 'T'){
                    P.health--;
                    TrapStatements();
                    cout << "You have " << P.health << " health left\n";
                }
                else if (location == 'H'){
                    if (P.health == 10);
                    else P.health++;
                    cout << "You found some health" << endl;
                    cout << "You have currently " << P.health << " health left\n";
                }
                else if (location == 'F'){
                    int food;
                    food = rand () % 5 + 4;
                    P.food += food;
                    FoodStatements();
                }
                else if (location == 'E'){ //calling combat since enemies have been encountered
                    Combat(P, rand () % 3 + 2);
                }
                else if (location == 'X'){
                    cout << "You won!" << endl;
                    break;
                }
            }
            else{
                cout << "Cant go there!" <<endl;
            }
        }
        else if ((direction == 'x') | (direction == 'X')){ //identifying key presses
            P.alive = false;
            cout << "You died!" << endl;
            break;
        }
        else{ //in case there are any invalid key presses
            cout << "Please enter a valid command" << endl;
        }
        P.food--; //consuming 1 food per move
        cout << "You have food for " << P.food << " more turn(s)" << endl;
        if (P.food == 0){//checking if food is left or not
            P.alive = false;
            cout << "You ran out of food and starved to death!" << endl;
            break;
        }
        if (P.health == 0){//checking if health is left or not
            P.alive = false;
            cout << "Your health ended, you're dead!" <<endl;
            break;
        }
        if (P.alive == false){
            cout << "You DIED!" << endl;
            break;
        }
   }
   //exitPoint.x = P.x; exitPoint.y = P.y;
   cout << "Game Ended!" << endl; //when the loop ends/breaks the game ends 
}

void Combat(Player &player, int enemies)
{
    /*
    *   ADD YOUR CODE HERE AS REQUIRED
    */
    //Player p1;
    // int enemy = rand()%2 + 2;
    // enemies +=enemy;
    int var, e_dead = 0; //keeping track of enemies dead
    while (enemies>0 & player.alive)
    {
        var = rand() % 3;
        if (var == 1)
        {
            HitStatements(); //enemy takes hit
            enemies--; e_dead++;
            cout << e_dead << " enem(ies) down " << enemies << " to go" << endl;
        }
        var = rand() % 10;
        if (var == 2)
        {
            player.health--;
            GetHitStatements(); //player takes hit
            cout << "You have " << player.health << " health left!" << endl;
        }
        if (player.health == 0){ //player dies
            player.alive = false;
        }
    }
    if (enemies == 0){
        cout << "Great Job, you knocked em all out!" <<endl;
    }
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
       dungeon[i] = ' '; //to get rid of any garbage values that may occur at empty spaces
   }
   for (int i = 0; i < width*height; i++){
       bruh = i%width;
       //cout << bruh << ", " << i << endl;
       if ((i < width) | (bruh == 0) | (bruh == (width - 1)) | (i > width*(height - 1))){ //creating boundary walls
            dungeon[i] = 'W';
       }
       else if ((rand () % 5 + 1) == 1){
            int var2;
            //cout << "bruh" <<endl;
            var2 = rand () % 100;
            if (var2 < 16)
                dungeon[i] = 'E'; //randomizing enemies
            else if (var2 > 15 and var2 < 31)
                dungeon[i] = 'H'; //randomizing health packs
            else if (var2 > 30 and var2 < 46)
                dungeon[i] = 'T'; //randomizing traps
            else if (var2 > 45 and var2 < 61)
                dungeon[i] = 'F'; //randomizing food
            else 
                dungeon[i] = 'W'; //randomizing walls
       }
   }
   dungeon[width + 1] = 'P'; //setting the initial position at the top left corner
   dungeon[width*height - width - 2] = 'X'; //setting the edit at the bottom right corner
   return dungeon;
}

// void display(char* dungeon, cint width, cint height){ //function to help code the game
//     for (int i = 0; i < width*height; i ++){
//         if ((i !=0) & (i%(width) == 0)){
//             cout << endl;
//         }
//         cout << dungeon[i] << " ";
//     }
//     cout << endl;
// }
