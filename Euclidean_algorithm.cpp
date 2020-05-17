int GCD(int &a, int &b){
  if(b==0) return a;
  else return gcd(b, a%b);
}

int LCM(int a, int b) {return a * b / GCD(a, b);}
