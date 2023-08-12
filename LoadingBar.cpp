#include <iostream>
#include <unistd.h>

using namespace std;
class LoadingBar {

    private:
    int amountOfFiller;
    int BarLength = 80;
    int updatedValue = 0;
    float currentProgress = 0;
    float TotalProgress = 100;

public:
        string firstPartOfpBar = "Loading....  ";//mostly used so i put that
        string lastPartOfpBar = "";
        string BarUpdater = "`~`~"; //anything we want
        char  BarFiller = 254;//char "BLOCK" ASCII code is 254.

    void update(double newProgress)
     {
        currentProgress = currentProgress + newProgress;
        amountOfFiller = (int)((currentProgress / TotalProgress)*BarLength);
     }

    void print()
    {
        updatedValue = updatedValue % BarUpdater.length();
        cout << "\r" << firstPartOfpBar;

        for (int a = 0; a < amountOfFiller; a++)
        {
          cout << BarFiller;
        }
        cout << BarUpdater[updatedValue];

        for (int b = 0; b < (BarLength-amountOfFiller); b++)
        {
            cout << " ";
        }
        cout << lastPartOfpBar //Print out last part of progress bar
            << " (" << (int)(100*(currentProgress/TotalProgress)) << "%)" //This just prints out the percent
            << flush;
        updatedValue = updatedValue + 1;
    }

};

int main() {

    LoadingBar bar;// creating object of Loading Bar Class.
    system("color 0C"); //changing color of the console and output using system function.

    //Main loop:

    for (int i = 0; i < 200; i++)
        {
        //Update LoadingBar:
        bar.update(0.5); //How much new progress was added.
        bar.print();//Print loading Bar:
        usleep(100);// using delay in microseconds. In 1 second there are 10^6 microseconds.
    }
    cout << endl;
    cout << endl;
    return 0;
}
