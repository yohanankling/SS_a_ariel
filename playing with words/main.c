#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define TXT 1024
#define WORD 30
int gematria;
char word [WORD];
char txt [TXT];
char atbash [WORD];
void getWord();
int getTxt();
void foo1(int counter);
void azby(int wordL);
void foo2(int wordL,int counter);
void foo3(int wordL,int counter);

int main(void)
{
    getWord();
    int counter = getTxt();
   // printf("%d tx ",counter);
    printf("Gematria Sequences: ");
    foo1(counter);
    int wordL = strlen(word)+1;
  //  printf("%d  wo ",wordL);
    azby(wordL);
   // printf("%d  wo",wordL);
    printf("Atbash Sequences: ");
    foo2(wordL,counter);
    //printf("%d  wo ",wordL);
    //printf("%d  tx ",counter);
    printf("Anagram Sequences: ");
    foo3(wordL,counter);
    //printf("%d  wo ",wordL);
    //printf("%d  tx ",counter);
    return 0;
}
void getWord() {
    char ch [WORD];
    scanf("%s",ch);
    int length = strlen(ch);
    for (int i = 0; i < length; ++i) {
        if (ch[i] != ' ' && ch[i] != '\n' && ch[i] != '\t')
            word [i] = ch[i];
        else i = length +1;
    }
    length = strlen(word);
    for (int i = 0; i<length ;i++){
        if (islower(word[i]) == 512){
            gematria = gematria + word[i] - 96;}
        else if (isupper(word[i]) == 256){
            gematria = gematria + word[i] - 64 ;
        }
    }
}

int getTxt() {
    char tx [TXT];
    int counter = 0;
    scanf("%[^~]s",tx);
    int length = strlen(tx);
    for (int i = 0; i<length;i++){
        if(tx[i] == '~') {
            i = TXT +1 ;
        }
        else {counter = counter +1;}
    }
    for (int i = 0; i<counter;i++){
        txt[i] = tx [i];
    }
    return counter;
}

void foo1(int counter) {
    // bee
    // I'm bringing home my baby bumble bee won't my Mommy be so proud of me I'm bringing home my baby bumble bee-OUCH!! it stung me!!~
    char res [counter];
    int sum = 0;
    int flag = 0;
    int first =1;
    for (int i = 0; i<counter;i++){
        sum = 0;
        flag =1;
        for (int j = i ; j<counter;j++){
            if (flag == 1 && islower(txt[j])!=512 && isupper(txt[j]) != 256)
                break;
            flag = 0;
            if (islower(txt[j]) == 512){
                sum  = sum  + txt[j] - 96;
            }
            else if (isupper(txt[j]) == 256) {
                sum = sum + txt[j] - 64;
            }
            res[j] = txt[j];
            if (sum == gematria){
                if (first == 0) {
                    printf("~");
                }
                first = 0;
                for (int k = i ; k<=j;k++) {
                    if (txt[k] == "\n")
                        printf("\n");
                    printf("%c", res[k]);
                }
                j=counter;
            }
        }
    }
    printf("\n");
}

void azby(int wordL) {
    for (int i = 0; i < wordL-1 ; ++i) {
        char ch;
        if (islower(word[i]) == 512){
            ch = (char)(122 - (word[i] - 97));
        }
        else if (isupper(word[i]) == 256) {
            ch = (char)(90 - (word[i] - 65));
        }
        else ch = word [i];
        atbash[i] = ch;
    }
}

void foo2(int wordL, int counter) {
    char resf [counter-1];
    char resl [counter-1];
    int flag = 1;
    int first = 1;
    int counterf = 0;
    int counterl = 0;
    int flag2 = 0;
    for (int i = 0; i < counter-1 ; i++) {
        flag =1;
        counterf = 0;
        counterl =0;
        for (int j = i; j < counter-1 ; j++) {
            if (flag == 1 && islower(txt[j]) != 512 && isupper(txt[j]) != 256) {
                break;
            }
            flag =0;
            flag2 =0;
            if (txt[j] == atbash[counterf]) {
                counterf++;
                resf[j] = txt[j];
                flag2 = 1;
            }
            else if (islower(txt[j]) != 512 && isupper(txt[j]) != 256){
                resf[j] = txt[j];
                flag2 =1;
            }
            if (txt[j] == atbash[wordL - 2 - counterl]) {
                counterl++;
                resl[j] = txt[j];
                flag2 =1;
            }
            else if (islower(txt[j]) != 512 && isupper(txt[j]) != 256){
                resl[j] = txt[j];
                flag2=1;
            }
            if(flag2 == 0) break;
            if (counterf == wordL-1 && resf[i] == atbash[0]){
                if (first == 0) {
                    printf("~");
                }
                first = 0;
                for (int k = i ; k<=j;k++) {
                    if (txt[k] == "\n")
                        printf("\n");
                    printf("%c", resf[k]);
                }
                j=counter;
            }
            else if (counterl == wordL-1 && resl[i] == atbash[wordL - 2]){
                if (first == 0) {
                    printf("~");
                }
                first = 0;
                for (int k = i ; k<=j;k++) {
                    if (txt[k] == "\n")
                        printf("\n");
                    printf("%c", resl[k]);
                }
                j=counter;
            }
        }
    }
    printf("\n");
}
//#aabcdefg
// b adacefg# ,gb dacefg# ,gb, adacefg#  , gb adacefg#

void foo3(int wordL,int counter) {
    char res [counter-1];
    int sum = 0;
    int flag = 1;
    int flag2 = 0;
    int first = 1;
    char tmp[wordL-1];
    for (int i = 0; i < counter-1 ; i++) {
        flag =1;
        flag2 =0;
        sum =0;
        for (int l = 0; l < wordL-1; ++l) {
            tmp[l] =word[l];
        }
        for (int j = i; j < counter ; j++) {
            if (flag == 1 && islower(txt[j]) != 512 && isupper(txt[j]) != 256) {
                break;
            }
            flag2 =0;
            flag =0;
            for (int l = 0; l < wordL; ++l) {
                if (txt[j] == tmp[l]){
                    res[j] = tmp[l];
                    tmp[l] = "块v";
                    flag2 =1;
                    sum =sum + 1;
                    break;
                }
            }
            if (txt[j] == ' ') {
                res[j] = txt[j];
                flag2=1;
            }
            if (flag2 == 0 ) break;
            if (sum == wordL -1){
                if (first == 0) {
                    printf("~");
                }
                first = 0;
                for (int k = i ; k<=j;k++) {
                    if (txt[k] == "\n")
                        printf("\n");
                    printf("%c", res[k]);
                }
                j=counter;
            }
        }
    }
}
//a-bc,dbca-zwxyzabzyxw0dcba~
//a-0dcba~
