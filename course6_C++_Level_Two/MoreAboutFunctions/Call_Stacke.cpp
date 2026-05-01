#include <iostream>
using namespace std;

// Call Stack/Call Hierarchy:
// It is the execution priority of functions according to the compiler.
// It works as follows: the last to enter the stack is the first to leave.

// From real life:
// In any family, it is the execution priority of the children’s requests according to the child’s age compared to his siblings.
// Usually, the youngest child (the last born) has higher priority than the rest of his siblings.

void middleSonOrder();
void YoungSonOrder();
void OldSonOrder()
{
    cout << "old Son: Great! I can finally join the gym and improve my fitness." << endl;

    cout << "Father: Are you crazy? Do you want to waste my money on this nonsense?\n"
         << "Son, don’t say I’m being harsh, but this is a waste of money. If you observe nature, you'll find that most animals with long lifespans don’t do much physical effort. For example, compare the turtle, which lives over a hundred years, with animals like lions that have much shorter lifespans." << endl;

    cout << "Think about it while I take your brother’s request." << endl;
    middleSonOrder();

    cout << "old son: The spoiled one always wins." << endl;
}

void middleSonOrder()
{
    cout << "Father: Your turn, Mark. What would you like to ask for?" << endl;
    cout << "MiddleSon: Well, I want to buy a sled to go ice skating. It has always been my favorite hobby." << endl;
    cout << "Father: Are you insane? You want to buy a sled in this heat? If you look out the window, even the shadow itself is gone — even the shadow can’t stand sitting outside in this heat!" << endl;

    cout << "It seems no one in this family is in their right mind, except my little one, Peter. What is your request, my dear?" << endl;
    YoungSonOrder();

    cout << "Are you serious!!" << endl;
}

void YoungSonOrder()
{
    cout << "young son: Well, since the Russians were the first to set foot on the moon, and Elon Musk started building colonies on Mars, I will make a trip to the sun to find out the reason behind this heat. Then I will make only one season—winter—so Mark can skate all year long." << endl;
    cout << "old Son: Are you crazy? The money won’t be enough for all that, and even if it were, the moment you get close to the sun, you’ll burn up!" << endl;
    cout << "Young son: Do you think I’m stupid enough to go during the day? My trip will be at night, you idiot!" << endl;

    cout << "Father: This is my son whom I’m proud of. From the moment you were born, I knew you'd be a genius. I told Molly, “This one will be the Newton of this world" << endl;
    cout << "Father: Don’t worry, my son. Even if the money isn’t enough, I’ll sell your brothers’ organs on the black market so you can carry out this amazing project" << endl;
}

int main()
{
    cout << "father: Great! I’ve won a prize worth one million dollars, and now I will fulfill any request you have immediately. To be fair, I will start with the oldest of you." << endl;
    OldSonOrder();

    return 0;
}
