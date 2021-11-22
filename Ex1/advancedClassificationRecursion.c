int reverse(int num,int temp);
int HisArmstrong(int digit,int n);

int isPalindrome(int num)
    {
       int revNum = reverse(num,0);
        if(num == revNum )
        {
            return 1;
        }
        return 0;
    }

int reverse(int num,int temp)
{
        if (num==0)
            return temp;
        temp = (temp * 10) +
                (num % 10);

        return reverse(num / 10, temp);
    }

int HisArmstrong(int digit,int n){
    if (n==0)
            return 0;
        else {
            int pow=n%10;
            int temp_2=n%10;
            for (int i =0;i<digit-1;i++){
            pow =pow*temp_2;}
            return  (pow+HisArmstrong(digit,n/10));
        }
    }
      
int isArmstrong(int n){
    int temp = n;
        int digit = 0;
        while (temp != 0) {
            digit++;
            temp = temp/10;
        }
        int sum = 0;
        sum = HisArmstrong(digit,n);
        if (n == sum){
        return 1;}
        else
        return 0;
    }
