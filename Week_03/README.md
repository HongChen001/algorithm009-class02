学习笔记
本周学习内容 递归、分治及回溯
递归(Recursion)：本质上就是循环，函数通过调用自己实现循环。向下一层层递归，需要一个返回条件，一层层返回得到最终结果。
递归模板：1、递归终止条件 2、当前层处理逻辑 3、进入下一层 4、清理当前层。
递归问题思维要点：1、不要人肉递归 2、找重复子问题 3、数学归纳法

分治(Divide)：特殊的递归，将问题拆解成子问题，将子问题结果合并返回原问题结果。与递归相比多了一步将子问题结果合并。

回溯(Conquer)：特殊的递归，在每一层递归不断尝试，不满足问题条件则返回上一层，直到解决问题或者问题无结果。