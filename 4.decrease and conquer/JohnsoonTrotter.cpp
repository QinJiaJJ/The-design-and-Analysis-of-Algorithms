//input: an integer n;
//outout: all Permutations(排列 [pɜ:mju:'teɪʃnz] ) of array{1,2,...,n}
//unsigned and int 之间的赋值和比较很有趣，c++是按位赋值，比较是统一到范围比较大的类型
#include<iostream>

class JohnsoonTrotter
{
private:
	int *PermutationsPointer;
	int N;
	bool *Direction;//ture for right ,false for left
public:
	JohnsoonTrotter(){}
	~JohnsoonTrotter(){}
	void Init();
	int SearchAndSelect();
	void MoveAndChangeDirection(unsigned i);
	void Display();
	void Run();
};
int main()
{
	JohnsoonTrotter JT;
	JT.Run();
	system("pause");
}
void JohnsoonTrotter::Init()
{
	std::cout << "Please enter the number :";
	std::cin >> N;
	PermutationsPointer = new int[N];
	Direction = new bool[N];
	for (int i = 0; i < N; ++i)
	{
		PermutationsPointer[i] = i + 1;
		Direction[i] = false;
	}
}
int JohnsoonTrotter::SearchAndSelect()
{
	int MoveIndex = -1;
	int MoveValue = -1;
	for (int i = 0; i < N; ++i)
	{
		if (Direction[i] == false)
		{
			if (i == 0)
				continue;
			else if ((PermutationsPointer[i] > PermutationsPointer[i - 1])&& (PermutationsPointer[i] > MoveValue))
			{
					MoveValue = PermutationsPointer[i];
					MoveIndex = i;	
			}
	    }
		else
		{
			if (i == N - 1)
				continue;
			else if (PermutationsPointer[i] > PermutationsPointer[i + 1]&& PermutationsPointer[i]>MoveValue)
			{
				
				MoveValue = PermutationsPointer[i];
				MoveIndex = i;
			}
		}
	}
	return MoveIndex;
}
void JohnsoonTrotter::MoveAndChangeDirection(unsigned i)
{
	int  MoveValue = PermutationsPointer[i];
	int Vtemp;
	bool Dtemp;
	Vtemp = MoveValue;
	Dtemp = Direction[i];
	if (Dtemp)
	{
		PermutationsPointer[i] = PermutationsPointer[i + 1];
		Direction[i] = Direction[i + 1];
		PermutationsPointer[i + 1] = Vtemp;
		Direction[i + 1] = Dtemp;
	}
	else
	{
		PermutationsPointer[i] = PermutationsPointer[i - 1];
		Direction[i] = Direction[i - 1];
		PermutationsPointer[i - 1] = Vtemp;
		Direction[i - 1] = Dtemp;
	}
	for (int i = 0; i < N; ++i)
	{
		if (PermutationsPointer[i] > MoveValue)
		{
			Direction[i] = !Direction[i];
		}
	}
}
void JohnsoonTrotter::Display()
{
	for(int i=0;i<N;++i)
	{
		std::cout << PermutationsPointer[i];
	}
	std::cout << "  ";
}
void JohnsoonTrotter::Run()
{
	Init();
	std::cout << "The all Permutations are as follows:\n";
	Display();
	int MoveIndex = -1;
	MoveIndex = SearchAndSelect();
	while (MoveIndex != -1)
	{
		MoveAndChangeDirection(MoveIndex);
		Display();
		MoveIndex = SearchAndSelect();
	}
}
