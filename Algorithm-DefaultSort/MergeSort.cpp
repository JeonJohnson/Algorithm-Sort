#include <iostream>

using namespace std;

//�ϴ� ��������

void MergeSort(int _iArr[], int _iSize)
{
	int iHalfSize1 = _iSize / 2;
	int iHalfSize2 = _iSize - (iHalfSize1);


	int* iResultArr = new int[_iSize];
	int* iArr1 = new int[iHalfSize1];
	int* iArr2 = new int[iHalfSize2];

	//2��� �ϱ�
	memcpy(iArr1, _iArr, sizeof(int) * (iHalfSize1));
	memcpy(iArr2, &_iArr[iHalfSize1], sizeof(int) * (iHalfSize2));
	

	//2��� �� ģ���鵵 2���� ���ؼ� �ΰ��� �����ϱ�
	for (int i = 0; i < iHalfSize1; i +=2)
	{
		if (iArr1[i] > iArr1[i+1])
		{
			int iTemp = iArr1[i];
			iArr1[i] = iArr1[i + 1];
			iArr1[i + 1] = iTemp;
		}
	}

	for (int i = 0; i < iHalfSize2; i += 2)
	{
		if (iArr2[i] > iArr2[i + 1])
		{
			int iTemp = iArr2[i];
			iArr2[i] = iArr2[i + 1];
			iArr2[i + 1] = iTemp;
		}
	}

	int iIndex1, iIndex2, iIndex3 = 0;

	while (iIndex1 > iHalfSize1 || iIndex2 > iHalfSize2)
	{
		if (iArr1[iIndex1] < iArr2[iIndex2])
		{
			iResultArr[iIndex3] = iArr2[iIndex2];

			++iIndex2;
			++iIndex3;
		}
		else if (iArr1[iIndex1] > iArr2[iIndex2])
		{


			iResultArr[iIndex3] = iArr2[iIndex1];

			++iIndex1;
			++iIndex3;
		}
	}

	


	//�� �ε��̵��� �ϳ��� ���ϸ鼭 �迭�� ����






	//for (int i = 0; i < iHalfSize; ++i)
	//{
	//	cout << iArr1[i] << endl;
	//}

	//cout << "--------" << endl;

	//for (int i = 0; i < _iSize - (iHalfSize); ++i)
	//{
	//	cout << iArr2[i] << endl;
	//}


};



void main()
{
	//�ܰ躰 
	//1. �迭�� ������ ������. (A / B)
	//2. �� ���� A�� B ������ �� �� 2�� �������� �ɰ���.
	//3. 2�� ������ �ɰ� �� �������� �����Ѵ�.
	//4. �ٽ� ó���� ������ ������ó�� A / B ��ģ��.
	//5. �� �ٽ� ������� A�� B�� ���ҵ��� �ϳ��� ���� ���ǿ� ���Ͽ�
	//�����ϴ� ģ������ ���ο� �迭�� �Ҵ� �Ѵ�.
	//ex. ABCD / 1234 �� ���
	// A�� 1��, A�� ���ǿ� ������ ���ο� �迭�� �Ҵ��Ѵٸ�,
	// �״������� B�� 1���ϴ� �̷� ��İ� ������
	//6. ���ο� �迭�� ������ ���� �迭�� �����ؼ� ����Ѵ�.

	int iArr[10] = {3, 99, 66, 10, 5, 
					7, 24, 13, 6, 9};

	int iArrSize = sizeof(iArr) / sizeof(int);

	MergeSort(iArr, iArrSize);

	system("pause");

}