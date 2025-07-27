#include <iostream>
using namespace std;
#include <cstdlib>

// ---------- generic functions --------

short readPositiveNumber(string massage)
{
    short number;
    cout << massage << endl;
    cin >> number;
    while (number <= 0)
    {
        cout << " the number most be grater than zero please retry -->";
        cin >> number;
        cout << endl;
    }

    return number;
}

short generateRandomNumberInRange(short from, short to)
{
    return rand() % (to - from + 1) + from;
}


int validateNumberInRange(int number, int from, int to)
{
    while (number < from || number > to)
    {
        cout << " the number most be between [" << from << " - " << to << "] please retry -->";
        cin >> number;
        cout << endl;
    }
    return number;
}
// --------------------------------------------------
enum enQuestionLevel
{
    easy = 1,
    Med = 2,
    Hard = 3,
    Mix = 4
};
enum enOpType
{
    Add = 1,
    Sub = 2,
    Mul = 3,
    Div = 4,
    MixOpType = 5
};

struct stQuestionItems{
    short firstNumber=0;
    short secondNumber=0;
    enQuestionLevel question_Level;
    string OptypeCharater="";
    enOpType OpType;
};

struct GameInfo{
    short questionsNumber=0;
    string questionsLevel;
    string operationType;
    short PlayerAnswer=0;
    short RightAnswers=0;
    short WrongAnswers=0;
};

enQuestionLevel ReadQuestionsLevel(){
    short QuestionLevel;
    cout << "Enter Questions Level :[1]Easy , [2]Med ,[3]Hard ,[4]Mix ? ";
    cin >> QuestionLevel;
    QuestionLevel = validateNumberInRange(QuestionLevel, 1, 4);
    return (enQuestionLevel) QuestionLevel;
}

enQuestionLevel chiosRandomLevel()
{
    return (enQuestionLevel)generateRandomNumberInRange(1, 3);
}

string GetQuestionsLevel(GameInfo &gameInfo, enQuestionLevel QuestionsLevel)
{
    switch (QuestionsLevel)
    {
    case enQuestionLevel::easy:
        return "Easy";
        
    case enQuestionLevel::Med:
        return "Med";
        
    case enQuestionLevel::Hard:
        return  "Hard";
        
    case enQuestionLevel::Mix:
        return  "Mix";
        
    default:
        cout << "Error While Getting Question Level ";
        return "";
    }
}



enOpType ReadOperationType()
{
    short operationType;
    cout << "Enter Operation Type :[1]Add , [2]Sub ,[3]Mul ,[4]Div ,[5]Mix ? ";
    cin >> operationType;
    operationType = validateNumberInRange(operationType, 1, 5);
    return (enOpType)operationType;
}

enOpType chiosRandomOpType()
{
    return (enOpType)generateRandomNumberInRange(1, 4);
}

string GetOperationType(GameInfo gameInfo,stQuestionItems &question)
{
    switch (question.OpType)
    {
        case enOpType::Add:
            question.OptypeCharater="+";
            return "+";
        case enOpType::Sub:
            question.OptypeCharater="-";
            return "-";
        case enOpType::Mul:
            question.OptypeCharater="x";
            return  "x";
        case enOpType::Div:
            question.OptypeCharater="/";
            return "/";
        case enOpType::MixOpType:
            return "Mix";
            break;
        default:
        cout << "Error While Getting Operation Type ";
        break;
    }
    return "+";
}



void fillQuestionItems(GameInfo &gameInfo,stQuestionItems &QuestionItems ){
    if(QuestionItems.question_Level ==enQuestionLevel::Mix){
        QuestionItems.question_Level = chiosRandomLevel();
    }
    if(QuestionItems.OpType == enOpType::MixOpType){
        QuestionItems.OpType = chiosRandomOpType();
    }

    if (QuestionItems.question_Level== enQuestionLevel::easy)
    {
        QuestionItems.firstNumber = generateRandomNumberInRange(1, 10);
        QuestionItems.secondNumber = generateRandomNumberInRange(1, 10);
    }
    else if (QuestionItems.question_Level == enQuestionLevel::Med)
    {
        QuestionItems.firstNumber = generateRandomNumberInRange(1, 20);
        QuestionItems.secondNumber = generateRandomNumberInRange(1, 20);
    }
    else if (QuestionItems.question_Level == enQuestionLevel::Hard)
    {
        QuestionItems.firstNumber = generateRandomNumberInRange(1, 100);
        QuestionItems.secondNumber = generateRandomNumberInRange(1, 100);
    }else{
        cout << "Error Will Fill Question Items \n";
    }

}

