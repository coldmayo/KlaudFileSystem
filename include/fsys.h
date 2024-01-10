//FS info

#define BLOCKSIZE 420

struct SuperBlock {
    int numInodes;
    int numBlocks;
    int numDirs;
    int sizeBlocks;
    int ifMounted;
    int currDir;
};

struct folder {
    int index;
    int prevDir;
    char name[8];
};

struct inode {
    int size;
    int firstBlock;
    int directory;
    char name[8];
};

struct block {
    int nextBlockNum;
    char data[BLOCKSIZE];
};

int initFS(void);
int mountFS(void);
void syncFS(void);
void fsInfo(void);
int makeFile(char * fileName);
void setFileSize(int fileNum, int size);
void writeToByte(int fileNum, int pos, char *data);
int findFileNum(char* fileName);
int unmountFS(void);
int delFile(int fileNum);
void clearAllData(void);
void makeFolder(char * foldName);
char * findDirName(int id);
int findDirNum(char * foldName);
int getCurrDir(void);
int cd(char * foldName);
void ls(void);
void addMoreInodes(int num);
void addMoreDirs(int num);
int pwd(void);