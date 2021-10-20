#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <fstream>
using namespace std;
int main()
{
setlocale(LC_ALL, ".1251");
ofstream text;
text.open("text.txt");
int var, pid;
var=1;
text << "var = " << var << endl;
var+=1;
text << "После увеличения:" << var <<endl;
pid=fork();
if(pid == 0){
text << "\nДочерний процесс:\nДо изменения var = " << var << endl;
var += 5;
text << "После изменения: var = "<< var << endl;
}
else if(pid > 0){
text << "\nРодительский процесс:\nДо изменения var = " << var << endl;
var += 3;
text << "После изменения: var = " << var << endl;

wait((int *)pid); 
}
else {
perror("Fork error ");
return -1;
}
return 0;
}