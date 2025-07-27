#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

enum enQuestionsLevel
{
    Easy = 1,
    Med = 2,
    Hard = 3,
    Mix=4
};

enum enOpType
{
    Add = 1,
    Sub = 2,
    Mul = 3,
    Div = 4,
    MixOpType = 5
};


struct stQuestion{
    short firstNumber = 0;
    short secondNumber = 0;
    enQuestionsLevel QuestionsLevel;
    enOpType OpType;
    int rightAnswer = 0;
    int playerAnswer = 0;
    bool answerResult = false;
};

struct stQuizz{
    stQuestion QuestionsList[100];
    short numberOfQuestions = 0;
    enQuestionsLevel questionsLevel;
    string nameOfQuestionLevel = "";
    enOpType OpType;
    string NameOfOpType;
    short NumberOfRightAnswers = 0;
    short NumberOfWrongAnswers = 0;
    bool IsPass = false;
};

short  RandomNumber(short From ,short To){
    return (short)(rand() % (To - From + 1) + From);
}

short ReadQuestionsNumber(){
    short QuestionsNumber = 0;
    do{
        cout << "Enter How Many Questions You Want TO Answer? from 1 To 10 ";
        cin >> QuestionsNumber;
    } while (QuestionsNumber < 0 || QuestionsNumber > 10);
    return QuestionsNumber;
}




enQuestionsLevel ReadQuestionLevel(){
    short QuestionsLevel=0;
    do{
        cout <<"\nEnter Question Level [1]Easy, [2]Med,[3]Hard,[4]Mix ? ";
        cin >> QuestionsLevel;
    } while (QuestionsLevel < 1 || QuestionsLevel > 4);
    return (enQuestionsLevel)QuestionsLevel;
}

string GetQuestionLevelText(enQuestionsLevel LevelNumber){
    string arrQuestionsLevel[4] = {"Easy", "Medium", "Hard", "Mixed"};
    return arrQuestionsLevel[LevelNumber- 1];
}

string GetOpTyeText(enOpType OpTypeNumber){
    string arrOpType[5]={"Add","Sub","Mul","Div","Mixed"};
    return arrOpType[OpTypeNumber-1];
}


enOpType GetRandomOpType()
{
    return (enOpType)RandomNumber(1, 4);
}

enOpType ReadOpType(){
    short OpType = 0;
    do
    {
        cout << "\nEnter Operation Type [1]Add, [2]Sub, [3]Mul, [4]Div, [5]Mix ? ";
        cin >> OpType;
    } while (OpType < 0 || OpType > 5);
    return (enOpType)OpType;
}

string GetOpTypeSymbol(enOpType OpType)
{
    switch(OpType){
        case enOpType::Add:
            return "+";
        case enOpType::Sub:
            return "-";
        case enOpType::Mul:
            return "x";
        case enOpType::Div:
            return "/";
        default:
            return "Mix";
        }
}



void setScreenColor(bool RightAnswer){
    if (RightAnswer){
        system("color 2F");
    }else{
        system("color 4F");
        system("\a");
    }
     
}


int RightAnswer(int Number1,int Number2,enOpType OpType){
    switch (OpType)
    {
    case enOpType::Add:
        return Number1 + Number2;
    case enOpType::Sub:
        return Number1 - Number2;
    case enOpType::Mul:
        return Number1 * Number2;
    case enOpType::Div:
        return (Number2 != 0) ? Number1 / Number2 : 0;
    default:
        cout << "\n you Have error related to Operation Type\n";
        return Number1 + Number2;
    }
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionsLevel,enOpType OpType){
    stQuestion Question;
  
    if (QuestionsLevel == enQuestionsLevel::Mix)
    {
        QuestionsLevel = (enQuestionsLevel)RandomNumber(1, 3);
    }
    if (OpType == enOpType::MixOpType)
    {
        OpType = GetRandomOpType();
    }
    Question.OpType = OpType;

    switch (QuestionsLevel)
    {
    case enQuestionsLevel::Easy:
        Question.firstNumber = RandomNumber(1, 10);
        Question.secondNumber = RandomNumber(1, 10);
        break;
    case enQuestionsLevel::Med:
        Question.firstNumber = RandomNumber(10, 50);
        Question.secondNumber = RandomNumber(10, 50);
        break;
    case enQuestionsLevel::Hard:
        Question.firstNumber = RandomNumber(50, 100);
        Question.secondNumber = RandomNumber(50, 100);
        break;
    }
    Question.QuestionsLevel= QuestionsLevel;
    Question.rightAnswer = RightAnswer(Question.firstNumber, Question.secondNumber, Question.OpType);

    return Question;
}

