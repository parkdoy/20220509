#include<iostream>
#define MAX 52
#define MAX10(X) (X>10) ? 10:X //Macro 선언

using namespace std;

//52장카드 만들기
//섞기
//나눠주기
//

int Max10(int Number) //함수화 10보다 크거나 같으면 10 아니면 Number
{
	return (Number >= 10) ? 10 : Number;
}

int main()
{	
	int Deck[MAX] = { 0, };

	//init
	for (int i = 0; i < 52; ++i)
	{
		Deck[i] = (i % 13) + 1;
	}

	srand(static_cast<unsigned int>(time(NULL)));

	int SuffleCount = (rand() % 20) + 2;
	//shuffle
	for (int i = 0; i < MAX * 3; i++)
	{
		int FirstNumber = rand() % MAX;
		int SecondNumber = rand() % MAX;
		int Temp = Deck[rand() % MAX];
		Deck[FirstNumber] = Deck[SecondNumber];
		Deck[SecondNumber] = Temp;

	}

	//플레이어와 AI 배열 생성
	//Deck 배열을 일정 step으로 나눠서 플레이어 배열과 AI배열에 저장
	int Player[3] = { 0, };
	int AI[3] = { 0, };

	for (int i = 0; i < 3; ++i)
	{
		Player[i] = Deck[i * 2]; //i=0일때 ,Deck[0]을 Player[0]에 저장 i=1 Deck[2]을 Player[1]
		AI[i] = Deck[(i * 2) + 1];//i=0일때 ,Deck[1]을 AI[0]에 저장, i=1 Deck[3]을 AI[1]
	}

	int PlayerSum = 0;
	int AISum = 0;

	//플레이어,AI 배열 요소 합
	for (int i = 0; i < 3; ++i)
	{
		PlayerSum += Max10(Player[i]);
		AISum += Max10(AI[i]);
	}

	cout << "Player : " << PlayerSum << endl;
	cout << "AI : " << AISum << endl;

	//승패 로직
	if (AISum >= 22)
	{
		cout << " Player Win" << endl;
	}
	else if (AISum <= 21 && PlayerSum <= 21)
	{
		if (PlayerSum >= AISum)
		{
			cout << "Player Win" << endl;
		}
		else
		{
			cout << "AI Win" << endl;
		}
	}
	else
	{
		cout << "AI Win" << endl;
	}
	
	return 0;
}