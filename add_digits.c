int addDigits(int num){
    int remainder;
    while(num>=10){
        int sum=0;
        while(num>0){
            remainder=num%10;
            sum=sum+remainder;
            num=num/10;
        }
        num=sum;
    }
    return num;
}
