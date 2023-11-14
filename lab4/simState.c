#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void findUnreachableStates(char states[][3], int numStates, char isGarb[8])
{
    int count = 0;
    int refcount = 0;
    int g = 0;
	for (int i = 0; i < 8; i++)
    {
		if(states[i][1] == states[i][2]){
			for(int j = 0; j < 8; j ++){
				if(j != i){
					isGarb[j] = states[j][0];
					count++;
				}			
			}
		}
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((states[i][0] == (states[j][1])) || (states[i][0] == states[j][2]))
            {
                refcount++;
            }
        }
        if (refcount == 0)
        {
            isGarb[g] = states[i][0];
            g++;
            count++;
        }
        refcount = 0;
    }
    int SoG = sizeof(isGarb) / sizeof(isGarb[0]);
    if (count == 0)
    {
        printf("No Garbage Detected");
    }
    else
    {
        for (int i = 0; i < SoG; i++)
        {
            if (isGarb[i] >= 'A' && isGarb[i] <= 'H')
            {
                printf("Garbage: %c\n", isGarb[i]);
            }
        }
    }

}

void deleteStates(char states[][3], int numStates, char isGarb[8])
{
    int count = 0;
    int size = (sizeof(isGarb) / sizeof(isGarb[0]));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (isGarb[i] == states[j][0])
            {
                printf("Deleted:%c\n", states[j][0]);
                states[j][0] = '-';
                states[j][1] = '-';
                states[j][2] = '-';
                count++;
            }
        }
    }
    numStates = numStates - count;
    if (count == 0)
    {
        printf("No garbage states.");
    }
}

void deletestate(char states[][3], int numStates, char strInput, char isGarb[8])
{
    int count = 0;
    int size = (sizeof(isGarb) / sizeof(isGarb[0]));
    for (int i = 0; i < size; i++)
    {
        if (isGarb[i] == strInput)
        {
            for (int index = 0; index < 8; index++)
            {
                if (isGarb[i] == states[index][0])
                {
                    states[index][0] = '-';
                    states[index][1] = '-';
                    states[index][2] = '-';
                    printf("Deleted: %c\n", strInput);
                }

            }
            count++;
        }
    }
    numStates = numStates - count;
    if (count == 0)
    {
        printf("State Not Deleted.");
    }
}


// det. nextState
char nextState(char a[8][3], char curr, int input) {
    char current[2] = { curr, '\0' };
    int currentIndex = 0;
    int check = 0;

    if (input != 0 && input != 1) { // checks if input is 0 or 1
        printf("input in method nextState isn't valid\n");

    }

    for (int i = 0; i < 8; i++) {
        if (a[i][0] == curr) {
            //printf("%c %c\n", a[i][0], curr);
            currentIndex = i;
            break;
        }
    }

    if (a[currentIndex][0] == curr) {
        //printf("check complete\n");
        check = 1;
    }
    else {
        printf("%d something wrong in the code pls contact arian\n", currentIndex);

    }

    if (check == 1) {
        if (input == 0) {
            return a[currentIndex][1];
        }
        else if (input == 1) {
            return a[currentIndex][2];
        }
        else {
            printf("something wrong in the code (code: meow)");

        }
    }

    return ' ';
}

void changeState(char command[100], char currentState, char states[][3]) {
    int i;
    
	for (i = 0; i < 8; i++) {
        if (states[i][0] == currentState && states[i][0] != '-') {
            if (command[2] == '0') {
                states[i][1] = command[4];
            }
            else if (command[2] == '1') {
                states[i][2] = command[4];
            }
            break;
        }
    }
}

void printS(char states[][3]) {
    int i;
    for (i = 0; i < 8; i++) {
        if (states[i][0] != '-') {
            printf("%c: %c %c\n", states[i][0], states[i][1], states[i][2]);
        }
    }
}


int main(int argc, char* argv[]) {
    char isGarb[8];
    memset(isGarb, '\0', sizeof(isGarb));
    int intInput;
    int numStates = 8;
    char strInput[100];
    char initialState = 'B';
    char currentState = initialState;
    char states[8][3] = {
        {'A','F','E'},
        {'B','G','A'},
        {'C','D','C'},
        {'D','A','E'},
        {'E','B','H'},
        {'F','C','G'},
        {'G','H','F'},
        {'H','B','C'}
    };

    printf("Starting state: < %c >\n", initialState);

    while (1) {
        intInput = 5;
        strInput[0] = '-';
        strInput[1] = '-';
        strInput[2] = '-';
        strInput[3] = '-';
        strInput[4] = '-';
        strInput[5] = '-';

        while (1) {
            printf("\nEnter a input:");
            fgets(strInput, 100, stdin);
            //printf("strInput is:%s\n", strInput); // Print the updated value here
            if (strInput[0] == '1' && strlen(strInput) == 2) {
                intInput = 1;
                break;
            }
            else if (strInput[0] == '0' && strlen(strInput) == 2) {
                intInput = 0;
                break;
            }
            else if (strInput[0] == 'c' && (strInput[2] == '0' || strInput[2] == '1') && strInput[4] >= 'A' && strInput[4] <= 'H') {
                break;
            }
            else if (strInput[0] == 'p' && strlen(strInput) == 2) {
                break;
            }
            else if (strInput[0] == 'd' && (strlen(strInput) == 2 || strlen(strInput) == 3)) {
                break;
            }
            else if (strInput[0] == 'g' && strlen(strInput) == 2) {
                break;
            }
            else if (strInput[0] == 'e') {
                exit(0);
            }
            else {
                printf("\ninput invalid try again\n");
            }
        }
        //printf("strInput is OUTSIDELOOP:%s\n", strInput); // Print the updated value here

        //printf("strInput is:%c%c%c\n", strInput[0], strInput[1],strInput[2]);
        if (intInput == 1) {
            currentState = nextState(states, currentState, 1);
            printf("current state is: < %c >\n", currentState);
        }
        else if (intInput == 0) {
            currentState = nextState(states, currentState, 0);
            printf("current state is: < %c >\n", currentState);
        }
        else if (strInput[0] == 'c') {
            changeState(strInput, currentState, states);


        }
        else if (strInput[0] == 'p') {
            printS(states);

        }
        else if (strInput[0] == 'd') {
            if (strlen(strInput) == 2) {


                deleteStates(states, numStates, isGarb);
            }
            else if (strlen(strInput) == 3) {

                deletestate(states, numStates, strInput[1], isGarb);
                numStates--;
            }

        }
        else if (strInput[0] == 'g') {
            findUnreachableStates(states, numStates, isGarb);

        } 


    }

    return 0;
}
