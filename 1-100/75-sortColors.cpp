#include <vector>
#include <cstdio>
using namespace std;

void printVector(vector<int>& nums) {
  printf("[");
  for (int i = 0; i < nums.size(); i++) {
    if (i > 0) {
      printf(",");
    }
    printf("%d", nums[i]);
  }
  printf("]\n");
}

void sortColors(vector<int>& nums) {
  int p = 0, q = nums.size()-1;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 0) {
      // 如果nums[p] == 0，那么交换没意义(nums[i] == nums[p] == 0)
      // 只有在nums[p] != 0时交换才有意义
      // p < nums.size()：数组越界检查
      while (p < nums.size() && nums[p] == 0) p++;

      // p >= i 说明数组在p之前已经全部是0了，排好了
      // i直接跳到p-1执行就好了
      // p-1是因为每次循环都要+1
      if (p >= i) {
        i = p-1;
        continue;
      }

      swap(nums[p++], nums[i]);
    } else if (nums[i] == 2) {
      // 如果nums[q] == 2，那么交换没意义(nums[i] == nums[q] == 2)
      // 只有在nums[q] != 2时交换才有意义
      // q >= 0：数组越界检查
      while (q >= 0 && nums[q] == 2) q--;
      
      // 数组下标i后面全部都是2，说明数组已经排序完成了
      if (q < i) break;
      
      /*
        为什么这里要用i--：
        对颜色进行排序，需要把全部的颜色都扫一遍
        因为q > i，所以如果不加i--的话，那么交换的那个元素(nums[q])就不会被扫描到(每次循环结束都要i++)
        因此会出现问题
      */
      swap(nums[q--], nums[i--]);
    }
  }
}

void sortColors2(vector<int>& nums) {
  int num0 = 0, num1 = 0, num2 = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 0) {
      nums[num2++] = 2;
      nums[num1++] = 1;
      nums[num0++] = 0;
    } else if (nums[i] == 1) {
      nums[num2++] = 2;
      nums[num1++] = 1;
    } else {
      nums[num2++] = 2;
    }
  }
}

int main() {
  vector<int> nums{2,0,2,1,1,0};
  sortColors2(nums);
  printVector(nums);
  return 0;
}