void askAndCorrectQuestionsListAnswers(stQuizz &Quizz){
    for (short QuestionNumber = 0; QuestionNumber < Quizz.numberOfQuestions; QuestionNumber++)
    {
        bool AnswerResult = Quizz.QuestionsList[QuestionNumber].answerResult;
        cout << "\nQuestion [" << QuestionNumber+1 << "/" << Quizz.numberOfQuestions << "]\n\n";
        cout << Quizz.QuestionsList[QuestionNumber].firstNumber << "\n"
             << Quizz.QuestionsList[QuestionNumber].secondNumber<<" "
             << GetOpTypeSymbol(Quizz.QuestionsList[QuestionNumber].OpType)
             << "\n______________________\n";
        cin >> Quizz.QuestionsList[QuestionNumber].playerAnswer;

        if (Quizz.QuestionsList[QuestionNumber].playerAnswer == Quizz.QuestionsList[QuestionNumber].rightAnswer)
        {
            cout << "\nCorrect";
            // AnswerResult = true;
            // setScreenColor(AnswerResult);
            Quizz.NumberOfRightAnswers++;
        }
        else
        {
            cout << "\nWrong :-( \n the Right Answer is : " << Quizz.QuestionsList[QuestionNumber].rightAnswer << endl;
            Quizz.NumberOfWrongAnswers++;
            // setScreenColor(AnswerResult);
        }
    }
    Quizz.IsPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);
}

void GenerateQuizzQuestions(stQuizz &Quizz){

    for (int QuestionNum = 0; QuestionNum <= Quizz.numberOfQuestions; QuestionNum++)
    {
        Quizz.QuestionsList[QuestionNum] = GenerateQuestion(Quizz.questionsLevel, Quizz.OpType);
    }
}

void finalResult(stQuizz Quizz){

    cout << "\n\n_________________________________________________\n\n";
    cout << "Final Result is " << (Quizz.IsPass ? "Pass :-)" : "Failed :-( ");
    cout << "\n\n_________________________________________________\n\n";
    cout << "Number Of Questions : " << Quizz.numberOfQuestions;
    cout << "\nQuestions Level : " << Quizz.nameOfQuestionLevel;
    cout << "\nOperation Type : " << Quizz.NameOfOpType;
    cout << "\nNumber Of Right Answer : " << Quizz.NumberOfRightAnswers;
    cout << "\nNumber Of Wrong Answer : " << Quizz.NumberOfWrongAnswers;
    cout << "\n\n_________________________________________________\n\n";
}

void PlayMathGame()
{

    char PlayAgain = 'Y';
    do{
        // system("cls");

        stQuizz  Quizz;
        Quizz.numberOfQuestions = ReadQuestionsNumber();
        Quizz.questionsLevel = ReadQuestionLevel();
        Quizz.OpType = ReadOpType();

        Quizz.nameOfQuestionLevel = GetQuestionLevelText(Quizz.questionsLevel);
        Quizz.NameOfOpType = GetOpTyeText(Quizz.OpType);

        GenerateQuizzQuestions(Quizz);
        askAndCorrectQuestionsListAnswers(Quizz);
        finalResult(Quizz);
        

        cout << "Do You Want To Play Again ? [Y/N] ";
        cin>>PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}


int main(){
    srand((unsigned)time(NULL));

    PlayMathGame();
    return 0;
}