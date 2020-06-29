class LCA {
public:
    int getLCA(int a, int b) {
        // write code here
        int a_num[a];
        int b_num[b];
        int a_n = 0;
        while(a/2)
        {
            a_num[a_n++] = a/2;
            a /= 2;
        }
        int b_n = 0;
        while(b/2)
        {
            b_num[b_n++] = b/2;
            b /= 2;
        }
        for(int i =0;i < a_n;i++)
        {
            for (int j = 0;j < b_n;j++)
                if(a_num[i] == b_num[j])
                    return a_num[i];
        }
        //大神做法
        if (a == b)
        return a;
        return a>b? getLCA(a/2, b): getLCA(a, b/2);
    }
};