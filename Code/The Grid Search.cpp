#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        int rowsGrid;
        int colsGrid;
        cin >> rowsGrid >> colsGrid;
        vector<string> grid(rowsGrid);
        for(int G_i = 0;G_i < rowsGrid;G_i++)
        {
           cin >> grid[G_i];
        }
        int rowsPattern;
        int colsPattern;
        cin >> rowsPattern >> colsPattern;
        vector<string> pattern(rowsPattern);
        for(int P_i = 0;P_i < rowsPattern;P_i++)
        {
           cin >> pattern[P_i];
        }
        int currPatternRow = 0;
        size_t found = 0;
        bool patternFound = false;
        vector<size_t> foundLocations;
        for(int currRow = 0; currRow < rowsGrid; currRow++)
        {
            //row before has been found now check next
            if(patternFound)
            {
                string patternLine = pattern[currPatternRow];
                string gridLine = grid[currRow];
                
                //need to go through all the found locations 
                int index = 0;
                //check char by char to see if same from found location in string 
                size_t lineX = foundLocations[index];
                for(size_t patternX = 0; patternX < colsPattern ; lineX++, patternX++)
                {
                    //grid doesn't follow pattern then break the search process and recheck to see if pattern starts on curr line
                    //keep track of edge of grid to prevent overflow
                    if(lineX >= colsGrid || gridLine[lineX] != patternLine[patternX])
                    {
                        if(index == foundLocations.size()-1)
                        {
                            patternFound = false;
                            currPatternRow = 0;
                            found = 0;
                        }
                        else
                            index++;
                     }
                }                
                
                //if the pattern is still found at this point then increment the pattern row
                if(patternFound)
                {
                    currPatternRow++;
                    if(currPatternRow == rowsPattern)
                    {
                        cout << "YES" << endl;
                        break;
                    }   
                }
            }
            
            //looking through the line for pattern
            //cases when there are multiple signs of the pattern, store all the start locations of found in a vector then loop through the search process for each entry?
            if(!patternFound)
            {
                foundLocations.clear();
                string line = grid[currRow];

                found = line.find(pattern[currPatternRow]);
                if(found != string::npos)
                {
                    foundLocations.push_back(found);
                    patternFound = true;
                    
                    //search for any more occurences of the pattern on this line and add to vector
                    while(found != string::npos)
                    {
                        found = line.find(pattern[currPatternRow],found+colsPattern);
                        if(found != string::npos)
                        {
                            foundLocations.push_back(found);
                        }
                    }
                }

                //to keep from incrementing while searching for all instances of the pattern
                if(patternFound)
                    currPatternRow++;
            }
            //if this is the last line and not YES then pattern is not in the grid
            if(currRow == rowsGrid-1)
                cout << "NO" << endl;
        }
    }
    return 0;
}