#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::ofstream;

class ExcercisePlan
{
public:
	// constructor
	ExcercisePlan(const string &newPlanName = "", const string &newDate = "", const int &newGoalCalories = 0);

	// copy constructor
	ExcercisePlan(const ExcercisePlan &copy);

	// destructor
	~ExcercisePlan();

	// overloaded assignment
	ExcercisePlan & operator= (const ExcercisePlan &rhs);

	// getters
	string getPlanName() const; 
	                            
	string getDate() const;
	int getGoalSteps() const;

	// setters
	void setPlanName(const string &newPlanName);
	void setDate(const string &newDate);
	void setGoalSteps(const int &newGoalCalories);

	// prompt the user for a different goal
	void editGoal(); 

private:
	string mPlanName;
	string mDate;
	int mGoalSteps;
};

// nonmember functions
ostream & operator<< (ostream &lhs, const ExcercisePlan &rhs);
// write a complete DietPlan to a file
fstream & operator<< (fstream &lhs, const ExcercisePlan &rhs);
// read a complete DietPlan from a file
fstream & operator>> (fstream &lhs, ExcercisePlan &rhs);