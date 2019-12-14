#define LINE 256
#define WORD 30

#include <stdio.h>


int substring( char * str1, char * str2)
{
    char* ptrOnStr2 = str2;
    while((*(str1)!=0)&&(*(str2)!=0))
    {
        if(*(str1)==*(str2)){
            str2++;
        }
        else
        {
            str2=ptrOnStr2;
        }
        str1++;
    }

    if (*(str2)==0)
    {
        return 1;
    }
    return 0;
}

int similar (char *s, char *t, int n)
{
    int counter = 0;
    while(*s!=0&&*t!=0)
    {
        if(*s==*t)
        {
            t++;
        }
        else
        {
            counter++;
        }
        s++;
        
    }
    if(*s==0&&*t==0){
        if (n==counter)
        {
            return 1;
        }
            return 0;      
    }
    if (*s==0)
    {
        return 0;
    }
    while (*s)
    {
        counter++;
        s++;
    }
    if (n==counter)
    {
        return  1;
    }
    return 0;
    
}

void print_lines(char* keyWord)
{
    char line [LINE];
    while (scanf("%[^\n]%*c", line)!=EOF)
    {
        if (substring(line, keyWord))
        {
            printf("%s\n", line);
        }
        
    }
}

void print_similar_words(char* keyWord)
{
    char word [WORD];
     while (scanf("%s", word)!=EOF)
    {
        if ((similar(word, keyWord, 1))||(similar(word, keyWord, 0))) 
        {
            printf("%s\n", word);
        }
        
    }


}
int main()
{
    char key;
    char keyWord [WORD];
    int idx = 0;
    char firstLine [LINE];
    char* lPtr;

    scanf("%[^\n]s", firstLine);
   
    lPtr = firstLine;
    while (*lPtr!=' ')
    {
        keyWord[idx]=firstLine[idx];
        idx++;
        lPtr++;
    }
    key=firstLine[++idx];
    keyWord[idx-1]='\0';
    
    scanf("%s",firstLine);
    if(key=='a'){
        print_lines(keyWord);   
    } 
    else
    {
        print_similar_words(keyWord);
    }
    
}

