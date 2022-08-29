#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Labyrinth.h"
#include "Searcher.h"
#include "BlindSearcherDeep.h"
#include "BlindSearcherWidth.h"
#include "HeuristicSearcherGreedy.h"
#include "HeuristicSearcherAStar.h"

using namespace std;

int main()
{
	// PRINT INICIAL
	cout << "--- LABIRINTO ---" << endl;
	cout << "IAC - PUCPR" << endl;
	cout << "Carlos Eduardo Marques Assuncao Torres" << endl;
	cout << "Milena Heloisa de Amorim Silverio" << endl;
	cout << "Ricardo Godoi Kurashiki" << endl;

	Coordinate searcherMovement;
	Context labyrinthContext;
	int iterationCounter = 0;

	Labyrinth labyrinth = Labyrinth();
	BlindSearcherDeep deepSearch = BlindSearcherDeep();
	BlindSearcherWidth widthSearch = BlindSearcherWidth();
	HeuristicSearcherGreedy greedySearch = HeuristicSearcherGreedy();
	HeuristicSearcherAStar aStarSearch = HeuristicSearcherAStar();
	
	// Joga para o m�todo de busca o contexto inicial.
	labyrinthContext = labyrinth.getCurrentContext();
	widthSearch.receiveContext(labyrinthContext);

	//// Busca cega por largura
	while (!labyrinth.solutionFound())
	{
		system("cls");
		cout << "BUSCA CEGA POR LARGURA" << endl << endl;
		// M�todo de busca seleciona que movimento fazer.
		searcherMovement = widthSearch.makeMovement();
		// Labirinto recebe o movimento e devolve o contexto.
		labyrinth.receiveMovement(searcherMovement);
		labyrinthContext = labyrinth.getCurrentContext();

		// M�todo de busca recebe o contexto devolvido.
		widthSearch.receiveContext(labyrinthContext);
		// M�todo de busca "pensa" qual o pr�ximo movimento.
		widthSearch.handle();
		Sleep(20);
		iterationCounter++;
	}

	cout << "Resolveu com " << iterationCounter << " iteracoes.\n";
	cout << "Aperte ENTER para continuar";
	cin.ignore();

	labyrinth = Labyrinth();
	labyrinthContext = labyrinth.getCurrentContext();
	deepSearch.receiveContext(labyrinthContext);
	iterationCounter = 0;
	
	// Busca cega por profundidade
	while (!labyrinth.solutionFound())
	{
		system("cls");
		cout << "BUSCA CEGA POR PROFUNDIDADE" << endl << endl;
		// M�todo de busca seleciona que movimento fazer.
		searcherMovement = deepSearch.makeMovement();
		// Labirinto recebe o movimento e devolve o contexto.
		labyrinth.receiveMovement(searcherMovement);
		labyrinthContext = labyrinth.getCurrentContext();

		// M�todo de busca recebe o contexto devolvido.
		deepSearch.receiveContext(labyrinthContext);
		// M�todo de busca "pensa" qual o pr�ximo movimento.
		deepSearch.handle();
		Sleep(20);
		iterationCounter++;
	}
	
	cout << "Resolveu com " << iterationCounter << " iteracoes.\n";
	cout << "Aperte ENTER para continuar";
	cin.ignore();

	Context labyrinthGoalContext;

	labyrinth = Labyrinth();
	labyrinthContext = labyrinth.getCurrentContext();
	labyrinthGoalContext = labyrinth.getGoalContext();
	greedySearch.receiveContext(labyrinthContext);
	greedySearch.receiveGoalContext(labyrinthGoalContext);
	iterationCounter = 0;
	
	// Busca heuristica Greedy
	while (!labyrinth.solutionFound())
	{
		system("cls");
		cout << "BUSCA HEURISTICA GREEDY" << endl << endl;
		// M�todo de busca seleciona que movimento fazer.
		searcherMovement = greedySearch.makeMovement();
		// Labirinto recebe o movimento e devolve o contexto.
		labyrinth.receiveMovement(searcherMovement);
		labyrinthContext = labyrinth.getCurrentContext();

		// M�todo de busca recebe o contexto devolvido.
		greedySearch.receiveContext(labyrinthContext);
		// M�todo de busca "pensa" qual o pr�ximo movimento.
		greedySearch.handle();
		Sleep(20);
		iterationCounter++;
	}

	cout << "Resolveu com " << iterationCounter << " iteracoes.\n";
	cout << "Aperte ENTER para continuar";
	cin.ignore();

	labyrinth = Labyrinth();
	labyrinthContext = labyrinth.getCurrentContext();
	labyrinthGoalContext = labyrinth.getGoalContext();
	aStarSearch.receiveContext(labyrinthContext);
	aStarSearch.receiveStartContext(labyrinthContext);
	aStarSearch.receiveGoalContext(labyrinthGoalContext);
	iterationCounter = 0;

	// Busca heuristica AStar
	while (!labyrinth.solutionFound())
	{
		system("cls");
		cout << "BUSCA HEURISTICA A*" << endl << endl;
		// M�todo de busca seleciona que movimento fazer.
		searcherMovement = aStarSearch.makeMovement();
		// Labirinto recebe o movimento e devolve o contexto.
		labyrinth.receiveMovement(searcherMovement);
		labyrinthContext = labyrinth.getCurrentContext();

		// M�todo de busca recebe o contexto devolvido.
		aStarSearch.receiveContext(labyrinthContext);
		// M�todo de busca "pensa" qual o pr�ximo movimento.
		aStarSearch.handle();
		Sleep(20);
		iterationCounter++;
	}

	cout << "Resolveu com " << iterationCounter << " iteracoes.\n";
	cout << "Jogo finalizado.\n";
	cout << "Aperte ENTER para continuar";
	cin.ignore();
	system("cls");
	labyrinth.showSolution(aStarSearch.m_contextHistory);
}