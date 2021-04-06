#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>

using namespace std;

#define UP		72
#define DOWN	80
#define LEFT	75
#define RIGHT	77

int currentX, currentY;
int c = 0;

char ShowMap[22][23] = {
	"++++++++++++++++++++++",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"+....................+",
	"++++++++++++++++++++++"
};

void gotoXY(int x, int y) {
	HANDLE hOut;
	COORD Cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}

void displayScreen() {
	if (c == 0) {
		for (int i = 0; i < 10; i++)
		{
			int a = rand() % 20 + 1;
			int b = rand() % 20 + 1;
			do
			{
				a = rand() % 20 + 1;
				b = rand() % 20 + 1;
			} while (ShowMap[b][a] == '+');
			ShowMap[b][a] = '+';

		}
		c++;
	}

	for (int y = 0; y < 22; y++)
	{
		for (int x = 0; x < 22; x++)
		{
			gotoXY(x, y);
			_putch(ShowMap[y][x]);
		}
	}


	gotoXY(currentX, currentY);
	_putch('0');
	gotoXY(30, 2);
	cout << "Q : 종료";
}

void Move(int dir) {
	int dir_x = 0, dir_y = 0;
	switch (dir)
	{
	case LEFT:
		dir_x = -1;
		break;
	case RIGHT:
		dir_x = 1;
		break;
	case UP:
		dir_y = -1;
		break;
	case DOWN:
		dir_y = 1;
		break;
	}
	if (ShowMap[currentY + dir_y][currentX + dir_x] != '+') {
		currentX += dir_x;
		currentY += dir_y;
	}


}

int main() {
	int ch;
	currentX = 1;
	currentY = 1;
	srand((unsigned)time(NULL));

	while (true)
	{
		displayScreen();
		ch = _getch();

		if (ch == 0xE0 || ch == 0) {
			ch = _getch();
			switch (ch)
			{
			case LEFT:
			case RIGHT:
			case UP:
			case DOWN:
				Move(ch);
				break;
			}
		}
		else {
			ch = tolower(ch);
			if (ch == 'q') {
				exit(0);
			}
			else if (ch == 'z') {
				ShowMap[currentY][currentX] = 'X';
			}
			else if (ch == 'a') {
				//상하좌우 +사라지고 .변경 / 테두리 제외
				// 0,? 22, ? 22,?
				//나중에고칠거
				if (currentY -1 != 0) {
					ShowMap[currentY - 1][currentX] = '.';
				}

				if (currentY + 1 != 21) {
					ShowMap[currentY + 1][currentX] = '.';
				}

				if (currentX - 1 != 0) {
					ShowMap[currentY][currentX - 1] = '.';
				}

				if (currentX + 1 != 21) {
					ShowMap[currentY][currentX + 1] = '.';
				}

			}
		}
	}


	return 0;
}





