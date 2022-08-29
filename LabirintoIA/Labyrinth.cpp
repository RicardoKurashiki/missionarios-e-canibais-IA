#include "Labyrinth.h"

Labyrinth::Labyrinth()
{
	m_labyrinth = 
	{
		"XXXXXXXXXXXXXXXXXXXXX",
		"X     X     X     X X",
		"XX XX XXXXX X X X   X",
		"X   X       XXX XXX X",
		"X X X XXXXXXX   X   X",
		"X X   X   X X X   X X",
		"X XXXXX X X   XXXXX X",
		"X X     X XXX  X    X",
		"X X X X X   XX XX XXX",
		"X X XXX X X     X   X",
		"E X X X X XXXXX XXX X",
		"X     X X   X X X   X",
		"X XXXXX XXX X XXX X X",
		"X X       X X   X X X",
		"X   XXX X X XXX X X S",
		"XXX X X X X X X X XXX",
		"X X   X X   X   X   X",
		"X XXX XXXXXXXXX XXX X",
		"X                 X X",
		"XXXXXXXXXXXXXXXXXXXXX"
	};

	m_currentContext.setPosition(findSpot('E'));
	m_goalContext.setPosition(findSpot('S'));

	updateContext();
}

void Labyrinth::receiveMovement(Coordinate movementPlace)
{
	if (m_labyrinth[movementPlace.getLine()][movementPlace.getColumn()] != 'S')
		m_labyrinth[movementPlace.getLine()][movementPlace.getColumn()] = '*';

	// Descomente caso queira vez o progresso
	//for (int i = 0; i < m_labyrinth.size(); i++)
	//{
	//	std::cout << m_labyrinth[i] << std::endl;
	//}
	//std::cout << std::endl;

	m_currentContext.setPosition(movementPlace);
	updateContext();
}

Context Labyrinth::getCurrentContext()
{
	return m_currentContext;
}

Context Labyrinth::getGoalContext()
{
	return m_goalContext;
}

void Labyrinth::updateContext()
{
	std::string possibleMovements = "";
	int line = m_currentContext.getPosition().getLine();
	int column = m_currentContext.getPosition().getColumn();

	/**
	 * Verifica as coordenadas atuais do contexto no labirinto e verifica
	 * as possibilidades de movimentação.
	 */
	if ((line > 0) &&
		((m_labyrinth[line - 1][column] == ' ') ||
		 (m_labyrinth[line - 1][column] == 'S')))
	{
		possibleMovements.push_back('N');
	}
	if ((line < m_labyrinth.size() - 1) &&
		((m_labyrinth[line + 1][column] == ' ') ||
		 (m_labyrinth[line + 1][column] == 'S')))
	{
		possibleMovements.push_back('S');
	}
	if ((column > 0) &&
		((m_labyrinth[line][column - 1] == ' ') ||
		 (m_labyrinth[line][column - 1] == 'S')))
	{
		possibleMovements.push_back('W');
	}
	if ((column < m_labyrinth[0].size()) &&
		((m_labyrinth[line][column + 1] == ' ') ||
		 (m_labyrinth[line][column + 1] == 'S')))
	{
		possibleMovements.push_back('E');
	}

	m_currentContext.setMovements(possibleMovements);
}

bool Labyrinth::solutionFound()
{
	return m_labyrinth[m_currentContext.getPosition().getLine()][m_currentContext.getPosition().getColumn()] == 'S';
}

Coordinate Labyrinth::findSpot(char spot)
{
	for (int line = 0; line < m_labyrinth.size(); line++)
	{
		for (int column = 0; column < m_labyrinth[line].size(); column++)
		{
			if (m_labyrinth[line][column] == spot)
			{
				return Coordinate(line, column);
			}
		}
	}
}
