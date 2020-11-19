#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Function prototypes
int numOfMatch(char ans[], const char correctAns[], const int Size);
void printWrong(char ans[], const char correctAns[], const int Size);

int main()
{
	// declaring variables
	const int Size = 20;
	char correctAns[Size];
	char ans[Size];
	int result;
	double percentage;
	int counter;

	// ifstream reading in files
	ifstream reader("CorrectAnswers.txt");

	if (!reader)
	{
		cout << "Error opening file" << endl;
		return 0;
	}

	counter = 0;
	while ((reader>>correctAns[counter++]) && counter < Size);

	reader.close();

	reader.open("StudentAnswers.txt");

	if (!reader)
	{
		cout << "Error opening file" << endl;
		return 0;
	}

	counter = 0;
	while ((reader >> ans[counter++]) && counter < Size);
	
	// storing number of correct answers in result variable
	result = numOfMatch(ans, correctAns, Size);

	// calculating percentage correct
	percentage = 1.0 * result / Size;

	if (result < 20)
	{
		cout << "The questions that were answered incorrectly" << endl;
		printWrong(ans, correctAns, Size);
	}
	else
	{
		cout << "No questions were answered incorrectly." << endl;
	}

	cout << "Total missed questions: " << Size - result << endl;

	cout << "Percentage of correct answers: " << percentage << endl;

	// Passing grade must be over 70
	if (percentage >= 0.7)
	{
		cout << "You passed!" << endl;
	}
	else
	{
		cout << "You failed" << endl;
	}

	return 0;
}

int numOfMatch(char ans[], const char correctAns[], const int Size)
{
	// intialize counter variable
	int correct = 0;

	// enter each individual array item 
	for (int i = 0; i < Size; i++)
	{
		// if answer is correct, add to the counter variable
		if (ans[i] == correctAns[i])
		{
			correct++;
		}
	}

	return correct;
}

void printWrong(char ans[], const char correctAns[], const int Size)
{
	// enter each individual array item
	for (int i = 0; i < Size; i++)
	{
		// when student gets an answer wrong, display the correct answer
		if (ans[i] != correctAns[i])
		{
			cout << "Question " << i + 1 << endl;
			cout << "Correct answer: " << correctAns[i] << endl;
			cout << "Student answer: " << ans[i] << endl;
		}
	}
}