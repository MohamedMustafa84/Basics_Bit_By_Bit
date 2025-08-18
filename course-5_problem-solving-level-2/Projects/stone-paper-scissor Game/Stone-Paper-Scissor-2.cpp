#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

enum enGameChoices
{
    stone = 1,
    paper = 2,
    scissor = 3
};

enum enWinner
{
    computer = 1,
    player1 = 2,
    Draw = 3
};

struct stRoundInfo{
    short RoundNumber = 0;
    enGameChoices computerChoice;
    enGameChoices player1Choice;
    enWinner Winner;
    string WinnerName = "";
};

struct stGameResult{
    short RoundsNumber=0;
    short Player1OwnTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner gameWinner;
    string winnerName = "";
};


// ---------- generic functions --------

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

int readPositiveNumber(string message)
{
    int number;
    cout << message << " --> ";
    cin >> number;
    cout << endl;
    while (number <= 0)
    {
        cout << " the number most be greeter than zero please retry -->";
        cin >> number;
        cout << endl;
    }

    return number;
}

// --------------------------------------



enGameChoices getComputerChoice(){
    return (enGameChoices)RandomNumber(1, 3);
}
enGameChoices getPlayer1Choice(){
    short choice;

    do{
        cout << "\nYour Choice :[1]Stone ,[2]Paper ,[3]Scissor ";
        cin >> choice;
    } while (choice > 3 || choice < 1);
    return (enGameChoices)choice;
}


enWinner RoundWinner(stRoundInfo RoundInfo){
    if(RoundInfo.computerChoice == RoundInfo.player1Choice){
        return enWinner::Draw;
    }
    switch (RoundInfo.player1Choice)
    {
    case enGameChoices::stone:
        return (RoundInfo.computerChoice == enGameChoices::paper) ? enWinner::computer : enWinner::player1;
    case enGameChoices::paper:
        return (RoundInfo.computerChoice == enGameChoices::scissor) ? enWinner::computer : enWinner::player1;
    case enGameChoices::scissor:
        return (RoundInfo.computerChoice == enGameChoices ::stone) ? enWinner::computer : enWinner::player1;
    }
    return enWinner::Draw;
}

enWinner GameWinner(short PlayerWinTimes ,short ComputerWinTimes){
    if(PlayerWinTimes > ComputerWinTimes){
        return enWinner::player1;
    }
    else if (PlayerWinTimes < ComputerWinTimes){
        return enWinner::computer;
    }
        
    return enWinner::Draw;
}


string NameChoice(enGameChoices choice){
    string arrGameChoice[3] = {"Stone", "Paper", "Scissor"};
    return arrGameChoice[choice - 1];
}

string WinnerName(enWinner winner)
{
    string arrWinnerName[3] = {"Player1", "Computer", "Draw"};
    return arrWinnerName[winner-1];
}

void PrintRoundResult(stRoundInfo RoundInfo){
    cout << "\n___________________ Round[" << RoundInfo.RoundNumber << "]___________________\n";
    cout << "Player1Choice : " << RoundInfo.player1Choice;
    cout << "\nComputer Choice : " << RoundInfo.computerChoice;
    cout << "\nRound Winner : " << RoundInfo.WinnerName;
    cout << "\n______________________________________________________" << endl;
}

void PrintFinalResult(stGameResult GameResult)
{
    cout << "\t\t\t_____________________________________________________________\n";
    cout << "\t\t\t\t\t +++ G a m e  O v e r +++\n";
    cout << "\t\t_______________________________________________________________________\n";
    cout << "\t\t____________________________ [Game Results ] ___________________________\n";
    cout << "\t\t\tGame Rounds           :" << GameResult.RoundsNumber;
    cout << "\n\t\t\tPlayer1 won times     :" << GameResult.Player1OwnTimes;
    cout << "\n\t\t\tComputer won times    :" << GameResult.ComputerWinTimes;
    cout << "\n\t\t\tDraw times            :" << GameResult.DrawTimes;
    cout << "\n\t\t\tfinal Winner          :" << GameResult.winnerName<< endl;
    cout << "\t\t_______________________________________________________________________\n";
}

stGameResult PlayGame(short RoundsNumber, stRoundInfo &RoundInfo)
{

    short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short currentRound = 1; currentRound <= RoundsNumber; currentRound++){
        cout << "\nRound ["<<currentRound <<"] Begins\n";
        RoundInfo.RoundNumber = currentRound;
        RoundInfo.player1Choice = getPlayer1Choice();
        RoundInfo.computerChoice = getComputerChoice();
        RoundInfo.Winner = RoundWinner(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::player1)
        {
            PlayerWinTimes++;
        }
        else if (RoundInfo.Winner == enWinner::computer){
            ComputerWinTimes++;
        }else{
            DrawTimes++;
        }
        PrintRoundResult(RoundInfo);
    }

    return (stGameResult){RoundsNumber, PlayerWinTimes, ComputerWinTimes, DrawTimes, GameWinner(PlayerWinTimes, ComputerWinTimes), WinnerName(GameWinner(PlayerWinTimes, ComputerWinTimes))};
}

void StartGame()
{
    stRoundInfo RoundInfo;
    char PlayAgain = 'Y';

    do{
        // system("cls");
        stGameResult GameResult = PlayGame(readPositiveNumber("Enter How Many Round You Want To Play"), RoundInfo);
        PrintFinalResult(GameResult);
        
        cout << "\n\nDo You Want To Play Again ? (Y/N) ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}



int main()
{
    srand((unsigned)time(NULL));
    StartGame();
    
    return 0;
}