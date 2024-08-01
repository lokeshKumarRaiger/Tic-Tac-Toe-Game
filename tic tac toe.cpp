// C++ program to implement tic tac toe game 
#include <iostream> 
using namespace std; 

// draw the 3x3 box
void drawBox(char box[3][3]) 
{ 
	cout << "-------------\n"; 
	for (int i = 0; i < 3; i++) { 
		cout << "| "; 
		for (int j = 0; j < 3; j++) { 
			cout << box[i][j] << " | "; 
		} 
		cout << "\n-------------\n"; 
	} 
} 

// check for a win 
bool checkWin(char box[3][3], char player) 
{ 
	// Check rows, columns, and diagonals 
	for (int i = 0; i < 3; i++) { 
		if (box[i][0] == player && box[i][1] == player 
			&& box[i][2] == player) 
			return true; 
		if (box[0][i] == player && box[1][i] == player 
			&& box[2][i] == player) 
			return true; 
	} 
	//diagonals
	if (box[0][0] == player && box[1][1] == player 
		&& box[2][2] == player) 
		return true; 
	if (box[0][2] == player && box[1][1] == player 
		&& box[2][0] == player) 
		return true; 
	return false; 
} 

int main() 
{ 
	// Initialize the box and players 
	char box[3][3] = { { ' ', ' ', ' ' }, 
						{ ' ', ' ', ' ' }, 
						{ ' ', ' ', ' ' } }; 
	char player = 'X'; 
	int row, col; 
	int turn; // Declare turn here 

	cout << "Welcome to Tic-Tac-Toe!\n"; 

	// Game loop 
	for (turn = 0; turn < 9; turn++) { 
		// Draw the board 
		drawBox(box); 

		// check valid input 
		while (true) { 
			cout << "Player " << player 
				<< ", enter row (0-2) and column (0-2): "; 
			cin >> row >> col; 

			if (box[row][col] != ' ' || row < 0 || row > 2 
				|| col < 0 || col > 2) { 
				cout << "Invalid move. Try again.\n"; 
			} 
			else { 
				break; // Valid input, exit the loop. 
			} 
		} 

		// Make the move 
		box[row][col] = player; 

		// Check for a win after making a move 
		if (checkWin(box, player)) { 
			drawBox(box); 
			cout << "Player " << player << " wins!\n"; 
			break; // Exit the loop after a win. 
		} 

		// Switch to the other player 
		player = (player == 'X') ? 'O' : 'X'; 
	} 

	// End of the game 
	drawBox(box); 

	// Check for a draw 
	if (turn == 9 && !checkWin(box, 'X') 
		&& !checkWin(box, 'O')) { 
		cout << "It's a draw!\n"; 
	} 

	return 0; 
}
