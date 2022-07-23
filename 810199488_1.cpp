#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#define EMPTY 0;
#define WRONG 0;
#define CORRECT 1;
using namespace std;
const string WORD_DELEMITOR = "	 ";
const int NUMBER_OF_PERSON_IN_EACH_GROUP = 3;
void Get_Initialize_input(int& Number_of_Group, int& Number_of_HomeWork, int& Number_of_Delivery);
void Create_Group(vector < vector< string > >& list_of_student, const int Number_of_Group);
void Random_number_of_delivery(vector <int>& list_random, const int Number_of_Delivery, const int Number_of_Group, vector < vector< string > >& list_of_student, int& srandTimer);
void Random_number_of_delivery_with_exeption(vector <int>& list_random, const int Number_of_Delivery, const int Number_of_Group, vector < vector< string > >& list_of_student, int& srandTimer, vector<int>previous);
void Present_list(vector < vector< string > >& list_random, vector < vector< string > >& presented, int& Number_of_Group, int& Number_of_HomeWork, int& Number_of_Delivery, int& srandTimer);
int sizeofVector(vector < vector< string > >& list_random);
int main()
{
	int Number_of_Group = EMPTY; int Number_of_HomeWork = EMPTY; int Number_of_Delivery = EMPTY; int srandTimer = EMPTY;
	Get_Initialize_input(Number_of_Group, Number_of_HomeWork, Number_of_Delivery);
	vector < vector< string > > list_of_student_in_first(Number_of_Group), presented(Number_of_Group);
	Create_Group(list_of_student_in_first, Number_of_Group);
	for (int i = 0; i < Number_of_HomeWork; i++)
		Present_list(list_of_student_in_first, presented, Number_of_Group, Number_of_HomeWork, Number_of_Delivery, srandTimer);
}