void PrintQuestion(GameInfo &gameInfo,stQuestionItems &QuestionItems, short NumberOfQuestion){
    short playerAnswer;
    cout << "\n Question [" << NumberOfQuestion << "/" << gameInfo.questionsNumber << "]\n\n";
    cout << QuestionItems.firstNumber << "\n";
    cout << QuestionItems.secondNumber << " ";
    cout << QuestionItems.OptypeCharater<< "\n";
    cout << "____________\n";
    cin >> playerAnswer;
    gameInfo.PlayerAnswer = playerAnswer;
}

short RightAnswer(GameInfo &GameInfo, stQuestionItems questionItems){
    short RightAnswer = 0;
    if(questionItems.OpType== enOpType::Add){
        RightAnswer = questionItems.firstNumber + questionItems.secondNumber;
    }
    else if (questionItems.OpType == enOpType::Sub){
        RightAnswer = questionItems.firstNumber - questionItems.secondNumber;
    }
    else if (questionItems.OpType == enOpType::Mul)
    {
        RightAnswer = questionItems.firstNumber * questionItems.secondNumber;
    }
    else if (questionItems.OpType == enOpType::Div)
    {
        RightAnswer = questionItems.firstNumber * questionItems.secondNumber;
    }else{
        cout << "Error Will Calculate Right Answer\n";
    }
    return RightAnswer;
}

void checkPlayerAnswer(GameInfo &GameInfo, stQuestionItems questionItems)
{
    short rightAnswer = RightAnswer(GameInfo, questionItems);
    if (GameInfo.PlayerAnswer == rightAnswer)
    {
        cout << "that is A Right Answer :) \n";
        GameInfo.RightAnswers = ++GameInfo.RightAnswers;
    }
    else
    {
        cout << "Wrong Answer\n";
        cout << "the Right Answer is " << rightAnswer << "\n";
        GameInfo.WrongAnswers = ++GameInfo.WrongAnswers;
    }
}

void startRound(GameInfo &gameInfo,stQuestionItems &questionItems, short NumberOfQuestion){
    fillQuestionItems(gameInfo, questionItems);
    PrintQuestion(gameInfo, questionItems, NumberOfQuestion);
    checkPlayerAnswer(gameInfo, questionItems);
}

void StartGame(GameInfo &gameInfo,stQuestionItems &questionItems )
{
    short questionsNumber= readPositiveNumber("How Many Question Do You Want To Answer ?");
    gameInfo.questionsNumber = questionsNumber;
    questionItems.question_Level= ReadQuestionsLevel();
    questionItems.OpType = ReadOperationType();

    gameInfo.questionsLevel = GetQuestionsLevel(gameInfo, questionItems.question_Level);
    gameInfo.operationType = GetOperationType(gameInfo, questionItems);

    for (int i = 1; i <= questionsNumber; i++){
        startRound(gameInfo, questionItems, i);
    }
}
string FinalResult(GameInfo gameInfo){
    string FinalResult = "";
    if(gameInfo.RightAnswers>=gameInfo.WrongAnswers){
        FinalResult = "Pass";
    }else{
        FinalResult = "Fail";
    }
    return FinalResult;
}

void printQuestionsStatistics(GameInfo gameInfo){
    cout << "\n\n_____________________________________________\n\n";
    cout << "\t\tFinal Result Is " << FinalResult(gameInfo) << "\n";
    cout << "\n\n_____________________________________________\n";
    cout << "\n\t\tNumber Of Questions : " << gameInfo.questionsNumber;
    cout << "\n\t\tQuestions Level : " << gameInfo.questionsLevel;
    cout << "\n\t\tOperation Type : " << gameInfo.operationType;
    cout << "\n\t\tNumber Of Right Answer: " << gameInfo.RightAnswers;
    cout << "\n\t\tNumber Of Wrong Answer: " << gameInfo.WrongAnswers;
    cout << "\n_____________________________________________"<<endl;

}
bool PlayAgain()
{
    bool playMore = true;
    cout << "do you want to play more  [ 0 or 1 ] ? ";
    cin >> playMore;
    return playMore;
}

void clearGameStatistics(GameInfo &gameInfo)
{
    gameInfo.questionsNumber=0;
    gameInfo.RightAnswers=0;
    gameInfo.WrongAnswers=0;
    gameInfo.PlayerAnswer=0;
}

void continuePlaying(GameInfo gameInfo, stQuestionItems questionItems)
{

    while (PlayAgain())
    {
        StartGame(gameInfo, questionItems);
        printQuestionsStatistics(gameInfo);
        clearGameStatistics(gameInfo);
    }
}

    int main()
{
    srand((unsigned)time(NULL));
    GameInfo gameInfo;
    stQuestionItems questionItems;


    StartGame(gameInfo, questionItems);
    printQuestionsStatistics(gameInfo);
    clearGameStatistics(gameInfo);

    continuePlaying(gameInfo, questionItems);

    return 0;
}
