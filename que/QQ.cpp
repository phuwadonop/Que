#include<iostream>

using namespace std;

typedef struct Student
{
    int Class;
    int ID;
    int Que;
}student;

void chang(int, student*, int);
void chang_down(student*, int);

int main()
{
    int nClass, nStd;
    cin >> nClass >> nStd;

    student std[1000];

    for (int i = 0; i < nStd; i++)
    {
        cin >> std[i].Class >> std[i].ID;
        std[i].Que = 0;
    }
    int que = 1;
    int index = 0;
    int ans[1000];
    while (1)
    {
        int pos = 0;
        char order; int id;
        cin >> order;
        if (order == 'X')
            break;
        else if (order == 'E')
        {
            cin >> id;
            for (int i = 0; i < nStd; i++)
            {
                if (std[i].ID == id)
                {
                    if (que == 1)
                    {
                        std[i].Que = que;
                        que++;
                        break;
                    }
                    else
                    {
                        for (int j = 0; j < nStd; j++)
                        {
                            if (std[i].Class == std[j].Class && std[j].Que != 0)
                            {
                                if (std[j].Que > pos)
                                    pos = std[j].Que + 1;
                            }
                        }
                        if (pos != 0)
                        {
                            chang(pos, std, que);
                            std[i].Que = pos;
                            que++;
                            break;
                        }
                        else
                        {
                            std[i].Que = que;
                            que++;
                            break;
                        }
                    }
                }
            }
        }
        else if (order == 'D')
        {
            int check=0;
            for (int j = 0; j < nStd; j++)
            {
                if (std[j].Que == 1)
                {
                    ans[index] = std[j].ID;
                    std[j].Que = 0;
                    chang_down(std, nStd);
                    que--;
                    index++;
                    check = 1;
                    break;
                }
            }
            if (check == 0)
            {
                ans[index] = -99;
                index++;
            }
        }
    }
    for (int i = 0; i < index; i++)
    {
        if (ans[i] != -99)
            cout << ans[i] << endl;
        else
            cout << "empty" << endl;
    }
    cout << "0";
}
void chang(int pos, student* std, int que)
{
    for (int i = 0; pos < que; i++)
    {
        if (std[i].Que == pos)
        {
            std[i].Que++;
            pos++;
        }
    }
}
void chang_down(student* std, int nStd)
{
    for (int i = 0; i < nStd; i++)
    {
        if (std[i].Que != 0)
        {
            std[i].Que--;
        }
    }
}
