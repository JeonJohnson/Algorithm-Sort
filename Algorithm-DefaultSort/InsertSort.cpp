#include <iostream>

using namespace std;

#define Desc true
#define Asce false

typedef bool SortMethod;


void InsertionSort(int _arr[], int _iArrLength, SortMethod _Methode = Asce)
{
	//n-1번의 사이클
	//이 방법은 스왑이 아니라 뒤로 밀어 내야함.

	//1. 숫자를 하나 뽑는다. (Temp에 저장.)
	//2. 앞의 숫자랑 비교한다.
	//3. (오름차순 비교) 앞의 숫자가 클 경우 앞의 숫자를 뒤로 한칸 민다.
	//4. 자신보다 작은 숫자가 나올떄 까지 비교한다.
	//5. 자신보다 작은 숫자가 나올경우 그 뒷칸에 대입한다.
	for (int i = 1; i < _iArrLength; ++i)
	{
		int iTemp = _arr[i]; //숫자 하나 뽑아서 저장.
		int k = 0;
#pragma region Old
		//for (int k = i - 1; k >= 0; --k)
		//{//앞의 숫자랑 비교

		//	if (_Methode == Asce)
		//	{
		//		if (iTemp > _arr[k])
		//		{//앞의 숫자가 더 작을 경우
		//			_arr[k + 1] = iTemp;
		//			break;
		//		}
		//		else if (iTemp < _arr[k])
		//		{//앞의 숫자가 더 클경우
		//			_arr[k + 1] = _arr[k];

		//			_arr[k] = iTemp;
		//		}
		//	}
		//	else
		//	{
		//		if (iTemp < _arr[k])
		//		{//앞의 숫자가 더 클 경우
		//			_arr[k + 1] = iTemp;
		//			break;
		//		}
		//		else if (iTemp > _arr[k])
		//		{//앞의 숫자가 더 작을 경우
		//			_arr[k + 1] = _arr[k];

		//			_arr[k] = iTemp;
		//		}
		//	}
		//}
#pragma endregion

#pragma region New
		//for문에다가 아예 조건을 달아버리는 방식.
		//조건에 부합할 경우(오름차순 기준 앞 숫자가 클 경우)
		//뒤로 멀어버리고
		//부합하지 않으면 for문에 안들어가고 숫자 삽입하는 방식.
		if (_Methode == Asce)
		{
			for (k = i - 1; k >= 0 && _arr[k] > iTemp; --k)
			{
				_arr[k + 1] = _arr[k];
			}

			//for문에 안들어간다면, 앞의 숫자가 더 작은 경우이거나 맨 앞임.
			//그 뒷칸에 넣어야함.
			//=> 이미 위에서 숫자들은 하나씩 밀었음으로 상관X
			_arr[k + 1] = iTemp;
			//for문 끝나고--k 해줬으니까 ㄱㅊㄱㅊ
		}
		else
		{

			for (k = i - 1; k >= 0 && _arr[k] < iTemp; --k)
			{
				_arr[k + 1] = _arr[k];
			}

			_arr[k + 1] = iTemp;
		}


#pragma endregion 
	}
}


void main()
{
	//210909 2200 삽입정렬
	//첫번째 싸이클에서 두번째 원소를 고른 뒤
	//첫번재 원소와 비교(앞쪽원소와)한 뒤 위치를 찾아서 삽입하고 
	//나머지 원소들은 뒤로 밀리기
	//두번째 싸이클은 세번째 원소를 골라서 같은방법으로 함.

	//장점 : 안정적인 방법.
			//데이터들이 정렬이 되있는 만큼 적은 이동.
			//데이터들이 적은 만큼 이동이 적음
	//단점 : 데이터들이 많을 수록 이동이 많음.


	int TestArr[7] = { 6, 1, 2, 7, 4
		, 9 , 0
	};

	int iLength = sizeof(TestArr) / sizeof(int);

	InsertionSort(TestArr, iLength/*,Desc*/);

	for (int i = 0; i < iLength; ++i)
	{
		cout << TestArr[i] << endl;
	}

	system("pause");


}