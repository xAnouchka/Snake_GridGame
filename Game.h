#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Snake - Thijs, Anouchka - Rings, Angelica - 1DAE13GDE" };

// Change the window dimensions here
float g_WindowWidth{ 700 };
float g_WindowHeight{ 700 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const float g_CellSize{ 25 };
const int g_NrCols{ int(g_WindowWidth / g_CellSize) }, g_NrRows{ int(g_WindowHeight / g_CellSize) };
const int g_GridSize{ int(g_WindowWidth/g_CellSize) * int(g_WindowHeight/g_CellSize) };
Rectf* pCells{ new Rectf[g_GridSize] {} };

int g_SnakeHeadIdx{};
int g_FruitIdx{};

bool g_UpdateFruit{};
bool g_ShowInfo{};

enum class Direction{ left, right, up, down };
Direction g_Dir{};

// Declare your own functions here
void InitGrid();
void InitSnake();
void InitFruit();

void DrawGrid();
void DrawSnake();
void DrawFruit();

void MoveSnake();

bool DidSnakeGetFruit();
int GetCellIdx(Point2f point);

void ShowInfo();

#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
