#include "ExcercisePlan.h"


ExcercisePlan::ExcercisePlan(const string &newPlanName, const string &newDate, const int &newGoalSteps)
{
	this->mPlanName = newPlanName;
	this->mDate = newDate;
	this->mGoalSteps = newGoalSteps;
	cout << "Inside DietPlan's constructor!" << endl;
}

ExcercisePlan::ExcercisePlan(const ExcercisePlan &copy)
{
	this->mPlanName = copy.mPlanName;

	this->mDate = copy.mDate;
	this->mGoalSteps = copy.mGoalSteps;
}

ExcercisePlan::~ExcercisePlan()
{
	cout << "Inside of ExcercisePlan's destructor!" << endl;
}

ExcercisePlan & ExcercisePlan::operator= (const ExcercisePlan &rhs)
{

	if (this != &rhs)
	{

		this->mPlanName = rhs.mPlanName;

		this->mDate = rhs.mDate;
		this->mGoalSteps = rhs.mGoalSteps;
	}

	return (*this);
}

// getters 
string ExcercisePlan::getPlanName() const
{
	return this->mPlanName;
}

string ExcercisePlan::getDate() const
{
	return this->mDate;
}

int ExcercisePlan::getGoalSteps() const
{
	return this->mGoalSteps;
}

// setters 
void ExcercisePlan::setPlanName(const string &newPlanName)
{
	this->mPlanName = newPlanName;
}

void ExcercisePlan::setDate(const string &newDate)
{
	this->mDate = newDate;
}

void ExcercisePlan::setGoalSteps(const int &newGoalSteps)
{
	this->mGoalSteps = newGoalSteps;
}

void ExcercisePlan::editGoal() // prompt the user for a different goal 
{
	cout << "Please enter a new step goal: ";
	cin >> this->mGoalSteps;

	cout << (*this) << endl;
}


ostream & operator<< (ostream &lhs, const ExcercisePlan &rhs)
{
	lhs << rhs.getPlanName() << endl << rhs.getGoalSteps() << endl << rhs.getDate();

	return lhs;
}


fstream & operator<< (fstream &lhs, const ExcercisePlan &rhs)
{
	((ofstream &)(lhs)) << rhs.getPlanName() << endl << rhs.getGoalSteps() << endl << rhs.getDate();

	return lhs;
}


fstream & operator >> (fstream &lhs, ExcercisePlan &rhs)
{
	char tempString[100] = "";
	lhs.getline(tempString, 100);
	rhs.setPlanName(tempString);
	int goalSteps = 0;
	lhs.getline(tempString, 100);
	goalSteps = atoi(tempString);
	rhs.setGoalSteps(goalSteps);
	lhs.getline(tempString, 100);
	rhs.setDate(tempString);

	return lhs;
}