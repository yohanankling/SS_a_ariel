
int isPalindrome(int n){
 int number = n;
        int rest = 0;
        int reversNumber = 0;
        while (n != 0) {
            rest = n % 10;
            reversNumber = reversNumber * 10 + rest;
            n /= 10;
        }
        if (number == reversNumber)
            return 1;
        else
            return 0;
    }

int isArmstrong(int n){
 int result = 0;
        int rest = 0;
        int pow=0;
        int temp = n;
        while (temp != 0) {
            pow++;
            temp = temp/10;
        }
        temp =n ;
        while (temp != 0) {
            rest = temp % 10;
            int temp_2=temp%10;
            for (int i =0;i<pow-1;i++){
                rest=rest*temp_2;}
            result = result + rest;
            temp /= 10;
        }
        if (result == n)
            return 1;
        else
            return 0;
    }