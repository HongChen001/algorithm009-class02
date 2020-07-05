#学习笔记
##本周学习了 
Trie树、并查集、剪枝、双向BFS、启发式搜索及AVL树和红黑树
##Trie树：
多叉树结构，每个节点存储一个字母，路径即为一个单词。是采用空间换时间的思想实现。
##并查集：
具有合并查找方法的集合，主要包含合并函数，查找元素所在集合函数。
##剪枝：
对于数量较多的状态树进行分支剪除操作。将不必要的分支剪除，达到简化算法，降低时间复杂度目的。
##双向BFS：
采用首尾同时进行广度优先搜索的策略降低时间复杂度。
##启发式搜索：
通常使用优先级队列，按照优先级搜索，优先级由估价函数决定。
##AVL树：
平衡二叉查找树。AVL树的左右子树高度差(平衡因子)的绝对值不超过1。通过左旋、右旋、左右旋、右左旋保证平衡因子不超过1。
##红黑树：
近似平衡二叉搜索树，任何一个节点的左右子树高度差小于两倍。
###红黑树满足：
- 每个节点是红色或黑色；
- 根节点是黑色；
- 每个叶节点(NIL节点, 空节点)是黑色；
- 不能有相邻的两个红色节点；
- 从任一节点到其每个叶节点的所有路径都包含相同数目的黑色节点。

##单词搜索 II 用字典树方式实现的时间复杂度分析:
 时间复杂度：O(M(4x3^(L-1)))其中M是二维网格中的单元格数，LL 是单词的最大长度。遍历二维网格的所有元素，最多4个方向，4个方向继续扩展每个方向有3个相邻的单元格，即回溯探索期间最多遍历4x3^(L-1)个单元格。

##双向BFS代码模板: 
    void twoWayBFS(vector<int> target, int start, int end {
	    Set<int> startSet, endSet, tmpSet,visited;
	    startSet.insert(start);
	    endSet.insert(end);
	    int ret = 0;
	    while (!startSet.empty() && !endSet.empty()) {
	        if (startSet.size() > endSet.size()) {
	            tmpSet = startSet;
	            startSet = endSet;
	            endSet = tmpSet;
	        }
	        ret++;
	        tmp.clear();
	        for (int i : startSet) {
	            ...
	            if (endSet.find(i) != endSet.end()) {
	                return ret;
	            }
	
	            if (visited.find(i) == visited.end()) {
	                visited.insert(i);
	                tmp.insert(i);
	            }
	        }
	        startSet = tmp;
	    }
	    
	    return 0;
	}


