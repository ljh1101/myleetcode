class Solution {
  public:
    int pivotInteger(int n)
    {
        if (n == 1) {
            return 1;
        }
        int l = 1, r = n - 1;
        int l_count = 0, r_count = n;
        while (l <= r) {
            if (l_count <= r_count) {
                l_count += l++;
            }
            else if (l_count >= r_count) {
                r_count += r--;
            }
            if (l == r && l_count == r_count) {
                return l;
            }
        }
        return -1;
    }
};
int main()
{
    Solution s;
    s.pivotInteger(8);
}