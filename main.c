#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100

int main() {
    FILE *file;
    char line[MAX_LENGTH];
    int lineCount = 0;
    int chosenLine = 0;

    // Open the file
    file = fopen("food.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Count the number of lines in the file
    while (fgets(line, sizeof(line), file)) {
        lineCount++;
    }

    // Generate a random line number
    srand(time(0));
    chosenLine = rand() % lineCount + 1;

    // Reset file position to the beginning
    fseek(file, 0, SEEK_SET);

    // Choose the random line
    int currentLine = 0;
    while (fgets(line, sizeof(line), file)) {
        currentLine++;
        if (currentLine == chosenLine) {
            printf("You should go here! ---> \033[1m%s\033[0m", line);
            break;
        }
    }

    // Close the file
    fclose(file);

    return 0;
}
