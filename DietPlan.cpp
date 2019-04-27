#include "DietPlan.h"

DietPlan::DietPlan(const string &newPlanName, const string &newDate, const int &newGoalCalories)
{
	this->mPlanName = newPlanName;
	this->mDate = newDate;
	this->mGoalCalories = newGoalCalories;
	cout << "Inside DietPlan's constructor!" << endl;
}

DietPlan::DietPlan(const DietPlan &copy)
{
	this->mPlanName = copy.mPlanName;   
	                           
	this->mDate = copy.mDate;  
	this->mGoalCalories = copy.mGoalCalories;  
}

DietPlan::~DietPlan()
{
	cout << "Inside of DietPlan's destructor!" << endl;
}

DietPlan & DietPlan::operator= (const DietPlan &rhs)
{
	
	if (this != &rhs) 
	{
	
		this->mPlanName = rhs.mPlanName;  
									
		this->mDate = rhs.mDate;  
		this->mGoalCalories = rhs.mGoalCalories;  
	}

	return (*this);
}

// getters 
string DietPlan::getPlanName() const 
{
	return this->mPlanName;
}

string DietPlan::getDate() const
{
	return this->mDate;
}

int DietPlan::getGoalCalories() const
{
	return this->mGoalCalories;
}

// setters 
void DietPlan::setPlanName(const string &newPlanName)
{
	this->mPlanName = newPlanName; 
}

void DietPlan::setDate(const string &newDate)
{
	this->mDate = newDate; 
}

void DietPlan::setGoalCalories(const int &newGoalCalories)
{
	this->mGoalCalories = newGoalCalories;
}

void DietPlan::editGoal() // prompt the user for a different goal 
{
	cout << "Please enter a new calories goal: ";
	cin >> this->mGoalCalories;

	cout << (*this) << endl; 
}




ostream & operator<< (ostream &lhs, const DietPlan &rhs)  
{
	lhs << rhs.getPlanName() << endl << rhs.getGoalCalories() << endl << rhs.getDate();

	return lhs; 
}


fstream & operator<< (fstream &lhs, const DietPlan &rhs)
{
	((ofstream &)(lhs)) << rhs.getPlanName() << endl << rhs.getGoalCalories() << endl << rhs.getDate();

	return lhs;
}


fstream & operator>> (fstream &lhs, DietPlan &rhs) 
{
	char tempString[100] = "";
	lhs.getline (tempString, 100); 
	rhs.setPlanName(tempString); 
	int goalCalories = 0;
	lhs.getline(tempString, 100); 
	goalCalories = atoi(tempString); 
	rhs.setGoalCalories(goalCalories);
	lhs.getline(tempString, 100);  
	rhs.setDate(tempString);

	return lhs; 
}