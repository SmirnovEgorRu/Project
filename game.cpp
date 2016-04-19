#include "game.h"
#include <ctime>
#include <stdlib.h>

#define MinusInfinity (-67)
#define PlusInfinity (67)


/*конструктор класса*/
game::game()
{
	
	/*заполнение полей*/
	for (int i = 0; i < 10; ++i)
	{
		Field_1[i] = 3;
		Field_2[i] = 3;
	}
	for (int i = 10, value = 2; i < 14; ++i,--value)
	{
		if (value == -1) value = 0;
		Field_1[i] = value;
		Field_2[i] = value;
	}

	round = -1;		//по умолчанию равен -1, что бы потом можно было определить направление на всю игру
	GameStatus = 1;
	NumberOfTurn = 1;
	
	PrevRound=-1;
	PrevGameStatus = 1;
	PrevNumberOfTurn = 1;
}

/*определяет победителя*/
int game::WhoWin()
{
	int Player_1_Win = 1;
	int Player_2_Win = 1;

	for (int i = 0; i < 14; ++i)
	{
		if (Field_1[i]) Player_2_Win = 0;
		if (Field_2[i]) Player_1_Win = 0;
	}

	if (Player_1_Win) return 1;			//победил 1 игрок
	else if (Player_2_Win) return 2;	//победил 2 игрок
	else return 0;						//игра продолжается
}

/*функция возвращения хода*/
void game::ReturnTurn()
{
	GameStatus = PrevGameStatus;
	round = PrevRound;
	NumberOfTurn = PrevNumberOfTurn;

	for (int i = 0; i < 14; ++i)
	{
		Field_1[i] = PrevField_1[i];
		Field_2[i] = PrevField_2[i];
	}
}

/*осуществляет перекладывание камней в заданном направлении как для компьютера, так и для игрока*/
int game::Shifting(int cell, int* field)
{
	/*cell - действующая ячейка, мы сначала из нее забираем все камни, 
	  а потом переходя на следующую ячейку, перекладываем по 1 камешку в нее.
	  field - поле, в котром мы перекладываем камешки*/
	
	int NumberOfStone;	//количество камней, которое осталось разложить
	int n = 0;			//счетчик от зацикливания
	
	/*в результате шага цикла cell будет хранить индекс ячейки куда упал последний камень*/
	do
	{
		n++;
		NumberOfStone = field[cell];	//количество камней в выбранной ячейке
		field[cell] = 0;

		if (round == 0 || round == -1)	//обход по часовой
		{
			++cell;
			while (NumberOfStone)
			{
				if (cell >= 14) cell = 0;
				++field[cell];
				--NumberOfStone;
				if (!NumberOfStone) break;
				++cell;
			}
		}
		else							//обход против часовой
		{
			--cell;
			while (NumberOfStone)
			{
				if (cell <= -1) cell = 13;
				++field[cell];
				--NumberOfStone;
				if (!NumberOfStone) break;
				--cell;
			}
		}

	} while (field[cell] != 1 && n<300);	//пока последний камень не упадет в пустую ячейку

	if (n >= 300) return -1;	//возращаем ошибку (произошло зацикливание)
	return cell;				//иначе возращаем номер ячейки, куда упал последний камень
}


//
//функции для хода игрока
//

