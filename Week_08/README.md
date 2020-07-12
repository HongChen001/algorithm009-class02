# 学习笔记 #
# 本周学习内容 #
位运算、布隆过滤器、LRU缓存及排序算法
# 位运算 #
计算机存储形式为二进制，位运算直接操作二进制位，效率高。
## 位运算符 ##
- >> 右移 0110 >> 0011
- << 左移 0011 << 0110
- | 按位或 0011 | 1011 => 1011
- & 按位与 0011 & 1011 => 0011
- ~ 按位取反 ~0011 => 1100
- ^按位异或 0011 ^ 1011 => 1000
## 指定位置位运算 ##
1. 将 x 的最右边 n 位清零：x & (~0 << n)
2. 获取 x 的第 n 位值：(x >> n) & 1
3. 获取 x 的第 n 位的幂值：x & (1 << n)
4. 将第 n 位置为 1：x | (1 << n)
5. 将第 n 位置为 0：x & (~(1 << n))
6. 将 x 最高位到第 n 位清零：x & ((1 << n) - 1)
# 布隆过滤器 #
布隆过滤器可以用于检索一个元素是否在一个集合中。优点是空间效率和查询时间远超一般算法，缺点是有一定的误识别率及删除困难。
# LRU Cache #
LRU最近最少使用，实现方式：哈希 + 双向链表
# 排序算法 #
## 1. 比较类排序： ##
- 交换排序：冒泡排序、快速排序
- 插入排序：简单插入排序、希尔排序
- 选择排序：简单选择排序、堆排序
- 归并排序：二路归并排序、多路归并排序
## 2. 非比较类排序： ##
- 计数排序
- 桶排序
- 基数排序

## 初级排序代码实现 ##
### 1. 选择排序： ###
    void SlectionSort(vector<int>& data) {
	    if (data.empty()) return; 
	    int n = data.size();
	    int minIndex, minValue;
	    for (int i = 0; i < n; ++i) {
	        minIndex = i;
	        minValue = data[i];
	        for (int j = i + 1; j < n; ++j) {
	            if (minValue > data[j]) {
	                minValue = data[j];
	                minIndex = j;
	            }
	        }
	        if (i != minIndex) {
	            int tmp = data[minIndex];
	            data[minIndex] = data[i];
	            data[i] = tmp;
	        }
	    }
	}

### 2. 插入排序： ###
    void InsertionSort(vector<int>& data) {
	    if (data.empty()) return;
	    int n = data.size();
	    for (int i = 1; i < n; ++i) {
	        for (int j = i; j > 0; --j) {
	            if (data[j - 1] > data[j]) {
	                int tmp = data[j];
	                data[j] = data[j - 1];
	                data[j - 1] = tmp;
	            }
	        }
	    }
	}
### 3. 冒泡排序： ###
    void BubbleSort(vector<int>& data) {
	    if (data.empty()) return;
	    int n = data.size();
	    bool isChanged = false;
	    for (int i = 0; i < n - 1; ++i) {
	        for (int j = 0; j < n - i - 1; ++j) {
	            if (data[j] > data[j + 1]) {
	                int tmp = data[j];
	                data[j] = data[j + 1];
	                data[j + 1] = tmp;
	                isChanged = true;
	            }
	        }
	        if (!isChanged) return;
	        isChanged = !isChanged;
	    }
	}