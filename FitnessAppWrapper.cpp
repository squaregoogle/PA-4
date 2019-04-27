#include "FitnessAppWrapper.h"

FitnessAppWrapper::FitnessAppWrapper()
{
	cout << "Inside FitnessAppWrapper's constructor!" << endl;
}

FitnessAppWrapper::~FitnessAppWrapper()
{
	cout << "Inside FitnessAppWrapper's destructor!" << endl;
}

void FitnessAppWrapper::runApp() 
{
	int option = 0;
	do
	{
		do 
		{
			this->displayMenu();
			cin >> option;
		} while (option < 1 || option > 9); 
		system("cls");
		this->performUserSelection(option);
	} while (option != 9); 
}

void FitnessAppWrapper::performUserSelection(const int &option)
{
	bool success = false;

	switch (option)
	{
	case 1: // load weekly DP
		this->loadWeeklyDietPlan();
		cout << "Diet plans loaded from dietPlans.txt" << endl;
		break;
	case 2: // load weekly EP
		cout << "Exersie plans loaded from exercisePlans.txt" << endl;
		break;
	case 3: // store weekly DP
		this->storeWeeklyDietPlan();
		cout << "Diet plans stored to dietPlans.txt" << endl;
		break;
	case 4: // store weekly EP
		cout << "Exercise plans stored to exercisePlans.txt" << endl;
		break;
	case 5: // display weekly DP
		system("cls"); // not necessarily a portable/safe way to clear the screen
		this->displayWeeklyDietPlan();
		break;
	case 6: // display weekly EP
		system("cls");
		/*this->displayWeeklyExcercisePlan();*/
		break;
	case 7: // edit daily DP
		success = this->editDietPlan();
		if (!success)
		{
			cout << "Could not find the diet plan specified!" << endl;
		}
		break;
	case 8: // edit daily EP
		//success = this->editExcercisePlan();
		//if (!success)
		//{
		//	cout << "Could not find the diet plan specified!" << endl;
		//}
		break;
	case 9: // exit
		this->storeWeeklyDietPlan();
		break;
	}
}

void FitnessAppWrapper::loadWeeklyDietPlan() 
{
	if (this->mFstrDP.is_open()) 
	{
		this->mFstrDP.close(); 
	}
	else 
	{
		this->mFstrDP.open("dietPlans.txt");
		this->loadWeeklyPlan(this->mFstrDP, this->mDPList);
		this->mFstrDP.close();
	}
}

void FitnessAppWrapper::displayWeeklyDietPlan()
{
	this->displayWeeklyPlan(this->mDPList);
}

void FitnessAppWrapper::storeWeeklyDietPlan() 
{
	if (this->mFstrDP.is_open())
	{
	
		this->mFstrDP.close();
	}
	else 
	{
		this->mFstrDP.open("dietPlans.txt"); 
		this->storeWeeklyPlan(this->mFstrDP, this->mDPList);
		this->mFstrDP.close();
	}
}

bool FitnessAppWrapper::editDietPlan() 
{
	system("cls");
	this->displayWeeklyDietPlan(); 
	cout << "Which diet plan would you like to edit (provide plan name)? ";

	char planName[100] = "";
	cin.ignore();
	cin.getline(planName, 100);
	string stdPlanName = planName;

	bool success = false;
	
	for (int day = 0; day < 7; ++day)
	{
		
		if (stdPlanName == this->mDPList[day].getPlanName())
		{
			success = true;
			this->mDPList[day].editGoal();
		}
	}

	return success;
}

//void FitnessAppWrapper::loadWeeklyExcercisePlan()
//{
//	if (this->mFstrEP.is_open())
//	{
//		this->mFstrEP.close();
//	}
//	else
//	{
//		this->mFstrEP.open("dietPlans.txt");
//		this->loadWeeklyPlan(this->mFstrEP, this->mDPList);
//		this->mFstrEP.close();
//	}
//}

//void FitnessAppWrapper::displayWeeklyExcercisePlan()
//{
//	this->displayWeeklyPlan(this->mEPList);
//}

//void FitnessAppWrapper::storeWeeklyExcercisePlan()
//{
//	if (this->mFstrEP.is_open())
//	{
//
//		this->mFstrEP.close();
//	}
//	else
//	{
//		this->mFstrEP.open("exercisePlans.txt");
//		this->storeWeeklyPlan(this->mFstrEP, this->mEPList);
//		this->mFstrEP.close();
//	}
//}

//bool FitnessAppWrapper::editExcercisePlan()
//{
//	system("cls");
//	this->displayWeeklyExcercisePlan();
//	cout << "Which exercise plan would you like to edit (provide plan name)? ";
//
//	char planName[100] = "";
//	cin.ignore();
//	cin.getline(planName, 100);
//	string stdPlanName = planName;
//
//	bool success = false;
//
//	for (int day = 0; day < 7; ++day)
//	{
//
//		if (stdPlanName == this->mEPList[day].getPlanName())
//		{
//			success = true;
//			this->mEPList[day].editGoal();
//		}
//	}
//
//	return success;
//}

void FitnessAppWrapper::loadDailyPlan(fstream &fileStream, DietPlan &plan)
{
	fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[])
{
	
	for (int day = 0; day < 7; ++day) 
	{
		this->loadDailyPlan(fileStream, weeklyPlan[day]); 
		char tempString[2];
		fileStream.getline(tempString, 2); 
	}
}

void FitnessAppWrapper::displayDailyPlan(const DietPlan &plan)
{
	cout << plan << endl; 
				         
}

void FitnessAppWrapper::displayWeeklyPlan(const DietPlan weeklyPlan[])
{

	for (int day = 0; day < 7; ++day) 
	{
		this->displayDailyPlan(weeklyPlan[day]); 
		cout << endl; 
	}
}

void FitnessAppWrapper::storeDailyPlan(fstream &fileStream, const DietPlan &plan)
{
	fileStream << plan << endl;
}

void FitnessAppWrapper::storeWeeklyPlan(fstream &fileStream, const DietPlan weeklyPlan[])
{

	for (int day = 0; day < 7; ++day) 
	{
		this->storeDailyPlan(fileStream, weeklyPlan[day]); 
		fileStream << endl; 
	}
}

void FitnessAppWrapper::displayMenu()
{
	cout << "1.\tLoad weekly diet plans from file." << endl;
	cout << "2.\tLoad weekly exercise plans from file." << endl;
	cout << "3.\tStore weekly diet plans to file." << endl;
	cout << "4.\tStore weekly exercise plans to file." << endl;
	cout << "5.\tDisplay weekly diet plans to screen." << endl;
	cout << "6.\tDisplay weekly exercise plans to screen." << endl;
	cout << "7.\tEdit daily diet plan." << endl;
	cout << "8.\tEdit daily exercise plan." << endl;
	cout << "9.\tExit." << endl;
}