/*обрабатывает ход как первого игрока, так и второго*/
int game::PlayerTurn(int cell, int player)
{
	/*player == 1 если ходит 1 игрок, player == 2 если 2 игрок
	  cell - ячейка, для перекладывания камней*/

	int field[14];			//копия поля игрока, что бы не испортить поле в случае зацикливания
	int IndexOfLastStone;	//индекс ячейки, куда упал последний камень

	/*создаем резервную копию поля и статусов для возможности вернуть ход*/
	CopyForReturn();

	/*инициализируем копию поля игрока*/
	if (player == 1) for (int i = 0; i < 14; ++i) field[i] = Field_1[i];
	else for (int i = 0; i < 14; ++i) field[i] = Field_2[i];

	/*Перекладываем камешки*/
	IndexOfLastStone = Shifting(cell, field);

	/*если произошло зацикливание - возращаем ошибку*/
	if (IndexOfLastStone == -1) return -1;

	/*забираем камешки у противника*/
	if (player == 1) AddFromOtherPlayer(player, IndexOfLastStone, Field_2, field);
	else if (player == 2) AddFromOtherPlayer(player, IndexOfLastStone, Field_1, field);

	/*записываем обратно из копии поля в исходное поле*/
	if (player == 1) for (int i = 0; i < 14; ++i) Field_1[i] = field[i];
	else for (int i = 0; i < 14; ++i) Field_2[i] = field[i];
	return 0;
}

/*забираем камешки у противника в противоположных ячейках*/
void game::AddFromOtherPlayer(int player, int cell, int*EnemyField, int *Field)
{
	/*1 условие - камень упал на передний ряд, но напротив него нет вражеских камней
	  2 условие - камень упал в задний ряд (cell < 7)
	  В обоих случайях выходим из алгоритма*/
	if ((!EnemyField[20 - cell] && !EnemyField[cell - 7]) || cell < 7)
	{
		if (GameMode == 2 && player==1) GameStatus = 2;			//ход переходит 2 игроку
		else if (GameMode == 1 || player == 1) GameStatus = 0;	//ход переходит компьютеру
		else GameStatus = 1;									//ход переходит 1 игроку

		++NumberOfTurn;											//ход игрока завершился
		return;
	}

	/*забираем камешки у противника с противоположных ячеек*/
	Field[cell] = Field[cell] + EnemyField[20 - cell] + EnemyField[cell - 7];
	EnemyField[20 - cell] = 0;
	EnemyField[cell - 7] = 0;
	
	if (player == 1) GameStatus = 3;		//ожидается забирание камешков у 2 игрока
	else if (player == 2) GameStatus = 4;	//ожидается забирание камешков у 1 игрока
	IndexForAdd = cell;						//сохраним куда будем добавлять камешки противника
}

/*забираем камешки из выбранной ячейки противника*/
void game::AddToIndexForAdd(int index)
{
	if (GameStatus == 3)					//забираем у 2 игрока
	{
		Field_1[IndexForAdd] += Field_2[index];
		Field_2[index] = 0;
		if (GameMode == 2) GameStatus = 2;	//передаем ход 2 игроку
		else GameStatus = 0;				//передаем ход компьютеру

		++NumberOfTurn;
	}
	else if (GameStatus == 4)				//забираем у 1 игрока
	{
		Field_2[IndexForAdd] += Field_1[index];
		Field_1[index] = 0;
		GameStatus = 1;						//передаем ход 1 игроку

		++NumberOfTurn;
	}

}

/*создаем резервную копию поля и статусов для возможности вернуть ход*/
void game::CopyForReturn()
{
	PrevGameStatus = GameStatus;
	PrevRound = round;
	PrevNumberOfTurn = NumberOfTurn;
	for (int i = 0; i < 14; ++i)
	{
		PrevField_1[i] = Field_1[i];
		PrevField_2[i] = Field_2[i];
	}
}



//
//функции для определения хода компьютера
//

/*осуществляет ход компьютера*/
void game::ComputerTurn()
{
	tree* head;							//корень дерева
	
	MaxLvl = Difficulty * 2;			//максимальная высота дерева, в зависимости от сложности игры
	PrevRound = round;					//определяем новое направление обхода
	
	srand(time(0));
	if (round == -1) round = rand() % 2;

	/*создание дерева решений*/
	head = new tree;
	CreateTree(head, Field_1, Field_2, 0, 0);
	
	Traversing(head, 0, MinusInfinity, PlusInfinity);
	record(head);

	DeleteTree(head);		//очищаем память
}

