//Imports
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cstring>

//Helper functions
void print(std::vector<string> const &a)
{
    std::cout << "A." + a.at(0) << "        ";
    std::cout << "B." + a.at(1) << "        ";
    std::cout << "C." + a.at(2) << "        ";
    std::cout << "D." + a.at(3) << "        ";
}

int getIndex(vector<string> v, string K)
{
    auto it = find(v.begin(), v.end(), K);

    // If element was found
    if (it != v.end())
    {

        // calculating the index
        // of K
        int index = it - v.begin();
        return index;
    }
    else
    {
        // If the element is not
        // present in the vector
        return -1;
    }
}

//main
int main()
{
    srand(time(0));

    vector<string> vectorOfQuestions;
    std::ifstream dbQuestions("dbQuestions.txt");
    std::string lineFromFile;

    std::string delimiter = "*";
    size_t pos = 0;
    std::string token;
    int userScore = 0;

    while (std::getline(dbQuestions, lineFromFile))
    {
        vectorOfQuestions.push_back(lineFromFile);
    }

    for (auto i = vectorOfQuestions.begin(); i != vectorOfQuestions.end(); ++i)
    {
        pos = 0;
        std::string s = *i;
        bool isQuestionString = true;
        bool isAnswerString = false;
        string answer = "";

        vector<string> vectorOfAnswersForCurrentQuestion;

        while ((pos = s.find(delimiter)) != std::string::npos)
        {
            token = s.substr(0, pos);

            if (isAnswerString == true)
            {
                answer = token;
                isAnswerString = false;
            }

            if (isQuestionString == true)
            {
                cout << "--------------------------------------------------" << endl;
                std::cout << token << std::endl;
                isQuestionString = false;
                isAnswerString = true;
            }
            else
            {
                vectorOfAnswersForCurrentQuestion.push_back(token);
            }

            s.erase(0, pos + delimiter.length());
        }

        vectorOfAnswersForCurrentQuestion.push_back(s);

        //Shuffle the vector of answers
        mt19937 g(static_cast<uint32_t>(time(0)));
        shuffle(vectorOfAnswersForCurrentQuestion.begin(), vectorOfAnswersForCurrentQuestion.end(), g);

        //Call helper function to print the vector of answers
        print(vectorOfAnswersForCurrentQuestion);

        //Get user answer
        std::string userAnswer;
        cout << ' ' << endl;
        cout << "Your Answer: ";
        cin >> userAnswer;

        //evaluate answer
        int index = getIndex(vectorOfAnswersForCurrentQuestion, answer);

        if (index == 0 && userAnswer == "A")
        {
            userScore++;
        }
        else if (index == 1 && userAnswer == "B")
        {
            userScore++;
        }
        else if (index == 2 && userAnswer == "C")
        {
            userScore++;
        }
        else if (index == 3 && userAnswer == "D")
        {
            userScore++;
        }

        //Feedback score
        cout << "Your Score" << ' ';
        cout << userScore << ' ';
        cout << ' ' << endl;
        cout << ' ' << endl;
        cout << ' ' << endl;
    }
}