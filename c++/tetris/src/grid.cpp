#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid()
{
    rows = 20,
    cols = 10;
    cellSize = 30;
    Init();
    colors = GetCellColors();
};

void Grid::Init()
{
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            grid[row][col] = 0;
        }
    }
}

void Grid::Print()
{
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            std::cout << grid[row][col] << ' ';
        }
        std::cout << '\n';
    }
}

void Grid::Draw()
{
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            int cellValue = grid[row][col];
            DrawRectangle(col * cellSize+11, row * cellSize+11, cellSize-1, cellSize-1, colors[cellValue]);
        }
        
    }
}

bool Grid::IsCellOutside(int row, int col)
{
    if(row >= 0 && row < rows && col >= 0 && col < cols)
    {
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int col)
{
    if (grid[row][col] == 0)
    {
        return true;
    }
    return false;
}

int Grid::ClearFullCRows()
{
    int completed = 0;
    for (int row = rows - 1; row >= 0; --row) // reverse iteration, bottom to top
    {
        if (IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if (completed > 0)
        {
            MoveRowDown(row, completed);
        }
    }
    return completed;
}

bool Grid::IsRowFull(int row) // T
{
    for (int col = 0; col < cols; ++col)
    {
        if (grid[row][col] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for (int col = 0; col < cols; ++col)
    {
        grid[row][col] = 0;
    }
}

void Grid::MoveRowDown(int row, int rows)
{
    for(int col = 0; col < cols; ++col)
    {
        grid[row + rows][col] = grid[row][col];
        grid[row][col] = 0;
    }
}