/*создание дерева решений*/
void game::CreateTree(tree* adress, int* PrevF_1, int* PrevF_2, int lvl, int turn)
{
	int NewField_1[14];					//поле 1 игрока после нового хода
	int NewField_2[14];					//поле 2 игрока после нового хода
	
	int IndexForAdd = 0;				//определяет с каким индексом будет записан адрес на сына
	int NumberOfAdress = 0;				//число сыновей у вершины
	
	adress->value = MinusInfinity;
	
	/*записываем в узел дерева предыдущие значения полей и определяем количество сыновей*/
	for (int i = 0; i < 14; ++i)
	{
		if (PrevF_1[i] && turn) ++NumberOfAdress;
		if (PrevF_2[i] && !turn) ++NumberOfAdress;
		adress->TempField_1[i] = PrevF_1[i];
		adress->TempField_2[i] = PrevF_2[i];
	}

	if (lvl >= MaxLvl									//превзошли максимальный уровень дерева
		|| StonesInField(adress->TempField_2) == 66		//компьютер уже выиграл
		|| StonesInField(adress->TempField_2) == 0)		//компьютер уже проиграл
			adress->NumberOfAdress = 0;					//уже выйграл компьютер
	else
	{
		adress->NumberOfAdress = NumberOfAdress;		//создание массива указателей
		adress->p = new tree*[NumberOfAdress];

		for (int i = 0; i < 14; ++i)
		{
			if ((turn == 0 && adress->TempField_2[i] == 0)
				 || (turn == 1 && adress->TempField_1[i] == 0))
					continue;		//выбранная ячейка пуста
			else
			{
				if (MoveStones(adress->TempField_1, adress->TempField_2, NewField_1, NewField_2, i, turn) == -1) 
							adress->p[IndexForAdd++] = NULL;	//условие зацикливания, отсекаем это поддерево
				else
				{
					adress->p[IndexForAdd] = new tree;
					CreateTree(adress->p[IndexForAdd], NewField_1, NewField_2, lvl + 1, (turn == 0 ? 1 : 0));
					++IndexForAdd;
				}
			}
		}
	}
}
 
/*осуществляет передвижение камней по полю*/
int game::MoveStones(int* TempField_1, int* TempField_2, int *NewField_1, int *NewField_2, int index, int turn)
{
	/*TempField_1 - поле 1 игрока на прошлом ходу, TempField_2 - 2 игрока
	  NewField_1 - как будет выглядеть поле 1 игрока после нового хода, TempField_2 - 2 игрока*/
	
	int IndexOfLastStone;		//индекс поля, куда упал последний камень
	
	/*начальное расположение совпадает*/
	for (int i = 0; i < 14; ++i)
	{
		NewField_1[i] = TempField_1[i];
		NewField_2[i] = TempField_2[i];
	}

	/*перекладываем камешки по своему полю*/
	if (turn == 0) IndexOfLastStone = Shifting(index, NewField_2);
	else if (turn == 1) IndexOfLastStone = Shifting(index, NewField_1);
	
	/*проверка на зацикливание*/
	if (IndexOfLastStone == -1) return -1;

	/*забираем камешки у противника*/
	if (turn==0) TakeStones(NewField_2, NewField_1, IndexOfLastStone);
	else if (turn == 1) TakeStones(NewField_1, NewField_2, IndexOfLastStone);

	return 0;
}

