#include <bits/stdc++.h>

struct pos
{
    size_t x;
    size_t y;
};

void countStack(std::queue<pos> &positions, size_t &count, std::vector<std::string> &matrix, size_t &x, size_t &y)
{
    long long arrX[] = {1, -1, 0, 0};
    long long arrY[] = {0, 0, -1, 1};
    count = 0;
    positions.push({x, y});

    while (!positions.empty())
    {
        pos p = positions.front();
        positions.pop();
        if (matrix[p.x][p.y] == '1')
        {
            for (long long k = 0; k < 4; ++k)
            {
                size_t newX = p.x + arrX[k];
                size_t newY = p.y + arrY[k];
                if (newX < matrix.size() && newY < matrix[0].size())
                {
                    if (matrix[newX][newY] != '0')
                    {
                        positions.push({newX, newY});
                    }
                }
            }
            matrix[p.x][p.y] = '0';
            count++;
        }
    }
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    std::vector<std::string> matrix;
    std::string str;
    std::getline(std::cin, str);
    for (size_t i = 0; i < n; ++i)
    {
        getline(std::cin, str);
        matrix.push_back(str);
    }
    size_t count = 0;
    size_t max_count = 0;
    size_t num = 0;
    std::queue<pos> positions;
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            if (matrix[i][j] != '0')
            {
                countStack(positions, count, matrix, i, j);
                num++;
                if (count > max_count)
                {
                    max_count = count;
                }
            }
        }
    }
    std::cout << num << " " << max_count << std::endl;
}