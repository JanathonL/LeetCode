223. Rectangle Area
这题一看就知道要分类讨论，但是纯用分类讨论做会比较麻烦，写了一半不想写了
一个比较好的想法就是，直接计算overlap的坐标，
经过思考后发现，overlap的顶点坐标是确定的，不管存不存在
int leftx = max(A,E), lefty = max(B,F), rightx = min(C,G), righty = min(D,H);
这样的话只需要判断一下这两个点的x和y是否满足右边的都大于等于左边就可以了，只有两种情况，有重叠或者没有。