/*забираем камешки у противника*/
void game::TakeStones(int *Field, int *EnemyField, int index)
{
	/*index - номер ячейки, в котрую упал последний камень (куда будем добавлять камни)*/
	
	int IndexOfMaxStones = 0;	//индекс вражеского поля с максимальным количеством камней

	/*если в противоположных ячейках есть камешки - забираем, иначе выходим*/
	if (!((!EnemyField[20 - index] && !EnemyField[index - 7]) || index < 7))
	{
		/*забираем камешки из противоположных ячеек*/
		Field[index] += EnemyField[20 - index];
		Field[index] += EnemyField[index - 7];
		EnemyField[20 - index] = 0;
		EnemyField[index - 7] = 0;

		/*забираем камешки из ячейки противника, имеющей наибольшее число камешков*/
		for (int i = 1; i < 14; ++i) if (EnemyField[IndexOfMaxStones] < EnemyField[i]) IndexOfMaxStones = i;
		Field[index] += EnemyField[IndexOfMaxStones];
		EnemyField[IndexOfMaxStones] = 0;
	}

}

/*определяет сумму камешков в данном поле*/
int game::StonesInField(int* Field)
{
	int sum = 0;
	for (int i = 0; i < 14; ++i) sum += Field[i];
	return sum;
}

/*обход дерева в поисках оптимального решения по статегии минимакса*/
int game::Traversing(tree* cur, int lvl, int alpha, int beta)
{
	int MinMax;		//возращаем значение value отцу вершины
	if (IsLeaf(cur)) cur->value = StonesInField(cur->TempField_2) - StonesInField(cur->TempField_1);
	else
	{
		for (int i = 0; i < cur->NumberOfAdress; ++i)
		{
			if (cur->p[i])
			{
				MinMax = Traversing(cur->p[i], lvl + 1, alpha, beta);
				
				/*альфа бета отсечение*/
				if (lvl % 2) alpha = (alpha > MinMax) ? alpha : MinMax;
				else beta = (beta < MinMax) ? beta : MinMax;
				if (beta < alpha) break; 
			}
		}
		cur->value = MinMax;
	}
	return cur->value;
}

/*проверяем лист ли данная вершина*/
bool game:: IsLeaf(tree* cur)
{
	for (int i = 0; i < cur->NumberOfAdress; ++i) if (cur->p[i]) return 0;
	return 1;
}

/*запись хода, выбранного компьютером.*/
void game::record(tree* head)
{
	int index;			//сохраняет индекс в массиве указателей на оптимальный вариант
	for (int i = 0; i < head->NumberOfAdress; ++i)
	{
		if (head->p[i]) if (head->p[i]->value == head->value)
		{
			index = i;
			break;
		}
	}
	
	/*записываем результат хода в ячейки поля*/
	for (int i = 0; i < 14; ++i)
	{
		Field_1[i] = head->p[index]->TempField_1[i];
		Field_2[i] = head->p[index]->TempField_2[i];
	}

	GameStatus = 1;		//ход переходит игроку
	++NumberOfTurn;		//номер хода увеличивается на 1
}

/*удаление дерева решений*/
void game::DeleteTree(tree *p)
{
	for (int i = 0; i < p->NumberOfAdress; ++i)
	{
		if (p->p[i]) DeleteTree(p->p[i]);
	}

	if (p->NumberOfAdress) delete [] p->p;	//удаление массива указателей на сыновей
	delete p;								//удаление вершины
}



/*Get-функции*/
int game::GetGameMode()
{
	return GameMode;
}

int game::GetGameStatus()
{
	return GameStatus;
}

int game::GetRound()
{
	return round;
}

int game::GetNumberOfTurn()
{
	return NumberOfTurn;
}

int game::GetField_1(int i)
{
	return Field_1[i];
}

int game::GetField_2(int i)
{
	return Field_2[i];
}

int game::GetPrevNumberOfTurn()
{
	return PrevNumberOfTurn;
}


/*Set-функции*/
void game::SetGameMode(int mode)
{
	GameMode = mode;
}

void game::SetGameStatus(int status)
{
	GameStatus = status;
}

void game::SetGameDifficulty(int dif)
{
	Difficulty = dif;
}

void game::SetRound(int r)
{
	round = r;
}

void  game::SetPrevRound(int r)
{
	PrevRound = r;
}