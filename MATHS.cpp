//! MATHS For DSA
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int inputNum() {
    int n;
    std :: cout << "enter a number :    ";
    std :: cin >> n;

    return n;
}

//* prime number
bool isPrime() {
    int n;
    std :: cout << "enter a number :    ";
    std :: cin >> n;

    for(int i=2;i*i<=n;i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

//* all primes between 0 to N (brute force O(n^2))
int primes() {

    int N;
    std :: cout << "enter range :    ";
    std :: cin >> N;

    std :: vector<int> pr_nos;

    if(N==0 || N==1 || N==2) {
        return 0;
    }
    else {

        for(int n=2;n<=N;n++) {
            bool isPrime = true;
            for(int i=2;i*i<=n;i++) {
                if(n % i == 0) {
                    isPrime = false;
                    break;
                }
            }   
            if(isPrime) {
                pr_nos.push_back(n);
            }
        }
    }
    int count = pr_nos.size();
    return count;
}

//* optimized : Sieve of Eratosthenes (discarding the multiples of current number from range)
int countPrime() {
    int N;
    std :: cout << "enter a number :    ";
    std :: cin >> N;

    std :: vector<bool> isPrime(N+1,true);
        int count = 0;

    for(int i=2; i<N; i++) {
        if(isPrime[i]) {
            count++;
        }
        for(int j=i*2;j<N;j+=i) {
            isPrime[j] = false;
        }
    }
    return count;
}

//* digits in a number
void digits() {
    int n;

    std :: cout << "enter a number :    ";
    std :: cin >> n;
    std :: cout << n << "\n";

    //^ logic
    while(n!=0) {
        int temp = n%10;
        std :: cout << temp << std :: endl;
        n/=10;
    }

    //^ shortcut
    //! std :: cout << (int)(log10(n) + 1);
}

//* armstrong number
void armstrong() {
    int n;

    std :: cout << "enter a number :    ";
    std :: cin >> n;
    std :: cout << n << "\n";

    int N = n;

    int cubeSum = 0;

    while(n!=0) {
        int temp = n % 10;
        cubeSum += (temp*temp*temp);
        n= n/10;
    }

    if(N==cubeSum) {
        std :: cout << "armstrong number\n";
    }
    else {
        std :: cout << "not a armstrong number\n";
    }

}

//* greatest common divisor(GCD) / HCF
//! time complexity = O(min(n1,n2)) ~ O(n)
int gcd() {
    int n1 = inputNum(); //^ 16
    int n2 = inputNum(); //^ 28

    if(n1==n2) {
        return n1;
    }

    if(n1==0) {
        return n2;
    }
    else if(n2==0) {
        return n1;
    }

    int great_div = 1;
    for(int i=1; i<= std :: min(n1,n2); i++) {
        if(n1%i == 0 && n2%i == 0) {
            great_div = std :: max(great_div,i);
        }
    }
    return great_div;
}

//* optimized : Euclid's Algorithm
int euclid() {
    int a = inputNum();
    int b = inputNum();

    //^ base case
    while(a>0 && b>0) {
        if(a>b) {
            a %= b; //^ use modulo instead of substraction bcoz of repeatation
        }
        else {
            b %= a;
        }
    }

    if(a==0) return b;
    return a;
}

//* using recurion (assume that a>b)
int recEuclid(int a, int b) {

    //^base case
    if(b==0) {
        return a;
    }
    return recEuclid(b, a%b);
}

//* lowest commom multiple (LCM) : basic... with gdc
int Lcm() {
    int a = inputNum();
    int b = inputNum();

    int lcm = (a*b)/recEuclid(a,b);

    return lcm;
}

//* LCM without calculating GCD (mine with some khatmals)
int Lcm2() {
    int a = inputNum(); //& 16
    int b = inputNum(); //& 10

    int l = std :: max(a,b);

    std :: vector<int> ma;
    std :: vector<int> mb;

    for(int i=1; i<l; i++) {
        ma.push_back(a*i);
    }
    for(int i=1; i<l; i++) {
        mb.push_back(b*i);
    }

    std :: vector<int> commons;

    for(int i=0;i<l;i++) {
        for(int j=0;j<l;j++) {
            if(ma[i]==mb[j]) {
                commons.push_back(ma[i]);
            }
        }
    }

    int least = commons[0];
    for(int i=0; i<commons.size(); i++) {
        if(commons[i] <= least) {
            least = commons[i];
        }
    }

    return least;
}

//* from github copilot
int lcm_cplt() {
    int a = inputNum(); //& 16
    int b = inputNum(); //& 10 
    
    int l = std :: max(a, b);

    for(int i=l; i<a*b; i++) {
        if(i%a == 0 && i%b == 0) {
            return i;
        }
    }
    return a*b;
}

//* reverse intiger
int reverseNum() {
    int n;
    
    std :: cout << "enter a number :    ";
    std :: cin >> n;
    std :: cout << n << "\n";
    int revNum = 0;
    
    while(n!=0) {
        int temp = n%10;
        if(revNum > INT_MAX/10 || revNum < INT_MIN/10){
            return 0;
        }
        revNum = (revNum*10) + temp;
        n /= 10;
    }
    return revNum;
}

//* palindrome number
bool isPalindrome(int x) {
    int reverse = 0;
    if(x<0) {
        return false;
    }
    else {
        while(x!=0) {
            int temp = x % 10;
            reverse = reverse*10 + temp;
            x = x / 10;
        }
    }
 
    return x==reverse;
}

//* modulo operator (return modulo of answer with val (10^7 + 9)) to prevent from overflow

//^ properties
//^ 1: (x +-* y) % m = x%m +-* y%m

//! catalan no. and power exp

//* roman to integar

//* plus one (leetcode 66)
std :: vector<int> plusOne(std :: vector<int> &vec) {

    int n = vec.size()-1;

    while(n >= 0) {
        if()
    }
}

int main() {
    return 0;
}

//& 999