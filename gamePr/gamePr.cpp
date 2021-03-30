#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
using namespace std;

void gotoXY(int x, int y)
{
    HANDLE hOut;
    COORD Cur;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(hOut, Cur);
}
char LittleStar[42] = {
    'c','c','G','G','A','A','G','F','F','E','E','D','D','c','G','G','F','F','E','E','D','G','G','F','F','E','E','D','c','c','G','G','A','A','G','F','F','E','E','D','D','c'
};

/*
int numGame(int max) {
    if (max > 10)
    {
        cout << "10개 이하로 입력해주십시오." << endl;
        return 0;
    }

    int check = 0;
    int number[10] = { 0, };

    for (int i = 0; i < max; i++)
    {
        number[i] = rand() % 100 + 1;
        Sleep(1000);
        cout << number[i] << " ";
    }
     system("cls");

    for (int i = 0; i < max; i++)
    {
        cin >> check;

        if (number[i] != check) {
            cout << "틀렸습니다." << endl;
            return 0;
        }

    }
    cout << "모두 맞추셨습니다." << endl;
}
*/

int main()
{
    /*srand((unsigned)time(NULL));

    const int num = 20;
    int answer[num];
    int a = 0;
    int sameNum = 0;
    bool bSame = false;
    int index = 1;
    for (int i = 0; i < 20; i++)
    {
        answer[i] = -1;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            do
            {
                index = rand() % 20;
            } while (answer[index] != -1);
            answer[index] = i;
        }
    }

    for (int i = 0; i < num; i++)
    {

        do {
            sameNum = 0;
            answer[i] = rand() % 10;
            bSame = false;


            if (i > 1) {
                for (int j = 0; j < i; j++)
                {
                    if (answer[i] == answer[j]) {
                        sameNum++;
                    }
                }
                if (sameNum > 1) {
                    bSame = true;
                }
            }


        } while (bSame);

    }


    for (int i = 0; i < num; i++)
    {
        gotoXY(i % 5, i / 5);
        cout << answer[i];
    }
    Sleep(3000);
    system("cls");
    for (int i = 0; i < num; i++)
    {
        gotoXY(i % 5, i / 5);
        cout << "*";
    }
    int key;
    int selectIndex[2] = { 0, };
    int check = 0; // 버튼 누른 횟수
    char keyCode[20] = { '1','2','3','4','5','q','w','e','r','t','a','s','d','f','g','z','x','c','v','b' };

    

    while (true)
    {
        key = _getch();

        for (int i = 0; i < 20; i++)
        {
            if (key == keyCode[i] && answer[i] != -1) {
                selectIndex[check] = i;

                gotoXY(i % 5, i / 5);
                cout << answer[i];
                check++;

                break;
            }

        }

        if (check == 2)
        {
            if (answer[selectIndex[0]] != answer[selectIndex[1]]) {
                Sleep(1000);

                for (int i = 0; i < 2; i++)
                {
                    gotoXY(selectIndex[i] % 5, selectIndex[i] / 5);
                    cout << "*";
                }
            }
            else {
                //짝맞음
                answer[selectIndex[0]] = -1;
                answer[selectIndex[1]] = -1;
            }
            check = 0;
        }

    }*/

    /*printf("Play music !");
    _getch();
    char Tone = 0;
    
    for (int i = 0; i < 42; i++)
    {
        Tone = LittleStar[i];
        switch (Tone) {
        case 'c':
            Beep(523.25, 500);
            break;
        case 'D':
            Beep(587.33, 500);
            break;
        case 'E':
            Beep(659.26, 500);
            break;
        case 'F':
            Beep(698.46, 500);
            break;
        case 'G':
            Beep(783.99, 500);
            break;
        case 'A':
            Beep(880, 500);
            break;
        case 'B':
            Beep(987.77, 500);
            break;
        case 'C':
            Beep(1046.50, 500);
            break;
        }

    }*/
    
    
    
    
    //numGame(10);

    /*int answer[3] = { 0, };

    answer[0] = rand() % 9 + 1;

    do
    {
        answer[1] = rand() % 9 + 1;
    } while (answer[0] == answer[1]);

    do
    {
        answer[2] = rand() % 9 + 1;
    } while (answer[0] == answer[2] || answer[1] == answer[2]);

    cout << answer[0] << ", " << answer[1] << ", " << answer[2] << endl;

    int input[3] = { 0, };


    while (true)
    {
        cin >> input[0] >> input[1] >> input[2];

        cout << answer[0] << ", " << answer[1] << ", " << answer[2] << endl;
        cout << input[0] << ", " << input[1] << ", " << input[2] << endl;

        int strike = 0, ball = 0, out = 0;

        for (int i = 0; i < 3; i++)
        {
            for (int j= 0; j < 3; j++)
            {
                if (answer[i] == input[j])
                {
                    if (i == j) {
                        strike++;
                    }
                    else {
                        ball++;
                    }
                }
            }
        }

        if (strike == 3) {
            cout << "Win";
            return 0;
        }
        else if (strike == 0 && ball == 0) {
            cout << "Out" << endl;
        }
        else {
            cout << "strike : " << strike << endl;
            cout << "ball : " << ball << endl;
        }

    }*/
    
    return 0;
}