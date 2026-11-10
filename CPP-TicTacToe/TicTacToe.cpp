#pragma once

#include <iostream>

#include "TicTacToe.h"
#include "Game.h"
	
//You will need to keep track of the state of the game, including the board and whose turn it is.
// You can do this by adding member variables to your TicTacToe class.I recommend using a char m_board[9] 
// to hold the marks on the board, and having an integer to keep track of the current player(0 or 1).
	char m_board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };//Array to hold the marks on the board	
	int currentPlayer = 0; //An integer to keep track of the current player(0 or 1).

#pragma region Win or Draw Checks
	bool winCheck()
	{
		//You will need to check for a win after each turn.You can do this by checking the board for a winning combination of marks.There are eight 
		// possible ways to win in Tic Tac Toe.You can check each of these combinations to see if one player has won.
		//1.2.3, 4.5.6, 7.8.9, 1.4.7, 2.5.8, 3.6.9, 1.5.9, 3.5.7
		if ((m_board[0] == m_board[1] && m_board[1] == m_board[2] && m_board[0] != ' ') ||
			(m_board[3] == m_board[4] && m_board[4] == m_board[5] && m_board[3] != ' ') ||
			(m_board[6] == m_board[7] && m_board[7] == m_board[8] && m_board[6] != ' ') ||
			(m_board[0] == m_board[3] && m_board[3] == m_board[6] && m_board[0] != ' ') ||
			(m_board[1] == m_board[4] && m_board[4] == m_board[7] && m_board[1] != ' ') ||
			(m_board[2] == m_board[5] && m_board[5] == m_board[8] && m_board[2] != ' ') ||
			(m_board[0] == m_board[4] && m_board[4] == m_board[8] && m_board[0] != ' ') ||
			(m_board[2] == m_board[4] && m_board[4] == m_board[6] && m_board[2] != ' '))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool tieCheck()
	{
		//You will need to check for a tie after each turn.If the board is full and no player has won, the game ends in a tie.
		if (m_board[0] != ' ' && m_board[1] != ' ' && m_board[2] != ' ' &&
			m_board[3] != ' ' && m_board[4] != ' ' && m_board[5] != ' ' &&
			m_board[6] != ' ' && m_board[7] != ' ' && m_board[8] != ' ')
		{
			return true;
		}
		else
		{
			return false;
		}
	};
#pragma endregion

bool TicTacToe::IsGameOver() const
{
	/*This function should return true if the game is over, and false otherwise.The game is over when one player has won, or the board is
	full and the game ends in a tie.*/
	if (winCheck() || tieCheck()) //if either/or true
	{
		std::cout << "Game Over! Player " << (currentPlayer + 1) << " wins!" << std::endl;
		return true;
	}
	else
	{
		return false;
	}

	return false;
}

void TicTacToe::TakeTurn()
{
	//This function should prompt the current player for their move, and then update the board with their mark.You will need to check that the 
	//move is valid (i.e. the space is not already occupied) before updating the board.

	std::cout << "\n Player " << (currentPlayer + 1) << "'s turn. Enter a position (1-9): ";
	int input;
	std::cin >> input;

	// Check if the input is valid (between 1 and 9)
	while (input < 1 || input > 9)
	{
		std::cout << "Invalid input. Please enter a position between 1 and 9." << std::endl;
		std::cin >> input; // Prompt for input again
	}

	// Check if the chosen position is already occupied
	while (m_board[input - 1] != ' ')
	{
		std::cout << "Position already occupied. Please choose another position." << std::endl;
		std::cin >> input; // Prompt for input again
	}

	m_board[input - 1] = (currentPlayer == 0) ? 'X' : 'O'; // Update the board with the current player's mark

	if (TicTacToe::IsGameOver())
	{
		// Handle game over logic
	}
	else 
	{
		if (currentPlayer == 0)
		{
			// Handle player 1's turn
			currentPlayer = 1; // Switch to player 2
		}
		else
		{
			// Handle player 2's turn
			currentPlayer = 0; // Switch to player 1
		}
	}

	system("cls"); // Clear the console screen after each turn)
}

void TicTacToe::Display() const
{
	//This function should display the current state of the board to the console.You can do this by printing out the contents of the m_board array in a 
	//3x3 grid format.

	std::cout << "   -------------" << std::endl;
	for (int i = 0; i < 9; i += 3)
	{
		std::cout << "   | " << m_board[i] << " | " << m_board[i + 1] << " | " << m_board[i + 2] << " |" << std::endl;
		std::cout << "   -------------" << std::endl;
	}
}