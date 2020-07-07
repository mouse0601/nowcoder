class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
    	/*
    	思路：选取一只手的手套，这只手的手套满足：（总数 - 最小 + 1），
			因为（总数 - 最小 + 1）满足这只手的每种颜色都拿到了，
			再拿另一只手的任一只手套即可满足题意。
		特殊情况：如果被选中手（A）某种颜色的手套数量为0，则在
			另一只手（B）中应该拿1 + B[A中为0的颜色的手套总和]只手套，
			因为要确保在B中一定拿到了1只A中的非0颜色的手套。
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
