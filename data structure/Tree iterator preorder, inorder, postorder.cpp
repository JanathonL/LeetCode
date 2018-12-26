Tree iterator preorder, inorder, postorder


//中序遍历
void InOrderWithoutRecursion2(BTNode* root)
{
	//空树
	if (root == NULL)
		return;
	//树非空
	BTNode* p = root;
	stack<BTNode*> s;
	while (!s.empty() || p)
	{
		if (p)
		{
			s.push(p);
			p = p->lchild;
		}
		else
		{
			p = s.top();
			s.pop();
			cout << setw(4) << p->data;
			p = p->rchild;
		}
	}
}

//前序遍历
void PreOrderWithoutRecursion2(BTNode* root)
{
	if (root == NULL)
		return;
	BTNode* p = root;
	stack<BTNode*> s;
	while (!s.empty() || p)
	{
		if (p)
		{
			cout << setw(4) << p->data;
			s.push(p);
			p = p->lchild;
		}
		else
		{
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
	cout << endl;
}

//后序遍历
void PostOrderWithoutRecursion(BTNode* root)
{
	if (root == NULL)
		return;
	stack<BTNode*> s;
	//pCur:当前访问节点，pLastVisit:上次访问节点
	BTNode* pCur, *pLastVisit;
	//pCur = root;
	pCur = root;
	pLastVisit = NULL;
	//先把pCur移动到左子树最下边
	while (pCur)
	{
		s.push(pCur);
		pCur = pCur->lchild;
	}
	while (!s.empty())
	{
		//走到这里，pCur都是空，并已经遍历到左子树底端(看成扩充二叉树，则空，亦是某棵树的左孩子)
		pCur = s.top();
		s.pop();
		//一个根节点被访问的前提是：无右子树或右子树已被访问过
		if (pCur->rchild == NULL || pCur->rchild == pLastVisit)
		{
			cout << setw(4) << pCur->data;
			//修改最近被访问的节点
			pLastVisit = pCur;
		}
		/*这里的else语句可换成带条件的else if:
		else if (pCur->lchild == pLastVisit)//若左子树刚被访问过，则需先进入右子树(根节点需再次入栈)
		因为：上面的条件没通过就一定是下面的条件满足。仔细想想！
		*/
		else
		{
			//根节点再次入栈
			s.push(pCur);
			//进入右子树，且可肯定右子树一定不为空
			pCur = pCur->rchild;
			while (pCur)
			{
				s.push(pCur);
				pCur = pCur->lchild;
			}
		}
	}
	cout << endl;
}
// --------------------- 
// 作者：苏叔叔 
// 来源：CSDN 
// 原文：https://blog.csdn.net/zhangxiangDavaid/article/details/37115355 
// 版权声明：本文为博主原创文章，转载请附上博文链接！