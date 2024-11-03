void fraction_adder(int a_numerator, int a_denominator, int b_numerator, int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr) {
  int under = a_denominator * b_denominator, upper = a_denominator * b_numerator + a_numerator * b_denominator;
  for(int i = 2; i <= 1000; i++)
  {
    while(upper % i == 0 && under % i == 0) upper/=i, under/=i;
  }
  *c_denominator_ptr = under;
  *c_numerator_ptr = upper;
  return;
}