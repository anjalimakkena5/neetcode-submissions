class Solution {
public:
    double pow(double x,int n){
        if(n==0) return 1;
        if(n%2==0) return pow(x*x,n/2);
        else return x*pow(x,n-1);
    }
    double myPow(double x, int n) {
        if(n<0){
            n=abs(n);
            x=1/x;
        }
        return pow(x,n);
    }
};
