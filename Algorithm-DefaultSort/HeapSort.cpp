#include <iostream>

using namespace std;

typedef	bool	Option;

#define Max true
#define Min false

class Heap
{
public:
	Heap(Option	_option =Max) 
		: SortOption(_option)
	{ 
		
	};
	virtual ~Heap() {};

public:
	void PrintVals()
	{
		for (int i = 1; i <= m_iSize; ++i)
		{
			cout << m_iArr[i] << endl;
		}
	}

public:
	void Insert(int _iVal)
	{
#pragma region MySolution
		////1. 맨 인덱스에 일단 삽입.
		//++m_iSize;
		//m_iArr[m_iSize] = _iVal;

		////2. 부모노드랑 비교해서 필요할 경우 교환 (부모가 더 커야함.)
		//int iMotherIndex = m_iSize / 2;
		//int iPastIndex = m_iSize;

		//while (true)
		//{
		//	if (iMotherIndex < 1)
		//	{
		//		break;
		//	}

		//	int iMotherVal = m_iArr[iMotherIndex];

		//	if (iMotherVal >= _iVal)
		//	{
		//		break;
		//	}
		//	else 
		//	{
		//		m_iArr[iPastIndex] = iMotherVal;
		//		m_iArr[iMotherIndex] = _iVal;
		//	}
		//	
		//	iPastIndex = iMotherIndex;
		//	iMotherIndex = iMotherIndex / 2;
		//}
#pragma endregion

#pragma region ReferenceSolution
		int iIndex = ++m_iSize;

		while (iIndex > 1 && (m_iArr[iIndex / 2] < _iVal))
		{
			m_iArr[iIndex] = m_iArr[iIndex / 2];

			iIndex /=  2;
		}

		m_iArr[iIndex] = _iVal;
			
#pragma endregion
	};

	void Delete()
	{
#pragma region MySolution
		////가장 큰(첫 노드) 값이랑 가장 마지막 값 교체
		//int iVal = m_iArr[m_iSize];
		//m_iArr[1] = iVal;
		//m_iArr[m_iSize] = 0;
		//--m_iSize;

		//int iCompare = 2;
		//
		////자식 노드들이랑 비교해 보며 값 정렬
		//while (iCompare <= m_iSize )
		//{
		//	if (iCompare + 1 > m_iSize)
		//	{
		//		if (m_iArr[iCompare] > iVal)
		//		{
		//			m_iArr[iCompare / 2] = m_iArr[iCompare];
		//			iCompare *= 2;
		//			break;
		//		}
		//	}
		//	else 
		//	{
		//		if (m_iArr[iCompare] >= m_iArr[iCompare + 1])
		//		{//지금 여기에서 문제 발생. iCompare+1이 size보다 큰 경우도 생김.
		//			if (m_iArr[iCompare] > iVal)
		//			{
		//				m_iArr[iCompare / 2] = m_iArr[iCompare];
		//				iCompare *= 2;
		//			}
		//			else
		//			{
		//				break;
		//			}

		//		}
		//		else if (m_iArr[iCompare] < m_iArr[iCompare + 1])
		//		{
		//			if (m_iArr[iCompare + 1] > iVal)
		//			{
		//				m_iArr[iCompare / 2 + 1] = m_iArr[iCompare];
		//				iCompare *= 2;
		//			}
		//			else
		//			{
		//				break;
		//			}
		//		}
		//	}
		//}

		//iCompare /= 2;

		//m_iArr[iCompare] = iVal;
		
		//작동 안함(한무루프 빠짐.)

#pragma endregion
#pragma region ReferenceSolution
		int iLastVal = m_iArr[m_iSize];
		--m_iSize;

		int iParentIndex = 1;
		int	iChildIndex = 2;

		while (iChildIndex <= m_iSize) 
		{
			// 현재 노드의 자식 노드 중 더 큰 자식 노드를 찾는다. 
			//(루트 노드의 왼쪽 자식 노드(index: 2)부터 비교 시작)
			if (iChildIndex < m_iSize&& 
				( m_iArr[iChildIndex] < m_iArr[iChildIndex+1]))
			{
				++iChildIndex;
			}

			if (iLastVal < m_iArr[iChildIndex])
			{
				// 더 큰 자식 노드보다 마지막 노드가 작으면, 
				// 부모 노드와 더 큰 자식 노드를 교환
				m_iArr[iParentIndex] = m_iArr[iChildIndex];

			}
			else 
			{//마지막 노드의 값이 더 큰 자식 노드의 값보다 작을 경우 탈출
					//=> 자리 찾은 경우
				break;
			}

			//다음 층으로 이동
			iParentIndex = iChildIndex;
			iChildIndex *= 2;
		}

		// 마지막 노드를 재구성한 위치에 삽입
		m_iArr[iParentIndex] = iLastVal;
	}

#pragma endregion




private:
	Option	SortOption = Max;
	int m_iArr[255] = {};
	int	m_iSize = 0;
};


void main()
{
	Heap myHeap;

	
	myHeap.Insert(2);
	myHeap.Insert(1);
	myHeap.Insert(7);
	myHeap.Insert(3);
	myHeap.Insert(5);

	myHeap.Insert(6);
	myHeap.Insert(8);
	myHeap.Insert(4);
	myHeap.Insert(7);
	myHeap.Insert(2);

	myHeap.Delete();
	myHeap.Delete();
	//myHeap.Delete();
	//myHeap.Delete();


	myHeap.PrintVals();
	system("pause");
}