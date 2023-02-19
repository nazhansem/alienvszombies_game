// *******************************************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT3L 
// Names: AHMAD AIMAN NAZHAN BIN MOHD AZHAR | MUHAMMAD HAZIM NAQIUDDIN BIN HARMAN
// IDs: 1221303604 | 1221303684
// Emails: 1221303604@STUDENT.MMU.EDU.MY | 1221303684@STUDENT.MMU.EDU.MY
// Phones: 0179735739 | 0149159172
// *******************************************************************************

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

const int MAX_ROWS = 15;
const int MAX_COLS = 15;
const int MIN_ROWS_COLS = 5;

class Alien {
public:
    Alien() : hp(100), attackDamage(50), receivedDamage(50) {}
    int getHp() const { return hp; }
    int getAttackDamage() const { return attackDamage; }
private:
    int hp;
    int attackDamage;
    int receivedDamage;
};

class Zombie1 {
public:
    Zombie1() : hp(100), attackDamage(20), receivedDamage(50) {}
    int getHp() const { return hp; }
    int getAttackDamage() const { return attackDamage; }
private:
    int hp;
    int attackDamage;
    int receivedDamage;
};

class Zombie2 {
public:
    Zombie2() : hp(100), attackDamage(20), receivedDamage(50) {}
    int getHp() const { return hp; }
    int getAttackDamage() const { return attackDamage; }
private:
    int hp;
    int attackDamage;
    int receivedDamage;
};

class Boomer {
public:
    Boomer() : hp(50), attackDamage(50), receivedDamage(50) {}
    int getHp() const { return hp; }
    int getAttackDamage() const { return attackDamage; }
private:
    int hp;
    int attackDamage;
    int receivedDamage;
};

// Override the insertion operator to display the information about the characters
ostream& operator<<(ostream& os, const Alien& alien) {
    os << "\nAlien:\n";
    os << "HP = " << alien.getHp() << "\n";
    os << "Attack damage = " << alien.getAttackDamage() << "\n=====================";
    return os;
}

ostream& operator<<(ostream& os, const Zombie1& zombie1) {
    os << "Zombie1:\n";
    os << "HP = " << zombie1.getHp() << "\n";
    os << "Attack damage = " << zombie1.getAttackDamage() << "\n=====================";
    return os;
}

ostream& operator<<(ostream& os, const Zombie2& zombie2) {
    os << "Zombie2:\n";
    os << "HP = " << zombie2.getHp() << "\n";
    os << "Attack damage = " << zombie2.getAttackDamage() << "\n=====================";
    return os;
}

ostream& operator<<(ostream& os, const Boomer& boomer) {
    os << "Boomer:\n";
    os << "HP = " << boomer.getHp() << "\n";
    os << "Attack damage = " << boomer.getAttackDamage() << "\n=====================";
    return os;
}

