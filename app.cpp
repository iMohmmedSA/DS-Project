#include <iostream>

using namespace std;

#define eeDebug 2

class Maze
{

public:
    int **maze;
    int size;

    Maze(int size)
    {
        this->size = size;
        this->maze = new int *[size];

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


    bool isSafe(int x, int y) const {
        return (x >= 0 && x < size && y >= 0 && y < size && maze[x][y] == 0);
    }

    // Movement
    bool moveUp(int x, int y)
    {
        if (isSafe(x - 1, y))
        {
            return true;
        }
        return false;
    }

    bool moveDown(int x, int y)
    {
        if (isSafe(x + 1, y))
        {
            return true;
        }
        return false;
    }

    bool moveLeft(int x, int y)
    {
        if (isSafe(x, y - 1))
        {
            return true;
        }
        return false;
    }

    bool moveRight(int x, int y)
    {
        if (isSafe(x, y + 1))
        {
            return true;
        }
        return false;
    }

    Maze solveMaze()
    {
        if (solveMaze(0, 0)){
            cout << "Solution:" << endl;
            for (int i = 0; i < this->size; i++)
            {
                cout << " ";
                for (int j = 0; j < this->size; j++)
                {
                    if (i == size - 1 && j == size - 1) {
                        cout << "2 ";
                    } else {
                        cout << maze[i][j] << " ";
                    }
                }
                cout << endl;
            }
        } else {
            cout << "No solution" << endl;
        }
        return *this;
    }
private:
    bool solveMaze(int x, int y){
        if (x == size - 1 && y == size - 1) {return true;}
        int xx = x;
        int yy = y;
        if (moveUp(xx, yy)) {
            maze[xx][yy] = 2;
            if (solveMaze(xx - 1, yy)) {return true;}
            maze[xx][yy] = 0;
        }
        if (moveDown(xx, yy)) {
            maze[xx][yy] = 2;
            if (solveMaze(xx + 1, yy)) {return true;}
            maze[xx][yy] = 0;
        }
        if (moveLeft(xx, yy)) {
            maze[xx][yy] = 2;
            if (solveMaze(xx, yy - 1)) {return true;}
            maze[xx][yy] = 0;
        }
        if (moveRight(xx, yy)) {
            maze[xx][yy] = 2;
            if (solveMaze(xx, yy + 1)) {return true;}
            maze[xx][yy] = 0;
        }
        return false;
    }
};

int main()
{
    Maze maze = Maze(3).displayMaze().solveMaze();
    return 0;
}
