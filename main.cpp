/*
 Skynet HK-Aerial
 Kieli Adkins
 CSC215
 May 15, 2018
*/

// Including standard libraries
#include <iostream>
#include <cstdlib>
#include <ctime>

// Including std namespace
using namespace std;

// Main function
int main()
{
    // Seeding the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    // Generating the random number
    int enemyLocation = rand() % 64 + 1;
    
    // Compiling the amount of tries
    int tries = 0;
    
    // Printing the enemy location information
    cout << "Initializing enemy placement on an 8 x 8 grid...\n" "Enemy is located at gridspace # " << enemyLocation << "\n\n";
    
    // Grid high number
    int searchGridHighNumber = 64;
    
    // Grid low number
    int searchGridLowNumber = 1;
    
    // Binary search algorithm
    int targetLocationPrediction = 0;
    
    do
    {
        // Printing the initialization sequence
        cout << "Initialization of Skynet HK-Aerial software commencing...\n";
        
        // Binary search algorithm
        int targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
        
        // Addition to the amount of tries
        ++tries;
        
        // If statement regarding the greater than status of the target location prediction
        if (targetLocationPrediction > enemyLocation)
        {
            // Re-initializing the high number within the binary search algorithm
            searchGridHighNumber = targetLocationPrediction;
            
            // Printing that enemy location guess is too high
            cout << "Analyzation resulted in a search of gridspace # " << targetLocationPrediction << " . This gridspace is a higher number than the enemy's location. \nCommencing another analyzation...\n ------------------" << endl;
        }
        
        // Else if statement regarding the less than status of the target location prediction
        else if (targetLocationPrediction < enemyLocation)
        {
            // Re-initializing the low number within the binary search algorithm
            searchGridLowNumber = targetLocationPrediction;
            
            // Printing that enemy location guess is too low
            cout << "Analyzation resulted in a search of gridspace # " << targetLocationPrediction << " . This gridspace is a lower number than the enemy's location. \nCommencing another analyzation...\n ------------------" << endl;
        }
        
        // Else statement regarding successful enemy location
        else
        {
            // Printing the successful enemy location sequence
            cout << "Analyzation resulted in a search of gridspace # " << targetLocationPrediction << "\nThe enemy was located at gridspace # " << targetLocationPrediction << "\nIt took Skynet HK-Aerial approximately " << tries << " analyzation sequences to find the enemy within the grid.\n\n" << endl;
            
            // Break statement to exit do loop
            break;
        }
    }
    
    // While loop to re-initialize do loop
    while (targetLocationPrediction != enemyLocation);


    // Return function to ensure program success
    return 0;
}
