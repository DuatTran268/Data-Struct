#pragma once
int DemSoNut(BSTree root);
int DemNutNhoHon(BSTree root, KeyType x);
BSTree Search(KeyType x, BSTree root);
int IsLeaf_x(BSTree root, KeyType x);
int DemNutLa(BSTree root);
int TinhMax(int a, int b);
int TinhChieuCao(BSTree root);
int TimMuc_x(BSTree root, KeyType x);
KeyType DeleteMin(BSTree& root);
int DeleteNode(KeyType x, BSTree& root);
void RemoveTree(BSTree& root);
//Dinh nghia ham
//Dem so nut
int DemSoNut(BSTree root)
{
	if (root == NULL)
		return 0;
	return 1 + DemSoNut(root->left) + DemSoNut(root->right);
}

int DemNutNhoHon(BSTree root, KeyType x)
{
	int soNut;
	if (root == NULL)
		soNut = 0;
	else
		if (root->key < x)
		{
			cout << root->key << '\t';
			soNut = 1 + DemNutNhoHon(root->left, x) + DemNutNhoHon(root->right, x);
		}
		else
			soNut = DemNutNhoHon(root->left, x) + DemNutNhoHon(root->right, x);
	return soNut;
}
BSTree Search(KeyType x, BSTree root)
{
	if (root != NULL)
	{
		if (root->key == x)
			return root;
		else
			if (root->key < x)
				return Search(x, root->right); 
			else
				return Search(x, root->left); 
	}
	return NULL; 
}
int IsLeaf_x(BSTree root, KeyType x)
{
	int kq = 0;
	BSTree T = Search(x, root);
	if (T == NULL)
		kq = -1;//x khong co trong cay
	else
		kq = (T->left == NULL) && (T->right == NULL);
	return kq;
}
int DemNutLa(BSTree root)
{
	int soNutLa;
	if (root == NULL)
		soNutLa = 0;
	else
		if (root->left == NULL && root->right == NULL)
		{
			cout << root->key << '\t';
			soNutLa = 1;
		}
		else
			soNutLa = DemNutLa(root->left) + DemNutLa(root->right);
	return soNutLa;
}
int TinhMax(int a, int b)
{
	if (a >= b)
		return a;
	return b;
}
 // tim chieu cao
int TinhChieuCao(BSTree root)
{
	int h;
	if (root == NULL)
		h = -1;
	else
		if (root->left == NULL && root->right == NULL)
			h = 0;
		else
			h = 1 + TinhMax(TinhChieuCao(root->left), TinhChieuCao(root->right));
	return h;
}
// tim muc
int TimMuc_x(BSTree root, KeyType x)
{
	int muc;
	muc = 0;
	BSTree T = root;
	while (T != NULL)
	{
		if (T->key == x)
			break;
		else
		{
			muc++;
			if (T->key > x)
				T = T->left;
			else
				T = T->right;
		}
	}
	return muc;
}
// so sanh
int SoSanhMuc(BSTree root, KeyType x, KeyType y)
{
	int kq1, kq2;
	kq1 = TimMuc_x(root, x);
	kq2 = TimMuc_x(root, y);
	if (kq1 > kq2)
		return 1;
	else
		if (kq1 < kq2)
			return -1;
		else
			return 0;
}

// Xoa
KeyType DeleteMax(BSTree& root)
{
	KeyType k;
	if (root->right == NULL)
	{
		k = root->key;
		root = root->left;
		return k;
	}
	else
		return DeleteMax(root->right);
}
// Xoa cho truoc
int DeleteNode(KeyType x, BSTree& root)
{
	if (root != NULL)
	{
		if (x < root->key)
			DeleteNode(x, root->left);
		else
			if (x > root->key)
				DeleteNode(x, root->right);
			else 
				if ((root->left == NULL) && (root->right == NULL))
					root = NULL;
				else
					if (root->left == NULL)
						root = root->right;
					else
						if (root->right == NULL)
							root = root->left;
						else 
							root->key = DeleteMax(root->right);
		return 1; 
	}
	return 0;
}

