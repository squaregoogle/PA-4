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

class DietPlan
{
public:
	// constructor
	DietPlan(const string &newPlanName = "", const string &newDate = "", const int &newGoalCalories = 0);

	// copy constructor
	DietPlan(const DietPlan &copy);

	// destructor
	~DietPlan();

	// overloaded assignment
	DietPlan & operator= (const DietPlan &rhs); 

	// getters
	string getPlanName() const; 
	                            
	string getDate() const;
	int getGoalCalories() const;

	// setters
	void setPlanName(const string &newPlanName);
	void setDate(const string &newDate);
	void setGoalCalories(const int &newGoalCalories);

	// prompt the user for a different goal
	void editGoal(); 

private:
	string mPlanName;
	string mDate;
	int mGoalCalories;
};

// nonmember functions
ostream & operator<< (ostream &lhs, const DietPlan &rhs); 
// write a complete DietPlan to a file
fstream & operator<< (fstream &lhs, const DietPlan &rhs);  
// read a complete DietPlan from a file
fstream & operator>> (fstream &lhs, DietPlan &rhs); 