/***********************************************************************
* A simple text-based sudoku program
************************************************************************/

#include <fstream>
#include <iostream>
using namespace std;

/**********************************************************************
 * prompts user for filename 
 ***********************************************************************/
void getFilename(char filename[])
{
   cout << "Where is your board located? ";
   cin >> filename;
}

/**********************************************************************
 * reads file into an array
 ***********************************************************************/
int readFile(int board[][9])
{
   char filename[256];
   getFilename(filename);

   ifstream fin(filename);

   if (fin.fail())
   {
      cout << "Unable to open file "
           << filename << endl;
      return -1;
   }

   for (int row = 0; row < 9; row++)
      for (int col = 0; col < 9; col++)
	  fin >> board[row][col];

   fin.close();
   return 0;
}

/**********************************************************************
 * displays the options for the user 
 ***********************************************************************/
void displayOptions()
{
   cout << "Options:\n";
   cout << "   ?  Show these instructions\n";
   cout << "   D  Display the board\n";
   cout << "   E  Edit one square\n";
   cout << "   S  Show the possible values for a square\n";
   cout << "   Q  Save and Quit\n\n";
}

/**********************************************************************
 * displays the sudoku board
 ***********************************************************************/
void displayBoard(int board[][9])
{
  int sideNumber = 1;
  cout << "   A B C D E F G H I\n";
   
  for (int row = 0; row < 9; row++)
    for (int col = 0; col < 9; col++)
      {

	if ((row == 3 && col == 0) || (row == 6 && col == 0))
	  cout << "   -----+-----+-----\n";
	
	if (col == 0)
	  {
            cout << sideNumber << "  ";
            sideNumber++;
	  }
	
	if ((col == 2 || col == 5) && (row != 3 || row != 6))
	  cout << board[row][col] << "|";

	else if (board[row][col] != 0)
	  cout << board[row][col] << " ";
	
	
	if (board[row][col] == 0)
	  cout << "  ";
	 
	if (col == 8)
	  cout << endl;

	if (col == 8 && row == 8)
	  cout << endl;
      }
}

/**********************************************************************
 * verifies the value input by the user based on the board
 ***********************************************************************/
void verifyValue(int board[][9])
{
}

/**********************************************************************
 * asks the user for a coordinate and a value to edit the board
 ***********************************************************************/
void editSquare(int board[][9])
{
   int row;
   char col;
   int value;

   cout << "What are the coordinates of the square: ";
   cin >> col >> row;

   int trueRow;
   int trueCol;

   trueRow = row - 1;

   if (col == 'a' || col == 'A')
      trueCol = 0;
   else if (col == 'b' || col == 'B')
      trueCol = 1;
   else if (col == 'c' || col == 'C')
      trueCol = 2;
   else if (col == 'd' || col == 'D')
      trueCol = 3;
   else if (col == 'e' || col == 'E')
      trueCol = 4;
   else if (col == 'f' || col == 'F')
      trueCol = 5;
   else if (col == 'g' || col == 'G')
      trueCol = 6;
   else if (col == 'h' || col == 'H')
      trueCol = 7;
   else
      trueCol = 8;

   if (board[trueCol][trueRow] != 0)
   {
      cout << "ERROR: Square " << "\'" << col << row << "\' is filled\n\n";
      return;
   }

   else
   {
      cout << "What is the value at \'" << col << row
           << "\': ";
      cin >> value;
      board[trueRow][trueCol] = value;
      cout << endl;
   }
}

/**********************************************************************
 * displays the possible values of the coordinate the user provides 
 ***********************************************************************/
void showPossibleValues(int board[][9])
{
}

/**********************************************************************
 * determines what option function to call based on user input 
 ***********************************************************************/
void getInput(int board[][9])
{
   char input;

   do
   {
      cout << "> ";
      cin >> input;

      if (input == '?')
         displayOptions();
      else if (input == 'd' || input == 'D')
         displayBoard(board);
      else if (input == 'e' || input == 'E')
         editSquare(board);
      else if (input == 's' || input == 'S')
         showPossibleValues(board);
      else if (input == 'q' || input == 'Q')
         return;
      else
         cout << "ERROR: Invalid command\n";
   }
   while (input != 'Q' || input != 'q');
}

/**********************************************************************
 * saves board to a file
 ***********************************************************************/
void saveFile(int board[][9])
{
   char filename[256];
   getFilename(filename);

   ofstream fout(filename);

   if (fout.fail())
   {
      cout << "Unable to write to file " << filename << endl;
      return;
   }

   for (int row = 0; row < 9; row++)
      for (int col = 0; col < 9; col++)
	fout << board[row][col] << " ";
   
   fout.close();
   cout << "Board written successully\n";
}

/**********************************************************************
 * calls other functions
 ***********************************************************************/
int main()
{
   int board[9][9];
   readFile(board);
   displayOptions();
   displayBoard(board);
   getInput(board);
   saveFile(board);
   return 0;
}
