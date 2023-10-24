#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "include/fsys.h"
#include "include/misc.h"

#define maxCommandLen 100
#define maxFileName 45

int parseInput() {
    char * inp = malloc(maxCommandLen);
    char * fileName = malloc(maxFileName);
    char * foldName = malloc(maxFileName);
    char buffer[strlen(inp)];
    char * currDir = findDirName(getCurrDir());
    printf("KlaudFS/%s> ", currDir);
    fgets(inp,maxCommandLen,stdin);
    
    // get rid of newline if there
    if ((strlen(inp) > 0) && (inp[strlen(inp) - 1] == '\n'))
        inp[strlen(inp) - 1] = '\0';

    if (strcmp(inp, "exit") == 0) {
        return 1;
    } else if (strcmp(inp, "mount") == 0) {
        return 2;
    } else if (strcmp(inp, "--help") == 0) {
        return 3;
    } else if (strcmp(inp, "unmount") == 0) {
        return 4;
    } else if (strcmp(inp, "create") == 0) {
        return 5;
    } else if (strcmp(inp, "info") == 0) {
        return 6;
    } else if (strcmp(slice_str(inp,buffer,0,6), "newFile") == 0) {
        fileName = slice_str(inp,buffer,8,strlen(inp));
        makeFile(fileName);
        setFileSize(findFileNum(fileName),2000);
        return 7;
    } else if (strcmp(inp, "resetData") == 0) {
        return 8;
    } else if (strcmp(slice_str(inp,buffer,0,6), "delFile") == 0) {
        fileName = slice_str(inp,buffer,8,strlen(inp));
        int num = findFileNum(fileName);
        if (num != -1) {
            delFile(findFileNum(fileName));
            return 9;
        } else {
            return 11;
        }
    } else if (strcmp(inp, "write") == 0) {
        return 10;
    } else if (strcmp(slice_str(inp,buffer,0,4), "mkdir") == 0) {
        foldName = slice_str(inp, buffer, 6, strlen(inp));
        makeFolder(foldName);
        return 7;
    } else if (strcmp(slice_str(inp, buffer,0,1), "cd") == 0) {
        foldName = slice_str(inp, buffer, 3, strlen(inp));
        int res = cd(foldName);
        if (res == -1) {
            return 13;
        }
        return 7;
    } else if (strcmp(inp, "ls") == 0) {
        return 12;
    }
    free(inp);
    free(fileName);
    free(foldName);
    return 0;
}

void run(int token) {
    int peen = 0;
    switch (token) {
        case 1:
            exit(0);
            break;
        case 2:
            printf("Mounting...\n");
            syncFS();
            peen = mountFS();
            if (peen != -1) {
                printf("Mount Success!\n");
            }
            break;
        case 3:
            printf("\nKlaudFS is the first Klaud themed File System\n\n");
            commands();
            break;
        case 4:
            printf("Unmounting...\n");
            unmountFS();
            break;
        case 5:
            printf("conjuring file system...\n");
            peen = initFS();
            syncFS();
            mountFS();
            if (peen != -1) {
                printf("done!\n");
            }
            break;
        case 6:
            fsInfo();
            break;
        case 7:
            syncFS();
            break;
        case 8:
            clearAllData();
            syncFS();
            break;
        case 9:
            syncFS();
            printf("File deleted\n");
            break;
        case 10:
            int i;
            for (i=0;200>i;i++) {
                writeToByte(findFileNum("penis"), i*10, "a");
            }
            syncFS();
            break;
        case 12:
            ls();
            break;
        case 13:
            printf("Directory not found\n");
            break;
        case 0:
            printf("Command not recognized, try --help to find usable commands\n");
            break;
        case 11:
            printf("Not an available file name\n");
            break;
    }
}

int main() {
    klaud_ascii();
    printf("\nWelcome to the Klaud File System!\n");

    if (access("disk", F_OK) == 0) {
        mountFS();
    }
    
    while (1) {
        run(parseInput());
    }
    return 0;
}