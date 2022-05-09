#include<iostream>
#define MAX 52
#define MAX10(X) (X>10) ? 10:X //Macro ����

using namespace std;

//52��ī�� �����
//����
//�����ֱ�
//

int Max10(int Number) //�Լ�ȭ 10���� ũ�ų� ������ 10 �ƴϸ� Number
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

	//�÷��̾�� AI �迭 ����
	//Deck �迭�� ���� step���� ������ �÷��̾� �迭�� AI�迭�� ����
	int Player[3] = { 0, };
	int AI[3] = { 0, };

	for (int i = 0; i < 3; ++i)
	{
		Player[i] = Deck[i * 2]; //i=0�϶� ,Deck[0]�� Player[0]�� ���� i=1 Deck[2]�� Player[1]
		AI[i] = Deck[(i * 2) + 1];//i=0�϶� ,Deck[1]�� AI[0]�� ����, i=1 Deck[3]�� AI[1]
	}

	int PlayerSum = 0;
	int AISum = 0;

	//�÷��̾�,AI �迭 ��� ��
	for (int i = 0; i < 3; ++i)
	{
		PlayerSum += Max10(Player[i]);
		AISum += Max10(AI[i]);
	}

	cout << "Player : " << PlayerSum << endl;
	cout << "AI : " << AISum << endl;

	//���� ����
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