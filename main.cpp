#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>
#include <unistd.h>

// Function to check if the current day is Sunday
bool isSunday()
{
    time_t t = time(nullptr);
    tm *timePtr = localtime(&t);
    return timePtr->tm_wday == 0;
}

int main()
{
    chdir("C:\\Users\\RUKUNDO\\Desktop\\scripted");
    std::string fileName = "scripts.txt";

    // Run the loop 10 times per day (excluding Sundays)
    for (int i = 0; i < 15; i++)
    {
        // Sleep for 5 minutes before each iteration
        std::this_thread::sleep_for(std::chrono::minutes(1));

        // Check if it's Sunday, if it is then skip this iteration
        if (isSunday())
        {
            continue;
        }

        // Open the file and append an 'A' to the end of the first line
        std::ofstream file(fileName, std::ios::app);
        file << "A";
        file.close();

        // Commit the changes to the local repository with the commit message "yohoho"
        std::string addCommand = "git add .";
        std::system(addCommand.c_str());
        std::string commitCommand = "git commit -am \"yohoho\"";
        std::system(commitCommand.c_str());

        // Push the changes to the remote repository
        std::string pushCommand = "git push";
        std::system(pushCommand.c_str());

        // Log done committing
        std::cout << "Pushed commit " << i << std::endl;
    }

    return 0;
}
