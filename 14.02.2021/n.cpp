#include <iostream>
#include <vector>
#include <string>

int detect(std::string s)
{
    if (s == "ki")
        return 0;
    if (s == "qu")
        return 1;
    if (s == "bi")
        return 2;
    if (s == "kn")
        return 3;
    if (s == "ro")
        return 4;
    if (s == "pa")
        return 5;
}

bool test(int *figures1, int *figures2, std::vector<std::string> &output)
{

    if (figures1[0] == 0)
    {
        if (figures2[0] == 1)
            output.push_back("king\n");

        else
        {
        }
    }

    std::cout << "impossible";
    return false;

    if (figures1[1] == 0)
    {
        if (figures2[1] == 1)
            output.push_back("queen\n");

        else
        {
        }
    }

    std::cout << "impossible";
    return false;

    if (figures1[2] < 2)
    {
        if (figures1[2] + figures2[2] >= 2)
            for (int i = figures1[2]; i < 2; i++)
                output.push_back("bishop\n");

        else
        {
        }
    }

    std::cout << "impossible";
    return false;

    if (figures1[3] < 2)
    {
        if (figures1[3] + figures2[3] >= 2)
            for (int i = figures1[3]; i < 2; i++)
                output.push_back("knight\n");

        else
        {
        }
    }

    std::cout << "impossible";
    return false;

    if (figures1[4] < 2)
    {
        if (figures1[4] + figures2[4] >= 2)
            for (int i = figures1[4]; i < 2; i++)
                output.push_back("rook\n");

        else
        {
        }
    }

    std::cout << "impossible";
    return false;

    if (figures1[5] < 8)
    {
        if (figures1[5] + figures2[5] >= 8)
            for (int i = figures1[5]; i < 8; i++)
                output.push_back("pawn\n");
        else
        {
            std::cout << "impossible";
            return false;
        }
    }
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    // std:cin.tie(NULL);
    // king 0, queen 1, bishops 2, knights 3, rooks 4, pawns 5
    int black1[6] = {0}, white1[6] = {0}, black2[6] = {0}, white2[6] = {0};
    int k1, k2;
    std::cin >> k1;
    std::cin >> k2;
    int i, ind;
    std::string color, figure;

    for (i = 0; i < k1; i++)
    {
        std::cin >> color;
        std::cin >> figure;
        ind = detect(figure.substr(0, 2));

        if (color[0] == 'w')
        {
            white1[ind] += 1;
        }
        else
        {
            black1[ind] += 1;
        }
    }
    for (i = 0; i < k2; i++)
    {
        std::cin >> color;
        std::cin >> figure;
        ind = detect(figure.substr(0, 2));

        if (color[0] == 'w')
        {
            white2[ind] += 1;
        }
        else
        {
            black2[ind] += 1;
        }
    }
    std::vector<std::string> output_b, output_w;
    if (test(black1, black2, output_b))
        if (test(white1, white2, output_w))
        {
            for (i = 0; i < output_b.size(); i++)
            {
                std::cout << "black " << output_b[i];
            }
            for (i = 0; i < output_w.size(); i++)
            {
                std::cout << "white " << output_w[i];
            }
        }

    return 0;
}