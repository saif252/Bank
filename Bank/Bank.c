#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

void folder()
{
    mkdir("database", 0755);
}

void session_info()
{
    printf("        Session Info        \n");
    printf("-----------------------------------\n");

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char date[20], time_str[20];

    strftime(date, sizeof(date), "%d-%m-%Y", t);
    strftime(time_str, sizeof(time_str), "%H:%M:%S", t);

    int acc_count = 0;
    DIR *dir = opendir("database");
    
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) 
    {
        if (strstr(entry->d_name, ".txt") && strcmp(entry->d_name, "index.txt") != 0)
        {
            acc_count++;
        }
    }
    closedir(dir);

    printf("Date: %s\n", date);
    printf("Time: %s\n", time_str);
    printf("Loaded Account: %d\n", acc_count);

    printf("-----------------------------------\n");
}

void menu()
{
    printf("\n");
    printf("        Welcome To Bank     \n");
    printf("-----------------------------------\n");
    printf("Please Choose An Option\n");
    printf("1. Create New Bank Account\n");
    printf("2. Delete Bank Account \n");
    printf("3. Deposit\n");
    printf("4. Withdrawal\n");
    printf("5. Remittance\n");
    printf("6. Quit\n");
    printf("-----------------------------------\n");

    char input[10];
    printf("Select Option: ");
    scanf("")
}



int main()
{
    folder();
    session_info();
    menu();
    return 0;
}