//#include <iostream>
//#include <time.h>
//#include <Windows.h>
//#include <conio.h>
//#include <string.h>
//using namespace std;
//
//void gotoXY(int x, int y)
//{
//    HANDLE hOut;
//    COORD Cur;
//    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//    Cur.X = x;
//    Cur.Y = y;
//    SetConsoleCursorPosition(hOut, Cur);
//}
//char LittleStar[42] = {
//    'c','c','G','G','A','A','G','F','F','E','E','D','D','c','G','G','F','F','E','E','D','G','G','F','F','E','E','D','c','c','G','G','A','A','G','F','F','E','E','D','D','c'
//};
//
///*
//int numGame(int max) {
//    if (max > 10)
//    {
//        cout << "10개 이하로 입력해주십시오." << endl;
//        return 0;
//    }
//
//    int check = 0;
//    int number[10] = { 0, };
//
//    for (int i = 0; i < max; i++)
//    {
//        number[i] = rand() % 100 + 1;
//        Sleep(1000);
//        cout << number[i] << " ";
//    }
//     system("cls");
//
//    for (int i = 0; i < max; i++)
//    {
//        cin >> check;
//
//        if (number[i] != check) {
//            cout << "틀렸습니다." << endl;
//            return 0;
//        }
//
//    }
//    cout << "모두 맞추셨습니다." << endl;
//}
//*/
//
//const int Tone[8] = { 523,587,659,698,784,880,988,1046 };
//const string name[8] = { "도","레","미","파","솔","라","시","도" };
//
//int main()
//{
//    /*srand((unsigned)time(NULL));
//
//    const int num = 20;
//    int answer[num];
//    int a = 0;
//    int sameNum = 0;
//    bool bSame = false;
//    int index = 1;
//    for (int i = 0; i < 20; i++)
//    {
//        answer[i] = -1;
//    }
//
//    for (int i = 0; i < 10; i++)
//    {
//        for (int j = 0; j < 2; j++)
//        {
//            do
//            {
//                index = rand() % 20;
//            } while (answer[index] != -1);
//            answer[index] = i;
//        }
//    }
//
//    for (int i = 0; i < num; i++)
//    {
//
//        do {
//            sameNum = 0;
//            answer[i] = rand() % 10;
//            bSame = false;
//
//
//            if (i > 1) {
//                for (int j = 0; j < i; j++)
//                {
//                    if (answer[i] == answer[j]) {
//                        sameNum++;
//                    }
//                }
//                if (sameNum > 1) {
//                    bSame = true;
//                }
//            }
//
//
//        } while (bSame);
//
//    }
//
//
//    for (int i = 0; i < num; i++)
//    {
//        gotoXY(i % 5, i / 5);
//        cout << answer[i];
//    }
//    Sleep(3000);
//    system("cls");
//    for (int i = 0; i < num; i++)
//    {
//        gotoXY(i % 5, i / 5);
//        cout << "*";
//    }
//    int key;
//    int selectIndex[2] = { 0, };
//    int check = 0; // 버튼 누른 횟수
//    char keyCode[20] = { '1','2','3','4','5','q','w','e','r','t','a','s','d','f','g','z','x','c','v','b' };
//
//    
//
//    while (true)
//    {
//        key = _getch();
//
//        for (int i = 0; i < 20; i++)
//        {
//            if (key == keyCode[i] && answer[i] != -1) {
//                selectIndex[check] = i;
//
//                gotoXY(i % 5, i / 5);
//                cout << answer[i];
//                check++;
//
//                break;
//            }
//
//        }
//
//        if (check == 2)
//        {
//            if (answer[selectIndex[0]] != answer[selectIndex[1]]) {
//                Sleep(1000);
//
//                for (int i = 0; i < 2; i++)
//                {
//                    gotoXY(selectIndex[i] % 5, selectIndex[i] / 5);
//                    cout << "*";
//                }
//            }
//            else {
//                //짝맞음
//                answer[selectIndex[0]] = -1;
//                answer[selectIndex[1]] = -1;
//            }
//            check = 0;
//        }
//
//    }*/
//
//    /*printf("Play music !");
//    _getch();
//    char Tone = 0;
//    
//    for (int i = 0; i < 42; i++)
//    {
//        Tone = LittleStar[i];
//        switch (Tone) {
//        case 'c':
//            Beep(523.25, 500);
//            break;
//        case 'D':
//            Beep(587.33, 500);
//            break;
//        case 'E':
//            Beep(659.26, 500);
//            break;
//        case 'F':
//            Beep(698.46, 500);
//            break;
//        case 'G':
//            Beep(783.99, 500);
//            break;
//        case 'A':
//            Beep(880, 500);
//            break;
//        case 'B':
//            Beep(987.77, 500);
//            break;
//        case 'C':
//            Beep(1046.50, 500);
//            break;
//        }
//
//    }*/
//    
//    
//    int SelectTone = 0;
//    int Select = 0;
//    char strTone[3];
//    _getch();
//    while (true)
//    {
//        srand((unsigned)time(NULL));
//
//        for (int i = 0; i < 8; i++)
//        {
//            cout << name[i] << "(" << i + 1 << ") ";
//            Beep(Tone[i], 500);
//        }
//
//        /*cout << "도(1) ";
//        Beep(*(Tone + 0), 1000);
//        cout << "레(2) ";
//        Beep(*(Tone + 1), 1000);
//        cout << "미(3) ";
//        Beep(*(Tone + 2), 1000);
//        cout << "파(4) ";
//        Beep(*(Tone + 3), 1000);
//        cout << "솔(5) ";
//        Beep(*(Tone + 4), 1000);
//        cout << "라(6) ";
//        Beep(*(Tone + 5), 1000);
//        cout << "시(7) ";
//        Beep(*(Tone + 6), 1000);
//        cout << "도(8) \n";
//        Beep(*(Tone + 7), 1000);*/
//
//        cout << "준비\n";
//        Sleep(1000);
//        SelectTone = rand() % 8;
//
//        Beep(Tone[SelectTone], 500);
//        Select = _getch() - '1';
//
//        if (SelectTone == Select) {
//            cout << "맞추셨스빈다~! \n";
//            cout << "게임을 그만둘까여? (Y/N) \n";
//            if (tolower(_getch()) == 'y') {
//                break;
//            }
//            
//        }
//        else {
//            cout << "틀리셨습니다\n";
//
//            switch (SelectTone) {
//            case 0:
//                strcpy_s(strTone, "도");
//                break;
//            case 1:
//                strcpy_s(strTone, "레");
//                break;
//            case 2:
//                strcpy_s(strTone, "미");
//                break;
//            case 3:
//                strcpy_s(strTone, "파");
//                break;
//            case 4:
//                strcpy_s(strTone, "솔");
//                break;
//            case 5:
//                strcpy_s(strTone, "라");
//                break;
//            case 6:
//                strcpy_s(strTone, "시");
//                break;
//            case 7:
//                strcpy_s(strTone, "도");
//                break;
//            }
//
//        }
//        cout << "정답은(" << strTone << ")입니다\n";
//    }
//    
//    //numGame(10);
//
//    /*int answer[3] = { 0, };
//
//    answer[0] = rand() % 9 + 1;
//
//    do
//    {
//        answer[1] = rand() % 9 + 1;
//    } while (answer[0] == answer[1]);
//
//    do
//    {
//        answer[2] = rand() % 9 + 1;
//    } while (answer[0] == answer[2] || answer[1] == answer[2]);
//
//    cout << answer[0] << ", " << answer[1] << ", " << answer[2] << endl;
//
//    int input[3] = { 0, };
//
//
//    while (true)
//    {
//        cin >> input[0] >> input[1] >> input[2];
//
//        cout << answer[0] << ", " << answer[1] << ", " << answer[2] << endl;
//        cout << input[0] << ", " << input[1] << ", " << input[2] << endl;
//
//        int strike = 0, ball = 0, out = 0;
//
//        for (int i = 0; i < 3; i++)
//        {
//            for (int j= 0; j < 3; j++)
//            {
//                if (answer[i] == input[j])
//                {
//                    if (i == j) {
//                        strike++;
//                    }
//                    else {
//                        ball++;
//                    }
//                }
//            }
//        }
//
//        if (strike == 3) {
//            cout << "Win";
//            return 0;
//        }
//        else if (strike == 0 && ball == 0) {
//            cout << "Out" << endl;
//        }
//        else {
//            cout << "strike : " << strike << endl;
//            cout << "ball : " << ball << endl;
//        }
//
//    }*/
//    
//    return 0;
//}