void Get_Initialize_input(int& Number_of_Group, int& Number_of_HomeWork, int& Number_of_Delivery) {
	cin >> Number_of_Group >> Number_of_HomeWork >> Number_of_Delivery;
}
void Create_Group(vector < vector< string > >& list_of_student, const int Number_of_Group) {
	string Temp_input_Text;
	for (int i = 0; i < Number_of_Group; i++)
	{
		for (int j = 0; j < NUMBER_OF_PERSON_IN_EACH_GROUP; j++)
		{
			cin >> Temp_input_Text;
			list_of_student[i].push_back(Temp_input_Text);
		}
	}
}
void Random_number_of_delivery(vector <int>& list_random, const int Number_of_Delivery, const int Number_of_Group, vector < vector< string > >& list_of_student, int& srandTimer) {
	for (int i = 0; i < Number_of_Delivery; i++)
	{
		int tempnum = EMPTY;int is_correct = EMPTY;
		do
		{
			srand(srandTimer); srandTimer++;
			tempnum = rand() % Number_of_Group;
			is_correct = EMPTY;
			for (int i = 0; i < list_random.size(); i++)
			{
				if (tempnum == list_random[i]) {
					is_correct = CORRECT;
					break;
				}
			}
			if (list_of_student[tempnum].size() == 0)
				is_correct = CORRECT;
			if (!is_correct)
				list_random.push_back(tempnum);
		} while (is_correct);
	}
}
void Present_list(vector < vector< string > >& list_of_student, vector < vector< string > >& presented, int& Number_of_Group, int& Number_of_HomeWork, int& Number_of_Delivery, int& srandTimer) {
	vector <int> list_random;
	vector <int> new_random;
	string Temp_Snumber;
	int VectorSize = sizeofVector(list_of_student);
	if (VectorSize == 0)
	{
		int number_group = EMPTY;
		Random_number_of_delivery(list_random, Number_of_Delivery, Number_of_Group, presented, srandTimer);
		for (int i = 0; i < Number_of_Delivery; i++)
		{
			srand(srandTimer);
			number_group = list_random[i];
			int number_of_person_here = presented[number_group].size();
			int rand_number_for_show_item = rand() % (number_of_person_here);
			Temp_Snumber = presented[number_group][rand_number_for_show_item];
			cout << Temp_Snumber << WORD_DELEMITOR;
		}
	}
	else if (VectorSize < Number_of_Delivery && VectorSize>0)
	{
		Random_number_of_delivery(list_random, VectorSize, Number_of_Group, list_of_student, srandTimer);
		int number_group = EMPTY;
		for (int i = 0; i < VectorSize; i++)
		{
			auto delete_item = list_of_student[list_random[i]].begin();
			srand(srandTimer); srandTimer++;
			int number_of_person_here = list_of_student[list_random[i]].size();
			int rand_number_for_show_item = rand() % (number_of_person_here);
			for (int i = 0; i < rand_number_for_show_item; i++)
				delete_item++;
			number_group = list_random[i];
			Temp_Snumber = list_of_student[number_group][rand_number_for_show_item];
			cout << Temp_Snumber << WORD_DELEMITOR;
			presented[list_random[i]].push_back(Temp_Snumber);
			list_of_student[list_random[i]].erase(delete_item);
		}
		Random_number_of_delivery_with_exeption(new_random, Number_of_Delivery - VectorSize, Number_of_Group, presented, srandTimer, list_random);
		for (int i = 0; i < Number_of_Delivery - VectorSize; i++)
		{
			number_group = new_random[i];
			int number_of_person_here = presented[number_group].size();
			int rand_number_for_show_item = rand() % (number_of_person_here);
			Temp_Snumber = presented[number_group][rand_number_for_show_item];
			cout << Temp_Snumber << WORD_DELEMITOR;
		}
	}
	else
	{
		Random_number_of_delivery(list_random, Number_of_Delivery, Number_of_Group, list_of_student, srandTimer);
		int number_group = EMPTY;
		for (int i = 0; i < Number_of_Delivery; i++)
		{
			auto delete_item = list_of_student[list_random[i]].begin();
			srand(srandTimer); srandTimer++;
			int number_of_person_here = list_of_student[list_random[i]].size();
			int rand_number_for_show_item = rand() % (number_of_person_here);
			for (int i = 0; i < rand_number_for_show_item; i++)
				delete_item++;
			number_group = list_random[i];
			Temp_Snumber = list_of_student[number_group][rand_number_for_show_item];
			cout << Temp_Snumber << WORD_DELEMITOR;
			presented[list_random[i]].push_back(Temp_Snumber);
			list_of_student[list_random[i]].erase(delete_item);
		}
	}
	cout << endl;
}
int sizeofVector(vector < vector< string > >& list_of_student) {

	int sizeVector = EMPTY;
	for (int i = 0; i < list_of_student.size(); i++)
		if (list_of_student[i].size() > 0)
			sizeVector++;
	return sizeVector;
}
void Random_number_of_delivery_with_exeption(vector <int>& list_random, const int Number_of_Delivery, const int Number_of_Group, vector < vector< string > >& list_of_student, int& srandTimer, vector<int>previous) {
	{
		int tempnum = 0, is_correct = 0;
		for (int i = 0; i < Number_of_Delivery; i++)
		{
			do
			{
				srand(srandTimer); srandTimer++;
				tempnum = rand() % Number_of_Group;
				is_correct = WRONG;
				for (int i = 0; i < list_random.size(); i++)
				{
					if (tempnum == list_random[i]) {
						is_correct = CORRECT;
						break;
					}
				}
				for (int i = 0; i < previous.size(); i++)
				{
					if (tempnum == previous[i]) {
						is_correct = CORRECT;
						break;
					}
				}
				if (list_of_student[tempnum].size() == 0)
					is_correct = CORRECT;
				if (!is_correct)
					list_random.push_back(tempnum);
			} while (is_correct);
		}
	}
}
