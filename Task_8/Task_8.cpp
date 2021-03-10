#include <iostream>
using namespace std;

int robberyTheory(int valueOfHouse, int* arrayOfValuesOfHouses)
{
    // ������������ �������� ��������
    int maxCostOfStolen = arrayOfValuesOfHouses[0];
    for (int i = 1; i < valueOfHouse; i++)
    {
        // ���� ������ ������ ���
        if (i % 2 == 0)
        {
            maxCostOfStolen += arrayOfValuesOfHouses[i];
        }
    }
    // ���������� ���������� ��������� ��������
    return maxCostOfStolen;
}

bool test()
{
    // ������ ���������� ����������� �����
    bool isPassed = true;
    // �������� � �������� ��������
    int firstTestArrayOfValuesOfHouses[7] = {6, 7, 1, 3, 8, 2, 4};
    if (robberyTheory(7, firstTestArrayOfValuesOfHouses) != 19)
    {
        isPassed = false;
    }
    // �������� � ������ ��������
    int secondTestArrayOfValuesOfHouses[6] = {6, 1, 3, 8, 2, 4};
    if (robberyTheory(6, secondTestArrayOfValuesOfHouses) != 11)
    {
        isPassed = false;
    }
    // �������� � ������� � ������
    int thirdTestArrayOfValuesOfHouses[4] = {0, 0, 0, 0};
    if (robberyTheory(4, thirdTestArrayOfValuesOfHouses) != 0)
    {
        isPassed = false;
    }
    // �������� � �������� �� ������
    int fourthTestArrayOfValuesOfHouses[4] = { 1, 1, 1, 1 };
    if (robberyTheory(4, fourthTestArrayOfValuesOfHouses) != 2)
    {
        isPassed = false;
    }
    return isPassed;
}

int main()
{
    //Unit �����
    if (!test())
    {
        printf("Some tests failed.");
        return 1;
    }

    // ������ �������
    int valueOfHouse = 0;
    cout << "Please, enter the integer value of houses: ";
    // ��������� �� ������������ ������� �������
    cin >> valueOfHouse;

    // ���� ����� ���, �� �������� ��� :)
    if (valueOfHouse <= 0)
    {
        cout << "Max cost of stolen: " << 0;
        return 0;
    }

    // ��������� ������ ��� �������
    int* arrayOfValuesOfHouses = new int[valueOfHouse];
    cout << "House numbers: ";
    for (int i = 0; i < valueOfHouse; i++)
    {
        // ������ ���������� �����, ������� ������ rand()
        arrayOfValuesOfHouses[i] = rand() % 100 + 1;
        cout << arrayOfValuesOfHouses[i] << ' ';
    }
    // ����� ���������� ���������� �������
    cout << endl << "Max cost of stolen: " << robberyTheory(valueOfHouse, arrayOfValuesOfHouses);
    // ������� ������
    delete[] arrayOfValuesOfHouses;
    return 0;
}