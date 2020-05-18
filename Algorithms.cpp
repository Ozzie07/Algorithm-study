int GCD(int &a, int &b){
  if(b==0) return a;
  else return gcd(b, a%b);
}

int LCM(int a, int b) {return a * b / GCD(a, b);}

//find Isit primenumber?
bool prime(int n){
  if(n<2) return false;
  for (int i = 2; i*i<=n; i++)
    if(n%i==0)
      return false;
  return true;
}
