#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	InitGrid();
	InitSnake();
	InitFruit();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawGrid();
	DrawSnake();
	DrawFruit();
}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	delete[] pCells;
	pCells = nullptr;
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
/* Function to add all the cells to the array pCells */
void InitGrid()
{
	// for every row: for every column: start.x + column*10, start.y + row*10, 25, 25
	int cellnr{ 0 };

	for (int row{ 0 }; row < g_NrRows; row++)
	{
		for (int col{ 0 }; col < g_NrCols; col++)
		{
			pCells[cellnr] = Rectf{ col * g_CellSize, row * g_CellSize, g_CellSize, g_CellSize };
			++cellnr;
		}
	}
}

/* Function to set g_FruitIdx to a new number */
void InitFruit()
{
	Point2f point{ GetRand(0, int(g_WindowWidth)) / 1.f, GetRand(0, int(g_WindowHeight)) / 1.f };
	g_FruitIdx = GetCellIdx(point);
}

/* Function to set the snake in grid when program is opened */
void InitSnake()
{
	// get idx of the middle cell?
	g_SnakeHeadIdx = GetLinearIndexFrom2DIndex(g_NrRows / 2, g_NrCols / 2, g_NrCols);
}

/* Function to get the cell index of a point in the screen, returns the index int */
int GetCellIdx(Point2f point)
{
	for (int i = 0; i < g_GridSize; i++)
	{
		if (IsPointInRect(point, pCells[i])) return i;
	}
	return 0;
}

/* Function to draw the grid based on rects in array */
void DrawGrid()
{
	SetColor(.2f, .2f, 2.f, 1);
	for (int i{ 0 }; i < g_GridSize; i++) {
		DrawRect(pCells[i]);
	}
}

/* Function to draw the snake (current: 1 rect big) */
void DrawSnake()
{
	SetColor(1, 0, 0, 1);
	FillRect(pCells[g_SnakeHeadIdx]);
}

/* Function to draw the fruit */
void DrawFruit()
{
	if (g_UpdateFruit)	// if true, get a new cell index
	{
		InitFruit();
		g_UpdateFruit = false;
	}

	SetColor(1, 1, 0, 1);
	FillRect( pCells[g_FruitIdx] );
}

/* Function to check if the snake has the fruit or not, returns a bool */
bool DidSnakeGetFruit()
{
	if (g_SnakeHeadIdx == g_FruitIdx)
	{
		return true;
	}
	return false;
}

/* Function to move the snake */
void MoveSnake()
{
	// maybe make an enum class for the direction? and based on which key it will give the param
	// snake keeps moving in this direction when button is clicked (dont need a bool because after the initial move it should always be moving somewhere)
}
#pragma endregion ownDefinitions