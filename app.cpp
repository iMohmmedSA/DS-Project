#include <iostream>

using namespace std;

#define eeDebug 2

class Point
{
public:
    int x;
    int y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

class Maze
{
    enum LAST_MOVE
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        NONE
    };

public:
    int **maze;
    int size;
    Point *position;
    int moveTimeout;
    LAST_MOVE lastMove;

    Maze(int size)
    {
        this->position = new Point(0, 0);
        this->size = size;
        this->maze = new int *[size];
        this->moveTimeout = 0;
        this->lastMove = NONE;

        srand(time(0));
        for (int i = 0; i < size; i++)
        {
            this->maze[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
                if (i == 0 && j == 0 || i == size - 1 && j == size - 1)
                {
                    this->maze[i][j] = 0;
                }
                else
                {
                    if (rand() % 2 == 0)
                    {
                        this->maze[i][j] = 0;
                    }
                    else
                    {
                        this->maze[i][j] = 1;
                    }
                }
            }
        }
    }

    Maze displayMaze()
    {
        cout << "Solve the maze:" << endl;
        for (int i = 0; i < this->size; i++)
        {
            cout << " ";
            for (int j = 0; j < this->size; j++)
            {
                cout << this->maze[i][j] << " ";
            }
            cout << endl;
        }
        return *this;
    }

    // Movement
    Maze moveUp()
    {
        if (eeDebug == 1 && this->position->x > 0)
            cout << "UP stat: " << maze[this->position->x - 1][this->position->y] << endl;
        if (this->position->x - 1 <= 0)
        {
            if (eeDebug == 1)
                cout << "You can't move up" << endl;
            return *this;
        }
        if (maze[this->position->x - 1][this->position->y] == 0)
        {
            if (eeDebug == 1)
                cout << "Moving up" << endl;
            this->position->x--;
            this->moveTimeout++;
            lastMove = UP;
        }
        return *this;
    }

    Maze moveDown()
    {
        if (eeDebug == 1 && this->position->x < this->size - 1)
            cout << "DOWN stat: " << maze[this->position->x + 1][this->position->y] << endl;
        if (this->position->x + 1 >= this->size - 1)
        {
            if (eeDebug == 1)
                cout << "You can't move down" << endl;
            return *this;
        }
        if (maze[this->position->x + 1][this->position->y] == 0)
        {
            if (eeDebug == 1)
                cout << "Moving down" << endl;
            this->position->x++;
            this->moveTimeout++;
            lastMove = DOWN;

            if (eeDebug == 2)
                cout << "Point:" << this->position->x << "y:" << this->position->y << endl;
        }
        return *this;
    }

    Maze moveRight()
    {
        if (eeDebug == 1 && this->position->y < this->size - 1)
            cout << "RIGHT stat: " << maze[this->position->x][this->position->y + 1] << endl;
        if (this->position->y + 1 >= this->size - 1)
        {
            if (eeDebug == 1)
                cout << "You can't move right" << endl;
            return *this;
        }
        if (maze[this->position->x][this->position->y + 1] == 0)
        {
            if (eeDebug == 1)
                cout << "Moving right" << endl;
            this->position->y++;
            this->moveTimeout++;
            lastMove = RIGHT;
            if (eeDebug == 2)
                cout << "Point:" << this->position->x << "y:" << this->position->y << endl;
        }
        return *this;
    }

    Maze moveLeft()
    {
        if (eeDebug == 1 && this->position->y > 0)
            cout << "LEFT stat: " << maze[this->position->x][this->position->y - 1] << endl;
        if (this->position->y - 1 <= 0)
        {
            if (eeDebug == 1)
                cout << "You can't move left" << endl;
            return *this;
        }
        if (maze[this->position->x][this->position->y - 1] == 0)
        {
            if (eeDebug == 1)
                cout << "Moving left" << endl;
            this->position->y--;
            this->moveTimeout++;
            lastMove = LEFT;
        }
        return *this;
    }

    Maze solveMaze()
    {
        // Move from the start to down right
        while (this->position->x != this->size - 1 || this->position->y != this->size - 1)
        {
            this->moveDown();
            this->moveRight();
            if (this->position->x == size - 1 && this->position->y == size - 1)
            {
                cout << "You solved the maze!" << endl;
                break;
            }
            else if (this->moveTimeout++ > 100)
            {
                cout << "Timeout at x:" << this->position->x << "y:" << this->position->y << endl;
                maze[this->position->x][this->position->y] = 2;
                switch (this->lastMove)
                {
                case UP:
                    this->moveUp();
                    break;
                case DOWN:
                    this->moveDown();
                    break;
                case LEFT:
                    this->moveLeft();
                    break;
                case RIGHT:
                    this->moveRight();
                    break;
                default:
                cout << "EE" << endl;
                    break;
                }
                this->displayMaze();
                if (maze[this->position->x][this->position->y] == 2)
                {
                    cout << "You can't solve the maze!" << endl;
                    break;
                }
                this->solveMaze();
                break;
            }
        }
        return *this;
    }
};

int main()
{
    Maze maze = Maze(10).displayMaze().solveMaze();
    return 0;
}
