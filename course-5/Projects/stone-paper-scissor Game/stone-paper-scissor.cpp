#include <iostream>
using namespace std;
#include <cstdlib>

// ---------- generic functions --------

int readNumberInRange(string message, int from, int to)
{
    int number;
    cout << message << " From " << from << " To " << to << "\n";
    cin >> number;
    cout << endl;
    while (number < from || number > to)
    {
        cout << " the number most be between  " << from << " - " << to << " -->";
        cin >> number;
        cout << endl;
    }
    return number;
}

short generateRandomNumberInRange(short  from, short to)
{

    return rand() % (to - from + 1) + from;
}

short validateNumberInRange(short  number,short from, short to )
{
    while (number < from || number > to)
    {
        cout << " the number most be between [" << from << " - " << to << "] please retry -->";
        cin >> number;
        cout << endl;
    }
    return number;
}

// -- -- -- -- -- -- -- -- -- -- -
enum enGameChoices {
    stone = 1,
    paper = 2,
    scissor = 3
};


struct stGameStatistics{
    int roundsNumber=0;
    enGameChoices playerChoice;
    enGameChoices computerChoice;
    int  playerWonNumber=0;
    int  computerWonNumber=0;
    int  drawNumber=0;
    string RoundWinner;
    string finalWinner;
};

void getRoundsNumber(stGameStatistics &GameStatistics){
    GameStatistics.roundsNumber = readNumberInRange("How Many Round you wont to play ?", 1, 10);
}

    enGameChoices getPlayerChoice()
{
    short playerChoice = 0;
    cout << "\n Your Choice : [1]:Stone, [2]:Paper,[3]:Scissors ?";

    cin >> playerChoice;
    playerChoice = validateNumberInRange(playerChoice, 1, 3);
    return (enGameChoices)playerChoice;
}

 enGameChoices GenerateComputerChoice(){
    
     return (enGameChoices)generateRandomNumberInRange(1, 3);
 }
 void playRound(stGameStatistics &GameInfo, int roundNumber)
 {
     cout << "Round [" << roundNumber << "] begins:\n";
     GameInfo.playerChoice = getPlayerChoice();
     GameInfo.computerChoice = GenerateComputerChoice();
    }
void roundWinner(stGameStatistics &Round){

        if (Round.playerChoice == enGameChoices::stone && Round.computerChoice == enGameChoices::paper)
        {
            Round.RoundWinner = "Computer";
        }
        else if (Round.playerChoice == enGameChoices::stone && Round.computerChoice == enGameChoices ::scissor)
        {
            Round.RoundWinner = "Player";
        }
        else if (Round.playerChoice == enGameChoices::stone && Round.computerChoice == enGameChoices ::stone)
        {
            Round.RoundWinner = "No Winner";
        }
        else if (Round.playerChoice == enGameChoices::paper && Round.computerChoice == enGameChoices::paper)
        {
            Round.RoundWinner = "No Winner";
        }
        else if (Round.playerChoice == enGameChoices::paper && Round.computerChoice == enGameChoices::scissor)
        {
            Round.RoundWinner = "Computer";
        }
        else if (Round.playerChoice == enGameChoices::paper && Round.computerChoice == enGameChoices::stone)
        {
            Round.RoundWinner = "Player";
        }
        else if (Round.playerChoice == enGameChoices::scissor && Round.computerChoice == enGameChoices::scissor)
        {
            Round.RoundWinner = "No Winner";
        }
        else if (Round.playerChoice == enGameChoices::scissor && Round.computerChoice == enGameChoices::paper)
        {
            Round.RoundWinner = "Player";
        }
        else if (Round.playerChoice == enGameChoices::scissor && Round.computerChoice == enGameChoices::stone)
        {
            Round.RoundWinner = "Computer";
        }
        else
        {
            cout << "they are something Wrong " << endl;
        }
    }
    
    void RoundResult(stGameStatistics &Round, int roundNumber)
    {
        cout << "\t\n _____________Round[" << roundNumber << "]___________________\n\n";
        cout << "Player Choice :" << Round.playerChoice << "\n";
        cout << "Computer Choice :" << Round.computerChoice << "\n";
        
        if (Round.RoundWinner == "Player")
        {
            cout << "Round winner :"<<Round.RoundWinner << endl;
            Round.playerWonNumber = Round.playerWonNumber+1;
        }
        else if (Round.RoundWinner == "Computer")
        {
            cout << "Round winner :"<<Round.RoundWinner << endl;
            Round.computerWonNumber = Round.computerWonNumber +1;
        }
        else 
        {
            cout << "Round winner :"<<Round.RoundWinner << endl;
            Round.drawNumber = Round.drawNumber+1;
        }

        cout << "___________________________________________\n\n";
    }

void playGame(stGameStatistics &gameInfo)
 {
     getRoundsNumber(gameInfo);
     for (int i = 1; i <= gameInfo.roundsNumber; i++)
     {
         playRound(gameInfo,i);
         roundWinner(gameInfo);
         RoundResult(gameInfo, i);
     }
 }
 bool PlayAgain(){
     bool playMore = true;
     cout << "do you want to play more  [ 0 or 1 ] ? ";
     cin >> playMore;
     return playMore;
 }

 void gameResult(stGameStatistics stGameStatistics){
     cout << "\t\t\t_____________________________________________________________\n";
     cout << "\t\t\t\t\t +++ G a m e  O v e r +++\n";
     cout << "\t\t\t_____________________________________________________________\n";
     cout << "\t\t\t_______________________ [Game Results ] ______________________\n";
     cout << "Game Rounds           :" << stGameStatistics.roundsNumber;
     cout << "\n\t\t\tPlayer1 won times     :" << stGameStatistics.playerWonNumber;
     cout << "\n\t\t\tComputer won times    :" << stGameStatistics.computerWonNumber;
     cout << "\n\t\t\tDraw times            :" << stGameStatistics.drawNumber;
     cout << "\n\t\t\tfinal Winner          :" << stGameStatistics.finalWinner << endl;
 }
 void finalWinner(stGameStatistics &stGameStatistics){
    if(stGameStatistics.playerWonNumber > stGameStatistics.computerWonNumber){
        stGameStatistics.finalWinner = "Player";
    }
    else if (stGameStatistics.playerWonNumber < stGameStatistics.computerWonNumber){
        stGameStatistics.finalWinner = "Computer";
    }else{
        
        stGameStatistics.finalWinner = "No Winner";
    }
 }
 void clearStatistics(stGameStatistics &statistics)
 {
     statistics.roundsNumber = 0;
     statistics.computerWonNumber = 0;
     statistics.drawNumber = 0;
     statistics.playerWonNumber = 0;
 }

void continuePlaying(stGameStatistics &stGameStatistics)
 {

     while (PlayAgain())
     {
         playGame(stGameStatistics);
         finalWinner(stGameStatistics);
         gameResult(stGameStatistics);
         clearStatistics(stGameStatistics);
     }

 }
 

     int main()
 {
     srand((unsigned)time(NULL));
     stGameStatistics stGameStatistics;
     playGame(stGameStatistics);
     finalWinner(stGameStatistics);
     gameResult(stGameStatistics);
     continuePlaying(stGameStatistics);

     return 0;
 }