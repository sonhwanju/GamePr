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
    srand((unsigned)time(NULL));

    const int num2 = 20;
    int num[num2] = { 0, };
    int a = 0;
    int sameNum = 0;
    bool bSame = false;
    for (int i = 0; i < num2; i++)
    {

        do {
            sameNum = 0;
            num[i] = rand() % 10;
            bSame = false;


            if (i > 1) {
                for (int j = 0; j < i; j++)
                {
                    if (num[i] == num[j]) {
                        sameNum++;
                    }
                }
                if (sameNum > 1) {
                    bSame = true;
                }
            }


        } while (bSame);

    }
    for (int i = 0; i < num2; i++)
    {
        gotoXY(i % 5, i / 5);
        cout << num[i];
    }
    Sleep(3000);
    system("cls");
    for (int i = 0; i < num2; i++)
    {
        gotoXY(i % 5, i / 5);
        cout << "*";
    }
    int key;
    int select[2] = { -1,1 };
    int selectNum = 0; // 버튼 누른 횟수
    int index[20] = { '1','2','3','4','5','q','w','e','r','t','a','s','d','f','g','z','x','c','v','b' };

    /*
        1 49 (
        2 50 (
        3 51 (
        4 52 (
        5 53 (
        q 113 (
        w 119 (
        e 101 (
        r 114 (
        t 116 (
        a 97 (
        s 115 (
        d 100 (
        f 102 (
        g 103 (
        z 122 (
        x 120 (
        c 99 (
        v 118 (
        b 98 (
    */

    while (true)
    {
        key = _getch();

        for (int i = 0; i < 20; i++)
        {
            if (key == index[i]) {
                gotoXY(i % 5, i / 5);;
                cout << num[i];

                select[selectNum] = num[i];
                selectNum++;
            }

            if (selectNum == 2)
            {
                Sleep(1000);
                if (select[0] != select[1]) {
                    //별찍기
                    gotoXY(i%5,i/5);
                    cout << "*";
                    gotoXY(i%5,i/5);
                    cout << "*";
                }
                else {
                    //짝맞음
                }
                selectNum = 0;
            }

        }

    }

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

    /*Sleep(1000);
    system("cls");*/

    return 0;
}