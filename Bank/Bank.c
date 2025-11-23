#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
//#include <direct.h>

/*
void database()
{
    // Makes Database Directory
    const char database_path[1024] = "Database";
    _mkdir(database_path);

    // Makes index.txt file
    const char indexfile_path[1024] = "Database/Index.txt";
    FILE *indexptr;
    indexptr = fopen(indexfile_path, "a");
    fclose(indexptr);

    // Makes transaction.log file
    const char transactionfile_path[1024] = Database/Transaction.log;
    FILE *transactionptr;
    transactionptr = fopen(transactionfile_path, "a");
    fclose(transactionptr);
}
*/

void database()
{
    // Makes Database Directory
    const char database_path[1024] = "Database";
    mkdir(database_path, 0755);

    // Makes index.txt file
    const char indexfile_path[1024] = "Database/Index.txt";
    FILE *indexptr;
    indexptr = fopen(indexfile_path, "a");
    fclose(indexptr);

    // Makes transaction.log file
    char transactionfile_path[1024] = "Database/Transaction.log";
    FILE *transactionptr;
    transactionptr = fopen(transactionfile_path, "a");
    fclose(transactionptr);
}



// Shows Session Info
void show_session_info()
{
    printf("        Session Info        \n");
    printf("-------------------------------\n");
    time_t timing = time(NULL);
    struct tm date = *localtime(&timing);

    // Count number of account by counting the number of lines in index.txt
    FILE *indexptr;
    indexptr = fopen("Database/Index.txt", "r");
    int acc_count = 1;
    int end = fgetc(indexptr); // Reads the line
    
    while (end != EOF) // Loops through the files until End of the file
    {
        if (end == '\n') // If Newline is found, then increment by 1
        {
            acc_count++;
        }
        end = fgetc(indexptr);
    }

    fclose(indexptr);

    printf("Date: %02d/%02d/%d\n", date.tm_mday, date.tm_mon + 1, date.tm_year + 1900); // Prints the Current Date
    printf("Time: %02d:%02d:%02d\n", date.tm_hour, date.tm_min, date.tm_sec); // Prints the Current Time 
    printf("Loaded Account: %d\n", acc_count);

    printf("-------------------------------\n");
}



int main()
{
    // Calls session_info Function
    show_session_info();

    // Call database Function
    database();

    return 0;
}
