#pragma once

#include <cstdlib> 

#include "DietPlan.h"
#include "ExcercisePlan.h"

class FitnessAppWrapper
{
public:
	FitnessAppWrapper(); // default constructor
	~FitnessAppWrapper(); // destructor

	void runApp(); // will drive the application
	void performUserSelection(const int &option);

	void loadWeeklyDietPlan(); 
	void displayWeeklyDietPlan(); 
	void storeWeeklyDietPlan(); 
	bool editDietPlan(); 

	void loadWeeklyExcercisePlan();
	void displayWeeklyExcercisePlan();
	void storeWeeklyExcercisePlan();
	bool editExcercisePlan();

private:
	DietPlan mDPList[7]; 
	fstream mFstrDP;    

	ExcercisePlan mEPList[7];
	fstream mFstrEP;

	// private helper/utility functions
	void loadDailyPlan(fstream &fileStream, DietPlan &plan);
	void loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]);
	void displayDailyPlan(const DietPlan &plan);
	void displayWeeklyPlan(const DietPlan weeklyPlan[]);
	void storeDailyPlan(fstream &fileStream, const DietPlan &plan);
	void storeWeeklyPlan(fstream &fileStream, const DietPlan weeklyPlan[]);

	void displayMenu();
};