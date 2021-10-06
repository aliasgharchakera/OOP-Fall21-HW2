#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

void CreateDungeon(int width, int height)
{
    /*
    *   ADD YOUR CODE HERE AS REQUIRED. DEFINE NEW FUNCTIONS IF IT GETS LONG.
    */
   char dungeon[width*height];
   int bruh;
   for (int i = 0; i < width*height; i++){
       bruh = i%width;
       cout << bruh << ", " << i << endl;
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
        if (i == (width*height - 1))
            dungeon[i] = 'X';
   }
   int j;
   for (int i = 0; i < width*height; i++){
       cout << dungeon[i] << ", ";
       j = (i + 1)%width;
       if (j == 0){
           cout << endl;
       }
   }

}
int main(){
    //int i = 1;
    // int var, n = 30;
    // //cin >> n;
    // for (int i = 0; i < n; i++){
    //     var = rand() % n;
    //     if (var == n)
    //         cout << "Random number is " << var << endl;
    //     else
    //         cout << "Random number is not " << n << " and is " << var << endl;
    // }
    CreateDungeon(8, 8);
    //cout << "bruh" << endl;
    return 0;
}