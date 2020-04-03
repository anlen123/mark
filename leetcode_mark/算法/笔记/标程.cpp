#include <fstream>
#define randint(a,b)    (rand() % (b-a+1))+ a;
srand((unsigned)time(NULL));
std::ofstream outFile;
std::ofstream outFile2;
outFile.open("F:\\shuru.txt");
outFile2.open("F:\\shuchu.txt");
outFile << T << endl;
outFile2 << b[2] << endl;
outFile.close();
outFile2.close();

