typedef struct equation *Equation;

Equation newEq(int a, int b, int n);
int get_a(Equation e);
int get_b(Equation e);
int get_n(Equation e);
int *getA(Equation e);
int *getB(Equation e);
int *getN(Equation e);
