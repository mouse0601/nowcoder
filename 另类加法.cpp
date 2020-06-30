class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        while(B != 0)
        {
            int a = 0;
            int c = 0;
            a = A ^ B;
            c = (A & B) << 1;
            A = a;
            B = c;
        }
        return A;
    }
};