int main() {
    // Declare variables for user input and game board
    int rows, cols;
    char board[MAX_ROWS][MAX_COLS];
	int number;
	
	srand(time(NULL));
    cout << "Let's Begin The Battle!" << endl;
	system("pause");
	system("cls");

  cout << "Welcome to The Game!" << endl;
  cout << "\n1- Start Game" << endl;
  cout << "2- Exit" << endl;

  cout << "\nEnter your choice: ";
  cin >> number;
  
  if (number == 1) 
  {
      system("cls");
      cout << "Starting Game..." << endl;
    // Get user input for number of rows and columns
    do 
	{
        cout << "\nEnter number of rows (odd number between 5 and 15): ";
        cin >> rows;
        cout << "Enter number of columns (odd number between 5 and 15): ";
        cin >> cols;
        cout << endl;
        system("cls");
    } 
	while (rows % 2 == 0 || cols % 2 == 0 || rows < MIN_ROWS_COLS || cols < MIN_ROWS_COLS ||
             rows > MAX_ROWS || cols > MAX_COLS);

    // Initialize game board with empty spaces
    cout<<" .:Alien vs Zombies:. \n" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = ' ';
        }
    }

    // Generate alien in the middle of the board
    int alienRow = rows / 2;
    int alienCol = cols / 2;
    board[alienRow][alienCol] = 'A';

    // Generate zombies, spitter, boomer, arrows, boulder, pod, and hpboost randomly on the board
    srand(time(NULL));
    int zombiesGenerated = 0;
    int spitterGenerated = 0;
    int boomerGenerated = 0;
    int arrowsGenerated = 0;
    int healthboostGenerated = 0;
    int boulderGenerated = 0;
    int podGenerated =0;

    while (zombiesGenerated < 2 || spitterGenerated < 1 || boomerGenerated < 1 || arrowsGenerated < 5 || healthboostGenerated < 2 || boulderGenerated < 2 || podGenerated < 2) {
        int randomRow = rand() % rows;
        int randomCol = rand() % cols;

        if (board[randomRow][randomCol] == ' ') {
            // Generate a zombie
            if (zombiesGenerated < 2) {
                board[randomRow][randomCol] = 'Z';
                zombiesGenerated++;
            }
            // Generate a spitter
            else if (spitterGenerated < 1) {
                board[randomRow][randomCol] = 'S';
                spitterGenerated++;
            }
            // Generate a boomer
            else if (boomerGenerated < 1) {
                board[randomRow][randomCol] = 'B';
                boomerGenerated++;
            }
            // Generate a healthboost
            else if (healthboostGenerated < 2) {
                board[randomRow][randomCol] = 'H';
                healthboostGenerated++;
            }
            // Generate a boulder
            else if (boulderGenerated < 2) {
                board[randomRow][randomCol] = 'X';
                boulderGenerated++;
            }
            // Generate a pod
            else if (podGenerated < 2) {
                board[randomRow][randomCol] = 'P';
                podGenerated++;
            }
            // Generate an arrow
            else if (arrowsGenerated < 5) {
                int randomArrow = rand() % 4;
                if (randomArrow == 0) {
                    board[randomRow][randomCol] = '<';
                    arrowsGenerated++;
                }
                else if (randomArrow == 1) {
                    board[randomRow][randomCol] = '>';
                    arrowsGenerated++;
                }
                else if (randomArrow == 2) {
                    board[randomRow][randomCol] = '^';
                    arrowsGenerated++;
                }
                else if (randomArrow == 3) {
                    board[randomRow][randomCol] = 'v';
                    arrowsGenerated++;
                }
            }
        }
    }
    while (zombiesGenerated < 2) {
    int randomRow = rand() % rows;
    int randomCol = rand() % cols;

    // Check that the zombie is not generated in a 3x3 radius around Alien
    if (board[randomRow][randomCol] == ' ' && 
        (abs(randomRow - alienRow) > 1 || abs(randomCol - alienCol) > 1)) {
        board[randomRow][randomCol] = 'Z';
        zombiesGenerated++;
    }
}

    // Print column numbers
	cout << " ";
	for (int j = 0; j < cols; j++) {
    cout << " " << ((j + 1) % 10);
	}
	cout << endl;

	// Print game board
	for (int i = 0; i < rows; i++) {
    	cout << ((i + 1) % 10) << "|";
    	for (int j = 0; j < cols; j++) {
        cout << board[i][j] << "|";
    	}
    	cout << endl;
	}
	
	// Print instructions for user to move the alien
	cout << "\nUse the following commands to move the alien:\n" << endl;
	cout << "up    = move up" << endl;
	cout << "down  = move down" << endl;
	cout << "left  = move left" << endl;
	cout << "right = move right" << endl;
	
	string input;
	while (true) {
		cout << "\nEnter move command: ";
		cin >> input;

		int newAlienRow = alienRow;
		int newAlienCol = alienCol;
		Alien alien;
		Zombie2 zombie2;
		Boomer boomer;
		Zombie1 zombie1;

		if (input == "up" && alienRow > 0) {
			newAlienRow--;
		} else if (input == "down" && alienRow < rows - 1) {
			newAlienRow++;
		} else if (input == "left" && alienCol > 0) {
			newAlienCol--;
		} else if (input == "right" && alienCol < cols - 1) {
			newAlienCol++;
		} else {
			cout << "Invalid move command, try again." << endl;
			continue;
		}

		if (board[newAlienRow][newAlienCol] != ' ') {
			cout << "You cannot move there, try again." << endl;
			continue;
		}
		else if (board[newAlienRow][newAlienCol - 1] == 'Z' || board[newAlienRow - 1][newAlienCol] == 'Z' || board[newAlienRow][newAlienCol + 1] == 'Z' || board[newAlienRow + 1][newAlienCol] == 'Z' ) {
			cout << "\nYou encountered a zombie!\n" << endl;
			continue;
		}
		else if (board[newAlienRow][newAlienCol - 1] == 'B' || board[newAlienRow - 1][newAlienCol] == 'B' || board[newAlienRow][newAlienCol + 1] == 'B' || board[newAlienRow + 1][newAlienCol] == 'B' ) {
			cout << "\nYou encountered a boomer!\n" << endl;
			continue;
		}
		else if (board[newAlienRow][newAlienCol - 1] == 'S' || board[newAlienRow - 1][newAlienCol] == 'S' || board[newAlienRow][newAlienCol + 1] == 'S' || board[newAlienRow + 1][newAlienCol] == 'S' ) {
			cout << "\nYou encountered a spitter!\n" << endl;
			continue;
		}
		else if (board[newAlienRow][newAlienCol - 1] == 'P' || board[newAlienRow - 1][newAlienCol] == 'P' || board[newAlienRow][newAlienCol + 1] == 'P' || board[newAlienRow + 1][newAlienCol] == 'P' ) {
			cout << "\nYou encountered a pod!\n" << endl;
			continue;
		}
		else if (board[newAlienRow][newAlienCol - 1] == 'X' || board[newAlienRow - 1][newAlienCol] == 'X' || board[newAlienRow][newAlienCol + 1] == 'X' || board[newAlienRow + 1][newAlienCol] == 'X' ) {
			cout << "\nYou encountered a boulder!\n" << endl;
			continue;
		}
		else if (board[newAlienRow][newAlienCol - 1] == 'H' || board[newAlienRow - 1][newAlienCol] == 'H' || board[newAlienRow][newAlienCol + 1] == 'H' || board[newAlienRow + 1][newAlienCol] == 'H' ) {
			cout << "\nYou encountered a healthpack!\n" << endl;
			continue;
		}
		else if (board[newAlienRow][newAlienCol - 1] == '^' || board[newAlienRow - 1][newAlienCol] == '^' || board[newAlienRow][newAlienCol + 1] == '^' || board[newAlienRow + 1][newAlienCol] == '^' ) {
			cout << "\nYou encountered a slinger!\n" << endl;
			continue;
		}
		else if (board[newAlienRow][newAlienCol - 1] == 'v' || board[newAlienRow - 1][newAlienCol] == 'v' || board[newAlienRow][newAlienCol + 1] == 'v' || board[newAlienRow + 1][newAlienCol] == 'v' ) {
			cout << "\nYou encountered a slinger!\n" << endl;
			continue;
		}
		else if (board[newAlienRow][newAlienCol - 1] == '<' || board[newAlienRow - 1][newAlienCol] == '<' || board[newAlienRow][newAlienCol + 1] == '<' || board[newAlienRow + 1][newAlienCol] == '<' ) {
			cout << "\nYou encountered a slinger!\n" << endl;
			continue;
		}
		else if (board[newAlienRow][newAlienCol - 1] == '>' || board[newAlienRow - 1][newAlienCol] == '>' || board[newAlienRow][newAlienCol + 1] == '>' || board[newAlienRow + 1][newAlienCol] == '>' ) {
			cout << "\nYou encountered a slinger!\n" << endl;
			continue;
		}

		board[alienRow][alienCol] = ' ';
		board[newAlienRow][newAlienCol] = 'A';

		alienRow = newAlienRow;
		alienCol = newAlienCol;

		// Print updated game board
		system("CLS");
		cout << " ";
		for (int j = 0; j < cols; j++) {
	    cout << " " << ((j + 1) % 10);
		}
		cout << endl;

		for (int i = 0; i < rows; i++) {
	    	cout << ((i + 1) % 10) << "|";
	    	for (int j = 0; j < cols; j++) {
	        cout << board[i][j] << "|";
	    	}
	    	cout << endl;
		}
		
		cout << alien << endl;
	    cout << zombie1 << endl;
	    cout << zombie2 << endl;
	    cout << boomer << endl;
	}
  }
  
		else if (number == 2) 
		{
			cout << "\nExiting Game..." << endl;
			cout << "ByeBye!" << endl;
		}
		
		else 
		{
			cout << "Invalid number. Please try again." << endl;
		}
}



