  int factorial(int actualFactorial);

   int isPrime(int n) 
   {
        int ans = 1;
        for (int i = 2; i <= n/2; i++) {
            if (n == 1) {
                ans = 1;
            }
            if (n!=i && n % i == 0) {
                return 0;
            }
        }
        return ans;
    }

int factorial(int actualFactorial) 
 {
        int thisSum=1;
        for(int i=1;i<=actualFactorial;i++)
        {
            thisSum=thisSum*i;
        }
        return thisSum;
    }

int isStrong(int n) { 
 int sum=0;
        int temp=n;
        int thisnum=0;
        while(temp!=0)
        {
            thisnum=temp%10;
            int finallFactorial=factorial(thisnum);
            temp=temp/10;
            sum=sum+finallFactorial;
        }
        if(sum==n)
            return 1;
        else
            return 0;
    }