#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enChoices {Rock = 1, Paper = 2, Scissor = 3};

int ReadPositiveNumber(string Message) {
    int Number = 0;
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

int RoundsNumber(int &Number,string Message) 
{
    do {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

string ChoiceName(int Choice)
{
    if(Choice == enChoices::Rock)
    {
        return "Rock";
    }
    else if (Choice == enChoices::Paper)
    {
        return "Paper";
    }
    else
    {
        return "Scissors";
    }
}

string WhoWonInRound(int MyChoice, int ComputerChoice,int &MyChoiceFreq,int &ComputerChoiceFreq) 
{
    if (MyChoice == ComputerChoice) 
    {
        return "It's a tie!";
    } 

    else if (MyChoice == enChoices::Rock && ComputerChoice == enChoices::Scissor)
    {
        MyChoiceFreq++;
        return "You win!";
    }

     else if (MyChoice == enChoices::Paper && ComputerChoice == enChoices::Rock) 
    {
        MyChoiceFreq++;
        return "You win!";
    } 

    else if (MyChoice == enChoices::Scissor && ComputerChoice == enChoices::Paper) 
    {
        MyChoiceFreq++;
        return "You win!";
    } 

    else 
    {
        ComputerChoiceFreq++;
        return "Computer wins!";
    }
}

void Round(int RoundsNumber,int &MyChoiceFreq,int &ComputerChoiceFreq)
{
    int RoundNumber = 0;
    cout << "Choose your move: (1 = Rock, 2 = Paper, 3 = Scissors)\n";

    do 
    {
        cout << "Round [" << RoundNumber + 1 << "] ";
        int MyChoice = ReadPositiveNumber("Enter your choice:");
        int ComputerChoice = RandomNumber(1,3);

        cout << "_________________________________________________________\n" << endl;
        cout << "Computer chose: " << ChoiceName(ComputerChoice) << endl;
        cout << "You chose     : " << ChoiceName(MyChoice) << endl;
        cout << WhoWonInRound(MyChoice,ComputerChoice,MyChoiceFreq,ComputerChoiceFreq) << endl;
        cout << "_________________________________________________________\n";

        RoundsNumber--;
        RoundNumber++;
    } while (RoundsNumber > 0);

    cout << endl;
    
}

void FinalResults(int &Number,int &MyChoiceFreq,int &ComputerChoiceFreq)
{
    printf("--------------------------------------------------\n");
    printf("|                   Game Over                    |\n");
    printf("--------------------------------------------------\n");
    printf("| %-20s | %-23d |\n", "Total rounds", Number);
    printf("| %-20s | %-23d |\n", "You won", MyChoiceFreq);
    printf("| %-20s | %-23d |\n", "Computer won", ComputerChoiceFreq);
    printf("--------------------------------------------------\n");

}

void Clear() 
{
    system("clear");
}

void Game()
{
    int Number = 0;
    int MyChoiceFreq = 0;
    int ComputerChoiceFreq = 0;

    Clear();
    Round(RoundsNumber(Number,"How many rounds would you like to play?"),MyChoiceFreq,ComputerChoiceFreq);
    FinalResults(Number,MyChoiceFreq,ComputerChoiceFreq);
    
}

void StartGame()
{
    char YesOrNo;
    
    do
    {   
        Game();
        cout << "Would you like to play again? (y/n): ";
        cin >> YesOrNo;
    }while(YesOrNo == 'y' || YesOrNo == 'Y');
}

int main()
{
    srand((unsigned) time(NULL));

    StartGame();

    return 0;
    
}
