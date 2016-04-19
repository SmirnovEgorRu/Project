#pragma once

class game
{
public:
	game();							//конструктор класса
	int PlayerTurn(int, int);		//ход игрока
	void AddToIndexForAdd(int);		//взятие камешков у противника
	void ComputerTurn();			//ход компьютера
	void ReturnTurn();				//возрат хода
	int WhoWin();					//проверка на выигрыш

	/*Get-функции*/
	int GetGameMode();
	int GetGameStatus();
	int GetNumberOfTurn();
	int GetRound();
	int GetField_1(int);
	int GetField_2(int);
	int GetPrevNumberOfTurn();

	/*Set-функции*/
	void SetGameMode(int);
	void SetGameStatus(int);
	void SetGameDifficulty(int);
	void SetRound(int);
	void SetPrevRound(int);

private:
	struct tree					//дерево решений
	{
		int TempField_1[14];	//поле 1 игрока после некотрого шага
		int TempField_2[14];	//поле 2 игрока после некотрого шага
		int value;				//количество камней на поле у компьютера
		int NumberOfAdress;		//количество сыновей
		tree** p;				//указатель на массив сыновей
	};

	int round;			//направление движения (0-по часовой, 1-против)
	int GameMode;		//игровой режим (1-против компьютера, 2 - 2 игрока)
	int GameStatus;		//ход: 0 - компьютера, 1 - 1 игрока, 2 - 2 игрока. Забираем камни у: 3 - 2 игрока, 4 - 1 игрока
	int Difficulty;		//сложность против компьютера
	int MaxLvl;			//максимальный уровень обхода дерева (зависит от сложности)
	int NumberOfTurn;	//номер хода
	int IndexForAdd;	//индекс для добавления чужих камешков
	int Field_1[14];	//поле 1 игрока
	int Field_2[14];	//поле 2 игрока

	/*резервные копии для отмены хода*/
	int PrevField_1[14];
	int PrevField_2[14];
	int PrevGameStatus;
	int PrevRound;
	int PrevNumberOfTurn;
	
	void CopyForReturn();								//копирование файлов, для возможности вернуть ход
	int Shifting(int, int*);							//перекладывание камней по полю
	
	void AddFromOtherPlayer(int, int, int*, int*);		//забирание камней игроком в противоположных клетках

	int MoveStones(int*, int*, int*, int*, int, int);	//перемещение камней компьютером
	void CreateTree(tree* , int*, int *, int , int);	//создание дерева решений
	void TakeStones(int *, int *, int );				//забирание камешков компьютером
	int StonesInField(int* );							//определяет количество камней в поле
	int Traversing(tree*, int, int, int);				//обход дерева в поисках оптимального хода
	bool IsLeaf(tree*);									//определение, является ли вершина листом
	void record(tree*);									//запись выбранного хода компьютера в массивы полей						
	void DeleteTree(tree*);								//удаляем дерево решений
};