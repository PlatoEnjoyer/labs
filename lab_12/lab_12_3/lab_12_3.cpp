#include <iostream>

const int n = 3;
const int m = 5;

void solution(int i, int j, int score, std::string matrix[n][m], int score_matrix[n][m])
{
    if (matrix[i][j] == "#" || i > n - 1 || j > m - 1 || i < 0 || j < 0)
    {
        return;
    }

    score++;

    if (score >= score_matrix[i][j])
    {
        return;
    }

    score_matrix[i][j] = score;
    if (matrix[i][j] == "E")
    {
        return;
    }

    solution(i+1, j, score, matrix, score_matrix);
    solution(i-1, j, score, matrix, score_matrix);
    solution(i, j+1, score, matrix, score_matrix);
    solution(i, j-1, score, matrix, score_matrix);
    solution(i+1, j+1, score, matrix, score_matrix);
    solution(i+1, j-1, score, matrix, score_matrix);
    solution(i-1, j+1, score, matrix, score_matrix);
    solution(i-1, j-1, score, matrix, score_matrix);
}

int main()
{
    std::string matrix[n][m] = {{"S", ".", "#", "#", "#"},
                                {".", ".", ".", "#", "#"},
                                {"#", "#", ".", "#", "E"}};

    int score_matrix[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            score_matrix[i][j] = INT_MAX;
        }
    }
    
    solution(0, 0, 0, matrix, score_matrix);

    if (score_matrix[n-1][m-1] == INT_MAX)
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        std::cout << score_matrix[n-1][m-1] + 1 << std::endl;
    }

    return 0;
}