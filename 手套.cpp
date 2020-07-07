class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
    	/*
    	˼·��ѡȡһֻ�ֵ����ף���ֻ�ֵ��������㣺������ - ��С + 1����
			��Ϊ������ - ��С + 1��������ֻ�ֵ�ÿ����ɫ���õ��ˣ�
			������һֻ�ֵ���һֻ���׼����������⡣
		��������������ѡ���֣�A��ĳ����ɫ����������Ϊ0������
			��һֻ�֣�B����Ӧ����1 + B[A��Ϊ0����ɫ�������ܺ�]ֻ���ף�
			��ΪҪȷ����B��һ���õ���1ֻA�еķ�0��ɫ�����ס�
    	*/
        // write code here
        int sum = 0;
        int sum_left = 0, sum_right = 0;
        int leftmin = INT_MAX;
        int rightmin = INT_MAX;
        for(int i = 0;i < n;i++)
        {
            if(left[i]*right[i] == 0)
                sum += (left[i] + right[i]);
            else{
                sum_left += left[i];
                sum_right += right[i];
                leftmin = min(leftmin,left[i]);
                rightmin = min(rightmin,right[i]);
            }
        }
        return sum + min(sum_left - leftmin + 1,sum_right - rightmin + 1) +1;
    }
};
